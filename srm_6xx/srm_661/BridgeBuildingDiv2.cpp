// BEGIN CUT HERE
/*
SRM 661 Div2 Medium (500)

PROBLEM STATEMENT

You have two rows of nodes.
Each row contains N nodes, numbered 0 through N-1 from the left to the right.

Within each row, adjacent nodes are already connected by edges.
You are given the lengths of these edges as vector <int>s a and b, each containing N-1 elements.
For each valid i, a[i] is the length of the edge between nodes i and (i+1) in the top row, and b[i] is the length of the edge between nodes i and (i+1) in the bottom row.

You want to add exactly K new edges to this graph.
Each of the new edges must be vertical -- i.e., it must connect some vertex i in the top row to the vertex i in the bottom row.
All new edges will have length 0.

By adding the K new edges we will produce a connected graph.
The diameter of this graph is the maximum of all shortest distances among pairs of its nodes.
In other words, the diameter is the smallest number D such that it is possible to travel from any node to any other node using a path of length D or less.

Given a, b, and the int K, compute and return the smallest possible diameter of the resulting graph.


DEFINITION
Class:BridgeBuildingDiv2
Method:minDiameter
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int minDiameter(vector <int> a, vector <int> b, int K)


CONSTRAINTS
-N will be between 2 and 11, inclusive.
-a,b will contain exactly N-1 elements each.
-K will be between 1 and N, inclusive.
-Each element of a,b will be between 1 and 50, inclusive.


EXAMPLES

0)
{2,1,1,1,2}
{1,9,1,9,1}
4

Returns: 6

One example of an optimal solution is to draw the bridges as follows:


1)
{1,50,1,50,1,50,1,50}
{50,1,50,1,50,1,50,1}
9

Returns: 8


2)
{50,10,15,31,20,23,7,48,5,50}
{2,5,1,8,3,2,16,11,9,1}
3

Returns: 124


3)
{2,4,10,2,2,22,30,7,28}
{5,26,1,2,6,2,16,3,15}
5

Returns: 54

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class BridgeBuildingDiv2 {
public:
	int minDiameter(vector <int> a, vector <int> b, int K) {
		int ans = 1 << 30;
		int _d[22][22];
		memset(_d, 0x3f, sizeof(_d));
		int N = (int)a.size() + 1;
		for (int i = 0; i < N * 2; ++i) {
			_d[i][i] = 0;
		}
		for (int i = 1; i < N; ++i) {
			_d[i - 1][i] = _d[i][i - 1] = a[i - 1];
			_d[i + N - 1][i + N] = _d[i + N][i + N - 1] = b[i - 1];
		}
		int B = 1 << N;
		for (int b = 1; b < B; ++b) {
			if (popcount(b) != K) {
				continue;
			}
			int d[22][22];
			memcpy(d, _d, sizeof(d));
			for (int i = 0; i < N; ++i) {
				if ((1 << i) & b) {
					d[i][i + N] = d[i + N][i] = 0;
				}
			}
			for (int k = 0; k < N * 2; ++k) {
				for (int i = 0; i < N * 2; ++i) {
					for (int j = 0; j < N * 2; ++j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			int m = 0;
			for (int i = 0; i < N * 2; ++i) {
				for (int j = 0; j < N * 2; ++j) {
					m = max(m, d[i][j]);
				}
			}
			ans = min(ans, m);
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
			int Arr0[] = {2,1,1,1,2};
			int Arr1[] = {1,9,1,9,1};
			int Arg2 = 4;
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,50,1,50,1,50,1,50};
			int Arr1[] = {50,1,50,1,50,1,50,1};
			int Arg2 = 9;
			int Arg3 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,10,15,31,20,23,7,48,5,50};
			int Arr1[] = {2,5,1,8,3,2,16,11,9,1};
			int Arg2 = 3;
			int Arg3 = 124;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,4,10,2,2,22,30,7,28};
			int Arr1[] = {5,26,1,2,6,2,16,3,15};
			int Arg2 = 5;
			int Arg3 = 54;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BridgeBuildingDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
