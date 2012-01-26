#include <iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool grid[900][900];
bool grid2[900][900];
string name[900];
int n;
long long val[900];
bool isAlive[900];
vector<int> v[900];
void mySort()
{
	int i,j;
	bool flag=false;
	for (i=0; i<n; i++) 
	{
		if(isAlive[i]==false)
			continue;
		int edge=0;
		for(j=0;j<n;j++)
			if(grid[j][i])
				edge++;
		if(edge==0)
		{
			flag=true;
			for (j=0; j<n; j++) 
				if(grid[i][j])
				{
					val[j]+=val[i];
					grid[i][j]=false;
				}
			isAlive[i]=false;
		}
	}
	if(!flag)return;
	else mySort();
}
void floyd()
{
	int i,j,k;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			grid2[i][j]=grid[i][j];
	for (k=0; k<n; k++)
		for (i=0; i<n; i++) 
			for (j=0; j<n; j++) 
				if (grid2[i][k]&&grid2[k][j]) 
					grid2[i][j]=true;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			if(grid2[i][j]&&grid2[j][i])
			{
				grid[i][j]=false;
				grid[j][i]=false;
			}
}
int main (int argc, char * const argv[]) {
	freopen("1569.in", "r", stdin);
	int cases,i,j,k,current,tot;
	string target;
	string s,temp;
	cin>>cases;
	while (cases--) {
		for(i=0;i<900;i++)
		{name[i]="";val[i]=1;}
		memset(grid,false, sizeof(grid));
		memset(isAlive,true,sizeof(isAlive));
		memset(grid2, false, sizeof(grid2));
		cin>>n;
		getline(cin,s);//eat space
		tot=0;
		for (i=0; i<n; i++) 
		{
			getline(cin,s);
			istringstream st(s);
			st>>temp;
			for(j=0;j<tot;j++)
				if(name[j]==temp)
					break;
			if(j==tot)
				name[tot++]=temp;
			current=j;
			while (st>>temp) 
			{
				for(k=0;k<tot;k++)
					if(name[k]==temp)
						break;
				if(k==tot)
					name[tot++]=temp;
				grid[k][current]=true;
			}
		}
		n=tot;
		cin>>target;
		floyd();
		mySort();
		for(i=0;i<n;i++)
			if(name[i]==target)
			{
				cout << val[i]<<endl;
				break;
			}
	}
    return 0;
}
