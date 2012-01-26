#include <iostream>
//#include<string>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int min(int a,int b)
{
	return a>b?b:a;
}
int main (int argc, char * const argv[]) {
	//freopen("test.txt","r",stdin);
	int n,length,minLength,i,j,k,p;
	int dp[310];
	string dict[610],word;
	memset(dp, 0, sizeof(dp));
	while (cin>>n>>length) {
		minLength=1<<30;
		cin>>word;
		for (i=0; i<n; i++){ 
			cin>>dict[i];
			minLength=min(minLength,dict[i].length());
		}
		if (minLength>length) {
			cout << length<<endl;
			continue;
		}
		for (i=0; i<length; i++) 
		{
			dp[i]=1<<30;
			if(i>length-minLength)dp[i]=length-i;
		}
		for (i=length-minLength; i>=0; i--) {
			for (j=0; j<n; j++) {
				k=0;p=i;
				while (k<dict[j].length()&&p<length) {
					if (dict[j][k]==word[p]) 
					{	
						k++;p++;
					}
					else 
						p++;
				}
				if (k>=dict[j].length()) 
					dp[i]=min(p-i-dict[j].length()+dp[p],dp[i]);
				else 
					dp[i]=min(length-i,dp[i]);
				//printf("dp[%d]=%d\n",i,dp[i]);
			}
		}
		cout << dp[0]<<endl;
	}
    return 0;
}
