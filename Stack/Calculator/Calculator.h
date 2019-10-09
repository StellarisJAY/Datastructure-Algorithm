#ifndef CALCULATE
#define CALCULATE
#include "SqStack.h"
#define EMPTY -10

int CompareTable[7][7];

Status IsOperator(char c, int* code);
int Precede(int precode, int nextcode);
int Operate(int a, int opt, int b);
int EvaluateExpression();
#endif