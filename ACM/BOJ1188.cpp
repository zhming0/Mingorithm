#include<stdio.h>
#include<string.h>
#include<math.h>
#define	MAX 1000001
bool prime[MAX];
int num[MAX];
int main (int argc, char * const argv[]) {
	int i,j,n=MAX;
	memset(prime, true, sizeof(prime));
	num[0]=0;
	num[1]=0;
	prime[1]=false;
	for (i=2; i<n; i++) {
		if (prime[i]) 
		{
			for (j=i*2; j<n; j+=i) 
				prime[j]=false;
			num[i]=num[i-1]+1;
		}
		else num[i]=num[i-1];
	}
	while (scanf("%d",&n)!=EOF)
		printf("%d\n",num[n]);
    return 0;
}
