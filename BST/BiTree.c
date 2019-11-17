#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

// 递归查找二叉树，如果elem大于根节点就递归查找右子树，如果小于就递归查找左子树，等于就返回根节点
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


// 二叉查找树中插入一个结点
// 思路是插入到叶子位置，而且如果大于根节点就在右叶子，小于就在左叶子
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

// 数组生成二叉查找树，就是一次插入数组中的值
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