#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct node
{
	int data;
	struct node* next;
};

void push(struct node** head_ref, int new_data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = new_data;
	newnode->next = (*head_ref);
	*head_ref = newnode;
}

void deleteNode(struct node* ptr)
{
	struct node* temp = ptr->next;
	 
	ptr->data = temp->data;
	ptr->next = temp->next;
	free(temp);
}

void printList(struct node* list)
{
	struct node* temp = list;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct node* head = NULL;

	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printf("\nBefore delete the node\n");
	printList(head);
	Sleep(2000);

	struct node* tmp = head;

	deleteNode(tmp);
	printf("\nAfter deleted!\n");
	printList(head);

	getchar();

}