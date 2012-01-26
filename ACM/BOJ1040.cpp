#include <iostream>
#include<string>
using namespace std;
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	string forward[101],back[101],current,command;
	int fhead=0,bhead=0;
	current="http://www.acm.org/";
	while (cin>>command) {
		if (command=="VISIT") {
			back[bhead++]=current;
			cin>>current;
			fhead=0;
			cout << current<<endl;
		}
		if (command=="BACK") 
		{
			if(bhead==0)
			{
				cout << "Ignored"<<endl;
				continue;
			}
			forward[fhead++]=current;
			current=back[--bhead];
			cout << current<<endl;
		}
		if(command=="FORWARD")
		{
			if(fhead==0)
			{
				cout << "Ignored"<<endl;
				continue;
			}
			back[bhead++]=current;
			current=forward[--fhead];
			cout << current<<endl;
		}
		if (command=="QUIT") 
			break;
	}
    return 0;
}
