#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 500
int root[MAX];
int exist[MAX];
int getRoot(int num)
{
	if (num==root[num]) 
		return num;
	root[num]=getRoot(root[num]);
	return root[num];
}

int main (int argc, const char * argv[]) {
	int p=1;
	int i,j;
	int a,b;
	while (1) 
	{
		int ans=1;
		for(i=0;i<MAX;i++){
			root[i]=i;exist[i]=0;
		}
		while (1) 
		{
			scanf("%d %d",&a,&b);
			if (a==-1&&b==-1) 
				return 0;
			if (a==0&&b==0)
			{
				if(ans==1)
				{
					int temp=0;
					for (i=0; i<MAX; i++) {
						if (exist[i]) 
							if(getRoot(i)==i)
								temp++;
						if(temp>1)
							break;
					}
					if (temp>1) 
						printf("Case %d is not a tree.\n",p);
					else 
						printf("Case %d is a tree.\n",p);
				}
				else 
					printf("Case %d is not a tree.\n",p);
				p++;
				break;
			}
			exist[a]=1;
			exist[b]=1;
			if (getRoot(a)==getRoot(b)) 
				ans=0;
			else
				root[getRoot(a)]=root[getRoot(b)];
		}
	}
	
    return 0;
}
