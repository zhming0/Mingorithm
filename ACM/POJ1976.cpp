#include <iostream>
#include<string>
#include<string.h>

#define MAX 50001

using namespace std;

int a[MAX];
int b[MAX];
int DP[MAX][4];

int max(int x,int y)
{
	return x>y? x:y;
}

void process(int m,int num)
{
	int i,j;
	int k;
	for (i=1; i<=num; i++) 
	{
		for (j=3; j>0; j--) 
		{
			if (i-m<0) 
				k=0;
			else 
				k=i-m;
			DP[i][j]=max(DP[i-1][j],DP[k][j-1]+b[i]);
		}
	}
}

int main (int argc, char * const argv[]) {
	
	int cases;
	int i,j;
	int n;
	int space;
	
	cin>>cases;
	
	while (cases--) 
	{
		cin>>n;
		
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(DP, 0, sizeof(DP));
		
		for (i=0; i<n; i++) {
			cin>>a[i];
		}
		cin>>space;
		
		for (i=1; i<=n-space+1; i++)
		{
			for (j=0; j<space; j++) 
			{
				b[i]+=a[i-1+j];
			}
		}
		process(space,n-space+1);
		cout << DP[n-space+1][3]<<endl;
	}
	
    return 0;
}
