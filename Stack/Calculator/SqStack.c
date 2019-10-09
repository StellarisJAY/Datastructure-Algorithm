#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

Status InitStack(SqStack* s)
{
	s->base = (ET*)malloc(sizeof(ET) * STACK_MAX_SIZE);
	if (s->base == NULL)return Error;
	s->top = 0;
	s->stackSize = sizeof(ET);
	return OK;
}

Status Push(SqStack* s, ET e)
{
	if (s->top == STACK_MAX_SIZE) return Error;
	s->base[s->top] = e;
	s->top++;
	return OK;
}

Status Pop(SqStack* s, ET* e)
{
	if (s->top == 0) return Error;
	*e = s->base[s->top - 1];
	s->top--;
	return OK;
}

ET GetTop(SqStack s)
{
	if (s.top > 0)
		return s.base[s.top - 1];
}