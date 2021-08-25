#include <stdio.h>
#include <math.h>
int main(){
	int set[3],count;
	for(int i=0;i<3;i++){
		scanf("%d",&set[i]);
	}
	if(set[0]+set[1]>set[2] && set[1]+set[2]>set[0] && set[2]+set[0]>set[1]){
		int s,space;
		s=(set[0]+set[1]+set[2])/2;
		space=pow((s*(s-set[0])+s*(s-set[1])+s*(s-set[2])),0.5);
		printf("%d",space);
		
	}
	else{
		printf("0");
	}
}
