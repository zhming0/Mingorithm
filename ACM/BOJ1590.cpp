#include <iostream>
#include<sstream>
#include<string>
#include<map>
using namespace std;
map<string,string> mp;
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int cases,n,i,j;
	string s,tmp;
	cin>>cases;
	while (cases--) {
		cin>>n;
		mp.clear();
		for (i=0; i<n; i++) {
			string s1,s2;
			cin>>s1>>s2;
			mp[s2]=s1;
		}
		getline(cin, s);
		getline(cin, s);
		stringstream st(s);
		while (st>>tmp) 
		{
			if(mp.find(tmp)==mp.end())
				cout << "?";
			else
				cout << mp[tmp];
		}
		cout <<endl;
	}

    return 0;
}
