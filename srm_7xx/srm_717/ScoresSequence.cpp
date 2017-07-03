// BEGIN CUT HERE
/*
SRM 717 Div1 Easy (250)

PROBLEM STATEMENT

A tournament is a directed graph on n vertices that can be obtained by taking an undirected complete graph on n vertices and assigning a direction to each edge.
The outdegree of a vertex is the number of directed edges that start at that vertex.
The score of a tournament is the list of the outdegrees of its vertices, in no particular order.

Alice used to have a tournament T but she lost it.
She only remembers its score.
You are given the score of T in the vector <int> s.

Determine and return the number of pairs of vertices (u,v) such that in the tournament T the vertex v was reachable from the vertex u.
Note that each vertex is reachable from itself.

You may assume that the answer can always be uniquely determined.


DEFINITION
Class:ScoresSequence
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> s)


CONSTRAINTS
-s will contain between 1 and 100 elements, inclusive.
-s will be a valid score of some tournament.


EXAMPLES

0)
{2, 0, 1}

Returns: 6


There are three vertices. Let's call them A, B, and C, in the order in which they are mentioned in the score.
As the outdegree of A is 2, the tournament must contain the edges A -> B and A -> C.
As the outdegree of B is 0, the tournament must also contain the edge C -> B.

There are six pairs of vertices (u,v) such that there is a path from u to v.
These are the pairs (A,A), (B,B), (C,C), (A,B), (A,C), and (B,C).


1)
{1, 0, 2}

Returns: 6


2)
{1, 1, 1}

Returns: 9

This tournament must clearly be a cycle.
Hence, each vertex is reachable from each vertex.


3)
{0, 2, 8, 4, 3, 9, 1, 5, 7, 6}

Returns: 55


4)
{22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3}

Returns: 1422

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

class ScoresSequence {
public:
	int count(vector <int> s) {
		int n = (int)s.size(), d[128][128] = {};
		sort(s.begin(), s.end());
		while (true) {
			int tot = accumulate(s.begin(), s.end(), 0);
			int nd[128][128] = {};
			int u[128] = {};
			vector <int> r = s;
			for (int i = n - 1; i > 0; --i) {
				if (r[i]) {
					int x = rand() % i;
					if (x != i && !u[x]) {
						u[x] = 1;
						nd[i][x] = 1;
						r[i]--;
						--tot;
					}
				}
			}
			bool f = true;
			while (f && tot) {
				f = false;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; r[i] && j < n; ++j) {
						if (i != j && !nd[i][j] && !nd[j][i]) {
							nd[i][j] = 1;
							r[i]--;
							--tot;
							f = true;
						}
					}
				}
			}
			if (!tot) {
				memcpy(d, nd, sizeof(d));
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			d[i][i] = 1;
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i != j && d[i][k] && d[k][j]) {
						d[i][j] = 1;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans += d[i][j];
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
			int Arr0[] = {2, 0, 1};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0, 2};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6};
			int Arg1 = 55;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
			int Arg1 = 1422;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;





		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0 };
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,0,2 };
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 11, 2, 6, 3, 5, 4, 7, 7, 5, 5, 7, 4 };
			int Arg1 = 133;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ScoresSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
