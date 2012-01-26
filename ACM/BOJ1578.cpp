#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,n,i,j,m,table[21][21];
	string s;
	cin>>cases;
	while (cases--) {
		bool flag=true;
		memset(table, 0, sizeof(table));
		cin>>n;
		getline(cin,s);
		for (i=0; i<n; i++) {
			getline(cin,s);
			istringstream stream(s);
			int temp;
			j=0;
			while (stream>>temp)
				table[i][j++]=temp;
			m=j;
		}
		n=m>n?m:n;
		for (i=1; i<n; i++) 
			for(j=1;j<n;j++)
				if (table[i][j] + table[i - 1][j - 1] != table[i - 1][j] + table[i][j - 1])
					flag=false;
		if (flag) 
			cout << "CORRECT"<<endl;
		else
			cout << "INCORRECT"<<endl;
	}
    return 0;
}
