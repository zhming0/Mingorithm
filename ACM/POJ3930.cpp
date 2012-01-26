#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define UP 1
#define DOWN 0
#define IDEL 0
#define OPEN 1
#define CLOSE 2
#define MOV 3
using namespace std;
struct E{
    int t, from, to;
    int toward;
    bool operator < (const E& b) const{
        return t<b.t ||(t==b.t && from>b.from) || (t==b.t && from==b.from && to>b.to);
    }
}e[110];
vector<int> out_req[51][2];
int inner_req[51];
int current,n, maxfloor;
int nowTime ,done, states ,des;

static void processIdel()
{
    if (!out_req[current][UP].empty() || !out_req[current][DOWN].empty()) {
        states=OPEN;
        printf("%02d:%02d The elevator door is opening.\n", nowTime/60, nowTime%60);
        return;
    }
    int earlist=5000;
    int validEvent=-1;
    for (int i=1; i<=maxfloor; i++) {
        if (!out_req[i][UP].empty()) 
        {
            if (earlist>e[out_req[i][UP][0]].t || (earlist==e[out_req[i][UP][0]].t && i>current)) {
                earlist=e[out_req[i][UP][0]].t;
                validEvent=out_req[i][UP][0];
            }
        }
        if (!out_req[i][DOWN].empty()) {
            if (earlist>e[out_req[i][DOWN][0]].t || (earlist==e[out_req[i][DOWN][0]].t && i>current)) {
                earlist=e[out_req[i][DOWN][0]].t;
                validEvent=out_req[i][DOWN][0];
            }
        }
    }
    if (earlist!=5000) {
        states=MOV;
        if (e[validEvent].from>current) {
            des=UP;
            printf("%02d:%02d The elevator starts to move up from floor %d.\n", nowTime/60, nowTime%60, current);
        }else{
            des=DOWN;
            printf("%02d:%02d The elevator starts to move down from floor %d.\n", nowTime/60, nowTime%60, current);
        }  
        return;
    }else
        states=IDEL;
}
static void processOpen()
{
    if (inner_req[current]!=0)
    {
        done+=inner_req[current];
        printf("%02d:%02d %d people leave the elevator.\n", nowTime/60, nowTime%60, inner_req[current]);
        inner_req[current]=0;
        bool temp_flag=false;
        if (des==UP) {
            for (int i=current+1; i<=maxfloor; i++) 
                if (inner_req[i]>0 || !out_req[i][UP].empty() || !out_req[i][DOWN].empty())  
                    temp_flag=true;
        }else if (des==DOWN){
            for (int i=1; i<current; i++) 
                if (inner_req[i]>0 || !out_req[i][UP].empty() || !out_req[i][DOWN].empty()) 
                    temp_flag=true;
        }
        if (!temp_flag)
            des=-1;
        return;
    }
    int count=0;
    if (des==-1) {
        if(!out_req[current][UP].empty()&&!out_req[current][DOWN].empty()) 
        {
            if (e[out_req[current][UP][0]].t<=e[out_req[current][DOWN][0]].t) {
                des=UP;
            }else
                des=DOWN;
        }
        if (out_req[current][UP].empty()&&!out_req[current][DOWN].empty()) {
            des=DOWN;
        }
        if (!out_req[current][UP].empty()&&out_req[current][DOWN].empty()) {
            des=UP;
        }
    }
    if (des==UP && !out_req[current][UP].empty()) {
        while (!out_req[current][UP].empty()) {
            inner_req[e[out_req[current][UP][0]].to]++;
            count++;
            out_req[current][UP].erase(out_req[current][UP].begin());
        }
    }
    if(des==DOWN && !out_req[current][DOWN].empty()){
        while (!out_req[current][DOWN].empty()) {
            inner_req[e[out_req[current][DOWN][0]].to]++;
            count++;
            out_req[current][DOWN].erase(out_req[current][DOWN].begin());
        }
    }
    if (count!=0) {
        printf("%02d:%02d %d people enter the elevator.\n", nowTime/60, nowTime%60, count);
        return;
    }
    if (des!=-1) {
        printf("%02d:%02d The elevator door is closing.\n", nowTime/60, nowTime%60);
        states=CLOSE;
        return;
    }
   
    int earlist=5000;
    int validEvent=-1;
    for (int i=1; i<=maxfloor; i++) {
        if (!out_req[i][UP].empty()) 
        {
            if (earlist>e[out_req[i][UP][0]].t||(earlist==e[out_req[i][UP][0]].t && i>current)) {
                earlist=e[out_req[i][UP][0]].t;
                validEvent=out_req[i][UP][0];
            }
        }
        if (!out_req[i][DOWN].empty()) {
            if (earlist>e[out_req[i][DOWN][0]].t || (earlist==e[out_req[i][DOWN][0]].t && i>current)) {
                earlist=e[out_req[i][DOWN][0]].t;
                validEvent=out_req[i][DOWN][0];
            }
        }
    }
    if (earlist!=5000) {
        if (e[validEvent].from>current) {
            des=UP;
        }else
            des=DOWN;
        printf("%02d:%02d The elevator door is closing.\n", nowTime/60, nowTime%60);
        states=CLOSE;
        return;
    }else{
        printf("%02d:%02d The elevator door is closing.\n", nowTime/60, nowTime%60);
        states=CLOSE;
        return;
    }
    
}
static void processClose()
{
    if (des==-1 && out_req[current][0].empty() && out_req[current][1].empty()) {
        
        int earlist=5000;
        int validEvent=-1;
        for (int i=1; i<=maxfloor; i++) {
            if (!out_req[i][UP].empty()) 
            {
                if (earlist>e[out_req[i][UP][0]].t || (earlist==e[out_req[i][UP][0]].t && i>current)) {
                    earlist=e[out_req[i][UP][0]].t;
                    validEvent=out_req[i][UP][0];
                }
            }
            if (!out_req[i][DOWN].empty()) {
                if (earlist>e[out_req[i][DOWN][0]].t) {
                    earlist=e[out_req[i][DOWN][0]].t;
                    validEvent=out_req[i][DOWN][0];
                }
            }
        }
        if (earlist!=5000) {
            if (e[validEvent].from>current) {
                des=UP;
                printf("%02d:%02d The elevator starts to move up from floor %d.\n", nowTime/60, nowTime%60, current);
            }else{
                des=DOWN;
                printf("%02d:%02d The elevator starts to move down from floor %d.\n", nowTime/60, nowTime%60, current);
            }
            states=MOV;
        }else{
            states=IDEL;
        }
        return;
    }
    if (des==-1 && (!out_req[current][UP].empty() || !out_req[current][DOWN].empty())) {
        printf("%02d:%02d The elevator door is opening.\n", nowTime/60, nowTime%60);
        states=OPEN;
        return;
    }
    if (des!=-1 && out_req[current][UP].empty() && out_req[current][DOWN].empty()) {
        if (des==UP) {
            printf("%02d:%02d The elevator starts to move up from floor %d.\n", nowTime/60, nowTime%60, current);
        }else
            printf("%02d:%02d The elevator starts to move down from floor %d.\n", nowTime/60, nowTime%60, current);
        states=MOV;
        return;
    }
    if ((des==UP && !out_req[current][UP].empty()) || (des==DOWN && !out_req[current][DOWN].empty())) {
        printf("%02d:%02d The elevator door is opening.\n", nowTime/60, nowTime%60);
        states=OPEN;
        return;
    }else{
        if (des==UP) {
            printf("%02d:%02d The elevator starts to move up from floor %d.\n", nowTime/60, nowTime%60, current);
        }else
            printf("%02d:%02d The elevator starts to move down from floor %d.\n", nowTime/60, nowTime%60, current);
        states=MOV;
    }
    return;
}

