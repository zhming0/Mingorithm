#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int arrive[100100], dp[100100];
int que[100100],front, tail, e[100100];
int sump[110][100100], suml[110][100100];
int n,m,k;
static void append_que(int row, int col, int mode)
{
    int tmp=arrive[col]+mode*sump[row][col];
    while (tail>front&&e[tail-1]<tmp) 
        tail--;
    que[tail]=col;
    e[tail++]=tmp;
}
int main (int argc, const char * argv[])
{
    int tmp;
    while (~scanf("%d %d %d", &n, &m, &k)&&(n||m||k)) {
        for (int i=0; i<=n; i++){
            sump[i][0]=0;
            for (int j=0; j<m; j++) {
                scanf("%d", &tmp);
                sump[i][j+1]=sump[i][j]+tmp;
            }
        }
        for (int i=0; i<=n; i++) {
            suml[i][0]=0;
            for (int j=0; j<m; j++) 
            {
                scanf("%d",&tmp);
                suml[i][j+1]=suml[i][j]+tmp;
            }
        }
        front=tail=0;
        for (int i=0; i<=m; i++) arrive[i]=0;
        for (int i=0; i<=n; i++) 
        {
            front=tail=0;
            for (int j=0; j<=m; j++) 
            {
                dp[j]=-100000000;
                while (tail>front && suml[i][j]-suml[i][que[front]]>k) front++;
                append_que(i, j, -1);
                dp[j]=max(dp[j], e[front]+sump[i][j]);
            }
            front=tail=0;
            for (int j=m; j>=0; j--) 
            {
                while (tail>front&&(suml[i][que[front]]-suml[i][j])>k) front++;
                append_que(i, j, 1);
                dp[j]=max(dp[j], e[front]-sump[i][j]);
            }
            for (int i=0; i<=m; i++) 
                arrive[i]=dp[i];
        }
        int ret=-100000000;
        for (int i=0; i<=m; i++) 
            ret=max(ret, dp[i]);
        printf("%d\n", ret);
    }
    return 0;
}

