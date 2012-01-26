#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2000

typedef struct mystruct{
	int num;
	struct mystruct* next;
}queue;


int main (int argc, const char * argv[]) {
    int stack[MAX];
	int head=0;
	int order[MAX];
	
	memset(stack,0,sizeof(stack));
	memset(order,0,sizeof(order));
	
	int n;
	int i;
	int count=0;
	while (scanf("%d",&n)!=EOF&&n!=0) 
	{
		//if (count>0) 
		//	printf("\n");
		//count++;
		queue* currentBlock;
		int pos;
		queue* Block[MAX];
		
		Block[0]=(queue*)malloc(sizeof(queue));
		Block[0]->num=0;
		Block[0]->next=NULL;
		
		while (scanf("%d",&order[0])!=EOF&&order[0]!=0) 
		{
			Block[1]=(queue*) malloc(sizeof(queue));
			Block[1]->num=1;
			Block[1]->next=(queue*) malloc(sizeof(queue));
			Block[2]=Block[1]->next;
			//currentBlock->num=1;
			//currentBlock->next=(queue*)malloc(sizeof(queue));
			//firstBlock=currentBlock;
			//currentBlock=currentBlock->next;
			for (i=1; i<n; i++) 
			{
				scanf("%d",&order[i]);
				Block[i+1]->num=i+1;
				Block[i+1]->next=(queue*) malloc(sizeof(queue));
				Block[i+2]=Block[i+1]->next;
				//currentBlock->num=i+1;
				//currentBlock->next=(queue*) malloc(sizeof(queue));
				//currentBlock=currentBlock->next;
			}
			currentBlock=Block[1];
			pos=1;
			//currentBlock=NULL;
			while (1)
			{
				if (order[n-1]==-1) 
				{
					printf("Yes\n");
					break;
				}
				/*if (head==0) 
				{
					for (i=0; order[i]==-1; i++) 
						;
					if(order[i]==Block[pos]->num)
					{
						pos++;
						order[i]=-1;
					}
					else 
					{
						while (Block[pos]->num!=order[i]) 
						{
							stack[head++]=Block[pos]->num;
							pos++;
						}
					}
				}
				else if(head!=0)
				{
					for(i=0;order[i]==-1;i++)
						;
					if(order[i]==stack[head-1]) 
					{
						order[i]=-1;
						head--;
					}
					else if(order[i]==Block[pos]->num)
					{
						order[i]=-1;
						pos++;
					}
					else 
					{
						printf("No\n");
						break;
					}
				}*/
				for(i=0;order[i]==-1;i++)
					;
				//printf("order[%d]=%d\n",i,order[i]);
				if (Block[pos]->num==order[i]&&pos<=n) 
				{
					pos++;
					order[i]=-1;
				}
				else if(order[i]==stack[head-1]&&head>0)
				{
					head--;
					order[i]=-1;
				}
				else if(pos<=n)
				{
					//printf("%d into stack\n",Block[pos]->num);
					stack[head++]=Block[pos]->num;
					pos++;
				}
				else 
				{
					//printf("<order[%d]=%d,pos=%d,head=%d,stack[%d]==%d>\n",i,order[i],pos,head,head-1,stack[head-1]);
					printf("No\n");
					break;
				}

			}
			memset(order,0,sizeof(order));
			head=0;
		}
		printf("\n");
		
	}
	
    return 0;
}
