#include "SqStack.h"
#include "Calculator.h"
#include <stdio.h>


int main(void)
{
	int result;
	printf("������ʽ��#��β��:");
	if ((result = EvaluateExpression()) != Error)
	{
		printf("�����%d\n", result);
	}
	else
	{
		printf("���ʽ����\n");
	}
	return 0;
}