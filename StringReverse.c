#include<stdio.h>

int main(){
	char a[7] = {"Program"};
	int length=sizeof(a)/sizeof(char);	
	int last=length-1;
	int temp;
	for(int i=0;i<length/2;i++)
	{
		temp = a[i];
		a[i] = a[last];
		a[last] = temp;
		last--;
	}

	for(int i=0;i<length;i++)
		printf("%c",a[i]);
    return 0;
}
