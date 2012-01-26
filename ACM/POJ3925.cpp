#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int grid[20][20], weight[20];
int node[20], result[20], dist[20];
bool visited[20];
double ratio;
int n,m;
static void prim()
{
    int done=1, nodeweight=0, edgeweight=0;
    double tmpRatio;
    for (int i=0; i<m; i++) {
        visited[i]=false;
        dist[i]=INF;
    }
    dist[0]=0;
    visited[0]=true;
    nodeweight+=weight[node[0]];
    for (int i=1; i<m; i++) 
        if (grid[node[0]][node[i]]<dist[i]) 
            dist[i]=grid[node[0]][node[i]];
    while (done<m) {
        int minl=INF, minnode;
        for (int i=0; i<m; i++) 
            if (!visited[i] && minl>dist[i] ) {
                minl=dist[i];
                minnode=i;
            }
        edgeweight+=minl;
        nodeweight+=weight[node[minnode]];
        done++;
        visited[minnode]=true;
        for (int i=0; i<m; i++) 
            if (dist[i]>grid[node[minnode]][node[i]]) 
                dist[i]=grid[node[minnode]][node[i]];
    }
    tmpRatio=(double)edgeweight/nodeweight;
    if (ratio-tmpRatio>0.0000001) {
        ratio=tmpRatio;
        for (int i=0; i<m; i++) 
            result[i]=node[i];
    }
}

static void selectNode(int num, int start)
{
    if (num==m) {
        prim();
        return;
    }
    
    for (int i=start; i<n; i++) {
        node[num]=i;
        selectNode(num+1, i+1);
    }
}

int main (int argc, const char * argv[])
{
    while (cin>>n>>m&&(n||m)) {
        ratio=INF;
        for (int i=0; i<n; i++) 
            cin>>weight[i];
        for (int i=0; i<n; i++) 
            for (int j=0; j<n; j++) 
                cin>>grid[i][j];
        selectNode(0, 0);
        sort(result, result+m);
        for (int i=0; i<m-1; i++) 
            printf("%d ", result[i]+1);
        printf("%d\n", result[m-1]+1);
    }
    return 0;
}

