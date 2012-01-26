#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500001

typedef struct myStruct{
	int num;
	struct myStruct* left;
	struct myStruct* right;
}ball;


int main (int argc, const char * argv[]) {
	int n,m;
	int i;
	while (scanf("%d %d",&n,&m)!=EOF) 
	{
		ball* Ball[MAX];
		Ball[0]=(ball*)malloc(sizeof(ball));
		Ball[0]->num=0;
		Ball[0]->left=NULL;
		Ball[0]->right=NULL;
		Ball[1]=(ball*)malloc(sizeof(ball));
		Ball[1]->left=NULL;
		for (i=1; i<=n; i++) 
		{
			Ball[i]->num=i;
			Ball[i+1]=(ball*)malloc(sizeof(ball));
			Ball[i]->right=Ball[i+1];
			Ball[i]->right->left=Ball[i];
		}
		Ball[n]->right=NULL;
		
		for (i=0; i<m; i++)
		{
			char dir;
			int from,to;
			scanf("\n",&dir);
			scanf("%c %d %d",&dir,&from,&to);
			
			if (Ball[from]->right==NULL) 
			{
				Ball[from]->left->right=NULL;
			}
			else if(Ball[from]->left==NULL)
			{
				Ball[from]->right->left=NULL;
			}
			else
			{
				Ball[from]->left->right=Ball[from]->right;
				Ball[from]->right->left=Ball[from]->left;
			}
			
			switch (dir) 
			{
				case 'L':
					if (Ball[to]->left==NULL) 
					{
						Ball[from]->right=Ball[to];
						Ball[to]->left=Ball[from];
						Ball[from]->left=NULL;
					}
					else 
					{
						Ball[from]->right=Ball[to];
						Ball[from]->left=Ball[to]->left;
						Ball[to]->left->right=Ball[from];
						Ball[to]->left=Ball[from];
					}

					break;
				case 'R':
					if (Ball[to]->right==NULL) 
					{
						Ball[from]->left=Ball[to];
						Ball[from]->right=NULL;
						Ball[to]->right=Ball[from];
					}
					else 
					{
						Ball[from]->left=Ball[to];
						Ball[from]->right=Ball[to]->right;
						Ball[to]->right->left=Ball[from];
						Ball[to]->right=Ball[from];
					}

					break;

				default:
					break;
			}
		}
		
		for (i=n; Ball[i]->left!=NULL; i--) 
			;
		ball* currentBall=Ball[i];
		
		while (currentBall->right!=NULL) 
		{
			printf("%d ",currentBall->num);
			currentBall=currentBall->right;
		}
		printf("%d\n",currentBall->num);

	}
    return 0;
}








