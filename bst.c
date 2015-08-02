#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* root, int data){
	if(root == NULL){
		root = (struct node* )malloc(sizeof(struct node));
		if(!root){
			printf("\nMemory error!");
			return NULL;
		}
		else{
			root->data = data;
			root->left = root->right = NULL;
		}
	}
	else{
		if(root->data < data)
			root->right = insert(root->right, data);
		else if(root->data >= data)
			root->left = insert(root->left, data);
	}
	return root;
}

void inOrder(struct node* root){
	if(root){
		inOrder(root->left);
		printf("\n%d", root->data);
		inOrder(root->right);
	}
	else
		return;
}

struct node* find(struct node* root, int data){
	if(!root)
		return NULL;
	if(root->data > data)
		return(find(root->left, data));
	else if(root->data < data)
		return(find(root->right, data));
	return root;
}

struct node* findMin(struct node* root){
	if(!root)
		return NULL;
	else if(root->left == NULL)
		return root;
	else
		return findMin(root->left);
}

// check if the given binary tree is a bst
int isBst(struct node* root){
	if (root == NULL)
		return 1;
	if(root->left != NULL && root->left->data > root->data)
		return 0;
	if(root->right != NULL && root->right->data < root->data)
		return 0;
	if(!isBst(root->left) || !isBst(root->right))
		return 0;
	return 1;
}

struct node* kthsmallest(struct node* root, int k){
	static int count = 0;
	if(!root)
		return NULL;
	struct node* left = kthsmallest(root->left, k);
	if(left)
		return left;
	if(++count == k)
		return root;
	return kthsmallest(root->right, k);
}

void printBetK1K2(struct node* root, int k1, int k2){
	if(!root)
		return;
	if(root->data >= k1)
		printBetK1K2(root->left, k1, k2);
	if(root->data >= k1 && root->data <= k2)
		printf("\n%d", root->data);
	if(root->data <= k2)
		printBetK1K2(root->right, k1, k2);
}

int main(){
	struct node* root = NULL;
	root = insert(root, 55);
	root = insert(root, 9);
	root = insert(root, 8);
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 35);
	root = insert(root, 56);
	root = insert(root, 3);
	root = insert(root, 90);
	root = insert(root, 7);
	root = insert(root, 45);

	// struct node* root = newNode(7);
	// root->left = newNode(1);
	// root->right = newNode(9);
	// root->left->left = newNode(0);
	// root->left->right = newNode(13);
	// root->right->left = newNode(8);
	// root->right->right = newNode(10);
	// root->left->right->left = newNode(2);
	// root->left->right->right = newNode(5);
	// root->left->right->right->left = newNode(4);
	// root->left->right->right->right = newNode(6);


	printf("\nThe inOrder traversal of the tree:\n");
	inOrder(root);
	printf("\nFinding the node 8: %d", find(root, 8)->data);
	printf("\nThe minimum element in the tree is: %d", findMin(root)->data);
	printf("\nchecking if the tree is a bst: %d", isBst(root));
	printf("\nKth smallest number in the tree: %d", kthsmallest(root, 2)->data);
	printf("\nPrinting the elements between 3 and 45 in the tree :\n");
	printBetK1K2(root, 3, 45);
}
