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
	int top;         //ջ��λ�ú�ʵ�ʴ���Ԫ������
	int stackSize;   //ջԪ�صĴ�С
}SqStack;

Status InitStack(SqStack* s);
Status Push(SqStack* s, ET e);
Status Pop(SqStack* s, ET* e);
ET GetTop(SqStack s);
#endif