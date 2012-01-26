#include <stdio.h>

int main () 
{
    int a;
	while (scanf("%d",&a)!=EOF) 
	{
		if (a/10==0) {
			printf("%i\n",a);
			continue;
		}
		printf("%i\n",(a/10)*(a%10));
	}
    return 0;
}
