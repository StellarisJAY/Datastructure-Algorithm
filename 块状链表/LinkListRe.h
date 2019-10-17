#pragma once

#define OK 111
#define ERROR -111
#define True 1
#define False 0

#define MAX_SIZE 1000000      // �����������
#define CHUNK_SIZE 100        // һ���������С

typedef int Status;
typedef int ElementType;
typedef ElementType ET;

// һ���ڴ�飬������һ��˳���
typedef struct chunk {
	ET elem[CHUNK_SIZE];
	int chunkLength;
}Chunk;


typedef struct node {
	Chunk e;
	struct node* next;
}LNode, *LinkList;

LinkList CreateList();
Status InsertList_L(LinkList L, int i, ET e);


