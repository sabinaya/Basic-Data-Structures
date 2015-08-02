#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void push(struct node** head_ref, int new_data){
	struct node* new_node = (struct node* )malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct node *head){
	struct node* temp = head;
	while( temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void reverse(struct node** head){
	struct node* prev = NULL;
	struct node* next;
	struct node* current = *head;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int listLength(struct node* head){
	int count = 0;
	while(head != NULL){
		++count;
		head = head->next;
	}
	return count;
}

struct node* nthLast(struct node* head, int length){
	int nth = (listLength(head) - length)+1;
	printf("length : %d", nth);
	for(int i = 1; i < nth; i++){
		head = head->next;
	}
	return head;
}

struct node* reversingPairs(struct node* root){
	struct node* temp;
	if(root == NULL || root->next == NULL)
		return NULL;
	else{
		temp = root->next;
		root->next = temp->next;
		temp->next = root;
		root = temp;
		root->next->next = reversingPairs(root->next->next);
		return root;
	}
}

int main(){
	struct node* head = NULL;
	push(&head, 20);
	push(&head, 50);
	push(&head, 10);
	push(&head, 9);

	printList(head);
	//reverse(&head);
	//printf("After reversing\n");
	//printList(head);

	struct node* nthnode;
	nthnode = nthLast(head, 3);
	printf("\nThe last 3rd node from the last of the list is: %d", nthnode->data);

	printf("\nReversing a linked list in pairs: ");
	head = reversingPairs(head);
	printList(head);
	return 0;
}