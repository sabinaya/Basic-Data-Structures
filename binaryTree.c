#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct queueNode{
	struct node* element;
	struct queueNode* next;
};

struct queue{
	struct queueNode* front;
	struct queueNode* rear;
};

struct queue* createQueue(){
	struct queue* Q = (struct queue* )malloc(sizeof(struct queue ));
	if(!Q)
		return NULL;
	Q->front = Q->rear = NULL;
	return Q;
}

int isEmptyQueue(struct queue* Q){
	return (Q->front == NULL);
}

void enQueue(struct queue* Q, struct node* dataNode){
	struct queueNode* newNode = (struct queueNode *)malloc(sizeof(struct queueNode ));
	newNode->element = dataNode;
	if(Q->rear)
		Q->rear->next = newNode;
	Q->rear = newNode;
	if(Q->front == NULL)
		Q->front = Q->rear;
}

struct node* deQueue(struct queue* Q){
	struct queueNode* temp;
	if(isEmptyQueue(Q)){
		printf("\nThe queue is empty!");
		return NULL;
	}
	else{
		temp = Q->front;
		Q->front = Q->front->next;
		return temp->element;
	}
}

struct node* newNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* deepestNode(struct node* root){
	if(!root)
		return NULL;
	struct node* temp;
	struct queue* Q = createQueue();
	enQueue(Q, root);
	while(!isEmptyQueue(Q)){
		temp = deQueue(Q);
		if(temp->left)
			enQueue(Q, temp->left);
		if(temp->right)
			enQueue(Q, temp->right);
	}
	return temp;
}

// non recursive function to find the height
int treeHeight(struct node* root){
	printf("\nHere is the dequed data %d", root->data);
	int level = 0;
	if(!root)
		return 0;
	struct node* temp;
	struct queue* Q = createQueue();
	enQueue(Q, root);
	enQueue(Q, NULL);
	while(!isEmptyQueue(Q)){
		root = deQueue(Q);
		if(root == NULL){
			if(!isEmptyQueue(Q))
				enQueue(Q, NULL);
			++level;
		}
		else{
			if(root->left)
				enQueue(Q, root->left);
			if(root->right)
				enQueue(Q, root->right);
		}
	}
	return level;
}

//recursive function to find the height
int recursiveTreeHeight(struct node* root){
	int left, right;
	if(!root)
		return 0;
	left = recursiveTreeHeight(root->left);
	right = recursiveTreeHeight(root->right);
	if(left > right)
		return left+1;
	else
		return right+1;
}

int leavesCount(struct node* root){
	if(!root)
		return 0;
	int count = 0;
	struct node* temp;
	struct queue* Q = createQueue();
	enQueue(Q, root);
	while(!isEmptyQueue(Q)){
		temp = deQueue(Q);
		if(!temp->left && !temp->right)  // Full nodes -  if(temp->left && temp->right) , Half-nodes - if((temp->left && !temp->right) || if(!temp->left && temp->right))
			count++;
		if(temp->left)
			enQueue(Q, temp->left);
		if(temp->right)
			enQueue(Q, temp->right);
	}
	return count;
}

int findWidth(struct node* root, int *ptr){
	int left, right;
	if(!root)
		return 0;
	left = findWidth(root->left, ptr);
	right = findWidth(root->right, ptr);
	if(left+right > *ptr)
		*ptr = left+right;
	return((left > right)? left+1 : right+1);
}

int structEqual(struct node* root1, struct node* root2){
	if(!root1 && !root2)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	return(root1->data == root2->data && structEqual(root1->left, root2->left) && structEqual(root1->right, root2->right));
}

int maxSumLevel(struct node* root){
	int level = 0, maxLevel = 0, maxSum = 0, currentSum = 0;
	if(!root)
		return 0;
	struct node* temp;
	struct queue* Q = createQueue();
	enQueue(Q, root);
	enQueue(Q, NULL);
	while(!isEmptyQueue(Q)){
		root = deQueue(Q);
		if(root == NULL){
			if(currentSum > maxSum)
			{
				maxSum = currentSum;
				maxLevel = level;
			}
			currentSum = 0;
			if(!isEmptyQueue(Q))
				enQueue(Q, NULL);
			++level;
		}
		else{
			currentSum += root->data;
			if(root->left)
				enQueue(Q, root->left);
			if(root->right)
				enQueue(Q, root->right);
		}
	}
	return maxLevel;
}

void printArray(int array[], int arrayLength){
	for(int i = 0; i < arrayLength; i++){
		printf("%d",array[i]);
	}
	printf("\n\n");
}

void printPaths(struct node* root, int path[], int pathLength){
	if(root == NULL)
		return;
	path[pathLength] = root->data;
	pathLength++;
	if(root->left == NULL && root->right == NULL)
		printArray(path, pathLength);
	else{
		printPaths(root->left, path, pathLength);
		printPaths(root->right, path, pathLength);
	}

}

// Function to check if path with the given sum exists
int hasPathSum(struct node* root, int sum){
	if(root == NULL)
		return(sum == 0);
	else{
		int remainingSum = sum-root->data;
		if((root->left && root->right) || (!root->left && !root->right))
			return(hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum));
		else if(root->left != NULL)
			return(hasPathSum(root->left, remainingSum));
		else
			return(hasPathSum(root->right, remainingSum));
	}
}

int add(struct node* root){
	if(!root)
		return 0;
	return(root->data + add(root->left) + add(root->right));
}

struct node* mirror(struct node* root){
	struct node* temp;
	if(root){
		mirror(root->left);
		mirror(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

int areMirror(struct node* root1, struct node* root2){
	if(root1 == NULL && root2 ==NULL)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	if(root1->data != root2->data)
		return 0;
	else 
		return(areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left));
}

int main(){
	int ptr = 0;
	int paths[30];
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	//root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->right = newNode(7);
	root->right->right->right = newNode(10);
	// root->right->left->right->left = newNode(9);
	//root->right->right->right->right = newNode(10);


	struct node* root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	//root->left->left = newNode(4);
	root1->right->left = newNode(5);
	root1->right->right = newNode(6);
	root1->right->left->right = newNode(7);
	root1->right->right->right = newNode(10);
	// root->right->left->right->left = newNode(9);
	//root->right->right->right->right = newNode(10);

	struct node* deepest = deepestNode(root);
	printf("\nDeepest node: %d", deepest->data);
	printf("\nHeight of the tree using non-recursive function: %d", treeHeight(root));
	printf("\nHeight of the tree using recursive function: %d", recursiveTreeHeight(root));
	printf("\nNumber of leaves in the tree: %d", leavesCount(root));
	printf("\nThe width of the tree is : %d", findWidth(root, &ptr));
	printf("\nAre the two trees structurally identical? %d", structEqual(root, root1));
	printf("\nThe level which has the max sum is: %d",maxSumLevel(root));
	printf("\n\nPrinting all the paths of the tree :");
	printPaths(root, paths, 0);
	printf("\nChecking if a path with the given sum exists?: %d", hasPathSum(root, 18));
	printf("\nThe sum of all the elements of the tree: %d", add(root));
	struct node* mirrorTree = mirror(root);
	printf("\n\nPrinting all the paths of the tree :");
	printPaths(mirrorTree, paths, 0);
	printf("\nAre the trees mirrors of each other? %d", areMirror(root, mirrorTree));
	return 0;
}