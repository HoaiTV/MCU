#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#define PROGRAM_START_ADDRESS       0x8000000
#define MAINAPP_START_ADDRESS       0x8002000

VOID InitSystem();
WORD GetTickCount();
WORD GetSecondCount();
WORD Random(WORD nRange);
BYTE ByteRandom();
VOID Reboot();
VOID CopyMemory(PBYTE pDest, PBYTE pSource, WORD nSize);
VOID CopyInvert(PBYTE pDest, PBYTE pSource, BYTE nSize);
VOID ZeroMemory(PBYTE pDest, BYTE nSize);
VOID ActivateWatchdog();
VOID ResetWatchdog();
VOID SetDefaultCacheMode();
VOID SetPrefetchCacheMode();

#endif // __BOOT_H__