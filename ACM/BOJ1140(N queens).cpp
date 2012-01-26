#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main (int argc, char * const argv[]) {
	// N queen~!
	int n;
	while (~scanf("%d",&n)&&n!=0) {
		int stack[n+1],head=0;
		int row[n+1],ld[n+1],rd[n+1],last[n+1];
		memset(row, 0, sizeof(row));
		memset(ld, 0, sizeof(ld));
		memset(rd, 0, sizeof(rd));
		memset(last, 0, sizeof(last));
		while (1) {
			if (head==n) 
				break;
			int pos=((1<<n)-1)-(row[head]|ld[head]|rd[head]);
			pos-=last[head];
			if (pos==0) {
				last[head]=0;
				stack[--head];
				continue;
			}
			int p=pos&-pos;
			last[head]+=p;
			stack[head++]=p;
			rd[head]=((rd[head-1]+p)>>1);
			if(rd[head]>=(1<<n))rd[head]-=(1<<n);
			ld[head]=((ld[head-1]+p)<<1);
			if(ld[head]>=(1<<n))ld[head]-=(1<<n);
			row[head]=(row[head-1]+p);
			if(row[head]>=(1<<n))row[head]-=(1<<n);
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) 
				if (stack[i]&(1<<j)) {
					printf("%d",j+1);
					break;
				}
			if (i<n-1) 
				printf(" ");
		}
		printf("\n");
	}
    return 0;
}
