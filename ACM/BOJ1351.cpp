#include <iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
string toString(int n)
{
	string ans;
	while (n!=0) {
		ans+=n%10+'0';
		n/=10;
	}
	return ans;
}
int process(string n)
{
	int ans=0,i;
	for (i=0; i<n.length(); i++) {
		ans+=n[i]-'0';
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	string n;
    while (cin>>n) {
		if(n.length()==1&&n[0]=='0')break;
		while (n.length()>1) {
			n=toString(process(n));
		}
		std::cout<<n<<endl;
	}
    return 0;
}
