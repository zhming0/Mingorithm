#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int min(int a,int b)
{
	return a>b?b:a;
}

int main (int argc, const char * argv[]) {
	freopen("b.txt", "r", stdin);
	int a[60];
	int isFinal[60];
	int isStart[60];
	int cases;
	scanf("%d",&cases);
	while (cases--) {
		int i,j;
		int ans=0;
		int queue[1000];
		int head=0;
		int tail=0;
		memset(isFinal,0,sizeof(isFinal));
		memset(isStart,0,sizeof(isStart));
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			scanf("%d",&a[i]);
		}
		int temp=a[n-1];
		isFinal[n-1]=1;
		
		int flag=0;
		int t=a[n-1];
		for (j=n-1; j>=0; j--) {
			if (t-a[j]<0) {
				flag=1;
			}
			t=a[j];
		}
		if(flag==1){
			ans++;
		}
		for (i=n-2; i>=0; i--) {
			if (temp<a[i]) {
				flag=0;
				t=a[i];
				for (j=i-1; j>=0; j--) {
					if (t-a[j]<0) {
						flag=1;
					}
					t=a[j];
				}
				if(flag==1||i==0){
					ans++;
				}
				isFinal[i]=1;
				temp=a[i];
			}
		}
		temp=a[0];
		isStart[0]=1;
		for (i=0; i<n; i++) {
			if (a[i]<temp) {
				isStart[i]=1;
				temp=a[i];
			}
		}
		for (i=0; i<n; i++) {
			if (isStart[i]==1) 
			{
				printf("Here start at a[%d]=%d\n",i,a[i]);
				queue[tail++]=i;
				while (head<tail) {
					int m=999999999;
					int now=queue[head++];
					if (isFinal[now]==1&&isStart[now]!=1) {
						ans++;
					}
					for (j=now+1; j<n; j++) {
						m=min(m,a[j]);
						if (a[j]>a[now]&&a[j]==m)
						{
							queue[tail++]=j;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
