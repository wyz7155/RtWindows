#include "../Include/RTWindowsServices.h"
#include <stdio.h>

int SEHFiler(int code)
{
	switch(code)
	{
		case EXCEPTION_ACCESS_VIOLATION :
			printf("�洢�����쳣��������룺%x\n", code);
			break;
		case EXCEPTION_DATATYPE_MISALIGNMENT :
			printf("��������δ�����쳣��������룺%x\n", code);
			break;
		case EXCEPTION_BREAKPOINT :
			printf("�ж��쳣��������룺%x\n", code);
			break;
		case EXCEPTION_SINGLE_STEP :
			printf("�����ж��쳣��������룺%x\n", code);
			break;
		case EXCEPTION_ARRAY_BOUNDS_EXCEEDED :
		printf("����Խ���쳣��������룺%x\n", code);
			break;
		case EXCEPTION_FLT_DENORMAL_OPERAND :
		case EXCEPTION_FLT_DIVIDE_BY_ZERO :
		case EXCEPTION_FLT_INEXACT_RESULT :
		case EXCEPTION_FLT_INVALID_OPERATION :
		case EXCEPTION_FLT_OVERFLOW :
		case EXCEPTION_FLT_STACK_CHECK :
		case EXCEPTION_FLT_UNDERFLOW :
			printf("�����������쳣��������룺%x\n", code);
			break;
		case EXCEPTION_INT_DIVIDE_BY_ZERO :
		printf("��0���쳣��������룺%x\n", code);
			break;
		case EXCEPTION_INT_OVERFLOW :
			printf("��������쳣��������룺%x\n", code);
			break;
		case EXCEPTION_IN_PAGE_ERROR :
			printf("ҳ�����쳣��������룺%x\n", code);
			break;
		case EXCEPTION_ILLEGAL_INSTRUCTION :
			printf("�Ƿ�ָ���쳣��������룺%x\n", code);
			break;
		case EXCEPTION_STACK_OVERFLOW :
			printf("��ջ����쳣��������룺%x\n", code);
			break;
		case EXCEPTION_INVALID_HANDLE :
			printf("��Ч�䲡�쳣��������룺%x\n", code);
			break;
		default :
			if(code & (1<<29))
			{
				printf("�û��Զ���������쳣��������룺%x\n", code);
			}
			else
			{
								printf("�����쳣��������룺%x\n", code);
			}
			break;
	}                     
	return 1;
}

void *GetSystemMem(int nLen)
{
	char *lpszMem = 0;

	nLen = (nLen & (ADDRESS_ALIGN - 1))?((nLen & ~(ADDRESS_ALIGN - 1)) + ADDRESS_ALIGN):nLen;

	if (s_SystemManager.lpSystemTable->nMemHead + nLen < SYSTEM_MEM_SIZE)
	{
		lpszMem = s_SystemManager.lpShareMemBase + s_SystemManager.lpSystemTable->nMemHead;

	//��֤Ϊ�ĵı���,�����ֱ߽�
		s_SystemManager.lpSystemTable->nMemHead += nLen;
	}

	return lpszMem;
}

