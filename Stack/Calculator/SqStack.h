#ifndef STACK
#define STACK

#define True 1
#define False 0
#define OK 111
#define Error -111
#define STACK_MAX_SIZE 10
#define STACK_INCREMENT 10

typedef int Status;
typedef int ElementType;
typedef ElementType ET;
typedef struct
{
	ET* base;
	int top;         //栈顶位置和实际储存元素数量
	int stackSize;   //栈元素的大小
}SqStack;

Status InitStack(SqStack* s);
Status Push(SqStack* s, ET e);
Status Pop(SqStack* s, ET* e);
ET GetTop(SqStack s);
#endif