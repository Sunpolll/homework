#include <stdio.h>
#include <math.h>
int main(){
	int set[3],count;
	for(int i=0;i<3;i++){
		scanf("%d",&set[i]);
	}
	for(int i=0;i<3;i++){
		if(set[i]+set[(i+1)%3]>set[(i+2)%3]){
			count+=1;
		}
	}
	if(count==3){
		int s,space;
		s=(set[0]+set[1]+set[2])/2;
		space=pow((s*(s-set[0])+s*(s-set[1])+s*(s-set[2])),0.5);
		printf("%d",space);
		
	}
	else{
		printf("0");
	}
}
