#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define IN 0
#define OUT 1
using namespace std;
struct Edge{int to,last,num;bool visited;}e[2001];
int cnt,head[2001];
void insert(int from,int to,int num){
	e[cnt].num=num;e[cnt].to=to;
	e[cnt].last=head[from];e[cnt].visited=false;
	head[from]=cnt++;
}
struct Word{char str[26];}word[2001];
bool cmp(Word a,Word b){return strcmp(a.str, b.str)>=0;}
int n,d[2][26],grid[26][26],counts[2],vst[26];
int stack[2001],top;
void dfs(int now)
{
	vst[now]=true;
	for (int i=0; i<26; i++) 
		if(grid[now][i]&&!vst[i])
			dfs(i);
}
int judge()
{
	int id=-1,i;
	for (i=0; i<26; i++) {
		if(d[IN][i]-d[OUT][i]==1)
			counts[0]++;
		if(d[OUT][i]-d[IN][i]==1)
			id=i,counts[1]++;
		if(d[IN][i]-d[OUT][i]>1||d[OUT][i]-d[IN][i]>1)
			return -1;
	}
	if (counts[0]>1||counts[1]>1) return -1;
	if(id==-1)
		for (i=0; i<26; i++) 
			if(d[OUT][i]>0){
				id=i;break;
			}
	dfs(id);
	for (i=0; i<26; i++) 
		if(!vst[i]&&(d[IN][i]!=0||d[OUT][i]!=0))
			return -1;
	/*if (counts[1] > 0)
	{
        for(int i = 0; i < 26; i++) if (d[OUT][i] > d[IN][i]) return i;
	}
    else
	{
        for(int i = 0; i < 26; i++) if (d[OUT][i] > 0) return i;
	}*/
	return id;
}
void eul(int pint,int eid)
{
	for (int i=head[pint]; i!=-1; i=e[i].last) {
		if(!e[i].visited)
		{
			e[i].visited=true;
			eul(e[i].to,i);
		}
	}
	if(eid>=0)
		stack[top++]=e[eid].num;
}
int main (int argc, char * const argv[]) {
	int cases,i;
	//freopen("backup.txt", "r", stdin);
	scanf("%d",&cases);
	while (cases--) {
		cin>>n;
		cnt=counts[0]=counts[1]=0;
		top=0;
		memset(d, 0, sizeof(d));
		memset(head, -1, sizeof(head));
		memset(vst, false, sizeof(vst));
		memset(grid, 0, sizeof(grid));
		for (i=0; i<n; i++) 
			scanf("%s",word[i].str);
		sort(word, word+n,cmp);
		for (i=0; i<n; i++) {
			int a=word[i].str[0]-'a';
			int b=word[i].str[strlen(word[i].str)-1]-'a';
			insert(a, b, i);d[OUT][a]++;d[IN][b]++;
			grid[a][b]=1;//grid[b][a]=1;
		}
		int start=judge();
		if(start==-1)
			printf("***\n");
		else
		{
			eul(start,-1);
			for (i=top-1; i>0; i--) {
				printf("%s.",word[stack[i]].str);
			}
			printf("%s\n",word[stack[i]].str);
		}
	}
    return 0;
}
