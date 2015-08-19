#include <stdio.h>

int main(){
	int arr[7] = {1,2,4,6,3,7,8};
	int n = 7,x = 0, y = 0;

	for(int i = 0; i < n; i++)
		x ^= arr[i];
	for(int i = 1; i <= n; i++)
		y ^= i;

	printf("The missing number is: %d\n", x^y);

	return 1;
}