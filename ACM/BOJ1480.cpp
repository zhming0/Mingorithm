#include <iostream>
#include<string>

using namespace std;

unsigned long long ans;

void cal(string s[],int line,int x,int y)
{
	int i,j;
	int col=s[0].length();
	for (i=0; i<line; i++) {
		for (j=0; j<col; j++) 
		{
			if (s[i][j]=='C'&&(i!=x||j!=y)) 
			{
				ans+=(x-i)*(x-i)+(y-j)*(y-j);
			}
		}
	}
	return;
}

int main (int argc, char * const argv[]) 
{
	int cases;
	int i,j;
	cin>>cases;
	while (cases--) 
	{
		unsigned long long min=((long long ) 1<<62);
		int line;
		cin>>line;
		string s[line];
		
		for (i=0; i<line; i++)
		{
			cin>>s[i];
		}
		int col=s[0].length();
		
		for (i=0; i<line; i++)
		{
			for (j=0; j<col; j++) 
			{
				if (s[i][j]=='C') 
				{
					ans=0;
					cal(s, line,i,j);
					
					if (ans<min) 
					{
						min=ans;
					}
					
				}
			}
		}
		
		cout << min<<endl;
		
	}
	
	
    return 0;
}
