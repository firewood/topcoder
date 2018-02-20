// BEGIN CUT HERE
/*
SRM 730 Div1 Easy (250)

PROBLEM STATEMENT

You are given a rooted tree with n nodes.
The nodes are labeled from 0 to n-1.
Node 0 is the root.
Each node of the tree has at most two children.

You are given the description of the tree: the vector <int>s p and w.
The vector <int> p has n-1 elements.
For each valid i, node p[i] is the parent of node (i+1).
You may assume that for each i we have p[i] ? i.
The vector <int> w has n elements.
For each valid i, w[i] is the weight of node i.

The vector <int> w has a special property: it is non-decreasing.
That is, for each valid i we have w[i-1] ? w[i].

All nodes of the tree are currently empty.
You are now going to play a game with the tree and an unlimited supply of stones.
The game is played in turns.
In each turn you can either remove a single stone from anywhere into a tree, or you can place a single stone onto a node of the tree.
However, there is a restriction on placing the stones:
you may only place a stone onto a node if all of its children currently have stones placed on them.
(Note that this means that you can always place a stone onto any leaf of the tree.)

The weight of a given state of the game is equal to the sum of weights of nodes with stones.

You win the game by placing a stone onto the root of the tree.
You want to win the game.
If there are multiple ways to do so, you prefer a way for which the maximum weight of a state during the game is minimized.
Compute and return this weight.
In other words, compute and return the smallest W for which there is a way to win the game such that during the game the total weight of nodes with stones never exceeds W.


DEFINITION
Class:StonesOnATree
Method:minStones
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minStones(vector <int> p, vector <int> w)


CONSTRAINTS
-p will have between 1 and 999 elements, inclusive. (Thus, the number of nodes is between 2 and 1,000, inclusive.)
-The i-th element of p will be between 0 and i, inclusive.
-In the given tree each node will have at most two children. In other words, each value will appear in p at most twice.
-w will have exactly len(p)+1 elements.
-Each element of w will be 1 and 10^5, inclusive.
-Elements of w will be non-decreasing.


EXAMPLES

0)
{0,1,2,3}
{1,2,2,4,4}

Returns: 8

There are five nodes in a line. 
Here, one optimal solution is as follows:

 Place stone on node 4 (weight = 4). 
 Place stone on node 3 (weight = 8). 
 Remove stone from node 4 (weight = 4). 
 Place stone on node 2 (weight = 6). 
 Place stone on node 1 (weight = 8). 
 Remove stone from node 2 (weight = 6). 
 Place stone on node 0 (weight = 7). 

The maximum weight over all states is 8. It can be shown there is no other sequence of moves that has a smaller maximum weight.


1)
{0,0}
{1,2,3}

Returns: 6

In order to be able to place a stone onto node 0 we have to place stones onto both of its children. Thus, at the end of the game each of these three nodes will have a stone.


2)
{0}
{100000,100000}

Returns: 200000


3)
{0,0,1,1,2,2}
{1,1,1,1,1,1,1}

Returns: 4


4)
{0,0,1,2,3,4,4,2,1,3,6,7}
{1,2,3,4,5,6,6,7,8,8,8,9,10}

Returns: 22

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class StonesOnATree {
	vector<int> edges[1024];
	vector<int> values;

	int dfs(int n) {
		int cost = 0, costs[2] = {}, max_costs[2] = {};
		for (int i = 0; i < (int)edges[n].size(); ++i) {
			costs[i] = values[edges[n][i]];
			max_costs[i] = dfs(edges[n][i]);
			cost = max(cost, max_costs[i]);
		}
		cost = max(cost, values[n] + costs[0] + costs[1]);
		return max(cost, min(costs[0] + max_costs[1], costs[1] + max_costs[0]));
	}

public:
	int minStones(vector <int> p, vector <int> w) {
		for (auto &v : edges) {
			v.clear();
		}
		values = w;
		for (int i = 0; i < (int)p.size(); ++i) {
			edges[p[i]].push_back(i + 1);
		}
		return dfs(0);
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
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {1,2,2,4,4};
			int Arg2 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0};
			int Arr1[] = {1,2,3};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {100000,100000};
			int Arg2 = 200000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,1,2,2};
			int Arr1[] = {1,1,1,1,1,1,1};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,2,3,4,4,2,1,3,6,7};
			int Arr1[] = {1,2,3,4,5,6,6,7,8,8,8,9,10};
			int Arg2 = 22;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minStones(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StonesOnATree ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
