#include <iostream>
#include<string>
#include<sstream>
using namespace std;
int main (int argc, char * const argv[]) {
	string s;
	while (cin>>s) {
		getline(cin, s);
		getline(cin, s);
		for (int i=0; i<s.length(); i++) {
			if(s[i]>='A'&&s[i]<='Z')
			{
				s[i]-=5;
				if(s[i]<'A')s[i]+=26;
			}
		}
		cout << s<<endl;
		cin>>s;
	}
    return 0;
}
