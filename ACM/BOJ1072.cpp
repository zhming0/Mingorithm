#include <stdio.h>
#define MAX 100000
#define MAXINT 10000

int main (int argc, const char * argv[]) {
	int n,k;
	
	while ((scanf("%i %i",&n,&k))!=EOF) 
	{
		
		
		int i;
		int time=0;
		int road[MAX];
		int dis[MAXINT];
		int s=n;
		int Alldis=0;
		int AllS;
		for (i=0; i<=MAX; i++) {
			road[i]=0;
		}
		for (i=0; i<=k; i++) {
			scanf("%i",&dis[i]);
		}
		
		for (i=0; i<=k; i++)
		{
			
			if (dis[i]>n) {
				printf("No Solution\n");
				break;
			}
		}
		
		if(dis[i]<=n)
		{
		
		for (i=0; i<=k; i++) {
			
			Alldis=Alldis+dis[i];
			road[Alldis]=dis[i];
		}
		AllS=Alldis;
		Alldis=0;
		
		while (1) {
			
			if (road[Alldis+s]!=0) {
				Alldis=Alldis+s;
				
				if (Alldis==AllS) {
					break;
				}
				time++;
				s=n+1;
				
			}
			s--;
		}
		
	printf("%i\n",time);	
		}
	}
    return 0;
}
