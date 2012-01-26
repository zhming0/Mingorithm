#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50001

void up(int num,int* person,int size,int* queue,int* rank)
{
	int i;
	int p=person[num];
	for (i=rank[num]; i/2!=0; i/=2) 
	{
		if (person[queue[i/2]]<p) 
		{
			rank[queue[i]]=i/2;
			queue[i]=queue[i/2];
		}
		else
			break;
	}
	rank[num]=i;
	queue[i]=num;
}
void down(int num,int* person,int size,int* queue,int* rank)
{
	int i;
	int child;
	int p=person[num];
	//printf("P=%d\n",p);
	for (i=rank[num]; i*2<=size; i=child) 
	{
		child=i*2;
		if(child!=size)
			if(person[queue[child+1]]>person[queue[child]])
				child++;
		if (p<person[queue[child]]) {
			rank[queue[i]]=child;
			queue[i]=queue[child];
		}else
			break;
	}
	queue[i]=num;
}
int main (int argc, const char * argv[]) {
    int n,m;
	int i;
	int cases,p=1;
	freopen("1511.in", "r", stdin);
	scanf("%d",&cases);
	while (cases--) 
	{
		scanf("%d %d",&m,&n);
		int* person=(int*)malloc((m+1)*sizeof(int));
		int* queue=(int*)malloc(sizeof(int)*(m+1));
		int* rank=(int*)malloc(sizeof(int)*(m+1));
		for (i=0; i<=m; i++)
		{
			person[i]=100;
			queue[i]=i;
			rank[i]=i;
		}
		printf("Case %d:\n",p);
		for (i=0; i<n; i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			person[a]+=b;
			if (b>0) 
				up(a,person,m,queue,rank);
			else
				down(a,person,m,queue,rank);
			printf("%d\n",person[queue[1]]);
		}
		p++;
	}
    return 0;
}
