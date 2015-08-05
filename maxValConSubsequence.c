#include <stdio.h>

// Program to find the max value produced by the contiguous subsequence in the array
int maxsum(int [], int , int );
int max(int , int , int );

int main(){
	int arr[10] = {-2,11,-4,13,-5,2};
	printf("\nThe max sum is: %d", maxsum(arr,0,5));
	return 0;
}

int maxsum(int arr[], int left, int right){
	int maxLeftSum = 0, maxRightsum = 0, leftsum = 0, rightsum = 0;
	int mid = left + (right-left)/2;
	if(left == right)
		return arr[left];
	int leftBorderSum = maxsum(arr, left, mid);
	int rightBorderSum = maxsum(arr, mid+1, right);
	for(int i=mid; i>=left; i--){
		leftsum += arr[i];
		if(leftsum > maxLeftSum)
			maxLeftSum = leftsum;
	}
	for(int i=mid+1; i<=right; i++){
		rightsum += arr[i];
		if(rightsum > maxRightsum)
			maxRightsum = rightsum;
	}

	return(max(leftBorderSum, rightBorderSum, maxLeftSum+maxRightsum));
}

int max(int a, int b, int c){
	int result;
	if(a>b && a>c)
		return a;
	else if(b>a && b>c)
		return b;
	else
		return c;
}