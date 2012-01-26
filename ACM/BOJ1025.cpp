#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
struct table {
	int floor;
	int people;
};


int cmp_table(const void*,const void*);
int chooseBig(int*);

int chooseState(int,struct table*);


int main (int argc, const char * argv[]) {
    int CASE;
	scanf("%d",&CASE);
	int count=1;
	int i;
	while (count++<=CASE) {
		int C,m;
		int j=0;
		int times=0;
		int des[MAX];
		int inElevator[3];
		int state;
		struct table a[40];
		for (i=0; i<40; i++) {
			a[i].people=0;
		}
		scanf("%d %d",&C,&m);
		for (i=0; i<3; i++) {
			inElevator[i]=C;
		}
		for (i=0; i<m; i++)
			scanf("%d",&des[i]);
		for (i=0; i<m; i++) {
			a[des[i]].floor=des[i];
			a[des[i]].people++;
		}
		qsort(a, 40, sizeof(a[0]), cmp_table);
		while (1) {
			state=chooseState(inElevator[chooseBig(inElevator)], a);
			switch (state) {
				case 1:
					for (j=0; a[j].people!=0; j++) {
						for (i=0; i<3; i++) {
							if (a[j].people<=inElevator[i]&&inElevator>0) 
							{
								a[j].people=0;
								inElevator[i]-=a[j].people;
								times++;
								break;
							}
						}
					}
					break;
				case 0:
					a[0].people-=inElevator[chooseBig(inElevator)];
					times++;
					break;
				default:
					break;
			}
			if (state==2)
				break;
			qsort(a, 40, sizeof(a[0]), cmp_table);
			
		}
		printf("Case: %d\n%d\n",count-1,times);
	}
    return 0;
}


int cmp_table( const void *a ,const void *b)
{
	return (*(struct table *)a).people > (*(struct table *)b).people ? -1 : 1;
}

int chooseBig(int* a)
{
	int temp=0;
	int big;
	int i;
	for (i=0; i<3; i++) {
		if (a[i]>temp) {
			temp=a[0];
			big=i;
		}
	}
	return big;
}


int chooseState(int space,struct table* a)
{
	int i;
	if (a[0].people==0) {
		return 2;
	}
	for (i=0; a[i].people!=0; i++) {
		if (a[i].people<=space) 
			return 1;
	}
	return 0;
}





