// BEGIN CUT HERE
/*
TCO20 R3A Easy (250)

PROBLEM STATEMENT

You are standing on the cell (0, 0) of an infinite square grid.

Elsewhere in the grid is a rectangular obstacle.
The obstacle covers all cells (x, y) such that x1 <= x <= x2 and y1 <= y <= y2.

The value y1 is positive, the value x1 is non-positive, and the value x2 is non-negative.
This means that if you went in the positive y direction, you would eventually hit the obstacle.

From your starting cell (0, 0) you are allowed to take between 0 and s steps, inclusive.
In each step you can move between two cells that share a side.
Obviously, you cannot enter cells covered by the obstacle.
Return the number of cells you can reach.


DEFINITION
Class:RectangularObstacle
Method:countReachable
Parameters:int, int, int, int, int
Returns:long long
Method signature:long long countReachable(int x1, int x2, int y1, int y2, int s)


CONSTRAINTS
-The x-coordinates will satisfy -10^6 <= x1 <= 0 <= x2 <= 10^6.
-The y-coordinates will satisfy 1 <= y1 <= y2 <= 10^6.
-s will be between 0 and 10^9, inclusive.


EXAMPLES

0)
-5
5
3
3
2

Returns: 13


The situation is shown below: X denotes the obstacle, S your starting position, * other cells you can visit, and . cells you cannot visit because they are too far.


XXXXXXXXXXX
.....*.....
....***....
...**S**...
....***....
.....*.....
...........


1)
-5
5
3
3
3

Returns: 24


The same situation as in Example 0 but we can do one more step. Note that walking into the obstacle is forbidden.


XXXXXXXXXXX
....***....
...*****...
..***S***..
...*****...
....***....
.....*.....
...........


2)
-4
1
1
2
6

Returns: 61


........*.....
.......***....
..XXXXXX***...
.*XXXXXX****..
******S******.
.***********..
..*********...
...*******....
....*****.....
.....***......
......*.......
..............

A fairly general case in which we can go partially around the obstacle.


3)
0
0
1
1
4

Returns: 38


...........
....*.*....
...*****...
..***X***..
.****S****.
..*******..
...*****...
....***....
.....*.....
...........

A nice, vaguely heart-shaped area.


4)
-100
100
42
47
0

Returns: 1

If you cannot move, the only cell you can visit is the starting cell.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

LL sq(int n) {
	if (n <= 0) return 0;
	return (LL)n * n;
}

LL getab(LL& n, LL d) {
	LL x = min(n + 1, d);
	if (x <= 0) return 0;
	LL ret = (n * 2 - x + 3) * x / 2;
	n -= x;
	return ret;
}

class RectangularObstacle {
public:

	long long countReachablell(LL x1, LL x2, LL y1, LL y2, LL s) {
		LL ans = sq(s + 1) + sq(s);
		if (y1 <= s) {
			ans -= sq(s - y1 + 1);
			LL d = s - y1 + 1;
			LL a = d - (x2 + 2), b = d - (-x1 + 2);
			ans += getab(a, y2 - y1 + 1) + getab(b, y2 - y1 + 1);
			ans += sq(a + 1) + sq(b + 1);
			LL i = a + b - (x2 - x1 + 1);
			ans -= sq((i + 1) / 2);
		}
		return ans;
	}

	long long countReachable(int x1, int x2, int y1, int y2, int s) {
		return countReachablell(x1, x2, y1, y2, s);
	}

	long long countReachable2(int x1, int x2, int y1, int y2, int s) {
		LL ans = 1;
		if (s <= 100) {
			vector<II> q;
			q.emplace_back(II(0, 0));
			set<II> ss;
			ss.emplace(II(0, 0));
			for (int i = 0; i < s; ++i) {
				vector<II> nq;
				for (auto xy : q) {
					const int dx[] = { -1,1,0,0 };
					const int dy[] = { 0,0,-1,1 };
					for (int dir = 0; dir < 4; ++dir) {
						int nx = xy.first + dx[dir], ny = xy.second + dy[dir];
						if (nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2) {
							continue;
						}
						II key(nx, ny);
						if (ss.find(key) == ss.end()) {
							++ans;
							nq.emplace_back(key);
							ss.insert(key);
						}
					}
				}
				q = nq;
			}
		}
		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long& Expected, const long long& Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = -5;
			int Arg1 = 5;
			int Arg2 = 3;
			int Arg3 = 3;
			int Arg4 = 2;
			long long Arg5 = 13LL;

			verify_case(n, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = -5;
			int Arg1 = 5;
			int Arg2 = 3;
			int Arg3 = 3;
			int Arg4 = 3;
			long long Arg5 = 24LL;

			verify_case(n, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = -4;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 6;
			long long Arg5 = 61LL;

			verify_case(n, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 4;
			long long Arg5 = 38LL;

			verify_case(n, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arg0 = -100;
			int Arg1 = 100;
			int Arg2 = 42;
			int Arg3 = 47;
			int Arg4 = 0;
			long long Arg5 = 1LL;

			verify_case(n, Arg5, countReachable(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RectangularObstacle ___test;
	___test.run_test(-1);

	for (int t = 0; t < 100000; ++t) {
		int x1 = -rand() % 100;
		int x2 = rand() % 100;
		int y1 = 1 + (rand() % 100);
		int y2 = y1 + (rand() % 100);
		int s = rand() % 100;
		int p = ___test.countReachable(x1, x2, y1, y2, s);
		int q = ___test.countReachable2(x1, x2, y1, y2, s);
		if (p != q) {
			cout << "ERR: " << x1 << "," << x2 << "," << y1 << "," << y2 << "," << s << endl;
			break;
		}
	}
}
// END CUT HERE
