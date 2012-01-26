#include<stdio.h>
#include<string.h>
int queue[1000000];
bool reachable[101][101][101],isVisited[101][101][101],flag;
int grid[101][101][101];
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int x,y,z,n,i;
	int head,tail;
	int x1,y1,z1,x2,y2,z2,a,b,c;
	while (scanf("%d %d %d",&x,&y,&z)!=EOF) {
		memset(reachable, true, sizeof(reachable));
		memset(isVisited, false, sizeof(isVisited));
		memset(grid, 0, sizeof(grid));
		head=0;flag=false;tail=0;
		scanf("%d %d %d",&x1,&y1,&z1);
		scanf("%d %d %d",&x2,&y2,&z2);
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			scanf("%d %d %d",&a,&b,&c);
			reachable[a][b][c]=false;
		}
		queue[tail++]=x1*10000+y1*100+z1;
		while (tail>head) {
			int temp=queue[head++];
			a=temp/10000;b=(temp%10000)/100;
			c=temp%100;
			if(a==x2&&b==y2&&c==z2)
			{
				flag=true;
				break;
			}
			if(a-1>=0)
			if(a-1>=0&&!isVisited[a-1][b][c]&&reachable[a-1][b][c])
			{
				grid[a-1][b][c]=grid[a][b][c]+1;
				isVisited[a-1][b][c]=true;
				queue[tail++]=(a-1)*10000+b*100+c;
			}
			if(a+1<x&&!isVisited[a+1][b][c]&&reachable[a+1][b][c])
			{
				grid[a+1][b][c]=grid[a][b][c]+1;
				isVisited[a+1][b][c]=true;
				queue[tail++]=(a+1)*10000+b*100+c;
			}
			if(b-1>=0)
			if(b-1>=0&&!isVisited[a][b-1][c]&&reachable[a][b-1][c])
			{
				grid[a][b-1][c]=grid[a][b][c]+1;
				isVisited[a][b-1][c]=true;
				queue[tail++]=a*10000+(b-1)*100+c;
			}
			if(b+1<y&&!isVisited[a][b+1][c]&&reachable[a][b+1][c])
			{
				grid[a][b+1][c]=grid[a][b][c]+1;
				isVisited[a][b+1][c]=true;
				queue[tail++]=a*10000+(b+1)*100+c;
			}
			if(c-1>=0)
			if(c-1>=0&&!isVisited[a][b][c-1]&&reachable[a][b][c-1])
			{
				grid[a][b][c-1]=grid[a][b][c]+1;
				isVisited[a][b][c-1]=true;
				queue[tail++]=a*10000+b*100+c-1;
			}
			if(c+1<z&&!isVisited[a][b][c+1]&&reachable[a][b][c+1])
			{
				grid[a][b][c+1]=grid[a][b][c]+1;
				isVisited[a][b][c+1]=true;
				queue[tail++]=a*10000+b*100+c+1;
			}
		}
		if(flag)
			printf("%d\n",grid[x2][y2][z2]);
		else
			printf("-1\n");
	}
    return 0;
}
