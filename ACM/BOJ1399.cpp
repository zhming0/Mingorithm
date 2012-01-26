#include <stdio.h>
#include<stdlib.h>
#include<string.h>

long long ans;

void combine(int,int,int,int,int*);

void MergerSort(int left,int right,int* num)
{
	if (left==right)
		return;
	int mid=(left+right)/2;
	MergerSort(left,mid,num);
	MergerSort(mid+1,right,num);
	
	combine(left, mid, mid+1, right,num);
	
}
void combine(int left1,int right1,int left2,int right2,int* num)
{
	int* temp=(int* )malloc(sizeof(int)*(right2-left1+1));
	int p1=left1,p2=left2;
	int i=0,j=0;
	while (1) 
	{
		if (p1>right1&&p2>right2) 
			break;
		
		if (p1>right1) {
			temp[i++]=num[p2];
			p2++;
			continue;
		}
		else if(p2>right2) 
		{
			temp[i++]=num[p1];
			p1++;
			continue;
		}

		if (num[p1]<=num[p2]) 
		{
			temp[i++]=num[p1];
			p1++;
		}
		else
		{
			temp[i++]=num[p2];
			ans+=right1-p1+1;
			p2++;
		}
	}
	
	for (i=left1; i<=right2; i++) 
	{
		num[i]=temp[j++];
	}
	free(temp);
}

int main (int argc, const char * argv[]) 
{
	int i;
	int n;
	while (scanf("%d",&n)) 
	{
		if (n==0) {
			break;
		}
		int* num=(int*)malloc(sizeof(int)*500001);
		ans=0;
		for (i=0; i<n; i++) 
		{
			scanf("%d",&num[i]);
		}
		
		MergerSort(0, n-1,num);

		free(num);
		printf("%I64d\n",ans);
	}

    return 0;
}
