#ifndef DU_LINK_LIST

#define ERROR -1
#define OK 1

typedef struct Node
{
	int elem;
	struct Node* next;
	struct Node* prior;
}Node, *DuLinkList;

DuLinkList InitDuLinkList();
int DuListInsert(DuLinkList L, int i, int e);
int DuListDelete(DuLinkList L, int i);
#endif
