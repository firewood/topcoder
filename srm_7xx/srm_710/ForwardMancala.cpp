// BEGIN CUT HERE
/*
SRM 710 Div2 Medium (600)

PROBLEM STATEMENT
Mancala is a family of games that are played using tokens (such as seeds or pebbles) that are placed into holes or pits in the ground.
In this problem we will call the tokens "stones" and the holes "slots".

You are playing a variant of mancala with n slots around a circle.
The slots are labeled from 0 to n-1 in clockwise order.
Initially, each slot may contain some stones: for each i, slot i contains start[i] stones.

The game is played in turns.
In each turn you do the following:

You choose a non-empty slot and you take all stones from that slot into your hand.
While you have some stones in your hand, you repeat the following process: you move one slot clockwise and you drop one stone into that slot.

Note that if you picked up a lot of stones you may go around the whole circle multiple times.
Also note that during the second step you also place stones into the slot chosen in the first step.
For example, suppose we have four slots with the following numbers of stones: (6, 3, 4, 0).
Next, suppose that in step 1 we chose slot 0, i.e., the slot that contains 6 stones.
In step 2 we will place those 6 stones into slots 1, 2, 3, 0, 1, and 2.
After this turn the stones will be distributed as follows: (1, 5, 6, 1).

You are given the vector <int> start with n elements: the initial distribution of the stones.
Find and return any sequence of at most 2500 moves that leads to a state in which all stones are in a single slot.
For the constraints used in this problem it is guaranteed that such a sequence of moves exists.
Note that you do not need to minimize the number of moves, any valid sequence will be accepted.

In order to return a sequence that consists of x moves, return a vector <int> with x elements: for each turn in chronological order, the number of the slot you chose.


DEFINITION
Class:ForwardMancala
Method:findMoves
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> findMoves(vector <int> start)


CONSTRAINTS
-start will contain between 2 and 10 elements, inclusive.
-Each element of start will be between 0 and 10, inclusive.
-It is guaranteed that the sum of elements in start is positive.


EXAMPLES

0)
{6,1,0,1}

Returns: {1, 2, 3, 1, 2, 3 }

In this case, the states would look as follows:

(6,1,0,1)
(6,0,1,1)
(6,0,0,2)
(7,1,0,0)
(7,0,1,0)
(7,0,0,1)
(8,0,0,0)


1)
{0,10,0,0,0}

Returns: { }

In this case, all the stones are already in one slot, so we don't have to do anything.


2)
{0,1,0,1,0,1}

Returns: {3, 4, 1, 2, 3, 4 }


3)
{5,0,0,1,3,0,2,0}

Returns: {3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7 }


4)
{10,10,10,10,10,10,10,10,10,10}

Returns: {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 }

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ForwardMancala {
	public:
	vector <int> findMoves(vector <int> start) {
		vector<int> v = start;
		int N = (int)v.size();
		int total = accumulate(v.begin(), v.end(), 0);
		vector <int> ans;
		int pos = N;
		while (v[0] != total) {
			do {
				if (++pos >= N) {
					pos = 1;
				}
			} while (!v[pos]);
			ans.push_back(pos);
			int x = v[pos];
			v[pos] = 0;
			for (int j = pos + 1; x--; ++j) {
				++v[j % N];
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6,1,0,1};
			int Arr1[] = {1, 2, 3, 1, 2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findMoves(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,10,0,0,0};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, findMoves(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,0,1,0,1};
			int Arr1[] = {3, 4, 1, 2, 3, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findMoves(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,0,0,1,3,0,2,0};
			int Arr1[] = {3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findMoves(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,10,10,10,10,10,10,10,10};
			int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findMoves(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ForwardMancala ___test;
	___test.run_test(-1);
}
// END CUT HERE
