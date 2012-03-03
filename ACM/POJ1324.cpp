#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
int maxstep, minstep;
int status[22][22][(1<<14)-1+10];
int grid[22][22], initgrid[22][22];
int n, m, l, k;
int currentstatus;
int tx, ty, lx, ly, hx, hy;
int M;
bool vst[22][22], tmp_grid[22][22];
int step[22][22];
int repr(int x1, int y1, int x2, int y2)
{
    if (x1 < x2) return 0; // right
    if (x1 > x2) return 1; // left
    if (y1 < y2) return 2; // up
    if (y1 > y2) return 3; //down
    while(1);
    return -1;
}
int bfs(int mode) // 0 ignore tail, 1 fixed tail, 2 dynamic tail
{
    int cur;
    queue<int> que;
    if (mode!=2) {
        que.push(hx*20 + hy);
        memset(step, 0, sizeof(step));
        memset(vst, false, sizeof(vst));
        vst[hx][hy] = true;
    }else
        que.push(currentstatus);
    while(!que.empty())
    {
        if (mode!=2) {
            tx = que.front()/20;
            ty = que.front()%20;
        } else {
            cur = que.front()/400;
            tx = (que.front()%400)/20;
            ty = (que.front()%400)%20;
        }
        que.pop();

        if (mode==2)
        {
            memset(tmp_grid, false, sizeof(tmp_grid));
            tmp_grid[tx][ty] = true;
            int tmp_cur = cur;
            //printf("cur = %d\n", cur);
            lx = tx, ly = ty;
            for (int i=1; i<l; i++)
            {
                int tmp_status = tmp_cur % 4;
                tmp_cur >>= 2;
                //printf("tmp_status = %d\n", tmp_status);
                if (tmp_status == 0)
                    tmp_grid[--lx][ly] = true;
                else if (tmp_status == 1)
                    tmp_grid[++lx][ly] = true;
                else if (tmp_status == 2)
                    tmp_grid[lx][--ly] = true;
                else if (tmp_status == 3)
                    tmp_grid[lx][++ly] = true;
                //cout << lx <<" "<< ly << endl;
            }
        }

        for (int i=-1; i<=1; i++)
            for (int j = -1; j<=1 ;j++)
            {
                if ((int)abs((double)i) == (int)abs((double)j) ) continue;
                int nx = tx+i, ny = ty+j;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (grid[nx][ny]==true || (mode==1 && initgrid[nx][ny])) continue;
                if (mode != 2 && !vst[nx][ny])
                {
                    que.push(nx*20 + ny);
                    step[nx][ny] = step[tx][ty] + 1;
                    if (nx == 0 && ny == 0) return step[nx][ny];
                    vst[nx][ny] = true;
                    continue;
                }
                if (mode!=2) continue;

                if (tmp_grid[nx][ny] == true) continue;
                int newcur = (cur<<2)%M + repr(tx, ty, nx, ny);
                if (status[nx][ny][newcur] >= 0) continue;
                status[nx][ny][newcur] = status[tx][ty][cur] + 1;
                if (nx ==0 && ny == 0) return status[nx][ny][newcur];
                if ((int)abs((double)nx) + (int) abs((double)ny) + status[nx][ny][newcur] > maxstep) continue;
                que.push(newcur*400 + nx * 20 + ny);
            }
    }
    return -1;
}
int main()
{
    //freopen("/home/ming/Desktop/input", "r", stdin);
    int T = 0;
    while(~scanf("%d %d %d", &n, &m, &l) && (n||m||l))
    {
        printf("Case %d: ", ++T);
        M = (1<< (2*l-2));
        scanf("%d %d", &hx, &hy);
        memset(grid, false, sizeof(grid));
        memset(initgrid, false, sizeof(initgrid));
        memset(status, -1, sizeof(status));
        lx = --hx, ly = --hy;
        initgrid[lx][ly] = true;
        currentstatus = 0;
        for (int i=1; i<l; i++)
        {
            scanf("%d %d", &tx, &ty);
            currentstatus += (repr(tx-1, ty-1, lx, ly) << (2*i-2));
            lx = tx-1, ly = ty-1;
            initgrid[lx][ly] = true;
        }
        status[hx][hy][currentstatus] = 0;
        currentstatus = currentstatus * 400 + hx * 20 + hy;
        scanf("%d", &k);
        for (int i=0; i<k; i++)
        {
            scanf("%d %d", &tx, &ty);
            initgrid[tx-1][ty-1] = grid[tx-1][ty-1] = true;
        }
        if (hx == 0 && hy == 0) {printf("0\n");continue;}
        minstep = bfs(0);
        if (minstep == -1)
        {
            printf("%d\n", -1);
            continue;
        }
        maxstep = bfs(1);
        //printf("maxstep = %d\n", maxstep);
        if (minstep == maxstep)
        {
            printf("%d\n", maxstep);
            continue;
        }
        if (maxstep == -1) maxstep = 200000000;
        printf("%d\n", bfs(2));
    }
    return 0;
}
