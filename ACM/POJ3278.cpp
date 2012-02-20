#include <iostream>
#include<queue>
#include<cstring>
int vst[500010];
using namespace std;
int bfs(int from, int to)
{
	queue<int> que;
	que.push(from);
	vst[from] = 0;
	while (!que.empty()) {
		int cur = que.front();
		if (cur == to ) return vst[to];
		que.pop();
		if (!vst[cur+1] && cur + 1 <= to)
		{
			que.push(cur+1);
			vst[cur + 1] = vst[cur] + 1;
		}
		if (!vst[cur-1] && cur - 1 >= 0)
		{
			que.push(cur-1);
			vst[cur - 1] = vst[cur] + 1;
		}
		if (!vst[cur*2] && cur*2 <= to * 2) {
			que.push(cur*2);
			vst[cur*2] = vst[cur] + 1;
		}
	}
	return -1;
}
int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	memset(vst, 0, sizeof(vst));
	cout << bfs(n, k) << endl;
	return 0;
}