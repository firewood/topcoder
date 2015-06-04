// BEGIN CUT HERE
/*
SRM 660 Div1 Easy (250)

PROBLEM STATEMENT
There is a rectangular field divided into a grid of n rows by m columns of unit square cells.
Each cell (i, j) has some strategic value which is an integer between 0 and 9, inclusive.
You are given these values as a vector <string> a where each a[i][j] is a digit between '0' and '9', inclusive.

It is possible to build stations in some cells.
A station built in a cell covers some set of cells.
You are given the offsets of those cells as vector <int>s x and y.
More precisely, for each valid k, a station in the cell (i, j) covers the cell (i + x[k], j + y[k]) if a cell with those coordinates exists.
Note that it may be the case that a station in (i, j) does not cover the cell (i, j).

Your task is to place two stations into two distinct cells.
The total strategic value of the two stations is the sum of strategic values of all cells that are covered by at least one of the stations.
Return the largest possible total strategic value of the two stations.


DEFINITION
Class:Coversta
Method:place
Parameters:vector <string>, vector <int>, vector <int>
Returns:int
Method signature:int place(vector <string> a, vector <int> x, vector <int> y)


NOTES
-The two stations must be built in two distinct cells of the given rectangular array. It is not allowed to build the stations at coordinates that are outside the given array.


CONSTRAINTS
-n will be between 2 and 100, inclusive.
-m will be between 2 and 100, inclusive.
-a will contain exactly n elements.
-Each element of a will contain exactly m characters.
-Each character in a will be a digit ('0'-'9').
-x will contain between 1 and 10 elements, inclusive.
-x and y will contain the same number of elements.
-Each element in x will be between -(n-1) and (n-1), inclusive.
-Each element in y will be between -(m-1) and (m-1), inclusive.
-The pairs (x[k], y[k]) will be distinct.


EXAMPLES

0)
{"11",
 "11"}
{0,0}
{0,1}

Returns: 4

A station at (i, j) covers the cells (i, j) and (i, j+1). The optimal solution is to place the two stations at (0, 0) and (1, 0).


1)
{"11",
 "11"}
{0,1}
{0,1}

Returns: 3

Here a station at (i, j) also covers (i+1, j+1). One optimal solution is to place the two stations at (0, 0) and (0, 1). The first station also covers the cell (1, 1).


2)
{"15",
 "61"}
{0}
{0}

Returns: 11

In this test case each station only covers its own cell. The optimal solution is to build the two stations in the two most important locations.


3)
{"151",
 "655",
 "661"}
{0,0,-1}
{0,1,0}

Returns: 33


4)
{"303",
 "333",
 "000"}
{-1,-1}
{-1,1}

Returns: 12

Note that in this test case the offset (0, 0) is not among the offsets (x[k], y[k]).


5)
{"0000000",
 "1010101"}

{-1,-1}
{-1,1}

Returns: 0

The stations must be built on some cells of the given field. They cannot be built outside the field.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Coversta {
public:
	int place(vector <string> a, vector <int> x, vector <int> y) {
		int ans = 0;
		int H = (int)a.size();
		int W = (int)a[0].length();
		int K = (int)x.size();
		vector<pair<int, int> > v;

		for (int i = 0; i < H*W; ++i) {
			int ix = i / W, iy = i % W;
			int sum = 0;
			for (int k = 0; k < K; ++k) {
				int p = ix + x[k], q = iy + y[k];
				if (p >= 0 && p < H && q >= 0 && q < W) {
					sum += a[p][q] - '0';
				}
			}
			v.push_back(make_pair(-sum, i));
		}
		sort(v.begin(), v.end());
		int M = min((int)v.size(), 100);

		for (int i = 0; i < M; ++i) {
			int ix = v[i].second / W, iy = v[i].second % W;
			int sum = 0;
			int u[128][128] = {};
			for (int k = 0; k < K; ++k) {
				int p = ix + x[k], q = iy + y[k];
				if (p >= 0 && p < H && q >= 0 && q < W) {
					sum += a[p][q] - '0';
					u[p][q] = 1;
				}
			}
			for (int j = 0; j < H*W; ++j) {
				int tot = sum;
				int jx = j / W, jy = j % W;
				for (int k = 0; k < K; ++k) {
					int p = jx + x[k], q = jy + y[k];
					if (p >= 0 && p < H && q >= 0 && q < W && !u[p][q]) {
						tot += a[p][q] - '0';
					}
				}
				ans = max(ans, tot);
			}
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
			string Arr0[] = {"11",
 "11"};
			int Arr1[] = {0,0};
			int Arr2[] = {0,1};
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"11",
 "11"};
			int Arr1[] = {0,1};
			int Arr2[] = {0,1};
			int Arg3 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"15",
 "61"};
			int Arr1[] = {0};
			int Arr2[] = {0};
			int Arg3 = 11;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"151",
 "655",
 "661"};
			int Arr1[] = {0,0,-1};
			int Arr2[] = {0,1,0};
			int Arg3 = 33;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"303",
 "333",
 "000"};
			int Arr1[] = {-1,-1};
			int Arr2[] = {-1,1};
			int Arg3 = 12;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0000000",
 "1010101"}
;
			int Arr1[] = {-1,-1};
			int Arr2[] = {-1,1};
			int Arg3 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, place(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Coversta ___test;
	___test.run_test(-1);
}
// END CUT HERE
