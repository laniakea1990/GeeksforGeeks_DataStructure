#include<stdlib.h>
#include<stdio.h>

struct QNode
{
	int data;
	struct QNode* next;
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
	queue->rear->next = temp;
	queue->rear = temp;

}

struct QNode* Dequeue(struct Queue* queue)
{
	if (queue->front == NULL)
		return NULL;
	struct QNode* temp = queue->front;
	queue->front = temp->next;

	if (queue->front == NULL)
		queue->rear = NULL;
	return temp;
}

int main()
{
	struct Queue* queue = createQueue();

	Enqueue(queue, 10);
	Enqueue(queue, 20);
	Dequeue(queue);
	Dequeue(queue);
	Enqueue(queue, 20);
	Enqueue(queue, 30);
	Enqueue(queue, 40);
	Enqueue(queue, 50);

	struct QNode* head = Dequeue(queue);
	if (head != NULL)
		printf("The dequeued item is %d.\n", head->data);
	getchar();
	return 0;
}