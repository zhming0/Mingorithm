#include <iostream>
#include<string>
#include<stdio.h>
#define MAX 12;
using namespace std;

int n;
string s[3][3];
int weight[12];

bool isFake()
{
	int i,j;
	for (i=0; i<3; i++) 
	{
		int left=0,right=0;
		for (j=0; s[i][0][j]!=0; j++) 
		{
			left+=weight[s[i][0][j]-'A'];
			right+=weight[s[i][1][j]-'A'];
		}
		switch (s[i][2][0]) 
		{
			case 'e':
				if (left!=right) 
				{
					return false;
				}
				break;
			case 'u':
				if (left<=right) 
				{
					return false;
				}
				break;
			case 'd':
				if (left>=right) {
					return false;
				}
				break;

			default:
				break;
		}
	}
	return true;
}

int main (int argc, char * const argv[]) 
{
	int i,j;
	cin>>n;
	while (n--) 
	{
		memset(weight, 0, sizeof(weight));
		for (i=0; i<3; i++) 
		{
			cin>>s[i][0]>>s[i][1]>>s[i][2];
		}
		for (i=0; i<12; i++) 
		{
			weight[i]=1;
			if(isFake())
			{
				printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
				break;
			}
			weight[i]=-1;
			if(isFake())
			{
				printf("%c is the counterfeit coin and it is light.\n",i+'A');
				break;
			}
			weight[i]=0;
			
		}
	}
    return 0;
}
