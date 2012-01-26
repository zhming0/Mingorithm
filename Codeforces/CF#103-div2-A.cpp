#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main (int argc, const char * argv[])
{
    int n, ret = 0;
    int a[110];
    cin >> n;
    int index_min, index_max;
    int MIN = 110, MAX = -1;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]<=MIN) {
            MIN = a[i];
            index_min = i;
        }
        if (a[i] > MAX) {
            MAX = a[i];
            index_max = i;
        }
    }
    if (index_min < index_max)
        ret -= 1;
    ret += (n-1-index_min);
    ret += (index_max);
    cout << ret <<endl;
    return 0;
}

