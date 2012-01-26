#include <iostream>
#include<string.h>
#include<string>

using namespace std;

typedef struct Team{
	int ti;
	int penalty[20];
	bool problem[20];
	int ac;
	int num;
}Team;

void swap(Team* a,Team* b)
{
	//cout << a->num<<"|"<<b->num<<endl;
	Team temp;
	temp=*a;
	*a=*b;
	*b=temp;
	//cout << a->num<<"|"<<b->num<<endl;
}

int main (int argc, char * const argv[]) 
{
	int teams;
	int n;
	int i,j;
	while (cin>>teams>>n) 
	{
		Team team[teams];
		
		for (i=0; i<teams; i++) {
			team[i].ti=0;
			team[i].ac=0;
			team[i].num=i+1;
			memset(team[i].penalty, 0, sizeof(team[i].penalty));
			memset(team[i].problem, false, sizeof(team[i].problem));
		}
		
		for (i=0; i<n; i++) 
		{
			int num,problem,t,result;
			cin>>num>>problem>>t>>result;
			if (result==0) {
				team[num-1].penalty[problem-1]+=1200;
			}else if(result==1)
			{
				if (!team[num-1].problem[problem-1]) 
				{
					team[num-1].ac++;
					team[num-1].problem[problem-1]=true;
					team[num-1].ti+=t;
					team[num-1].ti+=team[num-1].penalty[problem-1];
				}
				
			}
		}
		
		//Sort
		
		for (i=0; i<teams; i++) 
		{
			for (j=i+1; j<teams; j++) 
			{
				if (team[i].ac<team[j].ac)
				{
					//cout << i<<","<<j<<endl;
					swap(&team[i], &team[j]);
				}else if (team[i].ac==team[j].ac) 
				{
					if (team[i].ti>team[j].ti) 
					{
						swap(&team[i], &team[j]);
					}else if (team[i].ti==team[j].ti) 
					{
						if (team[i].num>team[j].num) 
						{
							swap(&team[i], &team[j]);
						}
					}
				}
			}
		}
		
		//swap(&team[0], &team[2]);
		
		for (i=0; i<teams; i++) {
			cout << team[i].num;
			if (i!=teams-1) {
				cout << " ";
			}
		}
		cout << endl;
		//cout << team[0].ac<<"?"<<team[1].ac<<endl;
	}
    return 0;
}
