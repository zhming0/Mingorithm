#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char grid[110][110];
int cnt[26];
int maxx[26],minx[26],maxy[26],miny[26];
static void init()
{
    for(int i=0;i<26; i++)
    {
        cnt[i]=0;
        maxx[i]=-1;
        maxy[i]=-1;
        minx[i]=200;
        miny[i]=200;
    }
}
static bool check(int num)
{
    if (!cnt[num])return false;
    if (maxx[num]-minx[num]<2||maxy[num]-miny[num]<2) return false;
    if (cnt[num]!=(2*(maxx[num]-minx[num]-1+maxy[num]-miny[num]-1)+4)) return false;
    for (int i=miny[num]+1; i<=maxy[num]-1; i++) 
        for (int j=minx[num]+1; j<=maxx[num]-1; j++) 
            if(grid[i][j]!='.')
                return false;
    return true;
}
int main (int argc, const char * argv[])
{
    int n,m;
    while (cin>>n>>m&&(n||m)) {
        init();
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) {
                cin>>grid[i][j];
                if (grid[i][j]!='.') 
                {
                    cnt[grid[i][j]-'A']++;
                    maxx[grid[i][j]-'A']=max(maxx[grid[i][j]-'A'], j);
                    minx[grid[i][j]-'A']=min(minx[grid[i][j]-'A'], j);
                    maxy[grid[i][j]-'A']=max(maxy[grid[i][j]-'A'], i);
                    miny[grid[i][j]-'A']=min(miny[grid[i][j]-'A'], i);
                }
            }
        for (int i=0; i<26; i++) 
            if (check(i)) 
                printf("%c", i+'A');
        printf("\n");
        
    }
    return 0;
}

