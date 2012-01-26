#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

string a;
string b;
int len1;
int len2;

int ans[1000][1000];

int max(int x,int y)
{
	return x>y ? x:y;
}

void process()
{
	int i,j;
	for (i=1; i<=len1; i++) 
	{
		for (j=1; j<=len2; j++) 
		{
			if (a[i-1]==b[j-1]) 
			{
				ans[i][j]=ans[i-1][j-1]+1;
			}
			else 
			{
				ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
			}

		}
	}
}

int main (int argc, char * const argv[]) 
{
	while (cin>>a>>b) 
	{
		int i,j;
		len1=a.length();
		len2=b.length();
		
		for (i=0; i<=len1; i++) 
		{
			for (j=0; j<=len2; j++) 
			{
				ans[i][j]=0;
			}
		}
		process();
		cout << ans[len1][len2]<<endl;
		
	}
    return 0;
}
