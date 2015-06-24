// BEGIN CUT HERE
/*
SRM 646 Div2 Medium (500)

PROBLEM STATEMENT
John is standing at the origin of an infinite two-dimensional grid.
He is going to move along this grid.
During each second he can either stay where he is or he can move by one unit in one of the four cardinal directions (north, south, east, or west).
Some of the grid points are blocked.
John is not allowed to move to a blocked grid point.

You are given the coordinates of the blocked grid points as vector <int>s x and y.
For each valid i, the grid point that is x[i] units east and y[i] units north of the origin is blocked.
You are also given an int k.
Compute and return the maximal possible x-coordinate of a point John can reach in k seconds.


DEFINITION
Class:TheGridDivTwo
Method:find
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int find(vector <int> x, vector <int> y, int k)


CONSTRAINTS
-x will contain between 0 and 47 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -1,000 and 1,000, inclusive.
-Each element of y will be between -1,000 and 1,000, inclusive.
-All pairs (x[i], y[i]) will be distinct.
-Each pair (x[i], y[i]) will be different from (0, 0).
-k will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{1,1,1,1}
{-2,-1,0,1}
4

Returns: 2

The optimal strategy is to move two times north to (0, 2) and then two times east to (2,2).


1)
{-1, 0, 0, 1}
{0, -1, 1, 0}
9

Returns: 0

John can not make any moves.


2)
{}
{}
1000

Returns: 1000


3)
{1,0,0,-1,-1,-2,-2,-3,-3,-4,-4}
{0,-1,1,-2,2,-3,3,-4,4,-5,5}
47

Returns: 31


*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> Queue;

class TheGridDivTwo {
public:
	int find(vector <int> x, vector <int> y, int k) {
		int ans = 0;

		bool vis[2002][2002] = {};
		vis[1000][1000] = true;
		for (int i = 0; i < (int)x.size(); ++i) {
			vis[1000 + y[i]][1000 + x[i]] = true;
		}

		Queue q;
		q.push_back(II(1000, 1000));
		for (int t = 0; t < k; ++t) {
			Queue next;
			for (int i = 0; i < (int)q.size(); ++i) {
				const int dx[] = { -1, 1, 0, 0 };
				const int dy[] = { 0, 0, -1, 1 };
				int x = q[i].second, y = q[i].first;
				for (int d = 0; d < 4; ++d) {
					int nx = x + dx[d], ny = y + dy[d];
					if (nx >= 950 && nx <= 2000 && ny >= 950 && ny <= 1050) {
						if (!vis[ny][nx]) {
							next.push_back(II(ny, nx));
							vis[ny][nx] = true;
							ans = max(ans, nx - 1000);
						}
					}
				}
			}
			q = next;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1};
			int Arr1[] = {-2,-1,0,1};
			int Arg2 = 4;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 0, 0, 1};
			int Arr1[] = {0, -1, 1, 0};
			int Arg2 = 9;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			// int Arr0[] = {};
			// int Arr1[] = {};
			int Arg2 = 1000;
			int Arg3 = 1000;

			vector <int> Arg0;
			vector <int> Arg1;
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
			int Arr1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
			int Arg2 = 47;
			int Arg3 = 31;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, find(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheGridDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
