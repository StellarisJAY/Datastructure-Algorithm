#include <stdio.h>
#include "LinkList.h"

int main(void)
{
	int i;
	LinkList List1;

	if ((List1 = InitLinkList()) != NULL)
		printf("成功初始化了链表List1\n");
	printf("自动向链表List1中插入10个元素:\n");
	for (i = 1; i <= 10; i++)
	{
		ListInsert(List1, i, i);
	}
	printf("结果：");
	PrintList(List1);

	printf("选择要删除的节点位置：");
	scanf("%d", &i);
	if (ListDelete(List1, i) != ERROR)
	{
		printf("成功删除第%d个节点\n", i);
		printf("删除后的链表：");
		PrintList(List1);
	}
	else
		printf("删除的节点无效");

	LinkList List2;
	if ((List2 = InitLinkList()) != NULL)
		printf("成功初始化链表List2\n");
	if ((CreateLinkList_H(List2, 10)) == OK)
	{
		printf("成功用头插法创建了链表List2\n结果:");
		PrintList(List2);
	}
	else
		printf("创建链表List2失败\n");

	LinkList List3;
	if ((List3 = InitLinkList()) != NULL)
		printf("成功初始化链表List3\n");
	if ((CreateLinkList_R(List3, 5)) == OK)
	{
		printf("成功用尾插法创建了链表List3\n结果:");
		PrintList(List3);
	}
	else
		printf("尾插法创建链表List3失败\n");
	return 0;
}