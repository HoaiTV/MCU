#ifndef __FLASH_H__
#define __FLASH_H__

#define MEDIUM_DENSITY

#ifdef LOW_DENSITY
#define FLASH_PAGE_FACTOR 10
#elif defined MEDIUM_DENSITY
#define FLASH_PAGE_FACTOR 10
#elif defined HIGH_DENSITY
#define FLASH_PAGE_FACTOR 11
#endif

VOID InitFlash();
VOID EraseFlash(DWORD nPage, DWORD nCount);
VOID WriteFlash(PVOID pData, WORD nSize, DWORD nAddr);
VOID ReadFlash(PVOID pBuffer, WORD nSize, DWORD nAddr);
VOID SetBank(BYTE nBank);
PVOID FlashToMemory(DWORD nAddr);

#endif // __FLASH_H__

