#include <iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define MAX 5842

int main (int argc, char * const argv[]) {
	int n;
	int humble[MAX];
	int times[MAX];
	int prime[4]={2,5,3,7};
	int i,j;
	int head=0;
	int now=0;
	humble[0]=1;
	times[0]=2;
	int a[4]={0,0,0,0};
	
	for (i=0; i<5842; i++) 
	{
		for (j=0; j<4; j++) 
		{
			while ((prime[j]*humble[a[j]])<=humble[i]) 
			{
				a[j]++;
			}
		}
		
		int min=2000000001;
		
		for (j=0; j<4; j++) 
		{
			if ((prime[j]*humble[a[j]])<min) 
			{
				min=prime[j]*humble[a[j]];
			}
		}
		//cout << i<<endl;
		humble[i+1]=min;
	}
	
	while (cin>>n) 
	{
		if (n==0) 
		{
			break;
		}
		
		if (n%10==1&&n%100!=11)
		{
			cout << "The "<<n<<"st humble number is "<<humble[n-1]<<"."<<endl;
		}
		else if(n%10==2&&n%100!=12)
			cout << "The "<<n<<"nd humble number is "<<humble[n-1]<<"."<<endl;
		else if(n%10==3&&n%100!=13)
			cout << "The "<<n<<"rd humble number is "<<humble[n-1]<<"."<<endl;
		else {
			cout << "The "<<n<<"th humble number is "<<humble[n-1]<<"."<<endl;
		}

		//cout << humble[n-1]<<endl;
	}
	
    return 0;
}
