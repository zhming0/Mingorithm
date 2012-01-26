#include <iostream>
#include<queue>
#define	INF 0x7fffffff
using namespace std;

struct point{
	int x,y;
};
int n,m;
double mp;
int grid[100][100],totstep[100][100];
double leftmp[100][100];
bool isZoc[100][100];
point from,destin;
queue<point> q;
int main (int argc, char * const argv[]) {
	int cases,T=0;
	//freopen("backup.txt", "r", stdin);
	cin>>cases;
	while (cases--) {
		cin>>n>>m>>mp;
		int ans=INF;
		while (!q.empty()) q.pop();
		memset(isZoc, false, sizeof(isZoc));
		for (int i=0; i<n; i++) 
			for (int j=0; j<m; j++)
			{
				cin>>grid[i][j];
				if(grid[i][j]&8)
				{
					for (int h=-1; h<2; h++) 
						for (int k=-1; k<2; k++) {
							if(h==0&&k==0)continue;
							if(i%2==0&&h==1&&k==1)continue;
							if(i%2==0&&h==-1&&k==1)continue;
							if(i%2==1&&h==-1&&k==-1)continue;
							if(i%2==1&&h==1&&k==-1)continue;
							if(i+h>=n||i+h<0||j+k>=m||j+k<0)continue;
							isZoc[i+h][j+k]=true;
						}
				}
				totstep[i][j]=INF;
				leftmp[i][j]=0;
			}
		cin>>from.x>>from.y>>destin.x>>destin.y;
		leftmp[from.x][from.y]=mp;
		totstep[from.x][from.y]=1;
		q.push(from);
		while (!q.empty()) {
			point crt=q.front();
			q.pop();
			if(crt.x==destin.x&&crt.y==destin.y)
				ans=totstep[crt.x][crt.y]<ans?totstep[crt.x][crt.y]:ans;
			if(leftmp[crt.x][crt.y]==0){totstep[crt.x][crt.y]+=1;leftmp[crt.x][crt.y]=mp;}
			if(totstep[crt.x][crt.y]>ans)continue;
			for (int i=-1; i<2; i++) 
				for (int j=-1; j<2; j++) {
					if(i==0&&j==0)continue;
					if(crt.x%2==0&&i==1&&j==1)continue;
					if(crt.x%2==0&&i==-1&&j==1)continue;
					if(crt.x%2==1&&i==-1&&j==-1)continue;
					if(crt.x%2==1&&i==1&&j==-1)continue;
					if(crt.x+i>=n||crt.x+i<0||crt.y+j>=m||crt.y+j<0)continue;
					if((grid[crt.x+i][crt.y+j]&8)>0)continue;
					if(isZoc[crt.x][crt.y]&&isZoc[crt.x+i][crt.y+j])
					{
						if(totstep[crt.x][crt.y]<totstep[crt.x+i][crt.y+j])
						{
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}
					}
					else if((grid[crt.x+i][crt.y+j]&4)&&(grid[crt.x][crt.y]&4))
					{
						if(totstep[crt.x][crt.y]<totstep[crt.x+i][crt.y+j])
						{
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=leftmp[crt.x][crt.y]-0.25;
							leftmp[crt.x+i][crt.y+j]=(leftmp[crt.x+i][crt.y+j]>0)?leftmp[crt.x+i][crt.y+j]:0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}else if (totstep[crt.x][crt.y]==totstep[crt.x+i][crt.y+j]&&leftmp[crt.x+i][crt.y+j]<(leftmp[crt.x][crt.y]-0.25)) {
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=leftmp[crt.x][crt.y]-0.25;
							leftmp[crt.x+i][crt.y+j]=(leftmp[crt.x+i][crt.y+j]>0)?leftmp[crt.x+i][crt.y+j]:0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}
					}else if((i==0&&j==1&&(grid[crt.x+i][crt.y+j]&256))||
							 (i==0&&j==-1&&(grid[crt.x+i][crt.y+j]&32))||
							 (crt.x%2==0&&i==-1&&j==-1&&(grid[crt.x+i][crt.y+j]&64))||
							 (crt.x%2==0&&i==-1&&j==0)&&(grid[crt.x+i][crt.y+j]&128)||
							 (crt.x%2==0&&i==1&&j==-1&&(grid[crt.x+i][crt.y+j]&16))||
							 (crt.x%2==0&&i==1&&j==0&&(grid[crt.x+i][crt.y+j]&512))||
							 (crt.x%2==1&&i==-1&&j==0&&(grid[crt.x+i][crt.y+j]&64))||
							 (crt.x%2==1&&i==-1&&j==1&&(grid[crt.x+i][crt.y+j]&128))||
							 (crt.x%2==1&&i==1&&j==0&&(grid[crt.x+i][crt.y+j]&16))||
							 (crt.x%2==1&&i==1&&j==1&&(grid[crt.x+i][crt.y+j]&512)))
					{
						if(totstep[crt.x][crt.y]<totstep[crt.x+i][crt.y+j])
						{
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}
					}
					else if((grid[crt.x+i][crt.y+j]&1))
					{
						if(totstep[crt.x][crt.y]<totstep[crt.x+i][crt.y+j])
						{
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=leftmp[crt.x][crt.y]-1;
							leftmp[crt.x+i][crt.y+j]=(leftmp[crt.x+i][crt.y+j]>0)?leftmp[crt.x+i][crt.y+j]:0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}else if (totstep[crt.x][crt.y]==totstep[crt.x+i][crt.y+j]&&leftmp[crt.x+i][crt.y+j]<(leftmp[crt.x][crt.y]-1)) {
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=leftmp[crt.x][crt.y]-1;
							leftmp[crt.x+i][crt.y+j]=(leftmp[crt.x+i][crt.y+j]>0)?leftmp[crt.x+i][crt.y+j]:0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}
					}
					else if((grid[crt.x+i][crt.y+j]&2))
					{
						if(totstep[crt.x][crt.y]<totstep[crt.x+i][crt.y+j])
						{
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=leftmp[crt.x][crt.y]-2;
							leftmp[crt.x+i][crt.y+j]=(leftmp[crt.x+i][crt.y+j]>0)?leftmp[crt.x+i][crt.y+j]:0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}else if (totstep[crt.x][crt.y]==totstep[crt.x+i][crt.y+j]&&leftmp[crt.x+i][crt.y+j]<(leftmp[crt.x][crt.y]-2)) {
							totstep[crt.x+i][crt.y+j]=totstep[crt.x][crt.y];
							leftmp[crt.x+i][crt.y+j]=leftmp[crt.x][crt.y]-2;
							leftmp[crt.x+i][crt.y+j]=(leftmp[crt.x+i][crt.y+j]>0)?leftmp[crt.x+i][crt.y+j]:0;
							point p;
							p.x=crt.x+i;p.y=crt.y+j;
							q.push(p);
						}
					}
				}
		}
		if(ans==INF)
			printf("Case %d: %d\n",++T,-1);
		else
			printf("Case %d: %d\n",++T,ans);
	}
    return 0;
}
