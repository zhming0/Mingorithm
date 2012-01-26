#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int a[1000010];
#define M 20080607
int main()
{
    int n, p, k;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &k, &p);
        int i;
        for(i=0; i<k; i++) a[i] = i+1;
        for(; i<=p/k; i++) a[i] = a[i-1] + a[i/k], a[i]%=M;
        printf("%d\n", a[p/k]);
    }
}