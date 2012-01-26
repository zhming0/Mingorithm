#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
char grid[110][110];
bool vst[110][110];
int main (int argc, const char * argv[])
{
    int n,m;
    while (~scanf("%d %d",&n, &m)) {
        int ret=0;
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                scanf("%c", &grid[i][j]);
        memset(vst, false, sizeof(vst));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) 
            {
                if (grid[i][j]=='#'&&!vst[i][j]) 
                {
                    ret++;
                    vst[i][j]=true;
                    if(j<m-1&&grid[i][j+1]=='#'){
                        vst[i][j+1]=true;
                        //continue;
                    }
                    if (i<n-1&&grid[i+1][j]=='#') {
                        vst[i+1][j]=true;
                        //continue;
                    }
                }
            }
        }
        printf("%d", ret);
    }
    return 0;
}

