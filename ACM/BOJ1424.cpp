#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 200

typedef struct treeItem{
	char text;
	struct treeItem* left;
	struct treeItem* right;
}treeItem;

void processOrder(char* pre_order,char* mid_order)
{
	//printf("Here~!pre_order=<%s>,mid_order=<%s>\n",pre_order,mid_order);
	//item->text=pre_order[0];
	char left[MAX];
	char right[MAX];
	char pre_left[MAX];
	char pre_right[MAX];
	int i,j;
	char* pointer;
	if (pre_order[1]!='\0') 
	{
		//pointer=&pre_order[1];
		
	}
	else
	{
		printf("%c",pre_order[0]);
		//item->left=NULL;
		//item->right=NULL;
		return;
	}
	//printf("%s\n",pre_order);
	for (i=0; mid_order[i]!=pre_order[0]; i++) 
	{
		pre_left[i]=pre_order[i+1];
		left[i]=mid_order[i];
	}
	pre_left[i]='\0';
	left[i]='\0';
	for (++i,j=0; mid_order[i]!=0; i++,j++) 
	{
		//printf("i=%d,j=%d",i,j);
		pre_right[j]=pre_order[i];
		right[j]=mid_order[i];
	}
	pre_right[j]='\0';
	right[j]='\0';
	
	//printf("pre_left=%s,pre_right=%s\n",pre_left,pre_right);
	
	if (left[0]!=0) 
	{
		//printf("Left\n");
		//item->left=(treeItem*) malloc(sizeof(treeItem));
		processOrder(pre_left,left);
	}
	else 
		;//item->left=NULL;
	
	if (right[0]!=0)
	{
		//printf("Right\n");
		//item->right=(treeItem*)malloc(sizeof(treeItem));
		processOrder(pre_right,right);
	}
	else
		;//item->right=NULL;
	
	printf("%c",pre_order[0]);
}

void printTree(treeItem* item)
{
	if (item->left!=NULL) 
	{
		printTree(item->left);
	}
	if (item->right!=NULL) 
	{
		printTree(item->right);
	}
	printf("%c",item->text);
}

int main (int argc, const char * argv[]) {

	char* pre_order=(char*)malloc(sizeof(char)*MAX);
	char* mid_order=(char*)malloc(sizeof(char)*MAX);
	int i;
	int j;
	while (scanf("%s",pre_order)!=EOF) 
	{
		//treeItem* item=(treeItem*) malloc(sizeof(treeItem));
		//treeItem* root=item;
		//item->left=NULL;
		//item->right=NULL;
		//strtok(pre_order,",");
		for (i=0; pre_order[i]!=','; i++) 
			;
		pre_order[i]='\0';
		for (++i,j=0; pre_order[i]!=0; i++,j++) 
			mid_order[j]=pre_order[i];
		mid_order[j]='\0';
		
		processOrder(pre_order, mid_order);
		//printTree(root);
		printf("\n");
	}
	
    return 0;
}
