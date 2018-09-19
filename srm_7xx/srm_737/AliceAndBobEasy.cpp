// BEGIN CUT HERE
/*
SRM 737 Div1 Easy (300)

PROBLEM STATEMENT

Alice and Bob are playing a game of NIM.

The rules of NIM are as follows:
There are several piles of stones.
The players take alternating turns.
In each turn, the current player selects one non-empty pile of stones and removes some stones from the pile.
(The player must remove at least one stone. They can remove as many stones as they want, possibly all of them, but just from a single pile.)
The game ends when all stones have been removed.
The player who removed the last stone wins the game.
Equivalently, the first player who is unable to make a valid move loses the game.

More formally, a position in the game is an ordered sequence of pile sizes and a move consists of decrementing one of those values.
Note that {1,2,3} and {3,2,1} are considered different positions, and thus the move from {3,2,3} to {1,2,3} and the move from {3,2,3} to {3,2,1} are two different moves.

Given a position, a move from that position is called a winning move if the player who plays that move can guarantee that from the resulting position they can win the game, even if their opponent plays optimally.

You are given the int N.
Construct and return any position such that:

There are exactly N piles of stones.
Each pile has between 1 and 737,373,737 stones, inclusive.
All pile sizes are distinct.
The number of different winning moves from this position is as large as possible. (I.e., no other position that satisfies the previous items has more winning moves.)


DEFINITION
Class:AliceAndBobEasy
Method:make
Parameters:int
Returns:vector <int>
Method signature:vector <int> make(int N)


CONSTRAINTS
-N will be between 1 and 37, inclusive.


EXAMPLES

0)
1

Returns: {737 }

In this position the active player has exactly one winning move: take all the stones.

1)
2

Returns: {737, 373 }

In this position there is also exactly one winning move: take 364 stones from pile 0.
There is no other valid position with more than one valid move.

2)
3

Returns: {3337, 3373, 3733 }

Note that the pile sizes must be distinct. For example, { 373, 373, 373 } is not a valid answer.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AliceAndBobEasy {
public:
	vector <int> make(int N) {
		vector <int> ans(N, 1 << 20);
		if (N % 2 == 0) {
			ans[0] = 0;
		}
		for (int i = 0; i < N; ++i) {
			ans[i] += i + 1;
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
			int Arg0 = 1;
			int Arr1[] = {737 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, make(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {737, 373 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, make(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {3337, 3373, 3733 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, make(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceAndBobEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
