#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#pragma pack(1)
typedef struct tagPARAMCHANGEEVENT {
	BYTE nEvent;
	BYTE nIndex;
	WORD nParam;
	WORD nValue;
} PARAMCHANGEEVENT, *PPARAMCHANGEEVENT;

#pragma pack(1)
typedef struct tagPARAMITEM {
	WORD nParam;
	WORD nValue;
} PARAMITEM, *PPARAMITEM;

#define PARAM_DEFINE_EVENT     0
#define PARAM_CHANGE_EVENT     1
#define PARAM_EVENT_COUNT      2
#define MAX_PARAM_ITEM		   100 

#define PARAMETER(index) (PARAM_ITEMS[(index)]->nValue)
#define DEFINE_PARAM(index, param, value)\
	{ PARAM_ITEMS[(index)]->nParam = (param); PARAM_ITEMS[(index)]->nValue = (value); }

EXTERNAL PPARAMITEM PARAM_ITEMS[];
EXTERNAL BYTE g_nParamCount;

VOID InitParameter(SYSTEMCALLBACK fnDefineProc);
BYTE GetParamCount();
BOOL SetParam(WORD nParam, WORD nValue);
WORD GetParam(WORD nParam);
VOID ResetParams();
VOID RegisterParamCallback(BYTE nEvent, SYSTEMCALLBACK fnCallback);
VOID ClearParams();

#endif // __PARAMETER_H__

