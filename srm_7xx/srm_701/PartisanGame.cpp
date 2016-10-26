// BEGIN CUT HERE
/*
SRM 701 Div1 Easy (300)

PROBLEM STATEMENT

Alice and Bob play a game with a pile of stones.
Initially, there are n stones in the pile.
The players take alternating turns, Alice goes first.

You are given two vector <int>s: a and b.
The elements of a are allowed moves for Alice, and the elements of b are allowed moves for Bob.

In each turn, the current player must remove some stones from the pile.
The number of removed stones must be equal to one of the player's allowed moves.
If a player cannot take a valid turn, they lose the game.

Assume that both Alice and Bob play the game optimally.
Return "Alice" if Alice wins, or "Bob" if Bob wins.
In other words, return "Alice" if and only if the first player has a winning strategy for the given n, a, and b.


DEFINITION
Class:PartisanGame
Method:getWinner
Parameters:int, vector <int>, vector <int>
Returns:string
Method signature:string getWinner(int n, vector <int> a, vector <int> b)


CONSTRAINTS
-n will be between 0 and 1,000,000,000, inclusive.
-all elements of  a  will be distinct.
-all elements of  b  will be distinct.
-all elements of  a  will be between 1 and 5, inclusive.
-all elements of  b  will be between 1 and 5, inclusive.


EXAMPLES

0)
7
{3, 4}
{4}

Returns: "Alice"

Alice should take 4 stones from the pile.
This will leave a pile of only 3 stones.
In that situation, Bob has no valid move.
(His only allowed move is 4, but it is not possible to remove 4 stones from a pile of only 3 stones.)
Thus, Bob loses the game.


1)
10
{1}
{4, 3, 2}

Returns: "Bob"

One winning strategy for Bob is to always take 4 stones.
If Bob follows this strategy, Alice will lose the game during her third turn.


2)
104982
{2, 3, 4, 5}
{2, 5}

Returns: "Alice"


3)
999999999
{4}
{5}

Returns: "Bob"


4)
1000000000
{1,2,3,4,5}
{1,2,3,4,5}

Returns: "Alice"

*/
// END CUT HERE
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PartisanGame {

	map<int, int> memo;

	int win(int n, int a, int b) {
		if (n <= 0) {
			return 0;
		}
		int key = (n << 16) | (b << 8) | a;
		if (memo.find(key) == memo.end()) {
			int result = 0;
			for (int i = 1; i <= 5 && n >= i; ++i) {
				if ((1 << i) & a) {
					if (!win(n - i, b, a)) {
						result = 1;
						break;
					}
				}
			}
			memo[key] = result;
		}
		return memo[key];
	}

public:
	string getWinner(int n, vector <int> a, vector <int> b) {
		memo.clear();
		int aa = 0, bb = 0;
		for (int x : a) {
			aa |= 1 << x;
		}
		for (int x : b) {
			bb |= 1 << x;
		}
		char r[1000];
		for (int x = 0; x < 1000; ++x) {
			r[x] = win(x, aa, bb);
		}
		char ans;
		if (n < 1000) {
			ans = r[n];
		} else {
			for (int f = 500; f >= 1; --f) {
				if (memcmp(r + f, r + 2 * f, f) == 0) {
					n = (n % f) + f;
					break;
				}
			}
			ans = r[n];
		}
		return ans ? "Alice" : "Bob";
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 7;
			int Arr1[] = { 3, 4 };
			int Arr2[] = { 4 };
			string Arg3 = "Alice";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arr1[] = { 1 };
			int Arr2[] = { 4, 3, 2 };
			string Arg3 = "Bob";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 104982;
			int Arr1[] = { 2, 3, 4, 5 };
			int Arr2[] = { 2, 5 };
			string Arg3 = "Alice";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 999999999;
			int Arr1[] = { 4 };
			int Arr2[] = { 5 };
			string Arg3 = "Bob";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getWinner(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000000;
			int Arr1[] = { 1,2,3,4,5 };
			int Arr2[] = { 1,2,3,4,5 };
			string Arg3 = "Alice";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getWinner(Arg0, Arg1, Arg2));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PartisanGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
