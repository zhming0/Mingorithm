#include<cstring>
#include<cstdio>
#define MAX 2000010
#define N 1010
struct Edge{
	int to,last;
}e[MAX];
int head[N],low[N],dfn[N],cnt,stack[N],head_s,num;
bool inStack[N];
void insert(int f,int t)
{e[cnt].to=t;e[cnt].last=head[f];head[f]=cnt++;}
int min(int a,int b){return a>b?b:a;}
void tarjan(int now)
{
	int tmp;
	dfn[now]=low[now]=++num;
	inStack[now]=true;
	stack[head_s++]=now;
	for (int i=head[now]; i!=-1; i=e[i].last) {
		if(!dfn[e[i].to])
		{
			tarjan(e[i].to);
			low[now]=min(low[e[i].to], low[now]);
		}else if(inStack[e[i].to])
			low[now]=min(low[now], dfn[e[i].to]);
	}
	if(low[now]==dfn[now])
		do {
			tmp=stack[--head_s];
			inStack[tmp]=false;
		} while (tmp!=now);
}
int main (int argc, char * const argv[]) {
	int n,m,i;
	char op[5];
	while (scanf("%d %d",&n,&m)!=EOF) {
		bool flag=true;
		cnt=0;num=0;head_s=0;
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(inStack, false, sizeof(inStack));
		while (m--) 
		{
			int a,b,res;
			scanf("%d %d %d %s",&a,&b,&res,op);
			if(op[0]=='A'&&res==1)
			{
				insert(a,b),insert(b,a);//'+n' means xa=0
				insert(a+n, a),insert(b+n,b);
			}
			if(op[0]=='A'&&res==0)
				insert(a,b+n),insert(b,a+n);
			if(op[0]=='O'&&res==0)
			{
				insert(a+n,b+n),insert(b+n,a+n);
				insert(a, a+n),insert(b, b+n);
			}
			if(op[0]=='O'&&res==1)
				insert(a+n,b),insert(b+n,a);
			if(op[0]=='X'&&res==1)
			{
				insert(a,b+n),insert(b+n,a);
				insert(b,a+n),insert(a+n,b);
			}
			if(op[0]=='X'&&res==0)
			{
				insert(a,b),insert(b,a);
				insert(a+n,b+n),insert(b+n,a+n);
			}
		}
		for (i=0; i<2*n; i++) 
			if(!dfn[i])
				tarjan(i);
		for (i=0; i<n; i++) 
			if(low[i]==low[i+n]){
				flag=false;
				break;
			}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
    return 0;
}
