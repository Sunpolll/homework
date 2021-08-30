#include <stdio.h> //4.1
int main(){
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		if(i==a){
			for(int j=0;j<2*a-1;j++){
				printf("*");
			}
		}
		else{
			for(int j=0;j<a-i;j++){
				printf(" ");
			}
			for(int j=0;j<2*i-1;j++){
				printf("*");
			}
		}
		printf("\n");
	}
}
