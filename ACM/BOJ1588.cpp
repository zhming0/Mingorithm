#include <iostream>
#include<string>
#include<map>
using namespace std;
typedef struct ns{
	string name;
	int score;
}ns;
ns team[51],member[51];
map<string,string> mp;
map<string,int> isHere;
int head_t=0,head_m=0;
void printNow()
{
	int i,j;
	cout << head_m+head_t<<endl;
	for (i=0; i<head_m; i++) 
		for (j=i+1; j<head_m; j++) 
		{
			if(member[i].score<member[j].score)
			{
				ns t=member[i];member[i]=member[j];member[j]=t;
			}
			else if(member[i].score==member[j].score&&member[j].name<member[i].name)
			{
				ns t=member[i];member[i]=member[j];member[j]=t;
			}
		}
	for (i=0; i<head_t; i++) 
		for (j=i+1; j<head_t; j++) 
		{
			if(team[i].score<team[j].score)
			{
				ns t=team[i];team[i]=team[j];team[j]=t;
			}
			else if(team[i].score==team[j].score&&team[j].name<team[i].name)
			{
				ns t=team[i];team[i]=team[j];team[j]=t;
			}
		}
	for (i=0; i<head_t; i++) 
	{
		cout << team[i].name<<" "<<team[i].score<<endl;
		for (j=0; j<head_m; j++) 
			if(mp[member[j].name]==team[i].name)
				cout << "  "<<member[j].name<<" "<<member[j].score<<endl;
	}
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int cases,n,i,j;
	cin>>cases;
	string from,tmp,to;
	while (cases--) {
		cin>>n;
		mp.clear();
		isHere.clear();
		head_t=0,head_m=0;
		for (i=0; i<n; i++) {
			string a,b;
			cin>>a>>b;
			mp[a]=b;
			member[head_m].name=a;
			member[head_m++].score=0;
			if (isHere.find(b)==isHere.end()) 
			{
				//cout << "New team="<<b<<endl;
				isHere[b]=1;
				team[head_t].name=b;
				team[head_t++].score=0;
			}
		}
		cin>>n;
		while (n--) 
		{
			cin>>from>>tmp>>to;
			if(mp[from]==mp[to])
			{
				for (i=0; i<head_m; i++) 
					if(member[i].name==from)
					{
						tmp=mp[from];
						member[i].score--;
						for(j=0;j<head_t;j++)
						{
							if(team[j].name==tmp)
							{
								team[j].score--;
								break;
							}
						}
						break;
					}
			}
			else 
			{
				for (i=0; i<head_m; i++) 
				{
					if(member[i].name==from)
					{
						tmp=mp[from];
						member[i].score++;
						for(j=0;j<head_t;j++)
						{
							if(team[j].name==tmp)
							{
								team[j].score++;
								break;
							}
						}
						
					}
					if(member[i].name==to)
					{
						tmp=mp[to];
						member[i].score--;
						for(j=0;j<head_t;j++)
						{
							if(team[j].name==tmp)
							{
								team[j].score--;
								break;
							}
						}
						
					}
				}
			}
		}
		printNow();
		//for(i=0;i<head_t;i++)
		//	cout << team[i].name<<endl;
		//cout << "================="<<endl;
	}
    return 0;
}
