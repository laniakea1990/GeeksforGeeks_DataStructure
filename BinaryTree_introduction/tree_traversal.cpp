#include<stdlib.h>
#include<stdio.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data)
{
	struct node* bNode = (struct node*)malloc(sizeof(struct node));
	if (!bNode)
		return NULL;

	bNode->data = data;
	bNode->left = NULL;
	bNode->right = NULL;
	
	return bNode;
}

void printPostOrder(struct node* root)
{
	if (root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);	
	printf("%d ", root->data);
}

void printInOrder(struct node* root)
{
	if (root == NULL)
		return;
	printInOrder(root->left);
	printf("%d ", root->data);
	printInOrder(root->right);
}

void printPreOrder(struct node* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	printPreOrder(root->left);
	printPreOrder(root->right);
}
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);	
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\n PreOrder traversal of the binary tree is \n");
	printPreOrder(root);
	printf("\n InOrder traversal of the binary tree is \n");
	printInOrder(root);
	printf("\n PostOrder traversal of the binary tree is \n");
	printPostOrder(root);

	getchar();
	return 0;
}