#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<queue>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i,j;
	cin>>cases;
	while (cases--) {
		queue<int> v;
		int ans=0;
		bool flag=true;
		bool isCircle=false;
		int startPoint[200];
		int endPoint;
		bool grid[200][200];
		bool visited[200];
		memset(startPoint, 0, sizeof(startPoint));
		memset(grid, false, sizeof(grid));
		memset(visited, false, sizeof(visited));
		string temp;
		int k;
		cin>>k;
		for (i=0; i<k; i++) {
			cin>>temp;
			for (j=0; j<k; j++) 
				if (temp[j]=='1')
					grid[i][j]=true;
		}
		int p;
		cin>>p;
		for (i=0; i<p; i++) 
			cin>>startPoint[i];
		cin>>endPoint;
		int max;
		cin>>max;
		
		for (i=0; i<p; i++) 
		{
			v.push(startPoint[i]);
			memset(visited, false, sizeof(visited));
			visited[startPoint[i]]==true;
			while (!v.empty()) 
			{
				int now=v.front();
				v.pop();
				for (j=0; j<k; j++) {
					if (grid[now][j]==true&&visited[j]) {
						isCircle=true;
					}
					if (grid[now][j]==true&&!visited[j]) {
						if (j==endPoint) {
							ans++;
						}else{
							v.push(j);
							visited[j]==true;
						}
					}
				}
				if (ans>max||(isCircle&&ans>0)) {
					cout <<-1<<endl;
					flag=false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			cout << ans<<endl;
		}
	}
	
    return 0;
}
