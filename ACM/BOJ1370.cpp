#include <iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
int cmp(const void* a,const void* b)
{
	return *((int*)a)>*((int*)b)?1:-1;
}
int main (int argc, char * const argv[]) {
	int n,num[10001],i;
	while (cin>>n) {
		for (i=0; i<n; i++) 
			cin>>num[i];
		qsort(num, n, sizeof(int), cmp);
		cout << num[n/2]<<endl;
	}
    return 0;
}
