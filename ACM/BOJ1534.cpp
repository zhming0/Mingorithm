#include <iostream>
#include<string>
using namespace std;

int main (int argc, char * const argv[]) {
	int cases,i;
	cin>>cases;
	while (cases--) {
		string mine;
		int ans=0;
		int left=0,right=0;
		cin>>mine;
		int length=mine.length();
		for (i=0; i<length; i++) {
			if (mine[i]=='<') {
				left++;
			}else {
				if (left>=right+1) {
					ans++;
					left--;
				}
			}
		}
		cout << ans<<endl;
	}
    return 0;
}
