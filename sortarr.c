#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b){
	return(*(int* )a - *(int *)b);
}

int main(){
	int arr[10] = {2,4,5,1,9,3,10,4,8,15};
	int temp1[100], temp2[100];
	int j1=0, j2=0;
	for(int i=0; i<10; i++){
		if(arr[i]%2 != 0)
			temp1[j1++] = arr[i];
		else
			temp2[j2++] = arr[i];
	}
	for(int i=0; temp1[i]!='\0'; i++)
		printf("\n%d", temp1[i]);
	printf("\n----");
	for(int i=0; temp2[i]!='\0'; i++)
		printf("\n%d", temp2[i]);

	qsort(temp1,j1-1,sizeof(int),cmp);
	printf("\nSorted..... odd ");
	for(int i=0; temp1[i]!='\0'; i++)
		printf("\n%d", temp1[i]);

	qsort(temp2,j2-1,sizeof(int),cmp);
	printf("\nSorted..... even ");
	for(int i=0; temp2[i]!='\0'; i++)
		printf("\n%d", temp2[i]);
	
	
	return 0;
}