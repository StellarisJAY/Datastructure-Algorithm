#ifndef LINK_LIST

#define ERROR -1
#define OK 1

typedef struct Node
{
	int elem;
	struct Node* next;
}Node, *LinkList;

LinkList InitLinkList();
int GetElem(LinkList L, int i, int* e);
Node* LocateElem(LinkList L, int e);
int ListInsert(LinkList L, int i, int e);
int ListDelete(LinkList L, int i);
void PrintList(LinkList L);
int GetLength(LinkList L);

int CreateLinkList_H(LinkList L, int n);
int CreateLinkList_R(LinkList L, int n);
#endif