#include <stdio.h>

// Implementation of counting sort
int main(){
	int arr[15] = {1,0,0,2,1,1,2,0,2,1,0,1,1,2,0}; // 0's - 5, 1's - 6, 2's - 4
	int length = 15, k = 3;
	int b[15];
	int c[k];

	printf("\nThe unsorted array is: \n");
	for(int i=0; i<length; i++)	
		printf("\n%d", arr[i]);

	// Initializing the count array
	for(int i=0; i<k; i++){
		c[i] = 0;
	}

	// counting the number of each element
	for(int i=0; i<length; i++){
		c[arr[i]] = c[arr[i]]+1;
	}

	// below loop - now each element in the array has the count of the elements less that element
	for(int i=1; i<k; i++)
		c[i] += c[i-1];

	// storing the result
	for(int i = length-1; i>=0; i--){
		b[c[arr[i]]] = arr[i];
		c[arr[i]] = c[arr[i]]-1;
	}

	printf("\nThe sorted array is: \n");
	for(int i=1; i<=length; i++)	
		printf("\n%d", b[i]);
	return 0;
}
