#include<stdlib.h>
#include<stdio.h>
#include<limits>

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* creatQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->size = 0;
	queue->capacity = capacity;
	queue->rear = capacity - 1;
	queue->array = (int *)malloc(queue->capacity * sizeof(int));

	return queue;
}

int IsFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

int IsEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

int Enqueue(struct Queue* queue, int item)
{
	if (IsFull(queue))
		return -1;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	
	printf("%d enqueued to queue.\n", item);
}

int Dequeue(struct Queue* queue)
{
	if (IsEmpty(queue))
		return -1;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	printf("%d dequeued from the queue.\n", item);
	return item;
}

int front(struct Queue* queue)
{
	if (IsEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
	if (IsEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main()
{
	struct Queue* queue = creatQueue(5);

	/*Enqueue(queue, 1); 
	Enqueue(queue, 2);
	Enqueue(queue, 3);
	Enqueue(queue, 4);
	Enqueue(queue, 5);
	Enqueue(queue, 6);
	*/
	Dequeue(queue);

	printf("The Front of the queue is %d.\n", front(queue));
	printf("The Rear of the queue is %d.\n", rear(queue));

	getchar();
	return 0;
}