static void processMove()
{
    if (des==UP) 
        current++;
    else
        current--;
    if ((inner_req[current]!=0 || !out_req[current][des].empty())) {
        states=OPEN;
        printf("%02d:%02d The elevator stops at floor %d.\n", nowTime/60, nowTime%60, current);
        printf("%02d:%02d The elevator door is opening.\n", nowTime/60, nowTime%60);
        return;
    }
    bool iflag=false;
    if (des==UP) {
        for (int i=current+1; i<=maxfloor; i++) {
            if (!out_req[i][DOWN].empty() || !out_req[i][UP].empty() || inner_req[i]>0) {
                iflag=true;
            }
        }
    }else if(des==DOWN){
        for (int i=1; i<current; i++) {
            if (!out_req[i][DOWN].empty() || !out_req[i][UP].empty() || inner_req[i]>0) {
                iflag=true;
            }
        }
    }
    if (!iflag) 
    {
        if (!out_req[current][UP].empty() || !out_req[current][DOWN].empty()) {
            states=OPEN;
            printf("%02d:%02d The elevator stops at floor %d.\n", nowTime/60, nowTime%60, current);
            printf("%02d:%02d The elevator door is opening.\n", nowTime/60, nowTime%60);
            if (!out_req[current][UP].empty()) 
                des=UP;
            else
                des=DOWN;
        }
    }
}

int main(){
    int cases, T=0;
    scanf("%d",&cases);
    while (cases--) {
        printf("Case %d:\n", ++T);
        scanf("%d %d", &current, &n);
        maxfloor=0;
        for (int i=0; i<n; i++) {
            scanf("%d %d %d", &e[i].t, &e[i].from, &e[i].to);
            if (e[i].to>e[i].from) 
                e[i].toward=UP;
            else if (e[i].to<e[i].from)
                e[i].toward=DOWN;
            /*else {
                i--;
                n--;
            }*/
            maxfloor=max(maxfloor, max(e[i].to, e[i].from));
        }
        done=nowTime=states=0;
        des=nowTime=-1;
        int validEvent=0;;
        sort(e, e+n);
        memset(inner_req, 0, sizeof(inner_req));
        for (int i=0; i<=50; i++) {
            out_req[i][0].clear();
            out_req[i][1].clear();
        }
        while (1) {
            nowTime++;
            //printf("now the des=%d\n",des);
            if ((done>=n && states==IDEL) || nowTime>50000) break;
            int i;
            for (i=validEvent; i<n && e[i].t==nowTime; i++) 
                out_req[e[i].from][e[i].toward].push_back(i);
            validEvent=i;
            if (states==IDEL) {
                processIdel();
            }else if(states==OPEN){
                processOpen();
            }else if(states==CLOSE){
                processClose();
            }else {
                processMove();
            }
        }
        printf("\n");
    }
}