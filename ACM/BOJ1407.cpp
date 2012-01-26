#include <iostream>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases;
	int queue[50000],head,tail;
	int grid[300][300];
	bool isVisited[300][300],flag;
	cin>>cases;
	while (cases--) {
		int x1,y1,x2,y2,l;
		cin>>l>>x1>>y1>>x2>>y2;
		head=0;tail=0;flag=false;
		memset(grid,0,sizeof(grid));
		memset(isVisited, false, sizeof(isVisited));
		queue[tail++]=x1*1000+y1;
		while (tail>head) {
			int a,b;
			int temp=queue[head++];
			a=temp/1000;b=temp%1000;
			if(a==x2&&b==y2)
			{flag=true;break;}
			if((a+2)<l&&(b+1)<l&&!isVisited[a+2][b+1])
			{
				isVisited[a+2][b+1]=true;
				grid[a+2][b+1]=grid[a][b]+1;
				queue[tail++]=(a+2)*1000+(b+1);
			}
			if((a+2)<l&&(b-1)<l&&!isVisited[a+2][b-1])
			{
				isVisited[a+2][b-1]=true;
				grid[a+2][b-1]=grid[a][b]+1;
				queue[tail++]=(a+2)*1000+(b-1);
			}
			if((b+2)<l&&(a+1)<l&&!isVisited[a+1][b+2])
			{
				isVisited[a+1][b+2]=true;
				grid[a+1][b+2]=grid[a][b]+1;
				queue[tail++]=(a+1)*1000+(b+2);
			}
			if((a+1)<l&&(b-2)<l&&!isVisited[a+1][b-2])
			{
				isVisited[a+1][b-2]=true;
				grid[a+1][b-2]=grid[a][b]+1;
				queue[tail++]=(a+1)*1000+(b-2);
			}
			if((a-2)<l&&(b+1)<l&&!isVisited[a-2][b+1])
			{
				isVisited[a-2][b+1]=true;
				grid[a-2][b+1]=grid[a][b]+1;
				queue[tail++]=(a-2)*1000+(b+1);
			}
			if((a-2)<l&&(b-1)<l&&!isVisited[a-2][b-1])
			{
				isVisited[a-2][b-1]=true;
				grid[a-2][b-1]=grid[a][b]+1;
				queue[tail++]=(a-2)*1000+(b-1);
			}
			if((a-1)<l&&(b+2)<l&&!isVisited[a-1][b+2])
			{
				isVisited[a-1][b+2]=true;
				grid[a-1][b+2]=grid[a][b]+1;
				queue[tail++]=(a-1)*1000+(b+2);
			}
			if((a-1)<l&&(b-2)<l&&!isVisited[a-1][b-2])
			{
				isVisited[a-1][b-2]=true;
				grid[a-1][b-2]=grid[a][b]+1;
				queue[tail++]=(a-1)*1000+(b-2);
			}
		}
		cout << grid[x2][y2]<<endl;
	}
    return 0;
}
