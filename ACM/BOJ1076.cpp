#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main (int argc, char * const argv[]) {
	string s;
	int k,i,j,ans;
    while (cin>>s) {
		cin>>k;
		ans=0;
		for (i=0; i<s.length(); i++) {
			if (s[i]=='a') {
				continue;
			}
			for (j=i+1; j<s.length(); j++) {
				if (s[j]!='a'&&(s[i]-'0')>(s[j]-'0')) {
					s[i]='a';
					i=-1;
					k--;
					//cout << s<<endl;
					break;
				}else if (s[j]!='a') {
					break;
				}
			}
			if (k==0) 
				break;
		}
		if (k>0) {
			for (i=s.length()-1; i>=0&&k>0; i--) {
				if (s[i]!='a') {
					s[i]='a';
					k--;
				}
			}
		}
		for (i=0; i<s.length(); i++) {
			if (s[i]!='a') {
				ans*=10;
				ans+=s[i]-'0';
			}
		}
		if (ans==0) {
			cout << ans<<endl;
			continue;
		}
		for (i=0; i<s.length(); i++) {
			if (s[i]!='a'&&s[i]!='0') {
				break;
			}
		}
		for (i; i<s.length(); i++) {
			if (s[i]!='a') {
				cout << s[i]-'0';
			}
		}
		cout << endl;
	}
    return 0;
}
