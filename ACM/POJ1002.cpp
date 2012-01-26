#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> v;
map<string,int> mp;
int main (int argc, char * const argv[]) {
	int n,i,j;
	string tmp,s;
	//freopen("backup.txt", "r", stdin);
	while (cin>>n) {
		v.clear();
		mp.clear();
		for (i=0; i<n; i++) {
			cin>>s;
			tmp="";
			for (j=0; j<s.length(); j++) 
			{
				switch (s[j]) {
					case '1':
						tmp+='1';
						break;
					case 'A':case 'B':case 'C':case '2':
						tmp+='2';
						break;
					case 'D':case 'E':case 'F':case '3':
						tmp+='3';
						break;
					case 'G':case 'H':case 'I':case '4':
						tmp+='4';
						break;
					case 'J':case 'K':case 'L':case '5':
						tmp+='5';
						break;
					case 'M':case 'N':case 'O':case '6':
						tmp+='6';
						break;
					case 'P':case 'R':case 'S':case '7':
						tmp+='7';
						break;
					case 'T':case 'U':case 'V':case '8':
						tmp+='8';
						break;
					case 'W':case 'X':case 'Y':case '9':
						tmp+='9';
						break;
					case '0':
						tmp+='0';
						break;
					default:
						break;
				}
			}
			s=tmp.substr(0, 3)+"-"+tmp.substr(3, 4);
			if (mp[s]==0) 
				v.push_back(s);
			mp[s]++;
		}
		sort(v.begin(), v.end());
		bool flag=false;
		/*for (i=0; i<v.size(); i++)
			if(mp[v[i]]>1)
			{
				flag=true;
				cout << v[i]<<" "<<mp[v[i]]<<endl;
			}
		 */
		map<string,int>::iterator it=mp.begin();
		while (it!=mp.end()) {
			if(it->second>1)
			{
				flag=true;
				cout << it->first<<" "<<it->second<<endl;
			}
			it++;
		}
		if (!flag) 
			cout << "No duplicates."<<endl;
	}
    return 0;
}
