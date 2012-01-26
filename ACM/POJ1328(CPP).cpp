#include<algorithm>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
#define MAX 1010
typedef struct Border{
	double left,right;
}Border;
int cmp(const void* a,const void* b)
{
	Border* x=(Border*)a;Border* y=(Border*)b;
	return (x->left>y->left)?1:-1;
}
//bool cmp(Border a,Border b){
//	return a.left<b.left;
//}
int main (int argc, const char * argv[]) {
	int n,d,i;
	int ans;
	int cases=0;
	int flag;
	//freopen("test.txt", "r", stdin);
	while (scanf("%d %d",&n,&d)!=EOF) 
	{
		ans=0;flag=1;
		Border border[MAX];
		int head=0;
		if (n==0&&d==0) 
			break;
		if (d<=0) 
			flag=0;
		for (i=0; i<n; i++) {
			int a,b;
			double c;
			scanf("%d %d",&a,&b);
			if (b>d) {
				flag=0;
			}else {
				c=sqrt((double)(d*d-b*b));
			}
			border[head].left=a-c;
			border[head++].right=a+c;
		}
		qsort(border, head, sizeof(Border), cmp);
		//sort(border, border+head,cmp);
		//for (i=0; i<head; i++) 
		//	printf("border[%d].left=%f,right=%f\n",i,border[i].left,border[i].right);
		if (flag==0) {
			printf("Case %d: %d\n",++cases,-1);
			continue;
		}
		if (n==1) {
			printf("Case %d: %d\n",++cases,1);
			continue;
		}
		double current=border[0].right;
		for (i=1; i<head; i++) {
			if (border[i].left>current) {
				ans++;current=border[i].right;
			}else if (current>border[i].right) {
				current=border[i].right;
			}
		}
		ans++;
		
		printf("Case %d: %d\n",++cases,ans);
	}
	
    return 0;
}
