//Totally wrong!!!!!!

#include<cstring>
#include<cstdio>
#include<string>
#include <iostream>
using namespace std;
int numOfDigit;
string ret[2];
string tmp_ret[2];
bool vst[2][10];
int ans;
static int toInt(const string& s){
    int temp_ret = 0;
    for (int i=0; i<s.length(); i++) {
        temp_ret *= 10;
        temp_ret += s[i] - '0';
    }
    return temp_ret;
}
static void judge()
{
    int tmp = toInt(tmp_ret[0]) + toInt(tmp_ret[1]);
    int tmp_ans=0;
    while(tmp%10 == 0 && tmp) {
        tmp_ans ++;
        tmp/=10;
    }
    if (ans < tmp_ans) {
        ans = tmp_ans;
        ret[0] = tmp_ret[0];
        ret[1] = tmp_ret[1];
    }
}
static void premutate(const string& s, int num, int mode) {
    if (num == numOfDigit) {
        if (mode == 0)
            premutate (s, 0, mode+1);
        else 
            judge();
        return;
    }
    for (int i=0; i<s.length(); i++){
        if (vst[mode][i]) continue;
        vst[mode][i] = true;
        tmp_ret[mode] += s[i];
        premutate(s, num+1, mode);
        tmp_ret[mode].erase(num);
        vst[mode][i] = false;
    }
}
int main (int argc, const char * argv[])
{
    ans = -1;
    string num;
    cin >> num;
    numOfDigit = (int)num.length();
    memset(vst, false, sizeof(vst));
    premutate(num, 0, 0);
    cout << ret[0] << endl;
    cout << ret[1] << endl;
    return 0;
}

