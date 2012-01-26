#include <iostream>
using namespace std;
typedef long long ll;
ll state[21][2][21][21];
int limit[21],digit;
ll X,Y,p,q,ans;
ll dfs(int n,int ctrl,int four,int seven)
{
	if(n<0&&four==X&&seven==Y)return 1;
	else if(n<0)return 0;
	if(four>X||seven>Y)return 0;
	if(state[n][ctrl][four][seven]!=-1) 
		return state[n][ctrl][four][seven];
	state[n][ctrl][four][seven]=0;
	int res=(ctrl?(limit[n]+1):10);
	for (int i=0; i<res; i++) {
		if(i==4)
			state[n][ctrl][four][seven]+=dfs(n-1,ctrl&&(i==limit[n]),four+1,seven);
		else if(i==7)
			state[n][ctrl][four][seven]+=dfs(n-1,ctrl&&(i==limit[n]),four,seven+1);
		else
			state[n][ctrl][four][seven]+=dfs(n-1,ctrl&&(i==limit[n]),four,seven);
	}
	return state[n][ctrl][four][seven];
}
void tostr(ll num)
{
	digit=0;
	while (num) {
		limit[digit++]=num%10;
		num/=10;
	}
}
void findRank(int n,int ctrl,int four,int seven,ll rank)
{
	int res=(ctrl?limit[n]+1:10),i=0;
	for (i=0; i<res; i++) {
		ll now;
		if (i==4) 
			now=dfs(n-1, ctrl&&(i==limit[n]), four+1, seven);
		else if(i==7)
			now=dfs(n-1, ctrl&&(i==limit[n]), four, seven+1);
		else
			now=dfs(n-1, ctrl&&(i==limit[n]), four, seven);
		if (rank>now) {
			rank-=now;
		}else {
			if(i==4)
				four++;
			if(i==7)
				seven++;
			break;
		}
	}
	ans=ans*10+i;
	if(n>0)
		findRank(n-1,ctrl&&(i==limit[n]),four,seven,rank);
}
int main (int argc, char * const argv[]) {
	//freopen("1.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cases,T=0,query;
	cin>>cases;
	while (cases--) {
		cin>>p>>q>>X>>Y;//p<q
		memset(state, -1, sizeof(state));
		tostr(p);
		ll totp=dfs(digit-1, 1, 0, 0);
		memset(state, -1, sizeof(state));
		tostr(q);
		ll totq=dfs(digit-1, 1, 0, 0);
		cin>>query;
		cout << "Case #"<<++T<<":"<<endl;
		while (query--) {
			ll k;
			cin>>k;
			if (k+totp>totq) 
				cout << "Nya!"<<endl;
			else
			{
				ans=0;
				findRank(digit-1, 1, 0, 0, k+totp);
				cout << ans<<endl;
			}
		}
		
	}
    return 0;
}
