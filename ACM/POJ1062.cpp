//
//  main.cpp
//  POJ1062
//
//  Created by  on 11-10-3.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define INF 1<<29
using namespace std;
struct stuff{
    int value,level;
}s[200];
struct edge{
    int to, last, value;
}e[20000];
int head[200],dist[200],cnt;
int m,n;
queue<int> q;
void addEdge(int from, int to, int value)
{
    e[cnt].value = value;
    e[cnt].to = to;
    e[cnt].last = head[from];
    head[from] = cnt++;
}
int spfa(int lowbound)
{
    int ret=INF;
    for (int i=1; i<=n; i++) dist[i]=INF;
    dist[1]=0;
    while (!q.empty()) q.pop();
    q.push(1);
    bool flag[200];
    memset(flag, false, sizeof(flag));
    while (!q.empty()) {
        int current=q.front();
        q.pop();
        flag[current]=false;
        int i=head[current];
        while (i!=-1) {
            int to=e[i].to;
            int cost=e[i].value;
            int level1=s[to].level;
            if (level1>=lowbound && level1<=lowbound+m && dist[to]>dist[current]+cost) {
                dist[to]=dist[current]+cost;
                if (!flag[to]) {
                    q.push(to);
                    flag[to]=true;
                }
            }
            i=e[i].last;
        }
    }
    for (int i=1; i<=n; i++) {
        dist[i]+=s[i].value;
        ret=min(ret, dist[i]);
    }
    return ret;
}
int main (int argc, const char * argv[])
{
    while (~scanf("%d%d",&m,&n)) {
        memset(head, -1, sizeof(head));
        cnt=0;
        for (int i=1; i<=n; i++) {
            int tmp;
            scanf("%d %d %d", &s[i].value, &s[i].level, &tmp);
            for (int j=0; j<tmp; j++) {
                int v,t;
                scanf("%d %d",&t,&v);
                addEdge(i, t, v);
            }
        }
        int ret=INF;
        for (int i=s[1].level-m; i<=s[1].level; i++) {
            ret=min(ret, spfa(i));
        }
        printf("%d\n",ret);
    }
    return 0;
}

