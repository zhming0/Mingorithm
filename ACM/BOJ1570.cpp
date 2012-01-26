#include <iostream>
#include<map>
using namespace std;
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int cases,n,ans,i;
	string s;
	cin>>cases;
	while (cases--) {
		map<string,int> cyclicMap;
		ans=0;
		cin>>n;
		while (n--) {
			cin>>s;
			if(cyclicMap.find(s)==cyclicMap.end())
			{
				ans++;
				for (i=0; i<s.length(); i++) {
					string temp_s=s.substr(i, s.length()-i)+s.substr(0, i);
					cyclicMap[temp_s]=ans;
				}
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
