#include<cstring>
#include<string>
#include<cstdio>
#include <iostream>
using namespace std;
int n, k;

static bool isRhy(const string& a, const string& b)
{
    int i, j;
    int tmp1=0, tmp2=0;
    if (a.length() < k || b.length() < k)
        return false;
    for (i=(int)a.length()-1; i>=0; i--) {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i]=='u')
            tmp1++;
        if (tmp1 == k)
            break;
    }
    for (j=(int)b.length()-1; j>=0; j--)
    {
        if (b[j] == 'a' || b[j] == 'e' || b[j] == 'i' || b[j] == 'o' || b[j]=='u')
            tmp2++;
        if (tmp2 == k)
            break;
    }
    if (i<0 || j<0 || tmp1!=k || tmp2!=k)
        return false;
    if (a.substr(i) == b.substr(j)) 
        return true;
    else
        return false;
}

int main (int argc, const char * argv[])
{
    string s[5];
    cin >> n >> k;
    int aaaa = 0, aabb = 0, abab=0, abba = 0;
    bool hasRhy = true;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<4; j++) cin>>s[j];
        if (isRhy(s[0], s[1]) &&
            isRhy(s[1], s[2]) &&
            isRhy(s[2], s[3])) {
            aaaa++;
        }else if (isRhy(s[0], s[1]) &&
                 isRhy(s[2], s[3]))
            aabb++;
        else if (isRhy(s[0], s[3]) &&
                 isRhy(s[1], s[2]))
            abba++;
        else if (isRhy(s[0], s[2]) &&
                 isRhy(s[1], s[3]))
            abab++;
        else {
            hasRhy = false;
            break;
        }
        if (aabb * abab !=0 ||
            aabb * abba !=0 ||
            abab * abba !=0) {
            hasRhy = false;
            break;
        }
    }
    if(!hasRhy) {
        printf("NO\n");
    } else if (aaaa == n) {
        printf("aaaa\n");
    } else if (aabb != 0){
        printf("aabb\n");
    } else if (abba!=0)
        printf("abba\n");
    else if (abab!=0)
        printf("abab\n");
    else
        ;
    return 0;
}
