#include <stdio.h>
int main (int argc, char * const argv[]) {
	int f[47],i,cases;
	f[0]=0;f[1]=1;f[2]=2;
	for (i=3; i<47; i++) 
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&cases);
	while (cases--) 
	{scanf("%d",&i);printf("%d\n",f[i]);}
    return 0;
}
