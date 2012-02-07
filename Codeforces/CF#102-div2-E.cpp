#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int n, m, map[9][9], ret, space;
char retmap[9][9];
int dx[4][5] = {{0,0,0,1,2}, {0,1,2,1,1},{2,2,2,1,0}, {0,1,2,1,1}};
int dy[4][5] = {{0,1,2,1,1}, {0,0,0,1,2},{0,1,2,1,1}, {2,2,2,1,0}};
void updateret()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            retmap[i][j] = (map[i][j]==-1 ? '.' : 'A'+map[i][j]);
}
void dfs(int x, int y, int num){
    if(x>=n-2){
        if (num>ret) {
            ret = num;
            updateret();
        }
        return;
    }
    if (y>=m-2) {
        dfs(x+1, 0, num);
        return;
    }
    if (space/5 + num <= ret)
        return;
    space -= (map[x][y] == -1?1:0);
    for(int i=0; i<4; i++) {
        bool flag = true;
        for (int j=0; j<5 ;j++)
            if (map[x+dx[i][j]][y+dy[i][j]]>=0)
                flag = false;
        if (flag) {
            for(int j =0; j<5; j++)
                map[x+dx[i][j]][y+dy[i][j]] = num;
            space -= 5;
            dfs(x, y+1, num+1);
            space += 5;
            for(int j =0; j<5; j++)
                map[x+dx[i][j]][y+dy[i][j]] = -1;
        }
    }
    dfs(x, y+1, num);
    space += (map[x][y] == -1?1:0);
}
void printret(){
    printf("%d\n", ret);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%c", retmap[i][j]);
            if (j==m-1) printf("\n");
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    ret = 0; space = n*m;
    memset(map, -1, sizeof(map));
    if (n<3 || m<3)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                retmap[i][j] = '.';
    dfs(0, 0, 0);
    printret();
    return 0;
}
