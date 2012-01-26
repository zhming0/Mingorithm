#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define t 1<<0;
#define a 1<<8;
int states[32][13][3001];
static bool leap(int year)
{
    if ((year%4==0&&(year%100!=0))||year%400==0) 
        return true;
    else
        return false;
}
static void calNextDay(int day, int month, int year)
{
    int newday=day+1;
    int newmonth=month;
    int newyear=year;
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (newday>31) {
                newday=1;
                newmonth=month+1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (newday>30) {
                newday=1;
                newmonth=month+1;
            }
            break;
        case 2:
            if (leap(year)) {
                if (newday>29) {
                    newday=1;
                    newmonth=month+1;
                }
            }else {
                if (newday>28) {
                    newday=1;
                    newmonth=month+1;
                }
            }
            break;
        default:
            break;
    }
    if(newmonth>12){
        newmonth=1;
        newyear++;
    }
    for (int i=1; i<=7; i++) 
        if (states[day][month][year]&(1<<i)){ 
            states[newday][newmonth][newyear]=1<<((i==7)?1:i+1);
            break;
        }
}
static void calPreDay(int day, int month ,int year)
{
    
}
int main (int argc, const char * argv[])
{
    memset(states, 0, sizeof(states));
    states[23][10][2010]=(1<<6);
    string s,r;
    int y;
    while (cin>>s>>r>>y) {
        
    }
    return 0;
}

