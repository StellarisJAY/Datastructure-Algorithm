#ifndef SqList
#define MAX_SIZE 1000

#define ERROR -1
#define OK 1

typedef int Status;
typedef int ElemType;

typedef struct {
	int* elem;
	int length;
}SqList;

int InitList(SqList* L);
void ClearList(SqList* L);
void DestroyList(SqList* L);

int GetElem(SqList L, int i, int* e);
int LocateElem(SqList L, int e);
int ListInsert(SqList* L, int i, int e);
int ListDelete(SqList* L, int i);
int PrintList(SqList L);

void Merge(SqList L1, SqList L2, SqList *L3);
void Union_Sq(SqList* L1, SqList* L2);

#endif