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

struct Point{
    int x, y;
}p[5000];
static bool cmp_x(const Point& p1, const Point& p2)
{
    return p1.x<p2.x;
}
static bool cmp_y(const Point& p1, const Point& p2)
{
    return p1.y<p2.y;
}

class DucksAlignment {
public:
	int minimumTime(vector <string> grid) {
		int ret = 0x7fffffff;
        int cnt=0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++)
                if (grid[i][j]=='o'){
                    p[cnt].x = i;
                    p[cnt++].y = j;
                }
        sort(p, p+cnt, cmp_y);
        for(int i=0; i<grid.size(); i++)
        {
            int tmp = 0;
            for (int k=0; k < cnt; k++)
                tmp += (abs(p[k].x - i));
            
            for (int j =0; j+cnt-1 < grid[0].length(); j++){
                int tmp_count = tmp;
                for (int k=0; k<cnt; k++)
                    tmp_count += abs(p[k].y- (j+k));
                ret = min(tmp_count, ret);
            }
        }
        
        sort(p, p+cnt, cmp_x);
        for(int i=0; i<grid[0].length(); i++)
        {
            int tmp = 0;
            for (int k=0; k < cnt; k++)
                tmp += (abs(p[k].y - i));
            for (int j = 0; j+cnt-1 < grid.size(); j++){
                int tmp_count = tmp;
                for (int k=0; k<cnt; k++)
                    tmp_count += abs(p[k].x-(j+k));
                ret = min(tmp_count, ret);
            }
        } 
        return ret;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	DucksAlignment *obj;
	int answer;
	obj = new DucksAlignment();
	clock_t startTime = clock();
	answer = obj->minimumTime(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
        // ----- test 0 -----
        string t0[] = {".o","o."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 1 -----
        string t0[] = {".o...","..o..","....o"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 2 -----
        string t0[] = {"o..........","..o........",".......o...","...........","...........","...........","........o..","..........."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 16;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 3 -----
        string t0[] = {".........","....o....","........."};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 0;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 4 -----
        string t0[] = {"...o..........................","............................o.",".o............................","............o.................",".................o............","......................o.......","......o.......................","....o.........................","...............o..............",".......................o......","...........................o..",".......o......................"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 99;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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