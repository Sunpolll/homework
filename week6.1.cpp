#include <stdio.h>
float det(float a[]){
	float sum;
	for(int num=0;num<=2;num+=2){
		for(int i=num;i<=num+6;i+=3){
			if(num==0){sum+=a[i]*a[(i+4)%9]*a[(i+8)%9];
			}
			if(num==2){sum-=a[i]*a[(i+2)%9]*a[(i+4)%9];}
		}	
	}
	return sum;
}
float scan(float a[]){
	for(int i=0;i<3;i++){
		for(int j=0;j<=6;j+=3){
			scanf("%f",&a[i+j]);
		}
	}
	return a[9];
}
void inverse(float a[],float det){
	if(det==0){
		printf("This Matrix Can't Find Inverse\n");
		return;
	}
	float inv[9],cof[4];
	int co;
	for(int i=0;i<9;i++){ 
		co=0;                               
		for(int j=0;j<9;j++){ 
		if(i/3!=j/3 && i%3!=j%3){
			cof[co]=a[j];
			co++;	
			}
		}
		inv[i]=(cof[0]*cof[3])-(cof[1]*cof[2]);
		if(i%2==1){
			inv[i]*=-1;
		}
	}
	for(int i=0;i<9;i++){
		inv[i]/=det;
	}
	for(int i=0;i<9;i+=3){
		printf("%.3f %.3f %.3f\n",inv[i],inv[i+1],inv[i+2]);
	}
}
void sum(float a[],float b[],int n){
	float sum[9];
	for(int i=0;i<9;i++){
		if(n==0){
			sum[i]=a[i]+b[i];
		}
		if(n==1){
			sum[i]=a[i]-b[i];
		}
	}
	for(int i=0;i<3;i++){
		printf("%.3f %.3f %.3f\n",sum[i],sum[i+3],sum[i+6]);
	}
}
void print(float a[]){
	for(int i=0;i<3;i++){
		printf("%.3f %.3f %.3f\n",a[i],a[i+3],a[i+6]);
	}
}
void multiple(float a[],float b[]){
	float sum;
	for(int i=0;i<3;i++){ 
		for(int j=0;j<=6;j+=3){
			sum=a[i]*b[j]+a[i+3]*b[j+1]+a[i+6]*b[j+2];
			printf("%.3f ",sum);
			if(j==6){
				printf("\n");
			}
		}
	}
}
int main(){
	float matA[9],matB[9];
	scan(matA);
	scan(matB);
	printf("\n\nThis is \"DET A\"\n\n");
	printf("%.3f\n______________________________\n\n",det(matA));
	printf("This is \"DET B\"\n\n");
	printf("%.3f\n______________________________\n\n",det(matB));
	printf("This is \"INVERSE A\"\n\n");
	inverse(matA,det(matA));
	printf("______________________________\n\n");
	printf("This is \"INVERSE B\"\n\n");
	inverse(matB,det(matB));
	printf("______________________________\n\n");
	printf("This is \"A + B\"\n\n");
	sum(matA,matB,0);
	printf("______________________________\n\n");
	printf("This is \"A - B\"\n\n");
	sum(matA,matB,1);
	printf("______________________________\n\n");
	printf("This is \"A * B\"\n\n");
	multiple(matA,matB);
	printf("______________________________\n\n");
}
