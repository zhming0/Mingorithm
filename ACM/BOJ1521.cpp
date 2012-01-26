#include <iostream>
#include<map>
#include<stdio.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int n,x,y;
	int p=0;
	scanf("%d",&n);
	while (n--) {
		int i;
		int ans=0;
		map<string,bool> m;
		string s;
		scanf("%d %d",&x,&y);
		for (i=0; i<x; i++) {
			int pos=1;
			int found;
			cin>>s;
			while ((found=s.find('/', pos))!=string::npos) {
				m[s.substr(0, found)]=true;
				pos=found+1;
			}
			m[s]=true;
		}
		for (i=0; i<y; i++) {
			cin>>s;
			int found,pos=1;
			while ((found=s.find('/', pos))!=string::npos) {
				if (m.count(s.substr(0, found))==0) {
					ans++;
					m[s.substr(0, found)]=true;
				}
				pos=found+1;
			}
			if (m.count(s)==0) {
				m[s]=true;
				ans++;
			}
		}
		printf("Case #%d: %d\n",++p,ans);
	}
	
    return 0;
}
