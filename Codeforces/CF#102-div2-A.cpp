#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include <iostream>
using namespace std;
int main (int argc, const char * argv[])
{
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    bool flag = false;
    for(int i=1; i<10; i++)
        for (int j=1; j<10; j++)
            for(int k=1; k<10; k++)
                for (int l=1; l<10; l++) {
                    if (i==j || j==k || k == l ||i==k || i == l || j == l)
                        continue;
                    if (d1 != i+l ||
                        d2 != j+k ||
                        c1 != i+k ||
                        c2 != j+l ||
                        r1 != i+j ||
                        r2 != k+l)
                        continue;
                    printf("%d %d\n", i, j);
                    printf("%d %d\n", k, l);
                    return 0;
                }
    printf("-1\n");
    return 0;
}

