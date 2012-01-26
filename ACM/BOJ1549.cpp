#include <iostream>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i,max;
	int num[10];
	cin>>cases;
	while (cases--) {
		int roomNum;
		max=0;
		memset(num, 0, sizeof(num));
		cin>>roomNum;
		while (roomNum!=0) {
			int temp=roomNum%10;
			roomNum/=10;
			num[temp]++;
		}
		for (i=0; i<9; i++) {
			if(i==6)
			{
				int temp=num[6]+num[9];
				if ((temp)%2==0) {
					max=max<(temp/2)?(temp/2):max;
				}else {
					max=max<(temp/2+1)?(temp/2+1):max;
				}
			}else
				max=max<num[i]?num[i]:max;
		}
		cout << max<<endl;
	}
    return 0;
}
