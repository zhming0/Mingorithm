#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void combine(int** a,int** b)
{
	int temp[2][2];
	int i,j;
	
	temp[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%7;
	temp[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%7;
	temp[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%7;
	temp[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%7;
	for (i=0; i<2; i++) {
		for (j=0; j<2; j++) {
			a[i][j]=temp[i][j];
		}
	}
}

int main (int argc, const char * argv[]) 
{
	int a,b,i;
	long long n;
	int** v;
	int ans;
	v=(int **)malloc(sizeof(int*)*2);
	for (i=0; i<2; i++) {
		v[i]=(int*)malloc(sizeof(int)*2);
	}
	while (1) 
	{
		scanf("%d %d %lld",&a,&b,&n);
		if (n==0&&a==0&&b==0) {
			break;
		}
		int** final_vector;
		final_vector=(int**)malloc(sizeof(int*)*2);
		for (i=0; i<2; i++) {
			final_vector[i]=(int*)malloc(sizeof(int)*2);
		}
		
		final_vector[0][0]=1;
		final_vector[0][1]=0;
		final_vector[1][0]=0;
		final_vector[1][1]=1;
		
		v[0][0]=b%7;
		v[1][0]=(a*b)%7;
		v[0][1]=(a)%7;
		v[1][1]=(a*a+b)%7;
		long long time;
		if (n%2==0) {
			time=(n-2)/2;
		}else{
			time=(n-1)/2;
		}
		while (time) {
			if (time&1) {
				combine(final_vector, v);
			}
			time>>=1;
			combine(v, v);
		}

		if (n%2==1) {
			ans=final_vector[0][0]+final_vector[0][1];
			ans%=7;
		}else {
			ans=final_vector[1][0]+final_vector[1][1];
			ans%=7;
		}
		
		printf("%d\n",ans);
	}
    return 0;
}
