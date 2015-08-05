#include <stdio.h>

void shuffleArray(int [], int , int );
void printarr(int []);

int main(){
	int arr[10] = {1,3,5,7,9,2,4,6,8,10};
	int left = 0;
	int right = 9;
	shuffleArray(arr,left,right);
	return 0;
}

void shuffleArray(int arr[], int l, int r){
	int c = l+(r-l)/2;
	int q = 1+l+(c-l)/2;
	if(l == r){
		return;
	}
	for(int k=1,i=q; i<=c; k++,i++){
		int temp = arr[i];
		arr[i] = arr[c+k];
		arr[c+k] = temp;
	}
	shuffleArray(arr,l,c);
	shuffleArray(arr,c+1,r);
}

void printarr(int arr[]){
	printf("\nArray:\n");
	for(int i=0; i<10; i++){
		printf("\n%d", arr[i]);
	}
}