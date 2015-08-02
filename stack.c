#include<stdio.h>
#include<stdlib.h>

struct stack{
	int top;
	int capasity;
	int *array;
};

struct stack* createStack(int size){
	struct stack* S = (struct stack* )malloc(sizeof(struct stack));
	if(!S)
		return NULL;
	S->top = -1;
	S->capasity = size;
	S->array = (int *)malloc(S->capasity*(sizeof(int)));
	if(!S->array)
		return NULL;
	return S;
}

int isEmptyStack(struct stack* S){
	return(S->top == -1);
}

int isFullStack(struct stack* S){
	return(S->top == S->capasity-1);
}

void push(struct stack* S, int data){
	if(isFullStack(S))
		printf("\nOverflow!");
	else
		S->array[++S->top] = data;
}

int pop(struct stack* S){
	if(isEmptyStack(S))
		return 0;
	else
		return(S->array[S->top--]);
}

void deleteStack(struct stack* S){
	if(S){
		if(S->array)
			free(S->array);
		free(S);
	}
}