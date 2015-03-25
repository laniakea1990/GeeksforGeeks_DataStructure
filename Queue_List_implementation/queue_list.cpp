#include<stdlib.h>
#include<stdio.h>

struct QNode
{
	int data;
	struct Node* next;
};

struct Queue
{
	struct QNode *front, *rear;
};

struct QNode* newNode(int item)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	if (!temp)
		return NULL;

	temp->data = item;
	temp->next = NULL;
	
	return temp;
}

struct Queue* createQueue()
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	
	return queue;
}
void Enqueue(struct Queue* queue, int item)
{
	struct QNode* temp = newNode(item);
	if (queue->rear == NULL)
		queue->front = queue->rear = temp;



}