#include <iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

int main (int argc, char * const argv[]) {
	int n;
	while (scanf("%d",&n)!=EOF) 
	{
		int i,j;
		priority_queue<int> q;
		for (i=0; i<n; i++) {
			int op,temp;
			scanf("%d",&op);
			if (op==0) {
				scanf("%d",&temp);
				q.push(temp);
			}else if(op==1){
				q.pop();
			}else {
				printf("%d\n",q.top());
			}


		}
	}
    return 0;
}
