#include<cstring>
#include<cstdio>
#include <iostream>
#include<queue>
using namespace std;
struct edge{
    int to, w, last;
}e[10010000];
int head[100100], cnt;
bool inqueue[100100];
int dist[100010], pre[100100];
int n, source, m, cap, L;
static void addEdge(int from, int to, int weight){
    e[cnt].to=to;
    e[cnt].w=weight;
    e[cnt].last=head[from];
    head[from]=cnt++;
}
static void spfa() 
{
	queue<int> que;
	que.push(source);
    dist[source] = 0;
	while (!que.empty()) 
	{
		int current=que.front();
		que.pop();
		inqueue[current]=false;
		for(int i=head[current]; i!=-1; i=e[i].last){
			if(dist[e[i].to] > dist[current]+e[i].w)
			{
				dist[e[i].to] = dist[current]+e[i].w;
                pre[e[i].to] = current;
				if(!inqueue[e[i].to]){
					que.push(e[i].to);
					inqueue[e[i].to]=true;
				}
			}
		}
	}
}
int main (int argc, const char * argv[])
{
    cnt=0;
    int ret=0;
    cin >> n >> m >> cap;
    memset(head, -1, sizeof(head));
    memset(inqueue, false, sizeof(inqueue));
    for(int i=0; i<n; i++) dist[i] = 0x7fffffff;
    memset(pre, -1, sizeof(pre));
    source = cap - 1;
    for (int i=0; i < m; i++)
    {
        int from, to, len;
        cin >> from >> to >> len;
        addEdge(from-1, to-1, len);
        addEdge(to-1, from-1, len);
    }
    cin >> L;
    if (L == 0) {cout << 1<<endl; return 0;}
    spfa();
    int tmp = 0;
    for(int i=0; i<n; i++) {
        if (dist[i]==L) {
            ret++;
            continue;
        }
        if (dist[i] > L)
            continue;
        int diff = L - dist[i];
        
        for (int j = head[i]; j!=-1; j=e[j].last)
        {
            int d = e[j].w;
            if ( d == diff*2 && dist[i]==dist[e[j].to]) {
                ret++;
                tmp++;
            }
            if (dist[i]+diff < dist[e[j].to]+e[j].w-diff)
                ret++;
        }
    }
    ret -= tmp/2;
    cout << ret << endl;
    return 0;
}

