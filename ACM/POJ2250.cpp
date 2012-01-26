#include <iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
typedef struct Node{
	Node* pre;
	bool isHere;
	string content;
}Node;
void iniNode(Node* node,Node* p,bool is,string c)
{
	node->pre=p;node->isHere=is;node->content=c;
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int i,j,l1,l2;
	string s1[102];
	string s2[102];
	int dp[101][101];
	while (cin>>s1[0]) {
		string stack[101];
		int head=0;
		i=1;
		l1=1;l2=0;
		memset(dp[0], 0, sizeof(dp));
		while (cin>>s1[i]) 
		{
			if (s1[i]!="#") 
				l1++;
			else
				break;
			i++;
		}
		i=0;
		while (cin>>s2[i]) {
			if (s2[i]!="#")
				l2++;
			else 
				break;
			i++;
		}
		Node node[l1][l2];
		for (i=0; i<l1; i++) {
			for (j=0; j<l2; j++) {
				if (s1[i]==s2[j]) 
				{
					if (i>0&&j>0) 
					{
						dp[i][j]=dp[i-1][j-1]+1;
						iniNode(&node[i][j], &node[i-1][j-1], true, s1[i]);
					}
					else
					{
						dp[i][j]=1;
						iniNode(&node[i][j], NULL, true, s1[i]);
					}
				}else {
					if (i>0&&j>0) 
					{
						if(dp[i-1][j]>dp[i][j-1]){
							dp[i][j]=dp[i-1][j];
							iniNode(&node[i][j],&node[i-1][j] , false, "");
						}else {
							dp[i][j]=dp[i][j-1];
							iniNode(&node[i][j],&node[i][j-1] , false, "");
						}
					}else if(j==0&&i>0)
					{
						dp[i][j]=dp[i-1][j];
						iniNode(&node[i][j],&node[i-1][j] , false, "");
					}else if (i==0&&j>0) {
						dp[i][j]=dp[i][j-1];
						iniNode(&node[i][j],&node[i][j-1] , false, "");
					}else {
						dp[i][j]=0;
						iniNode(&node[i][j], NULL, false, "");
					}
				}
			}
		}
		Node* temp=&node[l1-1][l2-1];
		while (temp->pre!=NULL) {
			if (temp->isHere) 
				stack[head++]=temp->content;
			temp=temp->pre;
		}
		stack[head++]=temp->content;
		while (head>0) {
			cout << stack[--head];
			if (head==0)
				cout << endl;
			else 
				cout << " ";
		}
	}
    return 0;
}
