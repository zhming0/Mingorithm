#include <stdio.h>
#include<stdlib.h>

#define MAX 500

char buf[MAX];
char op_stack[MAX];
float stack[MAX];
int op_head;
int head;
int ispos;

void processOp(char op)
{
	float m,n;
	switch (op) {
		case '*':
		case '/':
			if (*op_head==0) 
			{
				op_stack[*op_head++]=op;
			}
			else
			{
				if (uop_head>0) 
				{
					uop_head--;
					
				}
			}
			break;
		default:
			break;
	}
}

int main (int argc, const char * argv[]) 
{
    
	int i;
	
	int isnega=1;
	scanf("%s",buf);
	
	for (i=0; buf[i]!=0; i++) 
	{
		if (buf[i]>='0'&&buf[i]<='9') 
		{	
			float c=buf[i]-'0';
			
			for (; buf[i+1]!=0&&buf[i+1]>='0'&&buf[i+1]<='9'; ) 
			{
				c=10*c+(buf[++i]-'0');
			}
			stack[head++]=c;
			isnega=0;
		}
		else if()
		{
			
		}
	}
	
	
	
    return 0;
}
