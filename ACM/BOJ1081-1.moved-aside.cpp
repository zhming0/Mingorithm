#include <stdio.h>
#include<string.h>
#include<stdlib.h>


int	CountEne(int* a)
{
	int	i;
	int Ene=0;
	for (i=0; i<=100; i++) {
		if (a[i]!=0) 
		{
			Ene++;
		}
	}
	return Ene;
}

void MyClear(int* a)
{
	int i;
	for (i=0; i<=100; i++) 
	{
		a[i]=0;
	}
}

int seek_pubene(int** s)
{
	int i;
	int tem=CountEne(s[0]);
	int Max;
	for (i=0; i<=100; i++) 
	{
		if (CountEne(s[i])>tem) 
		{
			Max=i;
			tem=CountEne(s[i]);
		}
	}
	return Max;
}

int clear_pubene(int b,int** s)
{
	int i,j;
	for (i=0; i<=100; i++) 
	{
		for (j=0; j<=100; j++) 
		{
			if (b==s[i][j]) 
			{
				return 1;
			}
		}
	}
	return 0;
}

/*int seekFriend(int** s,int pep)
{
	int i,j;
	int sign=0;
	for (i=1; i<=pep; i++) {
		sign=0;
		
		for (j=0; j<=pep; j++) 
		{
			if (s[i][j]!=j&&j!=i) 
			{
				sign=1;
				return 1;
			}
		}
		
		
	}
	return 0;
}*/


int main (int argc, const char * argv[]) {
    int people,foe;
	int tes;
	int num_ofteam;
	int a,b;
	int** team;
	team=(int**)malloc(sizeof(int*)*200);
	int i,j;
	for (i=0; i<200; i++) {
		team[i]=(int*)malloc(sizeof(int)*200);
		for (j=0; j<200; j++) {
			team[i][j]=0;
		}
	}
	while(scanf("%d %d",&people,&foe)!=EOF)
	{
		if (foe==0) {
			printf("%i\n",people);
			continue;
		}
		if (foe==1) {
			printf("%i\n",people-1);
			continue;
		}
	num_ofteam=people;
	for (i=0; i<foe; i++) 
	{
		scanf("%d %d",&a,&b);
		team[a][b]=b;
		team[b][a]=a;
	}
	i=0;
	j=0;
	while (1) 
	{
		if (j==people) 
		{
			break;
		}
		i=seek_pubene(team);
		
		

		tes=clear_pubene(i,team);

		if (tes==1) {
			num_ofteam--;
			
		}
		MyClear(team[i]);
		j++;
	}
	/*if (seekFriend(team,people)==1&&num_ofteam<2) 
		printf("%i\n",2);
	else
		printf("%i\n",num_ofteam);*/
	}
		printf("%i\n",num_ofteam);
    return 0;
}
