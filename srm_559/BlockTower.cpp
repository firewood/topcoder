// BEGIN CUT HERE
/*
// SRM 559 Div2 Easy (250)

// PROBLEM STATEMENT
// Josh loves playing with blocks. Currently, he has N blocks, labeled 0 through N-1. The heights of all blocks are positive integers. More precisely, for each i, the height of block i is blockHeights[i]. Josh is interested in making the tallest block tower possible. He likes all his towers to follow three simple rules:

The blocks must be stacked in a single column, one atop another. The height of the tower is simply the sum of heights of all its blocks.
The labels of blocks used in the tower must increase from the bottom to the top. In other words, whenever Josh places box x on top of box y, we have x > y.
Josh will never place a box of an even height on top of a box of an odd height.

You are given the vector <int> blockHeights. Return the height of the tallest possible block tower Josh can build.

DEFINITION
Class:BlockTower
Method:getTallest
Parameters:vector <int>
Returns:int
Method signature:int getTallest(vector <int> blockHeights)


CONSTRAINTS
-blockHeights will contain between 1 and 50 elements, inclusive.
-Each element of blockHeights will be between 1 and 50, inclusive.


EXAMPLES

0)
{4,7}

Returns: 11

The optimal tower contains both blocks. Block 0 is on the bottom of the tower.


1)
{7,4}

Returns: 7

This time the optimal tower contains just block 0. Josh cannot put block 1 on top of it, because 4 is even and 7 is odd.


2)
{7}

Returns: 7


3)
{4}

Returns: 4


4)
{48,1,50,1,50,1,48}

Returns: 196

Note that in a valid tower the labels of the blocks have to increase from bottom to top. Their heights do not have to. In this case the optimal tower consists of blocks 0, 2, 4, and 6, in this order. Its total height is 48 + 50 + 50 + 48 = 196.


5)
{49,2,49,2,49}

Returns: 147


6)
{44,3,44,3,44,47,2,47,2,47,2}

Returns: 273

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

class BlockTower {

public:
	int getTallest(vector <int> blockHeights) {
		int even = 0, odd = 0, i, j;
		for (i = 0; i < (int)blockHeights.size(); ++i) {
			j = blockHeights[i];
			if (j % 2) {
				odd = max(even, odd) + j;
			} else {
				even = even + j;
			}
		}
		return max(even, odd);
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
			int Arr0[] = {4,7};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,4};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7};
			int Arg1 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {48,1,50,1,50,1,48};
			int Arg1 = 196;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {49,2,49,2,49};
			int Arg1 = 147;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {44,3,44,3,44,47,2,47,2,47,2};
			int Arg1 = 273;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getTallest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BlockTower ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
