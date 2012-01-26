#include <iostream>
#include <iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<stdio.h>

using namespace std;
int ans;

int main (int argc, char * const argv[]) {
    int cases;
	int p=1;
	int i,j;
	scanf("%d",&cases);
	while(cases--)
	{
		int head=0;
		ans=0;
		string dlist[100000];
		int n,m;
		scanf("%d%d",&n,&m);
		for (i=0; i<n;i++) 
		{
			cin>>dlist[head++];
		}
		for (i=0; i<m; i++)
		{
			//cout << "Begin checking\n";
			string d;
			int temp;
			bool flag=false;
			//printf("Reading\n");
			cin>>d;
			//cout << d<<endl;
			int min;
			if (head==0) 
			{
				//printf("Here?");
				min=0;
				for (int k=0; d[k]!=0; k++) 
				{
					if (d[k]=='/') {
						min++;
					}
					if (k!=0) {
						dlist[head++]=d.substr(0, k);
					}
					
				}
			}
			else {
				min=10000000;
				for (j=0; j<head; j++)
				{
					//printf("head=%d\n",head);
					if (dlist[j].find(d)==0) 
					{
						flag=true;
						break;
					}
					else if(d.substr(0, dlist[j].length())==dlist[j])
					{
						temp=0;
						for (int k=dlist[j].length()-1; d[k]!=0; k++) 
						{
							if (d[k]=='/') {
								temp++;
							}
							//dlist[head++]=d.substr(0, k);
						}
						
						min=(temp<min)?temp:min;
					}
					else 
					{
						temp=0;
						for (int k=0; d[k]!=0; k++) 
						{
							if (d[k]=='/') {
								temp++;
							}
						}
						
						min=(temp<min)?temp:min;
					}

				}
			}
			
			if (!flag) 
			{
				//printf("min=%d",min);
				ans+=min;
			}
			
			dlist[head++]=d;
			
		}
		
		printf("Case #%d: %d\n",p,ans);
		p++;
	}
    return 0;
}
