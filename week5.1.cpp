#include <stdio.h>
int main(){
	int arr[102];
	for(int i=0;i<100;i++){
		scanf("%d,",&arr[i]);
	}
	arr[101],arr[102]=arr[99]+1,arr[0]+1;
	printf("Result: ");
	for(int i=0;i<100;i++){
		if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
			printf("%d ",i+1);
		}
	}
}
