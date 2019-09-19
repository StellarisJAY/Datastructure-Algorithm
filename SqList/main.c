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
	
	printf("向顺序表中插入10个元素:\n");
	for (i = 1; i <= 10; i++)
	{
		ListInsert(&List, i, i);
	}
	printf("结果：\n");
	PrintList(List);

	printf("删除顺序表中元素1和元素5：\n");
	ListDelete(&List, 5);
	ListDelete(&List, 1);
	printf("结果：\n");
	PrintList(List);
	

	printf("查找元素：4\n");
	printf("位置：%d\n", LocateElem(List, 4));

	printf("获得位于3位置的元素：\n");
	GetElem(List, 3, &elem);
	printf("值：%d\n", elem);

	ClearList(&List);                // 清空List
	DestroyList(&List);                 // 销毁List
	

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

	printf("有序归并结果：");
	SqList Lc;
	InitList(&Lc);
	Merge(La, Lb, &Lc);
	PrintList(Lc);

	printf("La, Lb 有序并集:");
	Union_Sq(&La, &Lb);
	PrintList(La);
	return 0;
}
