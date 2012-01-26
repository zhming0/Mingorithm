#include <iostream>
#include<cstdio>
#include<string>
using namespace std;
char stack[10];
int head;
string s;
int main (int argc, const char * argv[])
{
    while (cin>>s) {
        bool isNone=false;
        bool hasDot=false;
        head=0;
        if (s[s.length()-1]=='.' || s[s.length()-1]==',') {
            stack[head++]=s[s.length()-1];
            s.erase(s.length()-1);
            hasDot=true;
        }
        for (int i=0; i<s.length(); i++) 
            if (s[i]>='A' && s[i] <= 'Z') 
                isNone=true;
        if (!isNone) {
            cout<< s;
            if(hasDot)
                cout<< stack[--head];
            cout<<endl;
            continue;
        }
        for (int i=0; i<s.length(); i++) 
            if(s[i]>='A' && s[i]<='Z')
                s[i]=s[i] - 'A' +'a';
        if (s[s.length()-1]=='x' ||
            s[s.length()-1]=='s' ||
            (s.length()>1 && s.substr(s.length()-2, 2)=="sh") ||
            (s.length()>1 && s.substr(s.length()-2, 2)=="ch")) {
            s.append("es");
        }else if (s[s.length()-1]=='y' && s.length()>1 && s[s.length()-2]!='a' &&
                  s[s.length()-2]!='e' && s[s.length()-2]!='i' &&
                  s[s.length()-2]!='u' && s[s.length()-2]!='o'){
            s[s.length()-1]='i';
            s.append("es");
        }else
            s.append("s");
        cout<< s;
        if(hasDot)
            cout<< stack[--head];
        cout<<endl;
    }
    return 0;
}

