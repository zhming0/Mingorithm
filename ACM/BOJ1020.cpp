#include <iostream>
#include<string>
using namespace std;
bool isInitial(char c)
{
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'v':
			return false;
		default:
			return true;
	}
}
bool isSpecial(char c)
{
	switch (c) {
		case 'c':
		case 's':
		case 'z':
			return true;
		default:
			return false;
	}
}
int main (int argc, char * const argv[]) {
	int cases,i,state;
	cin>>cases;
	while (cases--) {
		string s;
		cin>>s;
		bool isIni[s.length()];
		state=0;
		for (i=0; i<s.length(); i++) {
			if (state==0) {
				if (isInitial(s[i])) 
				{
					isIni[i]=true;
					if(isSpecial(s[i]))
						state=2;
					else
						state=1;
				}
				else
				{
					isIni[i]=true;
					state=3;
				}
			}else if (state==1) {
				isIni[i]=false;
				if ((s[i]-'a')>('z'-'a')||(s[i]-'a')<0) 
				{
					isIni[i]=true;
					state=0;
				}
			}else if(state==2){
				if(s[i]=='h')
					isIni[i]=true;
				else
				{
					i--;
					state=1;
				}
			}else {
				isIni[i]=true;
				if ((s[i]-'a')>('z'-'a')||(s[i]-'a')<0) 
					state=0;
			}

		}
		for (i=0; i<s.length(); i++)
			if (isIni[i]) 
				cout << s[i];
		cout << endl;
	}
    return 0;
}
