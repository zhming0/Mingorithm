#include <iostream>
#include<string.h>
using namespace std;
int winmove[1000001];
int main()
{
	int i,j,k,m,temp,digit;
	for(i=0;i<=9;i++)
		winmove[i]=-1;
	for (i=10; i<=1000000; i++)
	{
		winmove[i]=-1;
		temp=i;
		digit=0;
		while (temp!=0) {
			digit++;
			temp/=10;
		}
		for (j=1; j<=digit; j++) {
			int subnum=0,e=1;
			for(k=0;k<j;k++)
				e*=10;
			//if(i==10)printf("subnum=%d\n",subnum);
			m=i;
			while (m!=0) {
				subnum=m%e;
				m/=10;
				if(subnum>0&&winmove[i-subnum]==-1&&subnum!=i)
				{
					if(winmove[i]==-1)winmove[i]=subnum;
					else winmove[i]=winmove[i]>subnum?subnum:winmove[i];
				}
			}
		}
	}
	//printf("winmove[230]=%d\n",winmove[230]);
	cin>>i;
	while (i--) {
		cin>>k;
		cout << winmove[k]<<endl;
	}
	return 0;
}
