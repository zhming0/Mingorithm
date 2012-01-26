#include<cstring>
#include<cstdio>
#include <iostream>
typedef long long LL;
using namespace std;
static LL Extend_euclid(LL a, LL b, LL& x, LL& y)
{
    if (b==0) {
        x=1,y=0;
        return a;
    }
    LL ret;
    LL tempx, tempy;
    ret=Extend_euclid(b, a%b, tempx, tempy);
    x=tempy;
    y=tempx-a/b * tempy;
    return ret;
}

int main (int argc, const char * argv[])
{
    LL a,b,c,k;
    while (scanf("%lld %lld %lld %lld",&a,&b,&c,&k)&&(a||b||c||k)) {
        LL n=1LL<<k;
        LL x,y,e;
        LL d=Extend_euclid(c, n, x, y);
        if ((b-a)%d) {
            printf("FOREVER\n");
            continue;
        }
        e=(x*(b-a)/d)%n+n;
        printf("%lld\n",e%(n/d));
    }
    return 0;
}

