#include <iostream>
#include<string>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases;
	int sum,i,j;
	cin>>cases;
	while (cases--) {
		sum=0;
		string a,b,l;
		int n1,n2;
		cin>>a>>b>>l;
		for (i=0; i<l.length(); i++) {
			n1=0;n2=0;
			for (j=0; j<a.length(); j++) {
				if (a[j]==l[i]||a[j]==l[i]-'a'+'A') {
					n1++;
				}
			}
			for (j=0; j<b.length(); j++) {
				if (b[j]==l[i]||b[j]==l[i]-'a'+'A') {
					n2++;
				}
			}
			sum+=((n1-n2)*(n1-n2));
		}
		cout << sum<<endl;
	}
    return 0;
}
