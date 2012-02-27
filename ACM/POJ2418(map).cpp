#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int> mp;
int main()
{
    string s;
    int cnt = 0;
    while(getline(cin, s)){
        mp[s]++;
        cnt++;
    }
    for (map<string, int>::iterator i=mp.begin(); i != mp.end(); i++)
        printf("%s %.4f\n", i->first.c_str(), (double) i->second * 100.0 / (double) cnt);
    return 0;
}
