#include<cstring>
#include<cstdio>
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct pint{
    int num;
    double x, y;
}p[60];
const double eps = 1e-8;
static bool cmp(const pint& a, const pint& b){
    double dis1 = (a.x - p[0].x) * (a.x - p[0].x) + (a.y - p[0].y) * (a.y - p[0].y);
    double dis2 = (b.x - p[0].x) * (b.x - p[0].x) + (b.y - p[0].y) * (b.y - p[0].y);
    return (dis1 - dis2 < eps) || 
           (fabs(dis1 - dis2) < eps && a.x - b.x < eps) || 
           (fabs(dis1 - dis2) < eps && fabs(a.x - b.x) < eps && a.y - b.y < eps);
}

int main (int argc, const char * argv[])
{
    int n;
    char tmp;
    const double coe = sin(M_PI/4.0f);
    while (~scanf("%d", &n)) {
        for (int i=0; i<n; i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            y =  -y;
            p[i].x = coe * x + coe * y;
            p[i].y = - coe * x + coe * y;
            p[i].num = i;
        }
        scanf("%c",&tmp);
        scanf("%c",&tmp);
        while (scanf("%c", &tmp) && tmp!='\n' && tmp != '\0') {
            sort(p, p+n, cmp);
            for (int j=1; j<n; j++) {
                if ((p[j].x >= p[0].x && p[j].y >= p[0].y && tmp == 'U') || 
                    (p[j].x >= p[0].x && p[j].y <= p[0].y && tmp == 'R') ||
                    (p[j].x <= p[0].x && p[j].y >= p[0].y && tmp == 'L') ||
                    (p[j].x <= p[0].x && p[j].y <= p[0].y && tmp == 'D')){
                    swap(p[0], p[j]);
                    break;
                }
            }
        }
        printf("%d\n", p[0].num);
    }
    return 0;
}

