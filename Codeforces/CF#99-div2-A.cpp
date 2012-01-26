#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
int pages[7];
int main (int argc, const char * argv[])
{
    int n;
    cin >> n;
    for (int i=0; i<7; i++)
        cin>>pages[i];
    int current = 0;
    while(1){
        n-=pages[current];
        if (n<=0)
            break;
        current += 1;
        current %= 7;
    }
    printf("%d\n", current+1);
    return 0;
}

