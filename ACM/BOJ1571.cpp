#include <iostream>
#include<cstdlib>
#include<string.h>
#include<string>
#define INI 100
using namespace std;
bool button[10];
int min(int a,int b)
{return a>b?b:a;}
bool check(int num)
{
	if(num<0)return false;
	if(num==0&&button[0]==false)
		return false;
	while (num!=0) {
		if(!button[num%10])
			return false;
		num/=10;
	}
	return true;
}
int digit(int num)
{
	if(num==0)return 1;
	int temp=num;
	int ans=0;
	while (temp!=0) {
		temp/=10;
		ans++;
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	int cases,n,i,temp,num;
	cin>>cases;
	while (cases--) {
		bool flag1=false;
		bool flag2=false;
		memset(button, true, sizeof(button));
		cin>>num;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			button[temp]=false;
		}
		for (i=0; i<=abs(num-100); i++) 
		{
			if (check(num+i))
				flag1=true;
			if (check(num-i))
				flag2=true;
			if(flag1||flag2)
				break;
		}
		int ans=abs(num-100);
		if(flag1)
			ans=min(ans, digit(num+i)+i);
		if(flag2)
			ans=min(ans,digit(num-i)+i);
		cout<<ans<<endl;
	}
    return 0;
}
