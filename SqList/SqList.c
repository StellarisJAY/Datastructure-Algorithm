#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

int InitList(SqList* L)
{
	L->elem = (int*)malloc(sizeof(int) * MAX_SIZE);
	if (L->elem == NULL)
		return ERROR;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		L->elem[i] = 0;
	}
	L->length = 0;
	return OK;
}

void ClearList(SqList* L)
{
	L->length = 0;
}

void DestroyList(SqList* L)
{
	if (L->elem) free(L->elem);
}

int GetElem(SqList L, int i, int *e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	*e = L.elem[i - 1];
	return OK;
}

int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}

int ListInsert(SqList* L, int i, int e)
{
	int j;

	if (i < 1 || i > L->length + 1 || L->length == MAX_SIZE) return ERROR;
	for (j = L->length; j >= i; j--)
	{
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length++;
	return OK;
}

int ListDelete(SqList* L, int i)
{
	int j;

	if (i < 1 || i > L->length) return ERROR;
	for (j = i; j < L->length; j++)
	{
		L->elem[j - 1] = L->elem[j];
	}
	L->length--;
	return OK;
}

int PrintList(SqList L)
{
	if (L.length <= 0)return ERROR;
	for (int i = 0; i < L.length; i++)
	{
		printf("%d  ", L.elem[i]);
	}
	putchar('\n');
	return OK;
}



// 遍历L1中每个元素，将其与L2中每个元素对比
// 如果L1中某元素与L2中没有一个相同，那么就将其插入到L2的对应位置（前一个位置元素小于它，后一个位置元素大于它）
void Union_Sq(SqList *L1, SqList *L2)
{
	int i, j;
	for (i = 0; i < L2->length; i++)
	{
		int foundPos = 0;
		for (int j = 0; j < L1->length; j++)
		{
			if (L2->elem[i] <= L1->elem[j])
			{
				ListInsert(L1, j, L2->elem[i]);
				foundPos = 1;
				break;
			}
		}
		if (foundPos == 0)
			ListInsert(L1, L1->length + 1, L2->elem[i]);
	}
}

void Merge(SqList L1, SqList L2, SqList* L3)
{
	int i;

	for (i = 0; i < L1.length; i++)
	{
		L3->elem[i] = L1.elem[i];
		L3->length++;
	}
	for (i = 0; i < L2.length; i++)
	{
		int foundPos = 0;
		for (int j = 0; j < L3->length; j++)
		{
			if (L2.elem[i] <= L3->elem[j])
			{
				ListInsert(L3, j, L2.elem[i]);
				foundPos = 1;
				break;
			}
		}
		if (foundPos == 0)
			ListInsert(L3, L3->length + 1, L2.elem[i]);
	}
}