#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int process(string s){
	int ans=0;
	int i,j;
	for (i=0; i<s.length(); i++) {
		int temp=0;
		if (s[i]>='0'&&s[i]<='9') {
			for (j=i; s[j]>='0'&&s[j]<='9'; j++) {
				temp*=10;
				temp+=s[j]-'0';
			}
			i=j;
		}
		ans+=temp;
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	int cases;
	cin>>cases;
	while (cases--) {
		string e;
		string temp;
		cin>>e;
		int ans=0;
		int tempNum;
		int i;
		int pre=0;
		for (i=0; ; i++) {
			tempNum=0;
			if (e[i]=='-'||e[i]==0) {
				temp=e.substr(pre, i-pre);
				tempNum=process(temp);
				if (pre==0) {
					ans+=tempNum;
				}else {
					ans-=tempNum;
				}
				if (e[i]==0) {
					break;
				}
				pre=i+1;
			}
		}
		cout << ans<<endl;
	}
    return 0;
}
