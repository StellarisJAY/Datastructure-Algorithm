#include "SqStack.h"
#include "Calculator.h"
#include <stdio.h>


int main(void)
{
	int result;
	printf("输入表达式（#结尾）:");
	if ((result = EvaluateExpression()) != Error)
	{
		printf("结果：%d\n", result);
	}
	else
	{
		printf("表达式错误\n");
	}
	return 0;
}