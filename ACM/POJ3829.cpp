#include<cstring>
#include<cstdio>
#include <iostream>
#include<algorithm>
using namespace std;
struct Query{
    int h, m, seats, index;
    int x,y;
}q[51];
int feeling[31][31];
bool vst[31][31];
static bool cmp1(const Query& a, const Query& b)
{
    return a.h<b.h || (a.h==b.h && a.m<b.m);
}
static bool cmp2(const Query& a, const Query& b)
{
    return a.index<b.index;
}

int main (int argc, const char * argv[])
{
    int n, m, que;
    while (~scanf("%d %d %d", &n, &m, &que)&&(n||m||que)) {
        for (int i=1; i<=n; i++) 
            for (int j=1; j<=m; j++) 
                scanf("%d", &feeling[i][j]);
        for (int i=0; i<que; i++) {
            scanf("%d:%d %d",&q[i].h, &q[i].m, &q[i].seats);
            q[i].x=q[i].y=0;
            q[i].index=i;
        }
        sort(q, q+que, cmp1);
        memset(vst, false, sizeof(vst));
        for (int now=0; now<que; now++) 
        {
            bool findSeats=false;
            int curFeeling=-1000000000;
            for (int i=1; i<=n; i++) 
            {
                for (int j=1; j<=m-q[now].seats+1; j++) 
                {
                    bool flag=true;
                    for (int k=0; k<q[now].seats; k++){
                        if (vst[i][j+k]) 
                        {
                            flag=false;
                            break;
                        }
                    }
                    
                    if (flag && curFeeling<feeling[i][j]) 
                    {
                        findSeats=true;
                        curFeeling=feeling[i][j];
                        q[now].x=i;
                        q[now].y=j;
                    }
                }            
            }
            if (findSeats) { 
                for (int i=0; i<q[now].seats; i++) 
                    vst[q[now].x][q[now].y+i]=true;
                continue;
            }
            
            for (int i=1; i<=n; i++) 
                for (int j=1; j<=m; j++) 
                {
                    if(!vst[i][j] && curFeeling<feeling[i][j])
                    {
                        findSeats=true;
                        curFeeling=feeling[i][j];
                        q[now].x=i;
                        q[now].y=j;
                    }
                }
            
            if (findSeats) 
                vst[q[now].x][q[now].y]=true;
        }
        
        sort(q, q+que, cmp2);
        for (int i=0; i<que; i++) {
            if(q[i].x || q[i].y)
                printf("%d %d\n", q[i].x, q[i].y);
            else
                printf("%d\n",-1);
        }
    }
    return 0;
}

