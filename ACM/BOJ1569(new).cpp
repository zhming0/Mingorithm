#include <iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#include<sstream>
using namespace std;
map<string,int> mp;
vector<int> v[1000];
vector<int> v2[1000];
int grid[1000];
int grid2[1000];
queue<int> q;
//bool Circle[1000];
int N;
bool cycle(int a, int b) 
{ 
	bool used[1000]; 
	memset(used, false, sizeof(used)); 
	while(!q.empty()) q.pop(); 
	q.push(b); 
	while(!q.empty()) { 
		int f = q.front(); 
		if(f==a) return true; 
		q.pop(); 
		for(int i = 0; i < v[f].size(); ++i) if(!used[v[f][i]]) { 
			used[v[f][i]] = true; 
			q.push(v[f][i]); 
		} 
	} 
	return false; 
} 
long long go(int num) 
{ 
	long long ret = 1; 
	for(int i = 0; i < v[num].size(); ++i) { 
		if(cycle(num,v[num][i])) continue; 
		else ret += go(v[num][i]); 
	} 
	return ret; 
} 
int main (int argc, char * const argv[]) {
	freopen("1569.in", "r", stdin);
	int cases,n,i;
	string s,tmp;
	cin>>cases;
	while (cases--) {
		N=0;
		cin>>n;
		mp.clear();
		for(i=0;i<1000;i++){v[i].clear();v2[i].clear();}
		memset(grid, false, sizeof(grid));
		memset(grid2, false, sizeof(grid2));
		getline(cin,tmp);
		for (i=0; i<n; i++) 
		{
			int to,from;
			getline(cin,tmp);
			istringstream in(tmp);
			in>>s;
			if(mp.find(s)==mp.end())
			{
				mp[s]=N;
				to=N;
				N++;
			}
			else 
				to=mp[s];
			while (in>>s) 
			{
				if(mp.find(s)==mp.end())
				{
					mp[s]=N;
					from=N;
					N++;
				}else
					from=mp[s];
				v[to].push_back(from);
				v2[from].push_back(to);
			}
		}
		cin>>s;
		cout << go(mp[s])<<endl;
	}
    return 0;
}
