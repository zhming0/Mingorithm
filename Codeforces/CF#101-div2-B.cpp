#include<cstring>
#include<cstdio>
#include <iostream>
#include<cmath>
using namespace std;
int main (int argc, const char * argv[])
{
    int length, x, y;
    cin >> length >> x >> y;
    if (y>0 && y<length && abs(2*x) < length) {
        printf("%d\n", 1);
        return 0;
    }
    int j=2;
    int tmp = 0;
    for (int i=length; i<y; i+=length, j+=((tmp+1)%3), tmp=(tmp+1)%2) {
        //printf("j=%d\n", j);
        if (y<i + length && y > i) {
            if (tmp == 0 && abs(2*x) < length) {
                printf("%d\n", j);
                return 0;
            }
            if (tmp == 1 && abs(x) < length && x!=0) {
                printf("%d\n", x>0? j+1: j);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}

