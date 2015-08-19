#include <stdio.h>

int main(){

	int arr[7] = {1,2,2,1,1,1,1};
	int n = 7, x=0;

	for(int i=0; i<n; i++){
		x ^= arr[i];
	}

	printf("\nThe element occuring odd number of times is: %d", x);

	return 1;
}