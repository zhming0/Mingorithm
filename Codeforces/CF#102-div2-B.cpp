#include<string>
#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
int main (int argc, const char * argv[])
{
    string s;
    bool isMinus = false;
    int dotpos;
    cin >> s;
    if (s[0] == '-') {
        isMinus = true;
        s.erase(0, 1);
    }
    dotpos = s.find('.');
    if (dotpos != string::npos) {
        if (s.length() -1 - dotpos < 2)
            s.append("0");
        if (s.length() -1 - dotpos < 2)
            s.append("0");
        if (s.length() -1 - dotpos > 2)
            s.erase(s.begin()+dotpos+3, s.end());
    }else {
        s.append(".00");
        dotpos = s.length() - 3;
    }
    int count = 0;
    for (int i=dotpos-1; i>=0 && s[i]!='-'; i--) {
        count++;
        if (count>3) {
            s.insert(i+1, ",");
            count-=3;
        }
    }
    if (isMinus == true)
        cout << "(" << "$" << s << ")" << endl;
    else
        cout << "$" << s << endl;
    return 0;
}

