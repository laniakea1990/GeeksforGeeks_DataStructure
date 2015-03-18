#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));
	/* put in the data  */
	new_node->data = new_data;
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
void printList(struct node *head)
{
	struct node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

void printMiddle(struct node* head)
{
	struct node* slowPtr = head;
	struct node* fastPtr = head;

	if (head != NULL)
	{
		while (fastPtr != NULL && fastPtr->next != NULL)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		}
		printf("The middle element is [%d]\n\n", slowPtr->data);
	}
}

int main()
{
	struct node* head = NULL;
	int i;
	for (i = 11; i > 0; i--)
	{
		push(&head, i);
		printList(head);
		printMiddle(head);
	}
	
	getchar();
	return 0;
}