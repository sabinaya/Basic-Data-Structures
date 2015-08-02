#include<stdio.h>

int main(){
	char *a;
	scanf("%s", a);
	printf("\n%s", a);
	int length = sizeof(a)/sizeof(int);
	int flag = 0;
	for(int i=0; i<length; i++){
			if(a[i]-48 >= a[i+1]-48)
				flag = 1;
	}

	if(flag == 0)
		printf("TRUE");
	else
	{
		flag =0;
		for(int i=0; i<length; i++){
				if(a[i]-48 <= a[i+1]-48)
					flag = 1;
		}
		if(flag == 1)
			printf("flase");
		else
			printf("true");
	}
	return 0;
}