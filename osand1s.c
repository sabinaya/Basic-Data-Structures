#include<stdio.h>

int main(){
	int arr[] = {1,0,0,1,1,1,0,1,1,0};
	int length = (sizeof(arr)/sizeof(int));
	printf("\nLength %d", length);
	int first = 0, last = length-1;
	int temp;
	while(first < last){
		while(arr[first] == 0)
			first++;
		while(arr[last] == 1)
			last--;
		if(first < last){
			temp = arr[first];
			arr[first] = arr[last];
			arr[last] = temp;
			first++;
			last--;
		}
	}

	for(int i=0; i<length; i++)
		printf("\n%d", arr[i]);
	return 0;
}