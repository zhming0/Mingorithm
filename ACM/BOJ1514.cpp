#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int mem[80][80];

int cal(int n,int max)
{
	/*if (n==1) {
		return 1;
	}*/
	if (n==0) {
		return 1;
	}
	int ans=0;
	int i;
	for (i=(n>max)?max:n; i>0; i--) {
		if (mem[n-i][i]!=0) {
			ans+=mem[n-i][i];
		}
		else {
			mem[n-i][i]=cal(n-i,i);
			ans+=mem[n-i][i];
		}
	}
	return ans;
}

int main (int argc, const char * argv[]) 
{
	int n;
	while (scanf("%d",&n)!=EOF) 
	{
		int ans=cal(n,n);
		memset(mem,0,sizeof(mem));
		printf("%d\n",ans);
	}
    return 0;
}
