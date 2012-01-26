#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}

int CrossRiver(int pep,int* ti)
{
	int endpoint=pep-1;
	int wholetime=0;
	for (;pep>=4 ; endpoint-=2) {
		if ((ti[0]+ti[endpoint-1])<=(2*ti[1])) {
			wholetime=wholetime+2*ti[0]+ti[endpoint-1]+ti[endpoint];
		}
		else if((ti[0]+ti[endpoint-1])>(2*ti[1]))
		{
			wholetime=wholetime+2*ti[1]+ti[0]+ti[endpoint];
		}
		pep=pep-2;
	}
	if (pep==3)
		wholetime=wholetime+ti[0]+ti[1]+ti[2];

	else
		wholetime=wholetime+ti[1];
	return wholetime;
}

int main (int argc, const char * argv[]) {
    int n;
	int i,j;

	int people[20];
	int** time;
	scanf("%d",&n);

	time=(int**)malloc(sizeof(int*)*20);

	for (i=0; i<n; i++) {

		scanf("%i",&people[i]);
		time[i]=(int*)malloc(sizeof(int)*people[i]);
		for (j=0;j<people[i];j++) {
			scanf("%i",&time[i][j]);
		}
		qsort(time[i], people[i], sizeof(time[i][0]), cmp);

		if (people[i]==1) {
			printf("%i\n",time[i][0]);
		}
		else if (people[i]==2)
		{
			printf("%i\n",time[i][1]);
		}
		else if (people[i]==3)
		{
			printf("%i\n",time[i][2]+time[i][1]+time[i][0]);
		}
		else {
			printf("%i\n",CrossRiver(people[i], time[i]));
		}

	}

	/*for (i=0; i<n; i++) {
		if (people[i]==1) {
			printf("%i\n",time[i][0]);
		}
		else if (people[i]==2)
		{
			printf("%i\n",time[i][1]);
		}
		else if (people[i]==3)
		{
			printf("%i\n",time[i][2]+time[i][1]+time[i][0]);
		}
		else {
			printf("%i\n",CrossRiver(people[i], time[i]));
		}

	}*/

    return 0;
}
