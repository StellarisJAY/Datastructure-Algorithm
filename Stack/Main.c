#include "Stack.h"
#include <stdio.h>

int main(void)
{
	Stack s;
	
	if (InitStack(&s) == OK) printf("成功创建了栈\n");

}