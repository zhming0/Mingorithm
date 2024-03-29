#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ColorfulStrings {
public:
    map<int, int> mp;
    int num, ansnum;
    string ret;
    int s[10];
    bool solve(int now, int n)
    {
        if (now == n || ansnum == num) {
            ansnum++;
            return true;
        }
        for (int i=2; i<=9; i++)
        {
            bool flag = true;
            if (mp.find(i)!=mp.end()) continue;
            vector<int> tv;
            int tmp = i;
            for (int j=now-1; j>=0; j--)
            {
                tmp *= s[j];
                if (mp.find(tmp) != mp.end()){
                    flag = false;
                    break;
                }
                tv.push_back(tmp);
            }
            if (!flag) continue;
            tv.push_back(i);
            for (int j=0; j<tv.size(); j++)
                mp[tv[j]] = 1;
            s[now] = i;
            solve(now+1, n);
            if (ansnum==num) return true;
            for (int j=0; j<tv.size(); j++)
                mp.erase(tv[j]);
        }
        return false;
    }
	string getKth(int n, int k) {
		if (n>8) return "";
		if (n==1 && k>0 && k<=10) { ret += ('0' + k -1); return ret;}
		if (n==1 && k>10) return "";
		num = k; ansnum = 0;
		if (solve(0, n)){
		    for (int i=0; i<n; i++)
		        ret += '0' + s[i];
		    return ret;
		}else
            return "";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	ColorfulStrings *obj;
	string answer;
	obj = new ColorfulStrings();
	clock_t startTime = clock();
	answer = obj->getKth(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	string p2;

	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 4;
	p2 = "238";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 2000;
	p2 = "";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 1;
	p2 = "23457";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 22;
	p2 = "52";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	p0 = 8;
	p1 = 1;
	p2 = "25346879";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
