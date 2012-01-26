#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char array[1000010];
int stack[50010<<4],head_stack;
int op[50010<<1],head_op;
char s[50010][16];
int main (int argc, char * const argv[]) {
	int cases,i;
	int cnt,head;
	//freopen("backup.txt", "r", stdin);
	scanf("%d",&cases);
	while (cases--) {
		scanf("%s",array);
		cnt=1,head=0;
		head_stack=0;head_op=0;
		for (i=0; array[i]!=0&&array[i]!='\n'; i++) {
			if (array[i]=='(') {
				op[head_op++]=cnt;
				stack[head_stack++]=cnt;
				s[cnt][head++]=0;
				cnt++;head=0;
				continue;
			}
			if (array[i]==',') {
				if (array[i-1]!=')'&&array[i-1]!=','&&array[i-1]!='(') {
					op[head_op++]=cnt;
					s[cnt][head++]=0;
					cnt++;head=0;
				}
				op[head_op++]=stack[head_stack-1];
				continue;
			}
			if (array[i]==')') {
				if(array[i-1]!=')'&&array[i-1]!=','&&array[i-1]!='(')
				{
					op[head_op++]=cnt;
					s[cnt][head++]=0;
					cnt++;head=0;
				}
				op[head_op++]=stack[--head_stack];
				continue;
			}
			s[cnt][head++]=array[i];
		}
		if (array[i-1]!=')') {
			printf("1\n");
			s[cnt][head++]=0;
			printf("%s\n",s[cnt]);
			printf("\n");
			continue;
		}
		printf("%d\n",cnt-1);
		for (int i=1; i<cnt; i++) 
			printf("%s\n",s[i]);
		for (int i=0; i<head_op-1; i++) 
			printf("%d %d\n",op[i],op[i+1]);
		printf("\n");
	}
    return 0;
}
