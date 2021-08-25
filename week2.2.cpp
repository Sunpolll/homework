#include <stdio.h>
#include <math.h>
int main(){
	int a,sum=1,i;
	scanf("%d",&a);
	while(sum!=0){
		i=100;
		sum=1;
		for(int j=0;j<6;j++){
			if(j==1 || j==3){
				printf(".");
			}
			else if(j==5){
				printf("=");
			}
			else{
				sum*=a%(i*10)/i;
				printf("%d",a%(i*10)/i);
				i/=10;
			}
		}
		a=sum;
		printf("%d\n",sum);
	}
	
}
