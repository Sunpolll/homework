#include <stdio.h>
int main(){
	int a[100],result[100],count=0;
	for(int i=0;i<100;i++){
		scanf("%d,",&a[i]);
	}
	printf("Result: ");
	for(int i=0;i<100;i++){
		if(i==0){
			if(a[0]<a[1]){result[count]=i;count++;}
		}
		if(i==99){
			if(a[99]<a[98]){result[count]=i;count++;}
		}
		else{
			if(a[i]<a[i-1] && a[i]<a[i+1]){result[count]=i;count++;}
		}
	}
	for(int i=0;i<count-1;i++){
		printf("%d,",result[i]+1);
	}
	printf("%d",result[count-1]+1);
}
