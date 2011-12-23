// BEGIN CUT HERE
/*
// SRM 527 Div1 Easy (275)
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

You want to build a graph consisting of N nodes and N-1 edges. The graph must be connected. That is, for each pair of nodes there must be some sequence of edges that connects them. For example, the following picture shows a connected graph with N=5 nodes (dots) and N-1=4 edges (lines connecting pairs of dots):



An edge is adjacent to the two nodes that it connects. The degree of a node in the graph is equal to the number of edges adjacent to the node. For example, the degree of node A in the picture above is 3, while the degree of node B is 1. Note that in your graph the degree of each node will be between 1 and N-1, inclusive.

You are given a vector <int> scores with N-1 elements. The score of a node with degree d is scores[d-1]. The score of a graph is the sum of the scores of its nodes.

Your method should compute and return the maximum possible score for a graph you can construct.


DEFINITION
Class:P8XGraphBuilder
Method:solve
Parameters:vector <int>
Returns:int
Method signature:int solve(vector <int> scores)


NOTES
-In your solution, the number of nodes N in your graph can be determined as one plus the length of scores.
-In your graph, there must be at most one edge connecting any pair of nodes, and an edge cannot connect a node with itself.


CONSTRAINTS
-scores will contain between 1 and 50 elements, inclusive.
-Each element in scores will be between 0 and 10,000, inclusive.


EXAMPLES

0)
{1, 3, 0}

Returns: 8

As scores contains 3 elements, we are building a graph with N=4 nodes. Nodes of degree 1 have score 1, nodes of degree 2 have score 3, and nodes of degree 3 have score 0.
One possible graph with the highest score looks as follows:



In this graph the degrees of the nodes are 1, 2, 2, 1, respectively. The sum of their scores is 1+3+3+1 = 8.

1)
{0, 0, 0, 10}

Returns: 10

One possible solution for this test case is:


2)
{1, 2, 3, 4, 5, 6}

Returns: 12



3)
{5, 0, 0}

Returns: 15



4)
{1, 3, 2, 5, 3, 7, 5}

Returns: 20



#line 80 "P8XGraphBuilder.cpp"
*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;

class P8XGraphBuilder {
	int _m[64];		// メモ化テーブル

	int rec(const IntVec &scores, bool is_root, int nodes) {
		int &res = _m[nodes];
		if (res >= 0) {
			return res;
		}

		// 節+全て葉のときのスコア
		// 葉の枚数はノード総数-1
		res = scores[!is_root + (nodes-1) -1] + scores[0]*(nodes-1);

		// 木のノード総数が3以上の場合
		// 節+i枚の葉+木
		int i;
		for (i = 0; i < (nodes - 2); ++i) {
			// 節の次数は1(根)+i(葉)+1(木)
			int node_score = scores[!is_root + i + 1 -1];
			// 木のノード数は、ノード総数-(1+i)
			int subtree_score = rec(scores, false, nodes - (i+1));
			// 節のスコア+葉のスコア+木のスコアの最大値
			res = max(res, node_score + scores[0]*i + subtree_score);
		}

		return res;
	}

public:
	int solve(vector <int> scores) {
		memset(_m, -1, sizeof(_m));
		// ノード総数はscores.size()+1
		return rec(scores, true, scores.size() +1);
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
			int Arr0[] = {1, 3, 0};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 10};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6};
			int Arg1 = 12;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 0, 0};
			int Arg1 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 2, 5, 3, 7, 5};
			int Arg1 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	P8XGraphBuilder ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
