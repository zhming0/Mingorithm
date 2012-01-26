#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 110
int main (int argc, const char * argv[]) {
	char buf[MAX];
	char ans[MAX];
	int stack[MAX];
	int head=0;
	int i;
	
	while ((scanf("%s",buf))!=EOF) 
	{
		printf("%s\n",buf);
		memset(ans,0,sizeof(ans));
		for (i=0; buf[i]!=0; i++) 
		{
			switch (buf[i]) 
			{
				case '(':
					stack[head++]=i;
					ans[i]='$';
					break;
				case ')':
					if (head!=0) 
					{
						ans[stack[head-1]]=' ';
						stack[--head]=-1;
						ans[i]=' ';
					}
					else 
						ans[i]='?';
					break;
				default:
					ans[i]=' ';
					break;
			}
		}
		printf("%s\n",ans);
		head=0;
		
	}
	
	
    return 0;
}
