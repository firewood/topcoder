// BEGIN CUT HERE
/*
SRM 753 Div1 Easy (300)

PROBLEM STATEMENT

You are given a simple undirected graph G on n nodes, numbered 0 through n-1.
More precisely, you are given the int n and two equally-long vector <int>s a and b.
For each valid index i, the graph contains an edge that connects the nodes a[i] and b[i].

An edge is called a bridge if the removal of this edge increases the number of connected components.

Given a subset S of nodes, the subgraph of G induced by S is a graph whose vertices are S and whose edges are all edges of G whose both endpoints are in S.

We are interested in sets S such that the subgraph induced by S does not contain any of the edges that are bridges in G.
Compute and return the size of the largest such set.


DEFINITION
Class:MaxCutFree
Method:solve
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int solve(int n, vector <int> a, vector <int> b)


NOTES
-An isolated vertex does count as a connected component.


CONSTRAINTS
-n will be between 1 and 1,000, inclusive.
-a will have between 0 and 1,500 elements, inclusive.
-b will have the same number of elements as a.
-Each element of a and b will be between 0 and n-1, inclusive.
-The graph defined by the input will be a simple graph (without self-loops and duplicate edges).


EXAMPLES

0)
4
{0, 1, 2, 0}
{1, 2, 0, 3}

Returns: 3

The edge 0-3 is a bridge. Thus, the set S cannot contain both node 0 and node 3. The largest two valid sets S are {0,1,2} and {1,2,3}.


1)
6
{0,1,2,3,3}
{2,2,3,4,5}

Returns: 4

Each of these five edges is a bridge. The optimal solution is to take S = {0,1,4,5}.


2)
7
{0,2,4}
{1,3,5}

Returns: 4


3)
4
{0,0,0,1,1,2}
{1,2,3,2,3,3}

Returns: 4

This is a complete graph with no bridges. We can take its entire set of vertices as S.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MaxCutFree {
	vector< vector<int> > e;
	vector< vector<int> > e2;
	vector<int> pre;
	vector<int> low;
	vector<int> used;
	vector<int> match;

	int bd_dfs(int v, int& count, int from) {
		pre[v] = count++;
		low[v] = pre[v];
		for (int to : e[v]) {
			if (pre[to] == -1) {
				low[v] = min(low[v], bd_dfs(to, count, v));
				if (low[to] == pre[to]) {
					e2[v].push_back(to);
					e2[to].push_back(v);
				}
			} else if (from != to) {
				low[v] = min(low[v], low[to]);
			}
		}
		return low[v];
	}

	bool bm_dfs(int v) {
		used[v] = true;
		for (int u : e2[v]) {
			int w = match[u];
			if (w < 0 || (!used[w] && bm_dfs(w))) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}

public:
	int solve(int n, vector <int> a, vector <int> b) {
		e.clear();
		e.resize(n);
		e2.clear();
		e2.resize(n);

		// bridge detection
		pre = vector<int>(n, -1);
		low = vector<int>(n, -1);
		for (int i = 0; i < (int)a.size(); ++i) {
			e[a[i]].push_back(b[i]);
			e[b[i]].push_back(a[i]);
		}
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (pre[i] < 0) {
				bd_dfs(i, count, -1);
			}
		}

		// bipartite matching
		int matched = 0;
		match = vector<int>(n, -1);
		for (int i = 0; i < n; ++i) {
			if (match[i] < 0) {
				used = vector<int>(n, 0);
				matched += bm_dfs(i);
			}
		}

		return n - matched;
	}


	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arr1[] = { 0, 1, 2, 0 };
			int Arr2[] = { 1, 2, 0, 3 };
			int Arg3 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 6;
			int Arr1[] = { 0,1,2,3,3 };
			int Arr2[] = { 2,2,3,4,5 };
			int Arg3 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 7;
			int Arr1[] = { 0,2,4 };
			int Arr2[] = { 1,3,5 };
			int Arg3 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arr1[] = { 0,0,0,1,1,2 };
			int Arr2[] = { 1,2,3,2,3,3 };
			int Arg3 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 7;
			int Arr1[] = { 0,0,0,0,0,0 };
			int Arr2[] = { 1,2,3,4,5,6 };
			int Arg3 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 8;
			int Arr1[] = { 7,7,7,2,1,0 };
			int Arr2[] = { 6,5,4,3,3,3 };
			int Arg3 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;


	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaxCutFree ___test;
	___test.run_test(-1);
}
// END CUT HERE
