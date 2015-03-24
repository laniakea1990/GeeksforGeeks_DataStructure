#include<stdlib.h>
#include<stdio.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int IsFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int IsEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int key)
{
	if (IsFull(stack))
		return;
	stack->array[++stack->top] = key;
	printf("%d pushed into the stack.\n", key);
	printf("The top number is %d.\n", stack->top);
}

int pop(struct Stack* stack)
{
	if (IsEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
	if (IsEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

int main()
{
	struct Stack* stack = createStack(100);

	push(stack, 30);
	push(stack, 20);
	push(stack, 10);
	push(stack, 9);
	push(stack, 8);
	push(stack, 7);


	printf("%d popped from the stack.\n", pop(stack));
	printf("The top of the stack is %d.\n", peek(stack));
	getchar();
	return 0;
}