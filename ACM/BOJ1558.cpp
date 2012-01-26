#include <iostream>
#include<string>
using namespace std;
int main (int argc, char * const argv[]) {
	int n,i,cases;
	cin>>cases;
	string swap;
	int current;
	while (cases--) {
		cin>>n;
		current=1;
		for (i=0; i<n; i++) 
		{
			cin>>swap;
			if((swap[0]-'0')==current)
				current=swap[2]-'0';
			else if((swap[2]-'0')==current)
				current=swap[0]-'0';
		}
		cout << current<<endl;
	}
    return 0;
}
