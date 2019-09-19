#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList InitLinkList()
{
	LinkList L = (LinkList)malloc(sizeof(Node));
	if (L == NULL)
		return NULL;
	L->next = NULL;
	L->elem = 0;
	return L;
}

int GetElem(LinkList L, int i, int* e)
{
	if (L->next == NULL)
		return ERROR;
	Node* p = L->next;
	int j = 1;

	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}

	if (p == NULL || j > i) return ERROR;
	*e = p->elem;
	return OK;
}

Node* LocateElem(LinkList L, int e)
{
	if (L->next == NULL)
		return NULL;
	Node* p = L->next;

	while (p != NULL && p->elem != e)
	{
		p = p->next;
	}
	return p;
}


int ListInsert(LinkList L, int i, int e)
{
	int j = 0;
	Node* p = L;

	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return ERROR;
	Node* s = (Node*)malloc(sizeof(Node));
	if (s == NULL) return ERROR;
	s->elem = e;
	s->next = p->next;
	p->next = s;
	L->elem += 1;

	return OK;
}

int ListDelete(LinkList L, int i)
{
	int j = 0;
	Node* p = L;
	
	if (L->next == NULL) return ERROR;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return ERROR;
	Node* d = p->next;
	p->next = p->next->next;
	free(d);
	L->elem--;
	return OK;
}

int CreateLinkList_H(LinkList L, int n)
{
	int i;
	printf("请输入%d个元素：", n);
	for (i = 0; i < n; i++)
	{
		Node* p;
		if ((p = (Node*)malloc(sizeof(Node))) == NULL) return ERROR;
		scanf("%d", &p->elem);
		p->next = L->next;
		L->next = p;
		L->elem++;
	}
	return OK;
}

int CreateLinkList_R(LinkList L, int n)
{
	int i;
	Node* r = L;

	printf("请输入%d个元素：", n);
	for (i = 0; i < n; i++)
	{
		Node* p;
		if ((p = (Node*)malloc(sizeof(Node))) == NULL) return ERROR;
		scanf("%d", &p->elem);
		p->next = NULL;
		r->next = p;
		r = p;
		L->elem++;
	}
	return OK;
}

int GetLength(LinkList L)
{
	return L->elem;
}

void PrintList(LinkList L)
{
	Node* p = L->next;

	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	putchar('\n');
}








