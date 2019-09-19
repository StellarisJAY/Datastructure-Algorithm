#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int InitStack(Stack* S)
{
	S->base = (int*)malloc(sizeof(int) * MAX_SIZE);
	if (S == NULL)return ERROR;
	S->top = S->base;
	S->stackSize = MAX_SIZE;
	return OK;
}

int Push(Stack* S, int elem)
{
	if (S->top - S->base == S->stackSize) return STACKFULL;
	*(++S->top) = elem;
	return OK;
}

int Pop(Stack* S, int* e)
{
	if (S->top == S->base) return ERROR;
	e = *(--S->top);
	return OK;
}

int GetTop(Stack* S)
{
	if (S->top != S->base)
		return S->top;
	return NULL;
}
