#pragma once

#define OK 111
#define ERROR -111
#define True 1
#define False 0

#define MAX_SIZE 1000000      // 链表最大结点数
#define CHUNK_SIZE 100        // 一个块的最大大小

typedef int Status;
typedef int ElementType;
typedef ElementType ET;

// 一个内存块，类似于一个顺序表
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


