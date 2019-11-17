#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

// �ݹ���Ҷ����������elem���ڸ��ڵ�͵ݹ���������������С�ھ͵ݹ���������������ھͷ��ظ��ڵ�
BiTNode* SearchBST(BiTNode* root, ElementType elem)
{
	if (root == NULL)
		return NULL;
	else
	{
		if (root->elem == elem) {
			return root;
		}
		else if (root->elem > elem) {
			return SearchBST(root->lChild, elem);
		}
		else if (root->elem < elem) {
			return SearchBST(root->rChild, elem);
		}
	}
}


// ����������в���һ�����
// ˼·�ǲ��뵽Ҷ��λ�ã�����������ڸ��ڵ������Ҷ�ӣ�С�ھ�����Ҷ��
int InsertNode(BiTree* tree, ElementType elem)
{
	BiTNode* node = (BiTNode*)malloc(sizeof(BiTNode));
	if (node == NULL)return 0;
	node->elem = elem;
	node->lChild = NULL;
	node->rChild = NULL;

	if (tree->root == NULL)
	{
		tree->root = node;
		return 1;
	}
	else
	{
		BiTNode* temp = tree->root;
		while (temp != NULL)
		{
			if (elem < temp->elem) {
				if (temp->lChild == NULL)
				{
					temp->lChild = node;
					return 1;
				}
				else
					temp = temp->lChild;
			}
			else {
				if (temp->rChild == NULL)
				{
					temp->rChild = node;
					return 1;
				}
				else
					temp = temp->rChild;
			}
		}
	}
}

// �������ɶ��������������һ�β��������е�ֵ
BiTree CreateBST(ElementType* array, int n)
{
	int i;
	BiTree tree;
	tree.root = NULL;
	for (i = 0; i < n; i++) {
		InsertNode(&tree, array[i]);
	}
	return tree;
}