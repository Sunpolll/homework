#include <stdio.h>
#include <math.h>
int main(){
	int a,sum=1,one,two,three;
	scanf("%d",&a);
	while(sum!=0){
		one=a/100;
		two=(a%100)/10;
		three=a%10;
		sum=one*two*three;
		printf("%d.%d.%d=%d\n",one,two,three,sum);
		a=sum;
	}
}
