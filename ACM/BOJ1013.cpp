#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void insert(int num,int size,int* heap)
{
	int i,child;
	for (i=1;i<=size-1; i=child) {
		if (num>heap[i]) {
			int temp=heap[i];
			heap[i]=num;
			num=temp;
		}
		child=i*2;
		if (child<size-1) 
			if(heap[child]<heap[child+1])
				child++;
	}
	heap[size]=num;
}

int deleteMax(int* heap,int* size)
{
	int max=heap[1];
	int i;
	int child;
	heap[1]=heap[*size];
	(*size)--;
	int p=heap[1];
	for (i=1; i*2<=*size; i=child) {
		child=i*2;
		if (child!=*size) 
			if(heap[child]<heap[child+1])
				child++;
		if (p<heap[child]) {
			heap[i]=heap[child];
		}else
			break;
	}
	heap[i]=p;
	return max;
}

int main (int argc, const char * argv[]) {
	int n,i,j;
	int* heap=(int*)malloc(sizeof(int)*1010);
	//freopen("Stripies.in", "r", stdin);
	while (scanf("%d",&n)!=EOF) {
		memset(heap,0,sizeof(heap));
		int size=0;
		for (i=1; i<=n; i++) {
			size++;
			int temp;
			scanf("%d",&temp);
			insert(temp, size, heap);
		}
		int* table=(int*)malloc(sizeof(int)*(n+1));
		table[0]=0;
		for (i=1; i<=n; i++) {
			table[i]=deleteMax(heap,&size);
		}
		double ans=table[1];
		for (i=2; i<=n; i++) {
			ans=2*(double)(sqrt((double)(ans*table[i])));
		}
		printf("%.3f\n",ans);
	}
    return 0;
}
