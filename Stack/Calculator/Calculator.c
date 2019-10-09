#include "Calculator.h"
#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

int CompareTable[7][7] = {
	{1, 1, -1, -1, -1, 1, 1},
	{1, 1, -1, -1, -1, 1, 1},
	{1, 1, 1, 1, -1, 1, 1},
	{1, 1, 1, 1, -1, 1, 1},
	{-1, -1, -1, -1, -1, 0, EMPTY},
	{1, 1, 1, 1, EMPTY, 1, 1},
	{-1, -1, -1, -1, -1, EMPTY, 0}
};

Status IsOperator(char c, int* code)
{
	if (c >= 48 && c <= 57)
	{
		*code = (int)c - 48;
		return False;
	}
	else
	{
		switch (c)
		{
		case '+': *code = 0; break;
		case '-': *code = 1; break;
		case '*': *code = 2; break;
		case '/': *code = 3; break;
		case '(': *code = 4; break;
		case ')': *code = 5; break;
		case '#': *code = 6; break;
		default: *code = -1; return Error;
		}
		return True;
	}
}

int Precede(int precode, int nextcode)
{
	
	if (precode < 0 || precode > 6 || nextcode < 0 || nextcode > 6) return Error;
	int code = CompareTable[precode][nextcode];
	
	if (code == EMPTY) return 2;
	else return code;
}

int Operate(int a, int opt, int b)
{
	switch (opt)
	{
	case 0: return a + b;
	case 1: return a - b;
	case 2: return a * b;
	case 3: return a / b;
	default: return Error;
	}
}

int EvaluateExpression()
{
	int i = 0;
	SqStack OPTR, OPND;           // 初始化操作符栈和操作数栈
	InitStack(&OPTR);
	InitStack(&OPND);

	char ch;
	Push(&OPTR, 6);           // 先在操作数栈中推入#
	
	ch = getchar();
	while (ch != '#' || GetTop(OPTR) != 6)     // 当读入的不是结束符‘#’或者操作符栈不为空时进行循环
	{
		int code;
		int a, b, opt;
		if (IsOperator(ch, &code) == False)         //判断当前读入字符是否是操作符， 并且将char类型转换为int存在code中
		{
			Push(&OPND, code);                      //操作符入栈
			ch = getchar();                         
		}
		else
		{
			switch (Precede(GetTop(OPTR), code))   //判断操作符优先级，根据优先级不同进行不同操作
			{
			case -1: Push(&OPTR, code); ch = getchar(); break;
			case 1: Pop(&OPTR, &opt); Pop(&OPND, &b); Pop(&OPND, &a); Push(&OPND, Operate(a, opt, b)); break;
			case 0: Pop(&OPTR, &opt); ch = getchar(); break;
			default: return Error;     // 如果读入的是无效字符就返回错误
			}
		}
	}
	return GetTop(OPND);
}