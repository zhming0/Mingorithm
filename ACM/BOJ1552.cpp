#include <iostream>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i,j;
	cin>>cases;
	string names[51];
	string attendance[51];
	bool isMeet[51];
	int num;
	while(cases--){
		memset(isMeet, true, sizeof(isMeet));
		cin>>num;
		for (i=0; i<num; i++) 
			cin>>names[i];
		for (i=0; i<num; i++) 
			cin>>attendance[i];
		for (i=0; i<num; i++) {
			float all=0,present=0;
			for(j=0;j<attendance[i].length();j++)
			{
				if (attendance[i][j]=='P') {
					present++;
					all++;
				}
				if(attendance[i][j]=='A')
					all++;
			}
			if(all==0)
				isMeet[i]=true;
			else if(double(present/all)<0.75)
				isMeet[i]=false;
			else
				isMeet[i]=true;
		}
		for (i=0; i<num; i++) {
			if(isMeet[i]==false)
				cout << names[i]<<endl;
		}
	}
    return 0;
}
