#include <stdio.h>
#include <math.h>
int main(){
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		if(i==1 || i==a){
			for(int j=0;j<a;j++){
				printf("*");
			}
		}
		else{
			for(int j=1;j<=a;j++){
				if(j==1 || j==a){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
