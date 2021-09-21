#include <stdio.h>
void print(float a[]){
	for(int i=0;i<9;i+=3){
		printf("%.3f %.3f %.3f\n",a[i],a[i+1],a[i+2]);
	}
}
float scan(float a[]){
	for(int i=0;i<9;i++){
		scanf("%f",&a[i]);
	}
	return a[9];
}
float det(float a[]){
	float sum;
	for(int i=0;i<=6;i+=3){
		sum+=(a[i]*a[(i+4)%9]*a[(i+8)%9]-a[i]*a[(i+7)%9]*a[(i+14)%9]);
	}
	return sum;
}
void inv(float a[],float det){
	if(det==0){
		printf("This Matrix Can't Find Inverse\n");
		return;
	}
	float inv[9],cf[4];int co;
	for(int i=0;i<9;i++){
		co=0;
		for(int j=0;j<9;j++){
			if(j%3!=i%3 && j/3!=i/3){
				cf[co]=a[j];
				co++;
			}
		}
		inv[i]=(cf[0]*cf[3])-(cf[1]*cf[2]);
		inv[i]/=det;
		if(i%2==1){inv[i]*=-1;}
	}
	for(int i=0;i<3;i++){
		printf("%.3f %.3f %.3f\n",inv[i],inv[i+3],inv[i+6]);
	}
}
void sum(float a[],float b[],char x){
	float sum[9];
	for(int i=0;i<9;i++){
		switch(x){
			case '+':
			sum[i]=a[i]+b[i];break;
			case '-':
			sum[i]=a[i]-b[i];break;
		}
	}
	print(sum);
}
void multiple(float a[],float b[]){
	float sum[9];
	for(int i=0;i<3;i++){ 
		for(int j=0;j<=6;j+=3){
			sum[i+j]=a[i]*b[j]+a[i+3]*b[j+1]+a[i+6]*b[j+2];
		}
	}
	print(sum);
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
	inv(matA,det(matA));
	printf("______________________________\n\n");
	printf("This is \"INVERSE B\"\n\n");
	inv(matB,det(matB));
	printf("______________________________\n\n");
	printf("This is \"A + B\"\n\n");
	sum(matA,matB,'+');
	printf("______________________________\n\n");
	printf("This is \"A - B\"\n\n");
	sum(matA,matB,'-');
	printf("______________________________\n\n");
	printf("This is \"A * B\"\n\n");
	multiple(matA,matB);
	printf("______________________________\n\n");
}
