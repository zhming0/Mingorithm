#include<cstring>
#include<cstdio>
#include <iostream>
#include<algorithm>
using namespace std;
struct Seg{
    int start,end;
    int latest;
    bool operator < (const Seg& b) const
    {
        return latest<b.latest ||(latest==b.latest&&end<b.end);
    }
}s[100100];
int n;
int main (int argc, const char * argv[])
{
    while (~scanf("%d", &n)&&n) {
        bool flag=true;
        for (int i=0; i<n; i++) {
            scanf("%d %d", &s[i].start, &s[i].end);
            if ((s[i].end-s[i].start)%2==0) 
                s[i].latest=s[i].start+(s[i].end-s[i].start)/2-1;
            else
                s[i].latest=s[i].start+(s[i].end-s[i].start)/2;
        }
        sort(s, s+n);
        int now=s[0].start;
        for (int i=0; i<n-1; i++) 
        {
            if (now>s[i].latest) {
                flag=false;
                break;
            }
            now+=((s[i].end-s[i].start)/2+1);
            now=max(now, s[i+1].start);
        }
        if (now>s[n-1].latest) 
            flag=false;
        if (!flag) 
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

