#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int> que;
int grid[510][510];
int ret[510][510];
int n,r;

int main (int argc, const char * argv[])
{
    while (~scanf("%d%d",&n,&r)&&(n||r)) {
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) 
                scanf("%d", &grid[i][j]);
        int tmp=0;
        for (<#initialization#>; <#condition#>; <#increment#>) {
            <#statements#>
        }
        for (int i=r; i<n-r; i++) {
            for (int j=r; j<n-r; j++) 
            {
                if(i==r&&j==r)continue;
            }
        }
    }
    return 0;
}

