#pragma once

typedef int ElementType;

typedef struct BiTNode
{
	ElementType elem;
	struct BiTNode* lChild;
	struct BiTNode* rChild;
}BiTNode;


typedef struct
{
	BiTNode* root;
}BiTree;

BiTree CreateBST(ElementType* array, int n);
BiTNode* SearchBST(BiTNode* root, ElementType elem);
int InsertNode(BiTree* tree, ElementType elem);