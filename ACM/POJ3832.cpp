#include<cstring>
#include<cstdio>
#include <iostream>
#include<algorithm>
#define UP 1
#define DOWN -1
#define SIZE 55555
using namespace std;
struct Seg{
    int l, r, h;
    int dir;
    bool operator < (const Seg& b) const{
        return h<b.h ||(h==b.h && dir<b.dir);
    }
}s[400010];
int tot;
int sum[SIZE<<2], cnt[SIZE<<2];
static void addSeg(int l, int r, int h, int dir)
{
    s[tot].l=l;
    s[tot].r=r;
    s[tot].h=h;
    s[tot++].dir=dir;
}
static void cutRect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    if (x3>x1) {
        addSeg(x1, x3, y1, DOWN);
        addSeg(x1, x3, y2, UP);
    }
    if (x2>x4) {
        addSeg(x4, x2, y1, DOWN);
        addSeg(x4, x2, y2, UP);
    }
    if (y3>y1) {
        addSeg(x3, x4, y1, DOWN);
        addSeg(x3, x4, y3, UP);
    }
    if (y4<y2) {
        addSeg(x3, x4, y4, DOWN);
        addSeg(x3, x4, y2, UP);
    }
}
static void PushUp(int rt, int l, int r)
{
    if (cnt[rt]<0) 
        sum[rt]=r+1-l;
    else if (l==r)
        sum[rt]=0;
    else
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
static void update(int dir, int L, int R, int l, int r, int rt)
{
    if (L<=l && R>=r) {
        cnt[rt]+=dir;
        PushUp(rt, l, r);
        return;
    }
    int m=(l+r)>>1;
    if (L<=m) update(dir, L, R, l, m, rt<<1);
    if (R>m) update(dir, L, R, m+1, r, rt<<1|1);
    PushUp(rt, l, r);
}
int main (int argc, const char * argv[])
{
    int n;
    while (~scanf("%d",&n)&&n) {
        tot=0;
        for (int i=0; i<n; i++) {
            int x1,y1,x2,y2;
            int x3,y3,x4,y4;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
            cutRect(x1, y1, x2, y2, x3, y3, x4, y4);
        }
        sort(s, s+tot);
        unsigned int ret=0;
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        for (int i=0; i<tot-1; i++) {
            update(s[i].dir, s[i].l, s[i].r-1, 0, 50000, 1);
            ret+=(sum[1]*(s[i+1].h-s[i].h));
        }
        printf("%u\n",ret);
    }
    return 0;
}

