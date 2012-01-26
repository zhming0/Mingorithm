#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 99999999
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i,j;
	cin>>cases;
	while (cases--) {
		int ans=MAX;
		string trail;
		cin>>trail;
		int length=trail.length();
		int n;
		cin>>n;
		string plan[n];
		for (i=0; i<n; i++) {
			cin>>plan[i];
		}
		for (i=0; i<n; i++) {
			int temp=0;
			for (j=0; j<length; j++) {
				if (plan[i][j]=='C'&&(trail[j]=='.')) {
					temp++;
				}
				if (plan[i][j]=='C'&&trail[j]=='^') {
					temp=-1;
					break;
				}
			}
			if (temp>=0) {
				ans=(ans<temp)?ans:temp;
			}
		}
		
		if (ans==MAX) {
			cout << -1<<endl;
		}else {
			cout << ans<<endl;
		}

		
	}
	
    return 0;
}
