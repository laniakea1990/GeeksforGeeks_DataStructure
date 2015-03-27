#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node *left, *right;
	bool rightThread;
};

struct Node* leftMost(struct Node* node)
{
	if (node == NULL)
		return NULL;
	while (node->left != NULL)
		node = node->left;
	return node;
}

void InOrder(struct Node* root)
{
	if (root == NULL)
		return;
	struct Node* cur = leftMost(root);
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		if (cur->rightThread)
			cur = cur->right;
		else
			cur = leftMost(cur->right);
	}
}