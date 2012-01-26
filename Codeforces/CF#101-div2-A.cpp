#include<cstring>
#include<cstdio>
#include<string>
#include <iostream>
#include<cmath>
using namespace std;
int table[2][26];
int main (int argc, const char * argv[])
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    memset(table, 0, sizeof(table));
    for (int i=0; i<s1.length(); i++) 
        table[0][s1[i]-'A']++;
    for (int i=0; i<s2.length(); i++) 
        table[0][s2[i]-'A']++;
    for (int i=0; i<s3.length(); i++)
        table[1][s3[i]-'A']++;
    for (int i=0; i<26; i++) 
        if (table[0][i] != table[1][i]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    return 0;
}

