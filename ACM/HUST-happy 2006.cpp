#include<iostream>
#include<string>
#include<string.h>
using namespace std;
bool array[1000010];
int main (int argc, char * const argv[]) {
	int n=0,m,i,k,time,j;
	while(cin>>m>>k)
	{
		n=0;
		for (i=0; i<1000010; i++) 
			array[i]=true;
		if (m!=1) 
			array[m]=false;
		for (i=2; i<m; i++) 
			if (array[i]) 
				if (m%i==0) 
					for (j=1; i*j<=m; j++) 
						array[j*i]=false;
		for (i=1; i<=m; i++) 
			if(array[i])
				n++;
		time=0;i=0;
		if(n>0&&k>n)
		{
			time=k/n;
			k%=n;
		}
		if(k==0)
		{k=n;time--;}
		while (k>0) 
			if(array[++i])
				k--;
		cout << i+time*m<<endl;
	}
    return 0;
}
