#include <iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	string word,table[10][60],num;
	int head[10];
	int i,j,cases,n;
	cin>>cases;
	while (cases--) {
		cin>>num;
		cin>>n;
		for(i=0;i<10;i++)
			head[i]=0;
		for (i=0; i<n; i++)
		{
			cin>>word;
			table[word.length()][head[word.length()]++]=word;
		}
		for(i=0;i<10;i++)
		{
			sort(table[i],table[i]+head[i]);
			head[i]=0;
		}
		for (i=0; i<num.length()-1; i++) 
			cout << table[num[i]-'0'][head[num[i]-'0']++]<<" ";
		cout << table[num[i]-'0'][head[num[i]-'0']++]<<endl;
	}
	
    return 0;
}
