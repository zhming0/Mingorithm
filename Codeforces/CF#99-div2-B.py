#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
struct Room{
    int x, y, z;
}r[510];
struct Paper{
    int length, width, price;
}p[510];
int n, m;
int main (int argc, const char * argv[])
{
    int ret = 0;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> r[i].x >> r[i].y >> r[i].z;
    cin >> m;
    for (int i=0; i<m; i++)
        cin >> p[i].length >> p[i].width >> p[i].price;
    for (int i=0; i<n; i++)
    {
        int len = r[i].x * 2 + r[i].y * 2;
        int tmp_ret = 0x7fffffff;
        for (int j=0; j<m; j++) {
            int k = p[j].length / r[i].z;
            if (k==0) continue;
            tmp_ret = min(tmp_ret, (len/(k*p[j].width) + (len%(k*p[j].width)==0?0:1))*p[j].price);
        }
        ret+=tmp_ret;
    }
    printf("%d\n", ret);
    return 0;
}

