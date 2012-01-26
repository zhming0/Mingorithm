#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define MAX2 100
typedef struct treeItem{
	int left_son;
	int right_son;
	int ex;//1 or 0
	int num;
}treeItem;

int last;

int main (int argc, const char * argv[]) {
	
	char s[MAX];
	int i=0;
	int ok;
	while (gets(s) != NULL) 
	{
		//printf("%s\n",s);
		
		ok=1;
		last=0;
		treeItem item[MAX2];
		for (i=0; i<MAX2; i++) {
			item[i].ex=0;
			item[i].left_son=0;
			item[i].right_son=0;
			item[i].num=-1;
		}
		i=0;
		while (1) 
		{
			int num=0;
			int pos=1;
			if (s[i]=='('&&s[i+1]==')') 
				break;
			i++;
			for (; s[i]>='0'&&s[i]<='9'; i++) 
				num=num*10+s[i]-'0';
			i++;
			if (s[i]==')') 
			{
				if (item[1].ex==1)
				{
					ok=0;
					break;
				}
				i++;
				i++;
				item[1].ex=1;
				item[1].num=num;
				if(last<1)
					last=1;
				continue;
			}
			for (;s[i]=='L'||s[i]=='R'; i++) 
			{
				int temp;
				if (s[i]=='L') 
				{
					temp=pos*2;
					item[pos].left_son=temp;
					pos=temp;
				}
				else if(s[i]=='R')
				{
					temp=pos*2+1;
					item[pos].right_son=temp;
					pos=temp;
				}
			}
			if (item[pos].ex==1) 
			{
				ok=0;
				break;
			}
			item[pos].ex=1;
			item[pos].num=num;
			last=(last>pos) ? last : pos;
			i++;
			i++;
		}
		
		if (ok==0) 
		{
			printf("%d\n",-1);
			continue;
		}
		
		for (i=1; i<=last; i++) 
		{
			if (item[i].ex!=1&&(item[i].left_son!=0||item[i].right_son!=0)) 
			{
				//printf("<Failed! i=%d>\n",i);
				printf("%d",-1);
				ok=0;
				break;
			}
		}
		
		if (ok) 
		{
			for (i=1; i<=last; i++) 
			{
				if (i==last&&item[i].ex==1) 
				{
					printf("%d",item[i].num);
					continue;
				}
				if (item[i].ex==1) 
					printf("%d ",item[i].num);
			}
		}
		printf("\n");
	}
	

    return 0;
}
