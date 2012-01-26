#include <iostream>
using namespace std;
int grid[4][4];
int main (int argc, char * const argv[]) {
	int ans=0;
	//memset(handle, false, sizeof(handle));
	memset(grid, 0, sizeof(grid));
	int i,j;
	int k;
	for (i=0; i<4; i++) 
		for (j=0; j<4; j++) {
			char temp;
			cin>>temp;
			if (temp=='+') {
				for (k=0;k<4 ; k++) 
					grid[i][k]++;
				for(k=0;k<4;k+=1)
					grid[k][j]++;
				grid[i][j]--;
			}
		}
	for (i=0; i<4; i++) 
		for (j=0; j<4; j++) 
			if (grid[i][j]%2==1) 
				ans++;
	printf("%d\n",ans);
	for (i=0; i<4; i++) 
		for (j=0; j<4; j++) 
			if (grid[i][j]%2==1) 
				printf("%d %d\n",i+1,j+1);
    return 0;
}
