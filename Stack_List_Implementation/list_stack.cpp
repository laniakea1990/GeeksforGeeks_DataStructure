#include<stdlib.h>
#include<stdio.h>

struct StackNode
{
	int data;
	struct StackNode* next;
};

struct StackNode* newNode(int data)
{
	struct StackNode* newnode = (struct StackNode*)malloc(sizeof(struct StackNode));
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}

int IsEmpty(struct StackNode* root)
{
	return !root;
}

void push(struct StackNode** root, int data)
{
	struct StackNode* newnode = newNode(data);
	newnode->next = (*root);
	(*root) = newnode;

	printf("%d pushed stack.\n", data);
}

int pop(struct StackNode** root)
{
	if (IsEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = (*root);
	(*root) = (*root)->next;
	int pop_data = temp->data;
	free(temp);

	return pop_data;
}

int peek(struct StackNode* root)
{
	if (IsEmpty(root))
		return INT_MIN;
	return root->data;
}

int main()
{
	struct StackNode* root = NULL;

	push(&root, 30);
	push(&root, 20);
	push(&root, 9);
	push(&root, 8);
	
	printf("%d popped from stack.\n", pop(&root));
	printf("%d popped from stack.\n", pop(&root));
	printf("The top item of the stack is %d.\n", peek(root));

	getchar();
	return 0;
}