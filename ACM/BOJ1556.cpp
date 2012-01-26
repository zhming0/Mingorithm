#include<iostream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int cmp(string s1,string s2)
{
	int i;
	for (i=0; i<s1.length(); i++) 
		if(s1[i]>='A'&&s1[i]<='Z')
			s1[i]=s1[i]-'A'+'a';
	for (i=0; i<s2.length(); i++) 
		if(s2[i]>='A'&&s2[i]<='Z')
			s2[i]=s2[i]-'A'+'a';
	return s1.compare(s2);
}
int main (int argc, char * const argv[]) {
	freopen("b.txt", "r", stdin);
	int cases,n,i,j;
	cin>>cases;
	while (cases--) {
		string word[51];
		cin>>n;
		string column1[100];
		string column2[100];
		int head1=0,head2=0;
		char newline;
		scanf("%c",&newline);
		for (i=0; i<n; i++) 
			getline(cin,word[i]);
		for (i=0; i<n; i++) 
			for (j=i+1; j<n; j++) 
				if (cmp(word[i], word[j])>0) 
				{
					string temp=word[i];
					word[i]=word[j];
					word[j]=temp;
				}
		//for(i=0;i<n;i++)
		//	cout << word[i]<<endl;
		char current=1;
		for (i=0; i<n; i++) 
		{
			if((word[i][0]==current)||(word[i][0]==current-'A'+'a'))
			{
				column1[head1++]+="  ";
				column1[head1-1]+=word[i];
				for(j=column1[head1-1].length();j<19;j++)
					column1[head1-1]+=" ";
			}
			else 
			{
				if(word[i][0]<='Z'&&word[i][0]>='A')
					current=word[i][0];
				else 
					current=word[i][0]-'a'+'A';
				if((current-'A')>('M'-'A'))
					break;
				column1[head1++]+=current;
				for(j=column1[head1-1].length();j<19;j++)
					column1[head1-1]+=" ";
				column1[head1++]="-------------------";
				column1[head1++]+="  ";
				column1[head1-1]+=word[i];
				for(j=column1[head1-1].length();j<19;j++)
				{
					column1[head1-1]+=" ";
				}
				//cout << column1[head1-1]<<"||"<<word[i]<<endl;
			}
		}
		if (i<n) {
			column2[head2++]=current;
			for(j=column2[head2-1].length();j<19;j++)
				column2[head2-1]+=" ";
			column2[head2++]="-------------------";
		}
		for (; i<n; i++) 
		{
			if((word[i][0]==current)||(word[i][0]==current-'A'+'a'))
			{
				column2[head2++]+="  ";
				column2[head2-1]+=word[i];
				for(j=column2[head2-1].length();j<19;j++)
					column2[head2-1]+=" ";
			}
			else 
			{
				if(word[i][0]<='Z'&&word[i][0]>='A')
					current=word[i][0];
				else 
					current=word[i][0]-'a'+'A';
				if((current-'A')>('Z'-'A'))
					break;
				column2[head2++]+=current;
				for(j=column2[head2-1].length();j<19;j++)
					column2[head2-1]+=" ";
				column2[head2++]="-------------------";
				column2[head2++]+="  ";
				column2[head2-1]+=word[i];
				for(j=column2[head2-1].length();j<19;j++)
					column2[head2-1]+=" ";
			}
		}
		i=0;j=0;
		while (i<head1||j<head2) {
			if (i<head1&&j<head2) {
				cout << column1[i++]<<"  "<<column2[j++]<<endl;
			}
			if (i<head1&&j==head2) {
				cout << column1[i++]<<"  "<<"                   "<<endl;
			}
			if(i==head1&&j<head2)
				cout <<"                   "<<"  "<<column2[j++]<<endl;
		}
	}
    return 0;
}
