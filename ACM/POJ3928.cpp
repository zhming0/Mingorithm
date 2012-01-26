#include<cstring>
#include <iostream>
#include<cstdio>
typedef long long LL;
using namespace std;
#define sizem 100000
#define sizen 20100
int a[sizen+100];
int n, ri[sizem+100], le[sizem+100];
int count_ri[sizen], count_le[sizen];
inline int lowbit(int x){return x&-x;}
static void insert(int b[sizem], int k)
{
    for (int i=k; i<=sizem; i+=lowbit(i)) 
        b[i]++;
}
static int sum(int b[sizem], int k)
{
    int ret=0;
    for (int i=k; i>0; i-=lowbit(i)) 
        ret+=b[i];
    return ret;
}
int main (int argc, const char * argv[])
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) 
            scanf("%d", &a[i]);
        memset(ri, 0, sizeof(ri));
        memset(le, 0, sizeof(le));
        for (int i=0; i<n; i++) {
            count_le[i]=sum(le, a[i]);
            insert(le, a[i]);
        }
        for (int i=n-1; i>=0; i--) {
            count_ri[i]=sum(ri, a[i]);
            insert(ri, a[i]);
        }
        LL ans=0;
        for (int i=1; i<n-1; i++) 
            ans+=(LL)count_le[i]*(LL)(n-i-1-count_ri[i])+(LL)count_ri[i]*(LL)(i-count_le[i]);
        printf("%lld\n", ans);
    }
    return 0;
}

