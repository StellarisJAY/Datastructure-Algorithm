#include "LinkListRe.h"
#include <stdio.h>
#include <stdlib.h>

LinkList CreateList()
{
	LinkList L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) return NULL;
	L->next = NULL;
	L->e.chunkLength = 0;
	return L;
}

Status InsertList(LinkList L, int i, ET e)
{
	if (i % CHUNK_SIZE == 0)
	{
		LNode* nNode = (LNode*)malloc(sizeof(LNode));
		
	}
}