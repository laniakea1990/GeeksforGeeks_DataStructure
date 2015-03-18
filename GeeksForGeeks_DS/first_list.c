#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<assert.h>
struct node
{
	int data;
	struct node * Next;
};
//��ӡ����
void print_list(struct node* list)
{
	while (list != NULL)
	{
		printf("%d\n", list->data);
		list = list->Next;
	}
}

//��ͷ�ڵ�ǰ����
void push(struct node **head_ref, int newdata)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = newdata;
	new_node->Next = (*head_ref);
	*head_ref = new_node;
}

//��ָ���ڵ�����
void insertAfter(struct node *prev_node, int newdata)
{
	if (prev_node == NULL)			
	{
		printf("the given previous node cannot be NULL");	
	}
	struct node *new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = newdata;
	new_node->Next = prev_node->Next;
	prev_node->Next = new_node;
}
//�����һ���ڵ����
void append(struct node **head_ref, int new_data)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *last = *head_ref;

	new_node->data = new_data;
	new_node->Next = NULL;

	if (*head_ref == NULL)	//the Linked list is empty
	{
		*head_ref = new_node;
		return;
	}
	while (last->Next != NULL)
	{
		last = last->Next;
	}
	last->Next = new_node;
	return;
}

//ɾ��dataΪkey��ָ���ڵ�
void deleteNode(struct node **head_ref, int key)
{
	struct node* temp = *head_ref;
	struct node* prev = NULL;

	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->Next;
		free(temp);
		return;
	}
	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->Next;
	}
	if (temp == NULL)
		return;
	prev->Next = temp->Next;
	
	free(temp);
}

//��ȡ�����еĵ�n��Ԫ�ؽڵ�ֵ
int getNth(struct node* head, int index)
{
	struct node *current = head;
	int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return current->data;
		count++;
		current = current->Next;
	}
	assert(0);
}
int main()
{
	struct node *head = NULL;
	
	append(&head, 6);   //6->NULL
	push(&head, 1);		//1->6->NULL
	push(&head, 5);		//5->1->6->NULL
	insertAfter(head->Next, 10);	//5->1->10->6->NULL
	append(&head, 88);		//5->1->10->6->88->NULL

	printf("\n Created linked list is: ");
	print_list(head);
	Sleep(3000);
	deleteNode(&head,6);
	print_list(head);

	deleteNode(&head, 1);
	print_list(head);

	int nkey = getNth(head, 2);
	printf("the key find is: %d\n", nkey);

	getNth(head, 8);

	getchar();
	return 0; 
	
}
/*struct node *second = NULL;
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

Sleep(3000);
push(&head, 8);
print_list(head);

Sleep(3000);
insertAfter(head->Next, 66);
print_list(head);
*/
