#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
#define MAX 50000
int highestx[MAX<<2],highesty[MAX<<2];
long long sumx[MAX<<2],sumy[MAX<<2];
int X[1000001],Y[1000001];
int w, h, n, m;
void build(int l,int r,int ind)
{
    highestx[ind]=0;
    highesty[ind]=0;
	if(l==r){
        sumx[ind]=h-m;
        sumy[ind]=w-m;
    }
	int m=(l+r)>>1;
	build(l,m,ind<<1);
	build(m+1,r,ind<<1|1);
    sumx[ind]=sumx[ind<<1]+sumx[ind<<1|1];
    sumy[ind]=sumy[ind<<1]+sumy[ind<<1|1];
}
void updatex(int h,int len,int L,int R,int l,int r,int rt)
{
	if (L<=l&&r<=R) {
		/*if (h-highestx[rt]<) {
            
        }*/
		return;
	}
	int m=(l+r)>>1;
	if (L<=m) updatex(h,len,L,R,l,m,rt<<1);
	if (R>m) updatex(h,len,L,R,m+1,r,rt<<1|1);
}
int main (int argc, const char * argv[])
{
    
    return 0;
}

