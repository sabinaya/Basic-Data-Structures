#include <stdio.h>

long long int exponenetial(long long int , long long int );

int main(){
	long long int k,n;
	printf("\nEnter the K value: ");
	scanf("%lld", &k);
	printf("\nEnter the N value: ");
	scanf("%lld", &n);
	long long int result = exponenetial(k,n);
	printf("\nThe result is: %lld", result);
	return 0;
}

long long int exponenetial(long long int k, long long int n){
	long long int a;
	if(n == 0)
		return 1;
	else{
		if(n%2 == 1){
			a = exponenetial(k,n-1);
			return (a*k);
		}
		else{
			a = exponenetial(k,n/2);
			return (a*a);
		}
	}
}