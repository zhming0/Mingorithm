#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct fileTree{
	fileTree* parent;
	fileTree* children[100];
	int num;
	char name[100];
}fileTree;

void buildTree(fileTree* tree,char* s)
{
	int i;
	int j;
	int state=0;
	for (i=1; s[i]!=0; i++) 
	{
		char temp[100];
		
		if (i==1) 
		{
			tree=(fileTree*)malloc(sizeof(fileTree));
			for (j=1; s[i]!='/'&&s[i]!=0; j++) 
			{
				temp[j]=s[i];
			}
			tree->name=temp;
			tree->num=0;
		}
		
		if (s[i]=='/') {
			i++;
			
		}
		
		if (s[i]==0) {
			return;
		}
	}
}

int main (int argc, const char * argv[]) {
	int cases;
	int i,j;
	int p=1;
	scanf("%d",*cases);
	while (cases--) 
	{
		int n,m;
		scanf("%d%d",&n,&m);
		fileTree* tree;
		for (i=0; i<n;i++)
		{
			char temp[100000];
			scanf("%s",temp);
		}
	}
    return 0;
}
