#include <stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct movement{
	int x,y;
	struct movement* pre;
	struct movement* next;
}movement;

int main (int argc, const char * argv[]) {
	//freopen("test.txt", "r", stdin);
	int maze[5][5];
	movement* queue[500];
	int visited[5][5];
	int i,j;
	while (1) {
		memset(maze,0,sizeof(maze));
		memset(visited,0,sizeof(visited));
		memset(queue,0,sizeof(queue));
		for (i=0; i<5; i++) 
			for (j=0; j<5; j++) 
				if(scanf("%d",&maze[i][j])==EOF)
					return 0;
		int head=0,tail=0;
		movement* temp=(movement*)malloc(sizeof(movement));
		temp->x=0;temp->y=0;temp->pre=NULL;temp->next=NULL;
		queue[tail++]=temp;
		while (head<tail) {
			temp=queue[head++];
			if (temp->x+1<5) 
				if(visited[temp->x+1][temp->y]==0&&maze[temp->x+1][temp->y]==0)
				{
					movement* newMove=(movement*) malloc(sizeof(movement));
					newMove->x=temp->x+1;
					newMove->y=temp->y;
					newMove->pre=temp;newMove->next=NULL;
					queue[tail++]=newMove;
					visited[newMove->x][newMove->y]=1;
					if (newMove->x==4&&newMove->y==4) {
						break;
					}
				}
			if (temp->x-1>=0) 
				if(visited[temp->x-1][temp->y]==0&&maze[temp->x-1][temp->y]==0)
				{
					movement* newMove=(movement*) malloc(sizeof(movement));
					newMove->x=temp->x-1;
					newMove->y=temp->y;
					newMove->pre=temp;newMove->next=NULL;
					queue[tail++]=newMove;
					visited[newMove->x][newMove->y]=1;
					if (newMove->x==4&&newMove->y==4) {
						break;
					}
				}
			if (temp->y+1<5) {//printf("here\n");
				if(visited[temp->x][temp->y+1]==0&&maze[temp->x][temp->y+1]==0)
				{
					movement* newMove=(movement*) malloc(sizeof(movement));
					newMove->x=temp->x;
					newMove->y=temp->y+1;
					newMove->pre=temp;newMove->next=NULL;
					queue[tail++]=newMove;
					visited[newMove->x][newMove->y]=1;
					if (newMove->x==4&&newMove->y==4) {
						break;
					}
				}
			}
			if (temp->y-1>=0) 
				if(visited[temp->x][temp->y-1]==0&&maze[temp->x][temp->y-1]==0)
				{
					movement* newMove=(movement*) malloc(sizeof(movement));
					newMove->x=temp->x;
					newMove->y=temp->y-1;
					newMove->pre=temp;newMove->next=NULL;
					queue[tail++]=newMove;
					visited[newMove->x][newMove->y]=1;
					if (newMove->x==4&&newMove->y==4) {
						break;
					}
				}
		}
		while (temp->pre!=NULL) {
			temp->pre->next=temp;
			temp=temp->pre;
		}
		while (temp->next!=NULL) {
			printf("(%d, %d)\n",temp->x,temp->y);
			temp=temp->next;
		}
		printf("(%d, %d)\n",temp->x,temp->y);
		printf("(%d, %d)\n",4,4);
	}
    return 0;
}
