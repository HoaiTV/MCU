#include "flash.h"
#include "parameter.h"

#define ACTIVE_FLAG		0x55AAF50A
#define UNUSED_FLAG		0x00000000
#define LOW_SECTION		0x3C00	//page 60
#define HIGH_SECTION	0x3E00  //page 62
#define SECTION_SIZE	0x0200  //2k
#define FREE_ITEM 		0xFF
#define ZERO_ITEM		0x00
#define FREE_BLOCK		0xFFFFFFFF
#define ZERO_BLOCK		0x00000000

#define SECTION_ACTIVE(block) (*((PDWORD)(FlashToMemory(block))) == ACTIVE_FLAG)
#define g_pParamItems PARAM_ITEMS

PPARAMITEM PARAM_ITEMS[MAX_PARAM_ITEM] = { 0 };
BYTE g_nParamCount = 0;
INTERNAL WORD g_nActiveSection = 0;
INTERNAL SYSTEMCALLBACK g_pParamEvents[PARAM_EVENT_COUNT] = { NULL };

// Internal functions
INTERNAL PPARAMITEM NewItem(PPARAMITEM pSource);
INTERNAL PPARAMITEM SearchItem(WORD nParam);
INTERNAL VOID FormatSection(WORD nAddr);
INTERNAL WORD SwapSections();

VOID InitParameter(SYSTEMCALLBACK fnDefineProc)
{
    PPARAMITEM pItem;
    BOOL bFormat = FALSE;
    PARAMITEM pParamBuffer[MAX_PARAM_ITEM] = { 0 };

    if (SECTION_ACTIVE(LOW_SECTION))
	{
        g_nActiveSection = LOW_SECTION;
	}
    else if (SECTION_ACTIVE(HIGH_SECTION))
	{
        g_nActiveSection = HIGH_SECTION;
	}
    else 
    {
        FormatSection(LOW_SECTION);
        g_nActiveSection = LOW_SECTION;
        bFormat = TRUE;
    }
    // Define Parameters
    for (BYTE nIndex = 0; nIndex < MAX_PARAM_ITEM; nIndex++)
    {
        g_pParamItems[nIndex] = &pParamBuffer[nIndex];
    }
    g_pParamEvents[PARAM_DEFINE_EVENT] = fnDefineProc;
    g_pParamEvents[PARAM_DEFINE_EVENT](NULL);
    g_nParamCount = 0;

    // Create or locate parameters in flash
    if (bFormat != FALSE)
    {
        WORD nAddr = g_nActiveSection + 1;
        for (BYTE nIndex = 0; nIndex < MAX_PARAM_ITEM; nIndex++)
        {
            if (g_pParamItems[nIndex]->nParam != 0)
            {
                WriteFlash(g_pParamItems[nIndex], sizeof(PARAMITEM), nAddr);
                g_pParamItems[nIndex] = (PPARAMITEM)FlashToMemory(nAddr);
                g_nParamCount++;
                nAddr++;
            }
        }	
    }
    else
    {
        for (BYTE nIndex = 0; nIndex < MAX_PARAM_ITEM; nIndex++)
        {
            if (g_pParamItems[nIndex]->nParam != 0)
            {
                pItem = SearchItem(g_pParamItems[nIndex]->nParam);
                if (pItem == NULL)
				{
                    pItem = NewItem(g_pParamItems[nIndex]);
				}
                g_pParamItems[nIndex] = pItem;
                g_nParamCount++;
            }
        }
    }
}

BYTE GetParamCount()
{
    return g_nParamCount;
}

BOOL SetParam(WORD nParam, WORD nValue)
{
    for (BYTE nIndex = 0; nIndex < g_nParamCount; nIndex++)
    {
        if (g_pParamItems[nIndex]->nParam == nParam)
        {            
            PARAMITEM stItem = *g_pParamItems[nIndex];
            stItem.nValue = nValue;
            g_pParamItems[nIndex] = NewItem(&stItem);
            if (g_pParamEvents[PARAM_CHANGE_EVENT] != NULL)
            {
                PARAMCHANGEEVENT stEvent = {
                    PARAM_CHANGE_EVENT,
                    nIndex,
                    nParam,
                    nValue };
                g_pParamEvents[PARAM_CHANGE_EVENT](&stEvent);
            }
            return TRUE;
        }		
    }
    return FALSE;
}

WORD GetParam(WORD nParam)
{
    for (BYTE nIndex = 0; nIndex < g_nParamCount; nIndex++)
    {
        if (g_pParamItems[nIndex]->nParam == nParam)
		{
            return g_pParamItems[nIndex]->nValue;
		}
    }
    return 0;
}

