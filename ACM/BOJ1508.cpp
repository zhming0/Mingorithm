#include <iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;

bool isChar(char a)
{
	if ((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
	{
		return true;
	}
	else {
		return false;
	}

}

int main (int argc, char * const argv[]) {
	
	int cases;
	int i,j;
	int tot;
	int num;
	double ans;
	cin>>cases;
	char temp;
	scanf("%c",&temp);
	while (cases--) 
	{
		num=0;
		tot=0;
		ans=0;
		char s[51];
		
		//memset(s, 0, sizeof(s));
		
		cin.getline(s,51);
		int state=0;
		
		for (i=0; s[i]!='\n'&&s[i]!=0; i++) 
		{
			switch (state) 
			{
				case 0:
					if (isChar(s[i])) 
					{
						num++;
						state=1;
						tot++;
					}
					break;
				case 1:
					if (isChar(s[i])) 
					{
						tot++;
					}
					else {
						state=0;
					}
					break;

				default:
					break;
			}
		}
		if (num==0) {
			printf("%.4f\n",ans);
			continue;
		}
		ans=(double)tot/num;
		printf("%.4f\n",ans);
	}
    return 0;
}
