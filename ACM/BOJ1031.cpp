//
//  main.cpp
//  BJTU-ACM1031
//
//  Created by  on 11-10-4.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int Y[10001];
int n;
int cal(int k)
{
    int ret=0;
    for (int i=0; i<n; i++) 
        ret+=abs(Y[i]-k);
    return ret;
}
int main (int argc, const char * argv[])
{
    while (~scanf("%d",&n)) {
        for (int i=0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            Y[i]=y;
        }
        sort(Y, Y+n);
        int ret;
        if (n==1) {
            printf("0\n");
            continue;
        }
        if (n%2==0) {
            int k=n/2;
            ret=min(cal(Y[k]), cal(Y[k-1]));
        }else{
            int k=n/2;
            ret=cal(Y[k]);
        }
        printf("%d\n",ret);
    }
    return 0;
}

