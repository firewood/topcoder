// BEGIN CUT HERE
/*
SRM 710 Div1 Easy (300)

PROBLEM STATEMENT
Mancala is a family of games that are played using tokens (such as seeds or pebbles) that are placed into holes or pits in the ground.
In this problem we will call the tokens "stones" and the holes "slots".

You are playing a variant of mancala with n slots around a circle.
The slots are labeled from 0 to n-1 in clockwise order.
Initially, each slot may contain some stones: for each i, slot i contains start[i] stones.

The game is played in turns.
In each turn you do either a type-A move or a type-B move.
These look as follows:

Type A: You choose a non-empty slot and you take all stones from that slot into your hand. Then, while you have some stones in your hand, you repeat the following process: you move one slot clockwise and you drop one stone into that slot. (You might go around the circle several times while doing so, and you might place some of the stones back into the slot you chose at the beginning.)
Type B: You choose a non-empty slot. Then, while the current slot is non-empty, you repeat the following process: take one stone from the current slot into your hand and then move one slot counter-clockwise. Finally, once you reach an empty slot, deposit all stones from your hand into that slot.

See Examples 0 and 1 for an annotated example of a move of each type.

You are given two vector <int>s start and finish, each with n elements.
As explained above, start describes the initial distribution of stones.
Your goal is to reach a distribution of stones in which, for each i, slot i contains exactly finish[i] stones.

Find and return any sequence of at most 2500 moves that reaches the desired state.
For the constraints used in this problem it is guaranteed that such a sequence of moves exists.
Note that you do not need to minimize the number of moves, any valid sequence will be accepted.

In order to return a sequence that consists of x moves, return a vector <int> with x elements.
For each turn in chronological order:

If you chose a type-A move and selected the slot y, the return value should contain the number y.
If you chose a type-B move and selected the slot y, the return value should contain the number y+n.


DEFINITION
Class:ReverseMancala
Method:findMoves
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findMoves(vector <int> start, vector <int> target)


CONSTRAINTS
-start will contain between 2 and 10 elements, inclusive.
-start,target will have the same number of elements.
-Each element of start,target will be between 0 and 10, inclusive.
-The sum of elements in start is positive.
-The sum of elements in start will be the same as the sum of elements in target.


EXAMPLES

0)
{6, 3, 4, 0}
{1, 5, 6, 1}

Returns: {0 }

This is an example of a type-A move.
We can reach the desired distribution of stones by selecting slot 0, i.e., the slot that contains 6 stones.
We will then place those 6 stones into slots 1, 2, 3, 0, 1, and 2.


1)
{1, 5, 6, 1}
{6, 3, 4, 0}

Returns: {6 }

This is an example of a type-B move.
We can reach the desired distribution of stones by selecting slot 2, i.e., the slot that contains 6 stones.
We will then pick up a stone from the slots 2, 1, 0, 3, 2, and 1.
Finally, we will reach an empty slot 0 and we will deposit all 6 stones from our hand into this slot.

Note that as this is a type-B move, the return value is not 2 but 2+4 = 6.


2)
{10, 0, 1, 2, 3}
{10, 0, 0, 2, 4}

Returns: {2, 4, 8 }

Note that during the game a slot may contain more than 10 stones.
The return value shown above corresponds to the following sequence of moves:

A type-A move selecting slot 2. This brings the game into the state (10,0,0,3,3).
A type-A move selecting slot 4. This brings the game into the state (11,1,1,3,0).
A type-B move selecting slot 8-5 = 3. This brings the game into the desired state (10,0,0,2,4).


3)
{2, 0, 1, 7}
{0, 2, 1, 7}

Returns: {2, 0, 1, 7 }


4)
{3, 2, 4, 5}
{0, 1, 6, 7}

Returns: {7, 1, 0, 7, 1, 0 }


5)
{2, 1, 6, 4, 5, 2, 4, 5, 3, 0}
{6, 4, 8, 0, 2, 6, 0, 1, 3, 2}

Returns: {10, 8, 2, 16, 19, 2, 4, 11, 7, 6, 12, 19, 14, 14, 15, 3, 4, 17, 11, 3, 9, 16, 4, 8, 13, 12, 11, 9, 17, 12, 19, 4, 9, 8, 10, 2, 0, 17, 10, 3, 4, 8, 16, 0, 19, 15, 7, 6, 17, 6 }


6)
{3, 4, 6, 7, 2, 2, 3, 9, 4, 6}
{6, 0, 5, 10, 10, 3, 1, 2, 8, 1}

Returns: {8, 14, 1, 12, 11, 4, 9, 10, 15, 16, 2, 19, 2, 16, 17, 11, 16, 0, 12, 7, 4, 5, 17, 14, 0, 5, 13, 3, 7, 10, 12, 1, 16, 14, 1, 9, 1, 8, 7, 5, 5, 11, 19, 16, 18, 1, 15, 10, 16, 1 }

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

class ReverseMancala {
	vector <int> moveToFirstSlot(vector <int> start, bool former) {
		int N = (int)start.size();
		vector<int> v = start;
		int total = accumulate(v.begin(), v.end(), 0);
		vector <int> ans;
		int pos = N;
		while (v[0] != total) {
			do {
				if (++pos >= N) {
					pos = 1;
				}
			} while (!v[pos]);
			if (former) {
				ans.push_back(pos);
			}
			int x = v[pos];
			v[pos] = 0;
			int j;
			for (j = pos + 1; x--; ++j) {
				++v[j % N];
			}
			if (!former) {
				ans.push_back(N + ((j - 1) % N));
			}
		}
		return ans;
	}

public:
	vector <int> findMoves(vector <int> start, vector <int> target) {
		vector <int> ans = moveToFirstSlot(start, true);
		vector <int> latter = moveToFirstSlot(target, false);
		ans.insert(ans.end(), latter.rbegin(), latter.rend());
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
			int Arr0[] = {6, 3, 4, 0};
			int Arr1[] = {1, 5, 6, 1};
			int Arr2[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 6, 1};
			int Arr1[] = {6, 3, 4, 0};
			int Arr2[] = {6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 0, 1, 2, 3};
			int Arr1[] = {10, 0, 0, 2, 4};
			int Arr2[] = {2, 4, 8 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 0, 1, 7};
			int Arr1[] = {0, 2, 1, 7};
			int Arr2[] = {2, 0, 1, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 2, 4, 5};
			int Arr1[] = {0, 1, 6, 7};
			int Arr2[] = {7, 1, 0, 7, 1, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 1, 6, 4, 5, 2, 4, 5, 3, 0};
			int Arr1[] = {6, 4, 8, 0, 2, 6, 0, 1, 3, 2};
			int Arr2[] = {10, 8, 2, 16, 19, 2, 4, 11, 7, 6, 12, 19, 14, 14, 15, 3, 4, 17, 11, 3, 9, 16, 4, 8, 13, 12, 11, 9, 17, 12, 19, 4, 9, 8, 10, 2, 0, 17, 10, 3, 4, 8, 16, 0, 19, 15, 7, 6, 17, 6 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 4, 6, 7, 2, 2, 3, 9, 4, 6};
			int Arr1[] = {6, 0, 5, 10, 10, 3, 1, 2, 8, 1};
			int Arr2[] = {8, 14, 1, 12, 11, 4, 9, 10, 15, 16, 2, 19, 2, 16, 17, 11, 16, 0, 12, 7, 4, 5, 17, 14, 0, 5, 13, 3, 7, 10, 12, 1, 16, 14, 1, 9, 1, 8, 7, 5, 5, 11, 19, 16, 18, 1, 15, 10, 16, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMoves(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ReverseMancala ___test;
	___test.run_test(-1);
}
// END CUT HERE
