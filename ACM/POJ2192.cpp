#include <iostream>
#include<string>
#include<string.h>
using namespace std;
int length1,length2,length3;
string s1,s2,s3;
int isMatch[201][402];
bool dfs(int l1,int l2,int l3)
{
	if (l1==length1&&l2==length2) 
		return 1;
	if(l1<length1&&s1[l1]==s3[l3])
	{
		if (isMatch[l1][l3]==0) {
			if(dfs(l1+1,l2,l3+1))
			{
				isMatch[l1][l3]=1;
				return 1;
			}
		}else if (isMatch[l1][l3]==1)
			return 1;
		else;
			
	}
	if(l2<length2&&s2[l2]==s3[l3])
	{
		if (isMatch[l1][l3]==0) {
			if(dfs(l1,l2+1,l3+1))
			{
				isMatch[l1][l3]=1;
				return 1;
			}
		}else if (isMatch[l1][l3]==1)
			return 1;
		else;
			
	}
	isMatch[l1][l3]=2;
	return 0;
}
int main (int argc, char * const argv[]) {
	int cases,p=1;
	cin>>cases;
	while (cases--) {
		cin>>s1>>s2>>s3;
		memset(isMatch, 0, sizeof(isMatch));
		length1=s1.length();length2=s2.length();length3=s3.length();
		if (s1[length1-1]!=s3[length3-1]&&s2[length2-1]!=s3[length3-1]) {
			cout << "Data set "<<p++<<": no"<<endl;
			continue;
		}
		if (dfs(0, 0, 0)) {
			cout << "Data set "<<p++<<": yes"<<endl;
		}else {
			cout << "Data set "<<p++<<": no"<<endl;
		}
	}
    return 0;
}
