#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
char p[501000], s[501000];
int alpha_count[27];
int table[27];
int fix[501000];
int main (int argc, const char * argv[])
{
    int ret = 0;
    memset(alpha_count, 0, sizeof(alpha_count));
    memset(fix, 0, sizeof(fix));
    scanf("%s", p);
    scanf("%s", s);
    int l1 = strlen(p), l2 = strlen(s);
    if (l2 > l1) {cout << 0 <<endl; return 0;}
    for(int i=0; i<l2; i++)
        table[s[i]-'a']++;
    for(int i=0; i<l1; i++)
    {
        if (i < l2){
            if (p[i]!='?') {
                alpha_count[p[i]-'a']++;
                fix[i] = fix[i-1];
            }else
                fix[i] = fix[i-1]+1;
        }else {
            int diff = 0;
            bool flag = true;
            for (int j=0; j<26; j++) {
                if (alpha_count[j] > table[j]) {
                    flag = false;
                    break;
                }else if (alpha_count[j] < table[j])
                    diff+= table[j] - alpha_count[j];
            }
            if (flag && diff-fix[i-1]==0) {
                //cout << i <<endl;
                //cout << p[i] <<endl;
                ret++;
            }
            if (p[i]!='?') {
                alpha_count[p[i]-'a']++;
                fix[i] = fix[i-1];
            }else
                fix[i] = fix[i-1] + 1;
            if (p[i-l2] != '?')
                alpha_count[p[i-l2] - 'a']--;
            else
                fix[i]--;
        }
        //printf("fix[%d] = %d\n", i, fix[i]);
    }
    
    bool flag = true;
    int diff = 0;
    for (int j=0; j<26; j++) {
        if (alpha_count[j] > table[j]) {
            flag = false;
            break;
        }else if (alpha_count[j] < table[j])
            diff+= table[j] - alpha_count[j];
    }
    //cout << diff << " " << fix[l1 - 1] << endl;
    if (flag && diff-fix[l1-1]==0)
        ret++;
    cout << ret << endl;
    
    return 0;
}

