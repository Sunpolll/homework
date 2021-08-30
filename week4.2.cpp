#include <stdio.h> //4.2
int main(){
	int x;
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		for(int j=1;j<=2*x-1;j++){
			if(j>=x-i && j<=x+i){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
	}
}
