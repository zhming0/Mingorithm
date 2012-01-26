#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num;
	int len;
	struct node* next;
}node;

int minLen[100];
int isInside[100];
int ans;

void addEdge(int from,int to,int len,node** point)
{
	if (point[from]!=0) {
		node* tempNode=point[from];
		do {
			if (tempNode->num==to) {
				tempNode->len=(len>tempNode->len)?tempNode->len:len;
				return;
			}
			tempNode=tempNode->next;
		} while (tempNode!=NULL);
	}
	node* newNode=(node*)malloc(sizeof(node));
	newNode->len=len;
	newNode->num=to;
	newNode->next=point[from];
	point[from]=newNode;
}

int main (int argc, const char * argv[]) {
	int n,i,j;
	//freopen("test.txt", "r", stdin);
	while(scanf("%d",&n)!=EOF)
	{
		node* point[n];
		for (i=0; i<n; i++) {
			point[i]=0;//(node*)malloc(sizeof(node));
		}
		memset(minLen,-1,sizeof(minLen));
		memset(isInside,0,sizeof(isInside));
		while (1) {
			int a,b,len;
			scanf("%d %d",&a,&b);
			if(a==0&&b==0)
				break;
			scanf("%d",&len);
			addEdge(a, b, len,point);
			addEdge(b, a, len,point);
		}
		ans=0;
		isInside[0]=1;
		minLen[0]=-1;
		node* temp=point[0];
		do {
			minLen[temp->num]=temp->len;
			temp=temp->next;
		} while (temp!=NULL);
		
		for (i=1; i<n; i++) {
			int min=999999999;
			int min_num;
			for (j=0; j<n; j++) 
			{
				//printf("minLen[%d]=%d,",j,minLen[j]);
				if(minLen[j]!=-1&&minLen[j]<min&&!isInside[j])
				{
					min=minLen[j];
					min_num=j;
				}
			}
			//printf("\n",min);
			isInside[min_num]=1;
			ans+=min;
			temp=point[min_num];
			do {
				if ((minLen[temp->num]>temp->len||minLen[temp->num]==-1)&&!isInside[temp->num]) {
					minLen[temp->num]=temp->len;
				}
				temp=temp->next;
			} while (temp!=NULL);
		}
		printf("%d\n",ans);
	}
	
	
    return 0;
}
