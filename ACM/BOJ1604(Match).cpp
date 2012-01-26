#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int grid[2001][2001];
bool check(int n)
{
	int sum=0,temp,i,j;
	for (i=0; i<n; i++) sum+=grid[0][i];
	for(i=1;i<n;i++)
	{
		temp=0;
		for (j=0; j<n; j++) 
			temp+=grid[i][j];
		if(sum==temp)return false;
	}
	//printf("Here\n");
	for (j=0; j<n; j++) {
		temp=0;
		for (i=0; i<n; i++) 
			temp+=grid[i][j];
		if(sum==temp)return false;
	}
	temp=0;
	for (i=0; i<n; i++) 
		temp+=grid[i][i];
	if(sum==temp)return false;
	temp=0;
	for (i=0; i<n; i++) 
		temp+=grid[n-i-1][i];
	if(sum==temp)return false;
	return true;
}
int main (int argc, char * const argv[]) {
	int cases,i,j,n,T=0;
	cin>>cases;
	while (cases--) {
		T++;
		cin>>n;
		//n=T+2;
		int num=1;
		for (i=0; i<n; i++) 
			for (j=0; j<n-1; j++)
				grid[i][j]=num++;
		for (i=0; i<n; i++) 
			grid[i][n-1]=num++;
		printf("Case #%d:\n",T);
		for (i=0; i<n; i++) {
			for (j=0; j<n-1; j++) 
				printf("%d ",grid[i][j]);
			printf("%d\n",grid[i][n-1]);
		}
		/*if (!check(n)) {
			printf("When n=%d, it's false!\n",n);
			break;
		}else {
			printf("When n=%d, it's true!\n",n);
		}*/
	}
    return 0;
}
