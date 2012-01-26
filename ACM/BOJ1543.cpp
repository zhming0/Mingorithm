#include <iostream>
#include<string>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i,n,ans;
	cin>>cases;
	while (cases--) {
		ans=0;
		i=0;
		cin>>n;
		string doc,word;
		while (n--) {
			string temp;
			cin>>temp;
			doc+=' ';
			doc+=temp;
		}
		cin>>word;
		int lengh_word=word.length();
		while (i<(doc.length()-word.length())) {
			if (doc.substr(i, lengh_word)==word) {
				ans++;
				i+=lengh_word;
			}else {
				i++;
			}
		}
		cout << ans<<endl;
	}
    return 0;
}
