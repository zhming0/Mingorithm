#include <iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;
#define MAX 210
#define fee(m, h) (abs(m.x-h.x)+abs(m.y-h.y))
#define S 2*MAX + 1
#define T 2*MAX + 2
#define SIZE 2*MAX + 10
#define INF 0x7fffffff
struct Pint{
	int x, y;
};
struct Edge{
	int to, last;
}e[40010];
int n, m;
int head[SIZE], cnt;
int pre[SIZE];
int cost[SIZE][SIZE], cap[SIZE][SIZE];
vector<Pint> man, house;
void addEdge(int from, int to)
{
	e[cnt].to = to;
	e[cnt].last = head[from];
	head[from] = cnt++;
}

bool spfa()
{
	int dist[SIZE];
	bool inqueue[SIZE];
	for (int i=0; i<SIZE; i++) dist[i] = 0x7fffffff;
	memset(inqueue, false, sizeof(inqueue));
	queue<int> que;
	dist[S] = 0;
	que.push(S);
	while(!que.empty())
	{
		int current = que.front();
		que.pop();
		inqueue[current] = false;
		for (int i= head[current]; i!=-1; i = e[i].last)
		{
			if (cap[current][e[i].to] && dist[e[i].to] > dist[current]+cost[current][e[i].to])
			{
				dist[e[i].to] = dist[current] + cost[current][e[i].to];
				pre[e[i].to] = current;
				if (!inqueue[e[i].to]){
					que.push(e[i].to);
					inqueue[e[i].to] = true;
				}
			}
		}
	}
	if (dist[T]!=INF) return true;
	return false;
}

int maxflow()
{
	int ret = 0;
	while(spfa())
	{
		int tmp_min = INF;
		for (int i = T; i!=S; i=pre[i])
			tmp_min = min(tmp_min, cap[pre[i]][i]);
		for (int i=T; i!=S; i=pre[i])
		{
			cap[pre[i]][i] -= tmp_min;
			cap[i][pre[i]] += tmp_min;
			ret += cost[pre[i]][i] * tmp_min;
		}
	}
	return ret;
}

int main (int argc, const char * argv[])
{
	while (~scanf("%d %d", &n, &m) && (n || m))
	{
		man.clear();
		house.clear();
		char tmp;
		scanf("%c", &tmp);
		int x=0, y=0;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				scanf("%c", &tmp);
				if (tmp == 'H')
				{
					x++;
					Pint newPoint;
					newPoint.x = i;
					newPoint.y = j;
					house.push_back(newPoint);
				}
				if (tmp == 'm')
				{
					y++;
					Pint newPoint;
					newPoint.x = i;
					newPoint.y = j;
					man.push_back(newPoint);
				}
			}
			scanf("%c", &tmp);
		}
		memset(head, -1, sizeof(head));
		cnt = 0;
		//printf("man = %d, house = %d\n", y, x);
		for (int i=0; i<man.size(); i++){
			addEdge(S, i);
			cost[S][i] = 0; cap[S][i] = 1;
			addEdge(i, S);
			cost[i][S] = 0; cap[i][S] = 0;
			for (int j=0; j < house.size(); j++)
			{
				addEdge(i, j+MAX);
				cost[i][j+MAX] = fee(man[i], house[j]);
				cap[i][j+MAX] = 1;
				addEdge(j+MAX, i);
				cost[j+MAX][i] = -cost[i][j+MAX];
				cap[j+MAX][i] = 0;
			}
		}
		for (int i=0; i<house.size(); i++){
			addEdge(T, i+MAX);
			cost[T][i+MAX] = 0; cap[T][i+MAX] = 0;
			addEdge(i+MAX, T);
			cost[i+MAX][T] = 0; cap[i+MAX][T] = 1;
		}
		
		printf("%d\n", maxflow());
	}
	return 0;
}

