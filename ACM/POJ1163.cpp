#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 101

using namespace std;

int triangle[MAX][MAX];
int longest[MAX][MAX];
int line;

int dp(int x,int y)
{
	//printf("Enter Here\n");
	if (longest[x][y]>0) 
	{
		//printf("Here\n");
		return longest[x][y];
	}
	if (x==line-1) {
		return triangle[x][y];
	}
	int a=dp(x+1,y)+triangle[x][y];
	int b=dp(x+1,y+1)+triangle[x][y];
	return longest[x][y]=(a>b)? a: b;
}

int main (int argc, char * const argv[]) {
	int i,j;
	while(cin>>line)
	{
		for (i=0; i<MAX; i++) 
		{
			memset(longest[i], 0, sizeof(longest[i]));
		}
		for (i=0; i<line; i++) 
		{
			for (j=0; j<i+1; j++) 
			{
				cin>>triangle[i][j];
				//std::cout<<triangle[i][j]<<std::endl;
			}
		}
		
		cout<<dp(0, 0)<<endl;
		
		
	}
	
	
    //std::cout << "Hello, World!\n";
    return 0;
}
