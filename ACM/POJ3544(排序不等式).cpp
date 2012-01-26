#include<cstring>
#include<cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Pig{
    int w;
    int num;
}p[1010];
struct City{
    long long benefit;
    int num;
}city[1010];
long long price[1010], dis[1010];
int citysell[1010];
static bool cmp_pig(const Pig& a, const Pig& b){
    return a.w > b.w;
}
static bool cmp_city(const City& a, const City& b){
    return a.benefit > b.benefit;
}
int n;
long long t;
int main (int argc, const char * argv[])
{
    while (~scanf("%d %I64d", &n, &t)) {
        for (int i=0; i<n; i++) {
            scanf("%d", &p[i].w);
            p[i].num=i+1;
        }
        for (int i=0; i<n; i++) scanf("%I64d", &dis[i]);
        for (int i=0; i<n; i++) scanf("%I64d", &price[i]);
        for (int i=0; i<n; i++) {
            city[i].benefit = price[i] - dis[i]*t;
            city[i].num=i+1;
        }
        sort(city, city+n, cmp_city);
        sort(p, p+n, cmp_pig);
        for (int i=0; i<n; i++) 
            citysell[city[i].num] = p[i].num;
        for (int i=1; i<n; i++) 
            printf("%d ", citysell[i]);
        printf("%d\n", citysell[n]);
    }
    return 0;
}

