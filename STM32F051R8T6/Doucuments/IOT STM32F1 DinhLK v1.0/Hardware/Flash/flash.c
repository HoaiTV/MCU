#include "stm32f10x_flash.h"
#include "flash.h"

#define FLASH_BEGIN_ADDRESS     0x08000000
#define BLOCK_TO_ADDR(block)    (((block) << 2) + (FLASH_BEGIN_ADDRESS))

VOID InitFlash()
{
    
}

VOID EraseFlash(DWORD nPage, DWORD nCount)
{
	DWORD nAddress;
	while (nCount != 0)
	{
		nAddress = (nPage << FLASH_PAGE_FACTOR) + FLASH_BEGIN_ADDRESS;
        FLASH_Unlock();
        FLASH_ErasePage(nAddress);
        FLASH_Lock();
		nPage++;
		nCount--;
	}
}

VOID WriteFlash(PVOID pData, WORD nSize, DWORD nAddr)
{
	DWORD nAddress = nAddr;
	PDWORD pPointer = (PDWORD)pData;
    if ((nSize % 4) != 0)
    {
        return;
    }
	while (nSize != 0)
	{
		nAddress = (nAddr << 2) + FLASH_BEGIN_ADDRESS;
        FLASH_Unlock();
		FLASH_ProgramWord(nAddress, *(pPointer));
        FLASH_Lock();
		pPointer++;
		nSize -= 4;
		nAddr++;
	}
}

VOID ReadFlash(PVOID pBuffer, WORD nSize, DWORD nAddr)
{
    FLASH_Unlock();
	PBYTE pSource = (PBYTE)(BLOCK_TO_ADDR(nAddr));
	for (WORD nIndex = 0; nIndex < nSize; nIndex++)
	{
		((PBYTE)pBuffer)[nIndex] = pSource[nIndex];
	}
    FLASH_Lock();
}

VOID SetBank(BYTE nBank)
{
    
}

PVOID FlashToMemory(DWORD nAddr)
{
	return (PVOID)(BLOCK_TO_ADDR(nAddr));
}



