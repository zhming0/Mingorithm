#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main (int argc, const char * argv[]) {
	char* s1=(char*)malloc(sizeof(char)*1001);
	char* s2=(char*)malloc(sizeof(char)*1001);
	while (scanf("%s",s1)!=EOF) 
	{
		scanf("%s",s2);
		int length1=strlen(s1);
		int length2=strlen(s2);
		int dp[length1+1][length2+1];
		memset(dp,0,sizeof(dp));
		int i,j;
		for (i=0; i<length1;i++ ) {
			for (j=0; j<length2; j++) {
				if (s1[i]==s2[j]) {
					dp[i+1][j+1]=dp[i][j]+1;
				}
				else {
					dp[i+1][j+1]=max(dp[i][j+1], dp[i+1][j]);
				}

			}
		}
		printf("%d\n",dp[length1][length2]);
	}
	
    return 0;
}
