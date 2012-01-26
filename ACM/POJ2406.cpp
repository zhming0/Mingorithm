#include <iostream>
#include<string>

#define MAX 1000000

using namespace std;

bool compare(const string word,const string text,int times)
{
	int i;
	int len=word.length();
	for (i=0; i<times; i++) 
	{
		if (word!=text.substr(i*len, len)) {
			return false;
		}
	}
	return true;
}

int main (int argc, char * const argv[]) {
	string text;
	int i;
	while (cin>>text) {
		if (text[0]=='.') {
			break;
		}
		int len=text.length();
		string word;
		for (i=1; i<=len; i++) 
		{
			if (len%i!=0) 
				continue;
			word=text.substr(0, i);
			if (compare(word,text,len/i)) 
			{
				cout << len/i<<endl;
				break;
			}
		}
	}
    return 0;
}
