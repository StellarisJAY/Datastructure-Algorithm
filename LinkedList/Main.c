#include <stdio.h>
#include "LinkList.h"

int main(void)
{
	int i;
	LinkList List1;

	if ((List1 = InitLinkList()) != NULL)
		printf("�ɹ���ʼ��������List1\n");
	printf("�Զ�������List1�в���10��Ԫ��:\n");
	for (i = 1; i <= 10; i++)
	{
		ListInsert(List1, i, i);
	}
	printf("�����");
	PrintList(List1);

	printf("ѡ��Ҫɾ���Ľڵ�λ�ã�");
	scanf("%d", &i);
	if (ListDelete(List1, i) != ERROR)
	{
		printf("�ɹ�ɾ����%d���ڵ�\n", i);
		printf("ɾ���������");
		PrintList(List1);
	}
	else
		printf("ɾ���Ľڵ���Ч");

	LinkList List2;
	if ((List2 = InitLinkList()) != NULL)
		printf("�ɹ���ʼ������List2\n");
	if ((CreateLinkList_H(List2, 10)) == OK)
	{
		printf("�ɹ���ͷ�巨����������List2\n���:");
		PrintList(List2);
	}
	else
		printf("��������List2ʧ��\n");

	LinkList List3;
	if ((List3 = InitLinkList()) != NULL)
		printf("�ɹ���ʼ������List3\n");
	if ((CreateLinkList_R(List3, 5)) == OK)
	{
		printf("�ɹ���β�巨����������List3\n���:");
		PrintList(List3);
	}
	else
		printf("β�巨��������List3ʧ��\n");
	return 0;
}