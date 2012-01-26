#include <iostream>
#include<queue>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
typedef struct act{
	int begin,endtime;
}act;
struct cmp {
	bool operator()(const int &x,const int &y)
	{
		return x>y;
	}
};
int compare(const void* a,const void * b){
	return (((act*)a)->begin>((act*)b)->begin)?1:-1;
}
int main (int argc, char * const argv[]) {
	int n,i;
	act a[50001];
	while (scanf("%d",&n)!=EOF) {
		priority_queue<int,vector<int>,cmp> heap;
		for (i=0; i<n; i++) 
			scanf("%d %d",&a[i].begin,&a[i].endtime);
		qsort(a, n, sizeof(act), compare);
		if (n==0) {
			printf("%d\n",0);
			break;
		}
		heap.push(a[0].endtime);
		for (i=1; i<n; i++) {
			if (a[i].begin<heap.top()) {
				heap.push(a[i].endtime);
			}else {
				int temp=heap.top();
				heap.pop();
				temp=a[i].endtime;
				heap.push(temp);
			}
		}
		printf("%d\n",(int)heap.size());
	}
    return 0;
}
