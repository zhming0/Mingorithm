#include<cstdio>
#include<cstring>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    long long money;
    int city;
};
struct Pig{
    int num;
    int w;
}p[1010];
int dis[1010], price[1010], citysell[1010];
bool visited[1010];
vector<node> pig[1010];
int n, t;
static bool cmp(const Pig& a, const Pig& b){
    return b.w<a.w;
}
static bool cmp_node(const node& a, const node& b){
    return b.money<a.money;
}
int main (int argc, const char * argv[])
{
    while (~scanf("%d %d", &n, &t)) {
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<n; i++) {scanf("%d", &p[i].w); p[i].num=i;}
        for (int i=0; i<n; i++) scanf("%d", &dis[i]);
        for (int i=0; i<n; i++) scanf("%d", &price[i]);
        sort(p, p+n, cmp);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                node tmp; 
                tmp.money = (long long)(price[j]*p[i].w - dis[j]*t*p[i].w);
                tmp.city = j;
                pig[i].push_back(tmp);
            }
            sort(pig[i].begin(), pig[i].end(), cmp_node);
        }
        for (int i=0; i<n; i++) 
            for (int j=0; j<pig[i].size(); j++) 
                if (!visited[pig[i][j].city]) {
                    citysell[pig[i][j].city] = p[i].num+1;
                    visited[pig[i][j].city] = 1;
                    break;
                }
        for (int i=0; i<n-1; i++) 
            printf("%d ", citysell[i]);
        printf("%d\n", citysell[n-1]);
    }
    return 0;
}

