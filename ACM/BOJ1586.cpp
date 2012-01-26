#include <iostream>
#include<string>
using namespace std;
int minute(string s)
{
	int ans=0;
	string sub=s.substr(3, 2);
	ans=(sub[0]-'0')*10+sub[1]-'0';
	return ans;
}
int hour(string s)
{
	string sub=s.substr(0, 2);
	int ans=0;
	ans=(sub[0]-'0')*10+sub[1]-'0';
	return ans;
}
int main (int argc, char * const argv[]) {
	int cases;
	string s;
	cin>>cases;
	while (cases--) {
		cin>>s;
		int h=hour(s);
		int m=minute(s);
		if(m==0)
			h=12-h;
		else
			h=12-h-1;
		if(h==12)h=0;
		m=60-m;
		if(m==60)m=0;
		string ho="",mi="";
		ho+=h/10+'0';
		ho+=h%10+'0';
		mi+=m/10+'0';
		mi+=m%10+'0';
		cout << ho<<":"<<mi<<endl;
	}
    return 0;
}
