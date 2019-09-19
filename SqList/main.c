#include "SqList.h"
#include <stdio.h>

int main(void)
{
	int i;
	int elem;
	SqList List;
	SqList La, Lb;

	InitList(&La);
	InitList(&Lb);
	InitList(&List);
	
	printf("��˳����в���10��Ԫ��:\n");
	for (i = 1; i <= 10; i++)
	{
		ListInsert(&List, i, i);
	}
	printf("�����\n");
	PrintList(List);

	printf("ɾ��˳�����Ԫ��1��Ԫ��5��\n");
	ListDelete(&List, 5);
	ListDelete(&List, 1);
	printf("�����\n");
	PrintList(List);
	

	printf("����Ԫ�أ�4\n");
	printf("λ�ã�%d\n", LocateElem(List, 4));

	printf("���λ��3λ�õ�Ԫ�أ�\n");
	GetElem(List, 3, &elem);
	printf("ֵ��%d\n", elem);

	ClearList(&List);                // ���List
	DestroyList(&List);                 // ����List
	

	for (i = 1; i < 10; i++)
	{
		ListInsert(&La, i, i);
	}
	for (i = 5; i < 15; i++)
	{
		ListInsert(&Lb, i - 4, i);
	}
	
	
	printf("La: ");
	PrintList(La);
	putchar('\n');
	

	printf("Lb: ");
	PrintList(Lb);
	putchar('\n');

	printf("����鲢�����");
	SqList Lc;
	InitList(&Lc);
	Merge(La, Lb, &Lc);
	PrintList(Lc);

	printf("La, Lb ���򲢼�:");
	Union_Sq(&La, &Lb);
	PrintList(La);
	return 0;
}