VOID ResetParams()
{
    PARAMITEM pParamBuffer[MAX_PARAM_ITEM] = { 0 };
    WORD nAddr;
    FormatSection(LOW_SECTION);
    g_nActiveSection = LOW_SECTION;
    // Define Parameters
    for (BYTE nIndex = 0; nIndex < MAX_PARAM_ITEM; nIndex++)
	{
        g_pParamItems[nIndex] = &pParamBuffer[nIndex];
	}
    
    if (g_pParamEvents[PARAM_DEFINE_EVENT] != NULL)
	{
        g_pParamEvents[PARAM_DEFINE_EVENT](NULL);
	}
    g_nParamCount = 0;
    nAddr = g_nActiveSection + 1;
    for (BYTE nIndex = 0; nIndex < MAX_PARAM_ITEM; nIndex++)
    {
        if (g_pParamItems[nIndex]->nParam != 0)
        {
            WriteFlash(g_pParamItems[nIndex], sizeof(PARAMITEM), nAddr);
            g_pParamItems[nIndex] = (PPARAMITEM)FlashToMemory(nAddr);
            g_nParamCount++;
            nAddr++;
        }
    }
}

VOID RegisterParamCallback(BYTE nEvent, SYSTEMCALLBACK fnCallback)
{
    if (nEvent < PARAM_EVENT_COUNT)
    {
        g_pParamEvents[nEvent] = fnCallback;
    }
}

VOID ClearParams()
{
	EraseFlash(LOW_SECTION >> (FLASH_PAGE_FACTOR - 2), 4);
}

INTERNAL PPARAMITEM NewItem(PPARAMITEM pSource)
{
    WORD nAddr = g_nActiveSection + 1;
    PPARAMITEM pItem;
    while (nAddr < (g_nActiveSection + SECTION_SIZE))
    {
        pItem = (PPARAMITEM)FlashToMemory(nAddr);
        if (pItem->nParam == pSource->nParam)
        {
            DWORD dwZero = ZERO_BLOCK;
            WriteFlash(&dwZero, sizeof(DWORD), nAddr);
        }
        else if ((*((PDWORD)pItem)) == FREE_BLOCK)
        {            
            WriteFlash(pSource, sizeof(DWORD), nAddr);
            return pItem;
        }
        nAddr++;
    }
    // No free block found, swap the sections
    nAddr = SwapSections();
    WriteFlash(pSource, sizeof(PARAMITEM), nAddr);
    return (PPARAMITEM)FlashToMemory(nAddr);
}

INTERNAL PPARAMITEM SearchItem(WORD nParam)
{
    WORD nAddr = g_nActiveSection + 1;
    PPARAMITEM pItem;
    while (nAddr < (g_nActiveSection + SECTION_SIZE))
    {
        pItem = (PPARAMITEM)FlashToMemory(nAddr);
        if (pItem->nParam == nParam)
		{
            return pItem;
		}
        nAddr++;
    }	
    return NULL;
}

INTERNAL VOID FormatSection(WORD nAddr)
{
    DWORD dwHeader = ACTIVE_FLAG;
    // Erase section
    EraseFlash(nAddr >> (FLASH_PAGE_FACTOR - 2), 2);
    // Write section header
    WriteFlash(&dwHeader, sizeof(DWORD), nAddr);
}
 
INTERNAL WORD SwapSections()
{
    WORD nReserved;
    PARAMITEM stItem;
    WORD nAddr;
    DWORD dwFlag = UNUSED_FLAG;
    
    if (g_nActiveSection == LOW_SECTION)
    {
        FormatSection(HIGH_SECTION);
        nReserved = HIGH_SECTION;
    }
    else
    {
        FormatSection(LOW_SECTION);
        nReserved = LOW_SECTION;
    }
    
    nAddr = nReserved + 1;
    
    for (BYTE nIndex = 0; nIndex < g_nParamCount; nIndex++)
    {
        if (g_pParamItems[nIndex]->nParam != ZERO_ITEM)
        {
            stItem = *g_pParamItems[nIndex];
            WriteFlash(&stItem, sizeof(PARAMITEM), nAddr);
			g_pParamItems[nIndex] = (PPARAMITEM)FlashToMemory(nAddr);
            nAddr++;
        }
    }
    
    WriteFlash(&dwFlag, sizeof(DWORD), g_nActiveSection);
    g_nActiveSection = nReserved;
    return nAddr;	
}