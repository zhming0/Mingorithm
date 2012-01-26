#include<cstring>
#include<cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 201
struct Seg{
    double l, r, h;
    int dir;            // -1->low 1->high
    bool operator < (const Seg& a) const{
        return h < a.h || (h == a.h && dir < a.dir);
    }
}s[SIZE];
vector<double> x;
int cnt[SIZE << 2], n, tot;
double sum[SIZE << 2];
static void addSeg(double l, double r, double h, int dir){
    s[tot].l = l; s[tot].r = r;
    s[tot].h = h; s[tot++].dir = dir;
}

static void pushUp(int rt, int l, int r){
    if (cnt[rt] < 0) {
        sum[rt] = x[r+1] - x[l];
    }else if (l==r) //No son can be reached
        sum[rt] = 0.0f;
    else
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

static void update(int dir, int L, int R, int l, int r, int rt){
    if (L<=l && R>=r) {
        cnt[rt] += dir;
        pushUp(rt, l, r);
        return;
    }
    int m = (l+r) >> 1;
    if(L<=m) update(dir, L, R, l, m, rt<<1);
    if(R>m) update(dir, L, R, m+1, r, rt<<1|1);
    pushUp(rt, l, r);
}

int main (int argc, const char * argv[])
{
    int t = 1;
    while (~scanf("%d", &n) && n) {
        tot = 0;
        for (int i=0; i<n; i++) {
            double x1, y1, x2, y2;
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            x.push_back(x1);
            x.push_back(x2);
            addSeg(x1, x2, y1, -1);
            addSeg(x1, x2, y2, 1);
        }
        sort(x.begin(), x.end());
        sort(s, s+tot);
        vector<double>::iterator it = unique(x.begin(), x.end());
        x.resize(it-x.begin());
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        double ret = 0;
        for (int i=0; i<tot-1; i++) {
            int l = (int)(lower_bound(x.begin(), x.end(), s[i].l) - x.begin());
            int r = (int)(lower_bound(x.begin(), x.end(), s[i].r) - x.begin())-1;
            update(s[i].dir, l, r, 0, (int)x.size()-1, 1);
            ret += sum[1] * (s[i+1].h - s[i].h);
        }
        printf("Test case #%d\n", t++);
        printf("Total explored area: %.2f\n\n", ret);
    }
    return 0;
}

