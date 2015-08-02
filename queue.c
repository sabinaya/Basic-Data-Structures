#include<stdio.h>
#include<stdlib.h>

struct queue{
	int front, rear;
	int capasity;
	int *array;
};

struct queue* createQueue(int size){
	struct queue* Q = (struct queue* )malloc(sizeof(struct queue));
	if(!Q)
		return NULL;
	Q->capasity = size;
	Q->front = Q->rear = -1;
	Q->array = (int *)malloc(sizeof(int)*Q->capasity);
	if(!Q->array)
		return NULL;
	return Q;
}

void enQueue(struct queue* Q, int data){
	if(isFullQueue(Q))
		printf("\nQueue Full!");
	else{
		Q->rear = (Q->rear+1)%q->capasity;
		q->array[Q->rear] = data;
		if(Q->front == -1)
			Q->front = Q->rear;
	}
}

int deQueue(struct queue* Q){
	int data = 0;
	if(isEmptyQueue(Q))
	{
		printf("\nQueue Empty!");
		return 0;
	}
	else{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
			Q->front = Q->rear = -1;
		else 
			Q->front = (Q->front+1)%Q->capasity;
	}
	return data;
}

int isEmptyQueue(struct queue* Q){
	return(Q->front == -1);
}

int isFullQueue(struct queue* Q){
	return((Q->rear+1)%Q->capasity == Q->front);
}

int QueueSize(struct queue* Q){
	return(Q->capasity - Q->front + Q->rear +1) % Q->capasity;
}

void deleteQueue(struct queue* Q){
	if(Q){
		if(Q->array)
			free(Q->array);
		free(Q);
	}
}