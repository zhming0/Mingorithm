#include<cstring>
#include<vector>
#include<algorithm>
#include <iostream>
#include<cmath>
using namespace std;
int mcount[5];
int main (int argc, const char * argv[])
{
    int n, m;
    memset(mcount, 0, sizeof(mcount));
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            int tmp = 0;
            if (i-1>=0 && j-2>=0) tmp++;
            if (i-2>=0 && j-1>=0) tmp++;
            if (i+1<n && j+2<m) tmp++;
            if (i+2<n && j+1<m) tmp++;
            if (i-1>=0 && j+2<m) tmp++;
            if (i+1<n && j-2>=0) tmp++;
            if (i+2<n && j-1>=0) tmp++;
            if (i-2>=0 && j+1<m) tmp++;
            //cout << tmp <<endl;
            if (tmp == 0) mcount[0]++;
            if (tmp == 1) mcount[1]++;
            if (tmp == 2) mcount[2]++;
            if (tmp == 4) mcount[3]++;
            if (tmp == 8) mcount[4]++;
        }
    int ret = 0;
    for(int i=0; i<5; i++) {
        printf("mcount[%d]=%d\n", i, mcount[i]);
        if(mcount[i]<=mcount[i+1]) {
            ret+=mcount[i];
            mcount[i+1] -= mcount[i];
        }else {
            if (i==0) ret+=mcount[i];
            if (i==1) ret+=mcount[i]/2 + (mcount[i]%2==0?0:1);
            if (i==2) ret+=mcount[i]/3 + (mcount[i]%4==0?0:1);
            if (i==3) ret+=mcount[i]/5 + (mcount[i]%5==0?0:1);
            if (i==4) ret+=mcount[i]/9 + (mcount[i]%9==0?0:1);
            //break;
        }
    }
    cout << ret << endl;
    return 0;
}

