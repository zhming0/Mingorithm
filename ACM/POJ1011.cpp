#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 65

int length[MAX];
int len;
int n;
int used[MAX];
int num,sum;

int cmp(const void* a,const void* b)
{
	int* x=(int*) a;
	int* y=(int*) b;
	return *y-*x;
}

int dfs(int now,int left,int number)
{
	int i;
	if (left==0) 
	{
		if (number==num-2) 
			return 1;
		for (now=0; used[now]==1; now++) 
			;
		used[now]=1;
		if(dfs(now,len-length[now],number+1))
			return 1;
		used[now]=0;
		return 0;
	}else {
		if (now==n-1) 
		{
			return 0;
		}
		for (i=now; i<n; i++) 
		{
			//printf("Here\n");
			if (used[i]) 
			{
				continue;
			}
			if ((length[i]==length[i-1])&&!used[i-1]) {
				continue;
			}
			if (left-length[i]<0) {
				continue;
			}
			used[i]=1;
			if(dfs(i,left-length[i],number))
				return 1;
			used[i]=0;
		}
		return 0;
	}
	//printf("Here\n");
	return 0;
}

int main (int argc, const char * argv[]) {
    int i,j;
	while (scanf("%d",&n)) 
	{
		int flag=0;
		sum=0;
		if(n==0)
			break;
		for (i=0; i<n; i++) 
		{
			scanf("%d",&length[i]);
			used[i]=0;
			sum+=length[i];
		}
		qsort(length, n, sizeof(int), cmp);
		
		for(i=length[0];i<=sum/2;i++)
		{
			//printf("!!");
			len=i;
			if (sum%len!=0) {
				continue;
			}
			
			num=sum/len;
			used[0]=1;
			if(dfs(0, len-length[0], 0)==1)
			{
				flag=1;
				printf("%d\n",len);
				break;
			}
			used[0]=0;
		}
		
		if (!flag) {
			printf("%d\n",sum);
		}
		memset(used,0,sizeof(used));
	}
    return 0;
}
