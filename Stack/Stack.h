#ifndef STACK

#define MAX_SIZE 1000
#define ERROR -1
#define STACKFULL 0
#define OK 1

typedef struct
{
	int* base;
	int* top;
	int stackSize;
}Stack;

int InitStack(Stack* S);
int Pusth(Stack* S, int elem);
int Pop(Stack* S);
#endif