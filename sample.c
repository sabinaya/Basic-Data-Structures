#include <stdio.h>
#include <stdlib.h>

int calc_sum(int num){
	int sum = 0, r;
	while(num != 0){
  	r = num%10;
  	sum += r;
  	num = num/10;
  }
  return sum;
}


int main() {
   	int num, sum = 0;
  	scanf("%d", &num);
  	sum = calc_sum(num);
  	while((sum/10) != 0){
  		sum = calc_sum(sum);
  	}
  	printf("\nSum : %d\n", sum);
  	return 0;
}