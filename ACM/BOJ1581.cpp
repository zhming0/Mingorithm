#include <iostream>
#include<string>
using namespace std;
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int cases,pos;
	string target,s;
	string isWhole;
	cin>>cases;
	while (cases--) {
		getline(cin, s);
		getline(cin, s);
		cin>>target;
		cin>>isWhole;
		cin>>pos;
		if(isWhole=="N")
		{
			int found;
			found=s.find(target, pos);
			if(found==string::npos)
				cout << -1<<endl;
			else
				cout << found<<endl;
			continue;
		}
		if(isWhole=="Y")
		{
			int found;
			found=s.find(target, pos);
			while (found!=string::npos&&pos<s.length()) 
			{
				if (found==0&&s[found+target.length()]==' ') 
				{
					cout << found<<endl;
					break;
				}
				else if(s[found-1]==' '&&s[found+target.length()]==' ')
				{
					//cout << s.substr(42, 10)<<endl;
					cout << found<<endl;
					break;
				}
				else if(s[found-1]==' '&&(found+target.length())==s.length())
				{
					cout << found<<endl;
					break;
				}
				else if(found==0&&(found+target.length())==s.length())
				{
					cout << found<<endl;
					break;
				}
				else
				{
					pos++;
					found=s.find(target, pos);
				}
			}
			if(found==string::npos||pos>s.length())
			{
				cout << -1<<endl;
				continue;
			}
		}
	}
	
    return 0;
}
