#include <iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i,j,n;
	long long ans=0;
	const long long E13=10000000000000;
	queue<int> que_pos;
	queue<int> que_num;
	int head=0,tail=0;
	cin>>cases;
	while (cases--) {
		ans=0;
		string a;
		string word[100];
		char current;
		int length;
		for (i=0; i<4; i++) 
		{
			string temp;
			cin>>temp;
			a+=temp;
		}
		cin>>n;
		for (i=0; i<n; i++) 
			cin>>word[i];
		for (i=0; i<n; i++) {
			length=word[i].length();
			for (j=0; j<16; j++)
			{
				current=word[i][0];
				if (a[j]==current) 
				{
					//cout << "Enter BFS with first="<<j<<endl;
					head=0;tail=0;
					int count=0;
					que_pos.push(j);
					que_num.push(0);
					while (!que_pos.empty()) {
						//cout << head<<"|||"<<tail<<endl;
						int now=que_pos.front();
						que_pos.pop();
						count=(que_num.front()+1);
						que_num.pop();
						current=word[i][count];
						//cout << "Current="<<current<<"Now="<<now<<endl;
						if (count==length)
						{
							//cout << "Got Path!\n";
							ans+=(length*length);
							ans%=E13;
							continue;
						}
						if (now%4!=3) 
							if (a[now+1]==current) 
							{	
								//cout << "Go right"<<endl;
								que_num.push(count);
								que_pos.push(now+1);
							}
						if (now%4!=0)
							if (a[now-1]==current) 
							{
								//cout << "Go left"<<endl;
								que_num.push(count);
								que_pos.push(now-1);
							}
						if (now-4>=0)
						{
							if (a[now-4]==current) 
							{
								que_num.push(count);
								que_pos.push(now-4);
							}
							if (now%4!=3) 
								if (a[now-3]==current) 
								{
									que_num.push(count);
									que_pos.push(now-3);
								}
							if (now%4!=0)
								if (a[now-5]==current) 
								{
									que_num.push(count);
									que_pos.push(now-5);
								}
						}
						if(now+4<16)
						{
							if (a[now+4]==current) 
							{
								que_num.push(count);
								que_pos.push(now+4);
							}
							if (now%4!=3) 
								if (a[now+5]==current) 
								{
									que_num.push(count);
									que_pos.push(now+5);
								}
							if (now%4!=0)
								if (a[now+3]==current) 
								{
									que_num.push(count);
									que_pos.push(now+3);
								}
						}
					}
				}
			}
		}
		//cout << ans<<endl;
		printf("%I64d\n",ans);
	}
    return 0;
}
