#include<cstring>
#include <iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
typedef long long LL;
using namespace std;
struct Com{
    bool isLoading;
    LL finished;
    bool timetable[1010]; // true online, false offline
}c[21];
struct Cmd{
    int start, comid;
}cmd[20001];
vector<int> server, client;
int n, m, totaltime;
int validCmd;
int spead[21][21];
LL filesize;
static void init()
{
    scanf("%d %d", &n, &totaltime);
    int k;
    cin>>k>>filesize;  //Cin....
    for (int i=0; i<n; i++) {
        c[i].isLoading=false;
        c[i].finished=0;
        memset(c[i].timetable, false, sizeof(c[i].timetable));
    }
    while (k--) {
        int tmp;
        scanf("%d", &tmp);
        c[tmp-1].finished=filesize;
        server.push_back(tmp-1);
    }
    for (int i=0; i<n; i++) 
        if (c[i].finished==0) 
            client.push_back(i);
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            scanf("%d", &spead[i][j]);
    for (int rt=0; rt<n; rt++) {
        int t;
        scanf("%d", &t);
        for (int i=0; i<t; i++) {
            int f, e;
            scanf("%d %d", &f, &e);
            for (int j=f; j<e; j++) 
                c[rt].timetable[j]=true;
        } 
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &cmd[i].start, &cmd[i].comid);
        cmd[i].comid--;
    }
}
static void updateClient(int current)
{
    int i;
    for (i=validCmd; i<m && cmd[i].start<=current; i++) 
        c[cmd[i].comid].isLoading=true;
    validCmd=i;
}
static LL findSpeed(int current, int comid)
{
    LL s=0;
    for (int i=0; i<server.size(); i++) 
        if (c[server[i]].timetable[current]) 
            s+=(LL)spead[server[i]][comid];
    return s;
}
int main (int argc, const char * argv[])
{
    int cases;
    scanf("%d" ,&cases);
    
    while (cases--) {
        client.clear();
        server.clear();
        init();
        validCmd=0;
        for (int current=0; current<=totaltime; current++) 
        {
            updateClient(current);
            vector<int>::iterator it;
            queue<int> q;
            for (it=client.begin(); it!=client.end(); it++) 
            {
                if(c[(*it)].timetable[current] && c[(*it)].isLoading)
                {
                    c[(*it)].finished+=findSpeed(current, *it);
                    if (c[(*it)].finished>=filesize) {
                        q.push((*it));
                        client.erase(it);
                        it--;
                    }
                }
            }
            while (!q.empty()) {
                server.push_back(q.front());
                q.pop();
            }
        }
        for (int i=0; i<n; i++) 
            printf("%lld%%\n", (c[i].finished*100)/filesize);
    }
    return 0;
}

