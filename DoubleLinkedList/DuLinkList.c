#include "DuLinkList.h"
#include <stdio.h>
#include <stdlib.h>

DuLinkList InitDuLinkList()
{
	DuLinkList list;
	if ((list = (DuLinkList)malloc(sizeof(Node))) == NULL)
		return NULL;
	list->elem = 0;
	list->next = list;
	list->prior = list;
	return list;
}

int DuListInsert(DuLinkList L, int i, int e)
{
	int j = 0;
	Node* p = L;

	while (j < i - 1)
	{
		p = p->next;
		j++;
	}
	Node* s;
	if ((s = (Node*)malloc(sizeof(Node))) == NULL) return ERROR;
	s->elem = e;
	s->prior = p;
	p->next->prior = s;
	s->next = p->next;
	p->next = s;
	return OK;
}

int DuListDelete(DuLinkList L, int i)
{
	if (L->next == L) return ERROR;
	int j = 1;
	Node* p = L->next;

	while (j < i)
	{
		p = p->next;
		j++;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}