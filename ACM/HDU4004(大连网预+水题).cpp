#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> > small; 

int main (int argc, char * const argv[]) {
	int n,k;
	char op;
	while (~scanf("%d%d",&n,&k)) {
		while (!small.empty()) small.pop();
		for (int i=0; i<k; i++) {
			scanf("%c",&op);
			int temp;
			scanf("%c",&op);
			scanf("%d",&temp);
			//printf("op=%c,temp=%d\n",op,temp);
			small.push(temp);
		}
		for (int i=0; i<n-k; i++) {
			int tmp;
			scanf("%c",&op);
			scanf("%c",&op);
			if(op=='I')
			{
				scanf("%d",&tmp);
				if(tmp>small.top())
					small.pop(),small.push(tmp);
			}else {
				printf("%d\n",small.top());
			}
		}
	}
    return 0;
}
