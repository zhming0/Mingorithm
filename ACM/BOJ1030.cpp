//
//  main.cpp
//  BJTU-ACM1030
//
//  Created by  on 11-10-3.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int sum[50000];
vector<int> factor;
int dfs(int n)
{
    int ret=0;
    int k=upper_bound(factor.begin(), factor.end(), n)-factor.begin()-1;
    //printf("k=%d\n",k);
    if (sum[k]) 
        return sum[k];
    for (int i=0; i<factor.size(); i++) {
        if (n%factor[i]==0) {
            ret+=dfs(n/factor[i]);
        }
    }
    sum[k]=ret;
    return ret;
}
int main(void)
{
    int n;
    while(~scanf("%d",&n))   
    {
        factor.clear();
        int m=sqrt(n);
        for (int i=2; i<=m; i++) 
            if (n%i==0) {
                factor.push_back(n/i);
                factor.push_back(i);
            }
        sort(factor.begin(), factor.end());
        printf("%d\n",upper_bound(factor.begin(), factor.end(), 2)-factor.begin());
        sum[0]=1;
        printf("%d\n",dfs(n));
    }
    return 0;
}