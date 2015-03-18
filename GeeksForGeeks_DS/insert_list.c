#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * Next;
};

void print_list(struct node* list)
{
	while (list != NULL)
	{
		printf("%d\n", list->data);
		list = list->Next;
	}
}
int main()
{
	struct node *head = NULL;
	struct node *second = NULL;
	struct node *third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1;
	head->Next = second;

	second->data = 2;
	second->Next = third;

	third->data = 3;
	third->Next = NULL;

	print_list(head);
	getchar();
	return 0;
}