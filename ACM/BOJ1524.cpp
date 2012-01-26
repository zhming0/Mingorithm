#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int ans;
typedef struct Vec{
	int row,column;
}Vec;
Vec v[101][101];
int DP[101][101];
int dp(int left,int right)
{
	if (DP[left][right]!=-1) {
		return DP[left][right];
	}
	if (left>=right) {
		return 0;
	}
	int temp_ans=999999999;
	int temp,i;
	for (i=left; i<right; i++) 
	{
		temp=dp(left,i)+dp(i+1,right)+v[left][i].row*v[left][i].column*v[i+1][right].column;
		temp_ans=(temp<temp_ans)?temp:temp_ans;
	}
	DP[left][right]=temp_ans;
	return temp_ans;
}

int main (int argc, const char * argv[]) {
	int cases,p=1;
	scanf("%d",&cases);
	while (cases--) {
		int i,j,n;
		ans=0;
		for (i=0; i<=100; i++) 
			for(j=0;j<=100;j++){
				v[i][j].row=0;
				v[i][j].column=0;
				DP[i][j]=-1;
			}
		//memset(DP,-1,sizeof(DP));
		
		scanf("%d",&n);
		scanf("%d",&v[0][0].row);
		for (i=1; i<n;i++) 
		{
			int temp;
			scanf("%d",&temp);
			v[i-1][i-1].column=temp;
			v[i][i].row=temp;
		}
		scanf("%d",&v[i-1][i-1].column);
		
		for (i=0; i<n-1; i++) {
			for (j=i+1; j<n; j++) {
				v[i][j].row=v[i][i].row;
				v[i][j].column=v[j][j].column;
			}
		}
		
		ans=dp(0,n-1);
		printf("Case %d: %d\n",p,ans);
		p++;
	}
    return 0;
}
