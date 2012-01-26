#include<cstring>
#include<vector>
#include<algorithm>
#include <iostream>
#include<cmath>
using namespace std;
vector<long long> fac;
int main (int argc, const char * argv[])
{
    long long n, ret_max = -1, ret_min=-1;
    cin >> n;
    for (long long i=1; i<=sqrt(n); i++) {
        if (n%i==0) {
            fac.push_back(i);
            if (i!=n/i)
                fac.push_back(n/i);
        }
    }
    for (int i=0; i<fac.size(); i++)
        for (int j=0; j<fac.size(); j++)
        {
            if (fac[i]*fac[j] > n || n%(fac[i]*fac[j])!=0)
                continue;
            long long k = n/(fac[i]*fac[j]);
            if (ret_max == -1) 
                ret_max = (fac[i]+1)*(fac[j]+2)*(k+2);
            if (ret_min == -1)
                ret_min = (fac[i]+1)*(fac[j]+2)*(k+2);
            ret_max = max(ret_max, (fac[i]+1)*(fac[j]+2)*(k+2));
            ret_min = min(ret_min, (fac[i]+1)*(fac[j]+2)*(k+2));
        }
    cout << ret_min-n << " "<< ret_max-n << endl;
    return 0;
}

