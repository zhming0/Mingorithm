#include <stdio.h>
#include<stdlib.h>
#include<string.h>

char* Trans(char* s)
{
	int i=0,j=0;
	char* res;
	res=(char*) malloc(sizeof(char)*8*2);
	while(s[i]!='\0')
	{
		switch (s[i]) {
			case 'A':
			case 'B':
			case 'C':
				s[i]='2';
				break;
			case 'D':
			case 'E':
			case 'F':
				s[i]='3';
				break;
			case 'G':
			case 'H':
			case 'I':
				s[i]='4';
				break;
			case 'J':
			case 'K':
			case 'L':
				s[i]='5';
				break;
			case 'M':
			case 'N':
			case 'O':
				s[i]='6';
				break;
			case 'P':
			case 'R':
			case 'S':
			case 'Q':
				s[i]='7';
				break;
			case 'T':
			case 'U':
			case 'V':
				s[i]='8';
				break;
			case 'W':
			case 'X':
			case 'Y':
				s[i]='9';
				break;
			case 'Z':
				s[i]='0';
				break;

			default:
				break;
		}
		i++;
	}
	i=0;
	while (s[i]!='\0') {
		if (s[i]<='9'&&s[i]>='0') {
			res[j++]=s[i];
		}
		if (j==3) {
			res[j++]='-';
		}
		i++;
	}
	res[8]=0;
	return res;
}


void Mysort(char** a,int num,int begin)
{
	char* tem;
	int j;
	if (begin==num-1) {
		return;
	}
	for (j=begin+1; j<num; j++) {
		if (strcoll(a[begin], a[j])>=0) {
			tem=a[j];
			a[j]=a[begin];
			a[begin]=tem;
		}
	}
	begin++;
	Mysort(a,num,begin);
	
}



int main (int argc, const char * argv[]) {
    int num;
	int sign=0;
	int i=0,j=0,n_result=0;
	
	
	scanf("%d",&num);
	if (num==0) {
		printf("No duplicates\n");
		return 0;
	}
	i=0;
	int time[num*2];
	
	char** tel;
	char** res;
	char** result;
	tel=(char**) malloc(sizeof(char*)*num*2);
	res=(char**) malloc(sizeof(char*)*num*2);
	result=(char**) malloc(sizeof(char*)*num*2);
	while(i<num)
	{
		tel[i]=(char*) malloc(sizeof(char)*80);
		scanf("%s",tel[i]);
		i++;
	}
	
	i=0;

	
	for (i=0; i<num; i++) {
		
		res[i]=(char*) malloc(sizeof(char)*8*2);
		res[i]=Trans(tel[i]);
	}
	
	
	
	Mysort(res,num,0);
	
	
	
	for (i=0; i<num; i++) {
		if (i==num-1) {
			
			break;
		}
		if (strcoll(res[i],res[i+1])==0) {
			result[n_result]==(char*)malloc(sizeof(char)*9);
			result[n_result]=res[i];
			j=1;
			while (1) 
			{
				j++;
				i++;
				if (i==num-1) {
					break;
				}
				if (strcoll(res[i],res[i+1])!=0) {
					break;
				}
			}
			time[n_result++]=j;
			
		}
		

	}
	
	for (i=0; i<n_result; i++) {
		sign=1;
		printf("%s %i\n",result[i],time[i]);
		
	}
	
	if (sign!=1) {
		printf("No duplicates\n");
	}
		
	
    return 0;
}


