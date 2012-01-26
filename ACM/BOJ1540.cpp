#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main (int argc, char * const argv[]) {
	int cases;
	cin>>cases;
	while (cases--) {
		string inst;
		int i;
		int x=0,y=0;
		cin>>inst;
		for (i=0; i<inst.length(); i++) {
			if (inst[i]=='E') {
				x++;
			}
			if (inst[i]=='W') {
				x--;
			}
			if (inst[i]=='N') {
				y++;
			}
			if (inst[i]=='S') {
				y--;
			}
		}
		if (x>0) {
			for (i=0; i<abs(x); i++) {
				cout << 'E';
			}
		}
		if (y<0) {
			for (i=0; i<abs(y); i++) {
				cout << 'S';
			}
		}
		if (y>0) {
			for (i=0; i<abs(y); i++) {
				cout << 'N';
			}
		}
		if (x<0) {
			for (i=0; i<abs(x); i++) {
				cout << 'W';
			}
		}
		cout << endl;
	}

    return 0;
}
