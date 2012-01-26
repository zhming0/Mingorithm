#include <iostream>
#include<cstring>
using namespace std;
long long f[31][10];
int table[4][3];
int main (int argc, char * const argv[]) {
	int i,j,cases;
	cin>>cases;
	memset(f, 0, sizeof(f));
	table[0][0]=1;table[0][1]=2;table[0][2]=3;
	table[1][0]=4;table[1][1]=5;table[1][2]=6;
	table[2][0]=7;table[2][1]=8;table[2][2]=9;
	table[3][0]=0;table[3][1]=-1;table[3][2]=-1;
	for (i=0; i<=9; i++) 
		f[1][i]=1;
	for (i=2; i<=30; i++) {
		for (j=0; j<=9; j++) {
			int x=(j-1)/3;
			int y=(j-1)%3;
			if(j==0)
			{x=3;y=0;}
			if(x-1>=0&&table[x-1][y]!=-1)
				f[i][j]+=f[i-1][table[x-1][y]];
			if(x+1<4&&table[x+1][y]!=-1)
				f[i][j]+=f[i-1][table[x+1][y]];
			if(y-1>=0&&table[x][y-1]!=-1)
				f[i][j]+=f[i-1][table[x][y-1]];
			if(y+1<3&&table[x][y+1]!=-1)
				f[i][j]+=f[i-1][table[x][y+1]];
		}
	}
	while (cases--) {
		int n;
		long long ans=0;
		cin>>n;
		for (i=0; i<=9; i++) {
			ans+=f[n][i];
			//cout << f[n][i]<<endl;
		}
		cout << ans<<endl;
	}
    return 0;
}
