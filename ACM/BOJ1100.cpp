#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
int n;
int *s1, *s2;
long long ret;
static void mergeSequence(int* a, int* b, int l, int r, int m){
    int i = l, j = m+1;
    while (i<=m && j<=r) {
        if (a[i] <= a[j]) {
            b[l++] = a[i++];
        }else {
            b[l++] = a[j++];
            ret += (long long) m - i + 1;
        }
    }
    while (i<=m) 
        b[l++] = a[i++];
    while (j<=r) 
        b[l++] = a[j++];
}

static void mergeSort(int* a, int* b, int l, int r)
{
    if (l<r) {
        int m = (l+r) >> 1;
        mergeSort(a, b, l, m);
        mergeSort(a, b, m+1, r);
        mergeSequence(a, b, l, r, m);
        while (l<=r) 
            a[l] = b[l], l++;
    }
}

int main (int argc, const char * argv[])
{
    while (~scanf("%d", &n)) {
        ret=0;
        s1=new int[n];
        s2=new int[n];
        for(int i=0; i<n; i++) 
            scanf("%d",&s1[i]), s2[i] = s1[i];
        mergeSort(s1, s2, 0, n-1);
        cout << ret << endl;
        delete s1;
        delete s2;
    }
    return 0;
}

