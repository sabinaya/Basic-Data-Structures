#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct stackNode{
	struct node* element;
	struct stackNode* next;
};

struct stack{
	struct stackNode* top;
};

struct stack* createStack(){
	struct stack* S = (struct stack* )malloc(sizeof(struct stack));
	if(!S)
		return NULL;
	S->top = NULL;
	return S;
}

int isStackEmpty(struct stack* S){
	return S->top == NULL;
}

void push(struct stack* S, struct node* node){
	struct stackNode* newNode = (struct stackNode* )malloc(sizeof(struct stackNode));
	newNode->element = node;
	newNode->next = NULL;
	if(S->top)
	{
		newNode->next = S->top;
		S->top = newNode;
	}
	else{
		S->top = newNode;
	}
}

struct node* pop(struct stack* S){
	struct stackNode* temp;
	if(!isStackEmpty(S)){
		temp = S->top;
		S->top = S->top->next;
		return(temp->element);
	}
	else{
		printf("\nUnderflow");
		return NULL;
	}
}

struct node* newNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printStack(struct stackNode* top){
	if(top == NULL)
		return;
	printStack(top->next);
	printf("\n%d",top->element->data);
}

void zigzag(struct node* root){
	int leftToright = 1;
	struct stack* currentLevel = createStack();
	struct stack* nextLevel = createStack();
	push(currentLevel, root);
	struct node* temp;
	while(!isStackEmpty(currentLevel)){
		temp = pop(currentLevel);
		if(temp){
			printf("\n%d",temp->data);
			if(leftToright == 1){
				push(nextLevel, temp->left);
				push(nextLevel, temp->right);
			}
			else{
				push(nextLevel, temp->right);
				push(nextLevel, temp->left);
			}
		}
		if(isStackEmpty(currentLevel)){
			struct stack* tempStack;
			leftToright = 1-leftToright;
			tempStack = currentLevel;
			currentLevel = nextLevel;
			nextLevel = tempStack;
		}
	}
}

int Search(int inorder[], int start, int end, int element){
	int mid;
	if(start > end)
		return -1;
	else{
		while(start <= end){
			mid = (start + end)/2;
			if(inorder[mid] < element){
				start = mid + 1;
			}
			else if(inorder[mid] == element){
				return mid;
			}
			else{
				end = mid - 1;
			}
		}
		return -1;
	}
}

struct node* buildPreIn(int inorder[], int preorder[], int inorderStart, int inorderEnd){
	static int preorderIndex = 0;
	struct node* new_node = newNode(preorder[preorderIndex]);
	if(!new_node)
		return NULL;
	if(inorderStart > inorderEnd)
		return NULL;
	preorderIndex++;
	int inorderIndex = Search(inorder, inorderStart, inorderEnd, new_node->data);
	if(inorderStart == inorderEnd)
		return new_node;
	new_node->left = buildPreIn(inorder, preorder, inorderStart, inorderIndex-1);
	new_node->right = buildPreIn(inorder, preorder, inorderIndex+1, inorderEnd);
	return new_node;
}

void inOrder(struct node* root){
	if(root){
		inOrder(root->left);
		printf("\n%d", root->data);
		inOrder(root->right);
	}
}

int main(){
	struct node* root = newNode(7);
	root->left = newNode(1);
	root->right = newNode(9);
	root->left->left = newNode(0);
	root->left->right = newNode(3);
	root->right->left = newNode(8);
	root->right->right = newNode(10);
	root->left->right->left = newNode(2);
	root->left->right->right = newNode(5);
	root->left->right->right->left = newNode(4);
	root->left->right->right->right = newNode(6);
	//root->right->right->right = newNode(10);
	// root->right->left->right->left = newNode(9);
	//root->right->right->right->right = newNode(10);
	// struct stack* S = createStack();
	// push(S, newNode(10));
	// push(S, newNode(20));
	// push(S, newNode(30));
	// printStack(S->top);
	// pop(S);
	// printf("\nElements after stack!:");
	// printStack(S->top);

	int inorder[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int preorder[11] = {7,1,0,3,2,5,4,6,9,8,10};
	//printf("\nThe zigzag of the tree is: ");
	//zigzag(root);
	struct node* newTree = buildPreIn(inorder, preorder, 0, 10);
	printf("\nInorder Traversal:\n");
	inOrder(newTree);
	return 0;
}

