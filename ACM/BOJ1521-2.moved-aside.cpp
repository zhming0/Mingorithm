#include <iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef	struct fileTree{
	int children[100];
	string cname[100];
	int num_child;
	string name;
}fileTree;

int main (int argc, char * const argv[]) {
    int cases;
	int p=0;
	int i,j;
	scanf("%d",&cases);
	while (cases--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (i=0; i<n; i++) 
		{
			string temp;
			cin>>temp;
			
			fileTree tree[100];
			
			for (j=1;temp[j]!=0; j++) 
			{
				if (tree[0]==NULL) 
				{
					string nm;
					for (int k=0;temp[j]!='/'&&temp[j]!=0 ; k++,j++) {
						nm[k]=temp[j];
					}
					nm[k]=0;
					tree[0].name=nm;

				}
				if (temp[j]=='/')
				{
					
				}
			}
			
		}
	}
    return 0;
}
