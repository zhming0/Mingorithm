#include <iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<queue>

using namespace std;

int main (int argc, char * const argv[]) {
	int p=1;
	int cases;
	int i,j;
	scanf("%d",&cases);
	while (cases--) 
	{
		int times,room,group;
		int move=0;
		scanf("%d%d%d",&times,&room,&group);
		
		queue<int> q;
		
		long long earn=0;
		
		for (i=0; i<group; i++) 
		{
			int temp;
			scanf("%d",&temp);
			q.push(temp);
		}
		
		//printf("Here\n");
		
		for (i=0; i<times; i++)
		{
			//printf("%d\n",i);
			j=0;
			int r=room;
			queue<int> temp;

			while (r-q.front()>=0&&!q.empty()) 
			{
				r-=q.front();
				earn+=q.front();
				
				temp.push(q.front());
				q.pop();
				j++;
				move++;
				//printf("1");
			}
			
			if (move%group==0) {
				earn=earn*(times/(i+1));
				i=times-times%(i+1);
				move=0;
			}
			
			while (j--) 
			{
				//printf("2");
				q.push(temp.front());
				temp.pop();
			}
			
		}
		
		printf("Case #%d: %lld\n",p,earn);
		p++;
	}
	
    return 0;
}
