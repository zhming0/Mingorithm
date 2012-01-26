//
//  main.cpp
//  POJ1151
//
//  Created by  on 11-10-2.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Seg{
    double l,r,h;
    int type;
    bool operator < (const Seg& a)const {
       return h<a.h;
    }
}seg[1000<<2];
int tot;
double length[1000<<2];
int cnt[1000<<2];
vector<double> x;
void addSeg(double a,double b,double h, int type){
    seg[tot].l=a;seg[tot].r=b;seg[tot].h=h;
    seg[tot++].type=type;
}
void PushUp(int l,int r,int rt)
{
    if (cnt[rt]) {
        //printf("cnt=%d,r=%d,l=%d\n",cnt[rt],r,l);
        length[rt]=x[r+1]-x[l];
    }else if(l==r){
        length[rt]=0;
    }else{
        length[rt]=length[rt<<1]+length[rt<<1|1];
    }
}
void update(int L,int R,int type,int l,int r,int rt)
{
    if (L<=l&&r<=R) {
        cnt[rt]+=type;
        PushUp(l, r, rt);
        return;
    }
    int m=(l+r)>>1;
    if (L<=m) update(L, R, type, l, m, rt<<1);
    if (R>m) update(L, R, type, m+1, r, rt<<1|1);
    PushUp(l, r, rt);
}
int main (int argc, const char * argv[])
{
    int n,T=0;
    while (~scanf("%d",&n)&&n) {
        tot=0;
        memset(cnt, 0, sizeof(cnt));
        memset(length, 0, sizeof((length)));
        for (int i=0; i<n; i++) {
            double x1,y1,x2,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            x.push_back(x1);
            addSeg(x1, x2, y1, 1);
            x.push_back(x2);
            addSeg(x1, x2, y2, -1);
        }
        sort(x.begin(), x.end());
        sort(seg, seg+tot);
        vector<double>::iterator it=unique(x.begin(), x.end());
        x.resize(it-x.begin());
        //printf("size=%d\n",x.size());
        double ret=0;
        for (int i=0; i<tot-1; i++) {
            int l=(lower_bound(x.begin(), x.end(), seg[i].l)-x.begin());
            int r=(lower_bound(x.begin(), x.end(), seg[i].r)-x.begin())-1;
            //printf("l=%d,r=%d,x[l]=%f,x[r]=%f\n",l,r,x[l],x[r]);
            update(l, r, seg[i].type, 0, x.size()-1, 1);
            //printf("length[1]=%f\n",length[1]);
            //printf("Increment=%f\n",length[1]*(seg[i+1].h-seg[i].h));
            ret+=length[1]*(seg[i+1].h-seg[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++T , ret);
    }
    return 0;
}

