#include<cstring>
#include <iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Edge{
    int to, cost, last;
}e[500];
int head[21], cnt;
int n, m;
int dist[21], price[21];
bool flag[21];
queue<int> que;
static void addEdge(int from, int to, int cost)
{
    e[cnt].to=to; e[cnt].cost=cost; e[cnt].last=head[from];
    head[from]=cnt++;
}
static void spfa()
{
    memset(flag, false, sizeof(flag));
	while (!que.empty()) que.pop();
	que.push(0);
	while (!que.empty()) 
	{
		int current=que.front();
		que.pop();
		flag[current]=false;
		int i=head[current];
		while (i!=-1)
		{
			int to=e[i].to;
			int cost=e[i].cost;
			if(dist[to]>(dist[current]+cost))
			{
				dist[to]=dist[current]+cost;
				if(!flag[to])
				{
					que.push(to);
					flag[to]=true;
				}
			}
			i=e[i].last;
		}
	}
}
int main (int argc, const char * argv[])
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        memset(head, -1, sizeof(head));
        cnt=0;
        for (int i=1; i<=n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(0, u, v-1);
            price[i]=v-1;
            dist[i]=1e9;
        }
        for (int i=1; i<=n; i++) 
            for (int j=1; j<=n; j++) 
                if (i!=j && price[i]==price[j]) {
                    addEdge(i, j, 0);
                    addEdge(j, i, 0);
                }
        
        scanf("%d", &m);
        while (m--) {
            int u, v, cost;
            scanf("%d %d %d", &u, &v, &cost);
            addEdge(u, v, cost);
        }
        dist[0]=0;
        spfa();
        for (int i=1; i<=n; i++) 
            printf("%d %d\n", i, dist[i]);
        int ret=0;
        for (int i=1; i<=n; i++) {
            bool ok=false;
            for (int j=1; j<=n; j++) 
            {
                if(ok) break;
                for (int k=1; k<=n; k++) 
                {
                    if ((j!=k && i!=k && j!=i) && dist[i]==dist[j]+dist[k]) {
                        ok=true;
                        break;
                    }
                }
            }
            if (ok) 
                ret++;
        }
        printf("%d\n", ret);
    }
    return 0;
}

