#include <iostream>
#include<string>
using namespace std;
double toDouble(string num)
{
	int i;
	double intpart=0;
	double decpart=0;
	double time=10;
	for (i=0; num[i]!='.'&&i<num.length(); i++) {
		intpart*=10;
		intpart+=(num[i]-'0');
	}
	if(i<num.length())
	{
		i++;
		for (; i<num.length(); i++) 
		{
			double tmp=num[i]-'0';
			decpart+=tmp/time;
			time*=10;
		}
	}
	
	return intpart+decpart;
}
int signum(string num)
{
	int ans;
	ans=num.find(".", 0);
	if(ans==string::npos)return 0;
	ans=num.length()-ans-1;
	return ans;
}

double round(double num,int n)
{
	int intpart=num;
	num-=intpart;
	
	return 0;
}
int main (int argc, char * const argv[]) {
	int cases,n,i,j;
	string s,a,b;
	cin>>cases;
	getline(cin,s);
	while (cases--) {
		getline(cin,s);
		a=s.substr(0, s.find("+",0));
		b=s.substr(s.find("+", 0)+1,s.length());
		//cout << a<<"+"<<b<<endl;
		i=signum(a);j=signum(b);
		n=i>j?j:i;
		double res=toDouble(a)+toDouble(b);
		res=round(res, n);
	}
    return 0;
}
