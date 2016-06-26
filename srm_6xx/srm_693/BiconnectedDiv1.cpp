// BEGIN CUT HERE
/*
SRM 693 Div1 Easy (250)

PROBLEM STATEMENT
A 2-edge-connected graph is a connected undirected graph with the following property:
for any two distinct vertices u,v and for any edge e there exists a path from u to v that does not contain e.

You are given a graph G with n vertices numbered 0 through n-1, where n is not less than 3.
The graph has a very specific structure.
For each i between 0 and n-2, inclusive, vertices i and i+1 are connected by an edge with weight w1[i].
Additionally, for each i between 0 and n-3, inclusive, vertices i and i+2 are connected by an edge with weight w2[i].
It is easy to verify that this graph is 2-edge-connected.

Note that some of the edge weights may be zeros.
An edge with weight zero is still present in the graph, just like any other edge.

You may erase some edges of the graph G.
If you do, you must do it in such a way that the graph remains 2-edge-connected.
Your goal is to minimize the sum of weights of edges that remain in G.

You are given the vector <int>s w1 and w2 that describe the graph G.
Compute and return the smallest possible sum of weights of a graph that can be produced in the way described above.


DEFINITION
Class:BiconnectedDiv1
Method:minimize
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimize(vector <int> w1, vector <int> w2)


CONSTRAINTS
-n will be between 3 and 100, inclusive.
-w1 will contain exactly n-1 elements.
-w2 will contain exactly n-2 elements.
-Each element of w1 and w2 will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{1,2}
{3}

Returns: 6

There are three vertices and three edges (0,1), (1,2), (2,0). If you erase edge (0,1), then any path from 0 to 1 has to go through edge (0,2). And if you erase two or more edges, the graph will become disconnected. So you cannot erase anything.


1)
{3,0,4}
{1,2}

Returns: 10

An optimal solution is to keep all the edges.


2)
{3,3,3,3}
{3,6,3}

Returns: 18

An optimal solution is to erase edge (1,3).


3)
{7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876}
{2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920}

Returns: 46729

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

static void update_min(int &a, int b) {
	if (a < 0 || b < a) {
		a = b;
	}
}

class BiconnectedDiv1 {

public:
	int minimize(vector <int> w1, vector <int> w2) {
		int N = (int)w1.size();
		w2.push_back(0);
		int dp[128][2];
		memset(dp, -1, sizeof(dp));
		dp[1][1] = w1[0] + w2[0];
		for (int i = 1; i < N; ++i) {
			if (dp[i][0] >= 0) {
				update_min(dp[i + 1][1], dp[i][0] + w1[i] + w2[i]);
			}
			if (dp[i][1] >= 0) {
				update_min(dp[i + 1][0], dp[i][1] + w1[i]);
				update_min(dp[i + 1][1], dp[i][1] + w2[i]);
			}
		}
		return dp[N][0];
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
			int Arr0[] = {3,0,4};
			int Arr1[] = {1,2};
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3,3};
			int Arr1[] = {3,6,3};
			int Arg2 = 18;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
			int Arr1[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
			int Arg2 = 46729;

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
	BiconnectedDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
