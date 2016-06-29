// BEGIN CUT HERE
/*
SRM 693 Div2 Medium (500)

PROBLEM STATEMENT
A biconnected graph is a connected undirected graph with the following property:
for any three distinct vertices u,v,w there exists a path from u to v that does not contain w.

You are given a graph G with n vertices numbered 0 through n-1, where n is not less than 3.
The graph has a very specific structure.
For each i between 0 and n-2, inclusive, vertices i and i+1 are connected by an edge with weight w1[i].
Additionally, for each i between 0 and n-3, inclusive, vertices i and i+2 are connected by an edge with weight w2[i].
It is easy to verify that this graph is biconnected.

Note that some of the edge weights may be zeros or negative integers.
An edge with weight zero is still present in the graph and it may contribute to its biconnectedness.

You may erase some edges of the graph G.
If you do, you must do it in such a way that the graph remains biconnected.
Your goal is to minimize the sum of weights of edges that remain in G.

You are given the vector <int>s w1 and w2 that describe the graph G.
Compute and return the smallest possible sum of weights of a graph that can be produced in the way described above.


DEFINITION
Class:BiconnectedDiv2
Method:minimize
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimize(vector <int> w1, vector <int> w2)


CONSTRAINTS
-n will be between 3 and 100, inclusive.
-w1 will contain exactly n-1 elements.
-w2 will contain exactly n-2 elements.
-Each element of w1 and w2 will be between -10,000 and 10,000, inclusive.


EXAMPLES

0)
{1,2}
{3}

Returns: 6

There are three vertices and three edges (0,1), (1,2), (2,0).
If you erase edge (0,1), then any path from 0 to 1 has to go through vertex 2. And if you erase two or more edges, the graph will become disconnected. So you cannot erase anything.


1)
{-1,-2,-3}
{-4,-5}

Returns: -15

An optimal solution is to keep all the edges.


2)
{1,100,-3,2}
{-2,1,4}

Returns: 3

An optimal solution is to erase edge (1,2).

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BiconnectedDiv2 {
public:
	int minimize(vector <int> w1, vector <int> w2) {
		int ans = accumulate(w2.begin(), w2.end(), 0);
		int N = (int)w1.size();
		for (int i = 0; i < N; ++i) {
			if (i == 0 || i == (N - 1) || w1[i] < 0) {
				ans += w1[i];
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
			int Arr0[] = {1,2};
			int Arr1[] = {3};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1,-2,-3};
			int Arr1[] = {-4,-5};
			int Arg2 = -15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,100,-3,2};
			int Arr1[] = {-2,1,4};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { -12, 1, 1, -2027 };
			int Arr1[] = { -577, 7, 5682 };
			int Arg2 = 3073;
//			3075
			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BiconnectedDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
