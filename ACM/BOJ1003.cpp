#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2002

typedef struct{
	int dec[MAX];
	int flt[MAX];
	int head;
}largeNum;

void processNumber(char* data,largeNum* num)
{
	//num->dec[0]='\0';
	//num->flt[0]='\0';
	memset(num->dec,-1,sizeof(num->dec));
	memset(num->flt,0,sizeof(num->flt));
	int state=0;
	int m=0;
	for (int i=0; data[i]!=0; i++) 
	{
		if (i==0) 
		{
			if (data[i]=='-') 
			{
				num->head=-1;
				state=1;
				continue;
			}
			else 
			{
				num->head=1;
			}
			state=1;
		}
		
		if (data[i]=='.') 
		{
			state=2;
			//num->dec[m]='\0';
			m=0;
			continue;
		}
		
		switch (state) 
		{
			case 1:
				num->dec[m++]=data[i]-'0';
				break;
			case 2:
				num->flt[m++]=data[i]-'0';
				break;
			default:
				printf("state=%d\n",state);
				perror("Error");
				printf("data[%d]=%c\n",i,data[i]);
				break;
		}
		
	}
	/*if (state==1) {
		num->dec[m]='\0';
	}
	else {
		num->flt[m]='\0';
	}*/
	
}

void plus(largeNum* a,largeNum* b,char* ans,char* ans_flt)
{
	
}


int main (int argc, const char * argv[]) {
    char a[MAX];
	char b[MAX];
	int ans[MAX];
	int ans_flt[MAX];
	int i;
	
	memset(ans,0,sizeof(ans));
	memset(ans_flt,-1,sizeof(ans));
	memset(a,'0',sizeof(a));
	memset(b,'0',sizeof(b));
	
	scanf("%s %s",a,b);
	
	largeNum num1;
	largeNum num2;
	
	processNumber(a, &num1);
	processNumber(b, &num2);
	
	//printf("num1.dec[0]=%d\n",num1.dec[1]);
	
	

	/*
	for (i=MAX-2; ans[i]==0&&i>=0; i--) 
		;
	for (; i>=0; i--) 
		printf("%d",ans[i]);
	for(i=MAX-2;ans_flt[i]==0&&i>=0;i--)
		;
	if (i>=0) 
		printf(".");
	printf("<ans_flt[%d]=%d>\n",i,ans_flt[i]);
	for(int j=0;j<=i;j++)
		printf("%d",ans_flt[j]);
	printf("\n");*/
	
    return 0;
}
