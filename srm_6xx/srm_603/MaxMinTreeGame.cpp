// BEGIN CUT HERE
/*
SRM 603 Div1 Easy (250)

PROBLEM STATEMENT
MaxMinTreeGame is a game for two players.
The game is played on a tree.
The tree has N nodes, labeled 0 through N-1.
Each node of the tree also has an integer cost.

The players take alternating turns.
In her turn, the current player starts by choosing one edge of the tree and erasing it.
This necessarily divides the tree into two components.
The current player then decides which of the components to keep, and erases the other component completely.

The game ends when there is only one node left.
The cost of that node is the result of the game.
The first player (i.e., the one that starts the game) wants to maximize the result.
Naturally, the second player's goal is to minimize the result.

You are given a vector <int> edges that describes the structure of the tree.
For each i between 0 and N-2, inclusive, the tree contains an edge between the vertices i+1 and edges[i].
You are also given a vector <int> costs.
For each i between 0 and N-1, inclusive, the cost of vertex i is costs[i].

Return the result of the game, assuming that both players play optimally.


DEFINITION
Class:MaxMinTreeGame
Method:findend
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int findend(vector <int> edges, vector <int> costs)


CONSTRAINTS
-The number of nodes in the tree N will be between 2 and 50, inclusive.
-edges will contain exactly N-1 elements.
-For each i, edges[i] will be between 0 and i, inclusive.
-costs will contain exactly N elements.
-Each element of costs will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{0}
{4,6}

Returns: 6

There is only one edge in this tree and the first player will choose it. After that she will keep the component containing the node with cost 6.


1)
{0,1}
{4,6,5}

Returns: 5

One of the optimal moves for the first player is to remove the edge between nodes 0 and 1 and to keep the component containing nodes 1 and 2. The second player will then remove the remaining edge and keep the node with cost 5.


2)
{0,1,2,3}
{0,1,0,1,0}

Returns: 0


3)
{0,0,0}
{5,1,2,3}

Returns: 3


4)
{0,0}
{3,2,5}

Returns: 5

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MaxMinTreeGame {
public:
	int findend(vector <int> edges, vector <int> costs) {
		int c[64] = {};
		for (int i = 0; i < (int)edges.size(); ++i) {
			c[i+1] += 1;
			c[edges[i]] += 1;
		}
		int ans = 0;
		for (int i = 0; i < (int)costs.size(); ++i) {
			if (c[i] == 1) {
				ans = max(ans, costs[i]);
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
			int Arr0[] = {0};
			int Arr1[] = {4,6};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findend(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1};
			int Arr1[] = {4,6,5};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findend(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {0,1,0,1,0};
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findend(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0};
			int Arr1[] = {5,1,2,3};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findend(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0};
			int Arr1[] = {3,2,5};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findend(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaxMinTreeGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
