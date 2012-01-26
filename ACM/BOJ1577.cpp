#include <iostream>
#include<string>
#include<cstdio>
using namespace std;
int degreeChange(string ins)
{
	int i;
	if(ins[0]=='L')
	{
		if (ins.length()>5) {
			int temp=0;
			for (i=5; i<ins.length(); i++) {
				temp*=10;
				temp+=ins[i]-'0';
			}
			return -1*temp;
		}else
			return -90;
	}
	if(ins[0]=='R')
	{
		if (ins.length()>6) {
			int temp=0;
			for (i=6; i<ins.length(); i++) {
				temp*=10;
				temp+=ins[i]-'0';
			}
			return temp;
		}else
			return 90;
	}
	if(ins[0]=='T')return -180;
	if(ins[0]=='H')return 360;
	return 999999999999;
}
int main (int argc, char * const argv[]) {
	int cases,n,i,j;
	string ins[51];
	cin>>cases;
	while (cases--) {
		bool flag=true;
		int ans=0;
		cin>>n;
		char newLine;
		scanf("%c",&newLine);
		for (i=0; i<n; i++) {
			getline(cin,ins[i]);
			if(flag)
			{
				int temp=degreeChange(ins[i]);
				if(temp==360)flag=false;
				ans+=temp;
				if(ans<0)ans+=360;
				if(ans>=360)ans-=360;
			}
		}
		cout<<ans<<endl;
	}

    return 0;
}
