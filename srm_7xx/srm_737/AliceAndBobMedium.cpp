// BEGIN CUT HERE
/*
SRM 737 Div2 Medium (500)

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

The game of NIM has a very simple strategy based on binary representations of pile sizes.
A position in the game of NIM is winning if the bitwise XOR of the sizes of all piles is non-zero, and losing if the bitwise XOR of the sizes of all piles is zero.
It can be shown that:

If it is your turn and you are in a losing position, you will lose the game if your opponent plays optimally.
If it is your turn and you are in a winning position, you will win the game if you play optimally.

Both Alice and Bob play the game of NIM optimally.
It is now Alice's turn.
You are given a description of the current state of the game: the vector <int> a.
Each element of a represents the number of stones on one of the piles.
Consider all possible first moves Alice can make in the given situation.
For how many of them will Alice eventually win the game?
Find and return that number.

(Two moves are considered distinct if they produce a different new sequence of pile sizes.
In other words, we can distinguish between different piles that have the same number of stones.
See Example #1.)


DEFINITION
Class:AliceAndBobMedium
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> a)


CONSTRAINTS
-a will contain between 1 and 37 elements, inclusive.
-Each element of a will be between 1 and 737,373,737, inclusive.


EXAMPLES

0)
{737}

Returns: 1

There is a single pile with 737 stones. In this situation Alice has exactly one winning move: she should remove all stones and win immediately. If she does anything else, Bob will remove all the remaining stones and win.


1)
{7,3,7}

Returns: 3

In this situation Alice has three different winning moves:

Remove three stones from the first pile.
Remove three stones from the second pile.
Remove three stones from the third pile.


2)
{3,7,3,7}

Returns: 0

Regardless of how Alice plays from this position, Bob will eventually win the game.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AliceAndBobMedium {
public:
	int count(vector <int> a) {
		int ans = 0, n = (int)a.size(), x = 0;
		for (int i = 0; i < n; ++i) {
			x ^= a[i];
		}
		if (x) {
			for (int i = 0; i < n; ++i) {
				int y = x ^ a[i];
				ans += a[i] >= y;
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
			int Arr0[] = {737};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,3,7};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,7,3,7};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceAndBobMedium ___test;
	___test.run_test(-1);
}
// END CUT HERE
