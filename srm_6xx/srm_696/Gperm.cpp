// BEGIN CUT HERE
/*
SRM 696 Div1 Easy (300)

PROBLEM STATEMENT
Hero has an undirected multigraph.
(Each pair of vertices can be connected by arbitrarily many undirected edges. There may also be arbitrarily many self-loops at each vertex.)
Hero's graph has exactly 50 vertices, labeled 0 through 49.

The graph has at most 20 edges.
You are given the list of those edges: the vector <int>s x and y.
For each valid i, there is an edge that connects the vertices x[i] and y[i].
(Self-loops have x[i] = y[i].)

Hero needs to paint all vertices red.
He can paint the vertices in any order he likes, one vertex at a time.
Each time he paints a vertex he has to pay a fee.
The fee is computed as the number of edges that already have both endpoints red.

Hero wants to minimize the sum of all fees he has to pay.
Find the order in which he should paint the vertices, and return the corresponding total fee.


DEFINITION
Class:Gperm
Method:countfee
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countfee(vector <int> x, vector <int> y)


CONSTRAINTS
-x will contain between 1 and 20 elements, inclusive.
-x and y will contain the same number of elements.
-Each element in x and y will be between 0 and 49, inclusive.


EXAMPLES

0)
{0}
{1}

Returns: 1

One optimal order of painting the vertices is 49, 48, 47, ..., 3, 2, 1, 0.
The first 49 times the fee is 0.
After Hero paints the last vertex, the last fee is 1.


1)
{0,1}
{1,2}

Returns: 2

One optimal order of painting these vertices is 49, 48, ..., 5, 4, 3, 0, 2, 1. The last three fees will be 0, 0, and 2.


2)
{4,7,7}
{7,4,4}

Returns: 3


3)
{0,0,1}
{1,2,2}

Returns: 4

Hero should first paint the 47 isolated vertices and then the remaining three vertices in any order.
Regardless of the order in which Hero paints the last three vertices, the last three fees will be 0, 1, and 3.


4)
{7,8,9}
{4,5,6}

Returns: 6


5)
{45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28}
{45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27}

Returns: 53

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

class Gperm {

public:
	int countfee(vector <int> x, vector <int> y) {
		int rem[50] = {};
		int edges = (int)x.size();
		int bm = 1 << edges;
		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < edges; ++j) {
				if (i == x[j] || i == y[j]) {
					rem[i] |= (1 << j);
				}
			}
		}
		int dp[1 << 20];
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int b = 0; b < bm; ++b) {
			if (dp[b] >= 0) {
				for (int i = 0; i < 50; ++i) {
					int a = b | rem[i];
					if (a != b) {
						dp[a | b] = min(dp[a | b], dp[b] + edges - popcount(b));
					}
				}
			}
		}
		return dp[bm - 1];
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
			int Arr0[] = {0};
			int Arr1[] = {1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1};
			int Arr1[] = {1,2};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,7,7};
			int Arr1[] = {7,4,4};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1};
			int Arr1[] = {1,2,2};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,8,9};
			int Arr1[] = {4,5,6};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {45,28,42,5,27,27,42,36,14,27,19,42,24,27,8,31,24,27,14,28};
			int Arr1[] = {45,27,45,8,34,34,28,0,11,42,24,19,14,31,45,42,14,24,28,27};
			int Arg2 = 53;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,1,1 };
			int Arr1[] = { 0,2,3 };
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, countfee(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Gperm ___test;
	___test.run_test(-1);
}
// END CUT HERE
