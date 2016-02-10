// BEGIN CUT HERE
/*
SRM 681 Div2 Easy (250)

PROBLEM STATEMENT

You have n coins, labeled 0 through n-1.
Each of the coins shows either heads or tails.
You are given the states of all coins in the string state with n characters.
For each i, state[i] is 'H' if coin i shows heads, or 'T' if it shows tails.

The coins are laid out in a row, ordered from coin 0 to coin n-1.
A coin is called interesting if it differs from at least one of its neighbors.
(For example, a coin that shows heads is interesting if at least one of its neighbors shows tails.)
Return the number of interesting coins.


DEFINITION
Class:CoinFlipsDiv2
Method:countCoins
Parameters:string
Returns:int
Method signature:int countCoins(string state)


NOTES
-The value of n is not given explicitly. Instead, you can determine it as the number of characters in state.


CONSTRAINTS
-state will have between 1 and 50 elements, inclusive.
-Each character of state will be either 'H' or 'T'.


EXAMPLES

0)
"HT"

Returns: 2

Coin 0 is interesting because it shows heads and its only neighbor shows tails.
Similarly, coin 1 is interesting because it shows tails and its only neighbor shows heads.
Thus, the answer is 2.


1)
"T"

Returns: 0

In this test case there is a single coin.
It has no neighbors, and therefore it has no different neighbors.
This means that the coin is not interesting.


2)
"HHH"

Returns: 0

None of these coins are interesting, because each of them is only adjacent to coins that show the same side.


3)
"HHTHHH"

Returns: 3

Here, the three interesting coins are coins 1, 2, and 3.
(Remember that the indices are 0-based.)


4)
"HHHTTTHHHTTTHTHTH"

Returns: 12

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CoinFlipsDiv2 {
public:
	int countCoins(string state) {
		string s = state.front() + state + state.back();
		int ans = 0;
		for (int i = 1; i != s.length() - 1; ++i) {
			ans += s[i - 1] != s[i] || s[i] != s[i + 1];
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
			string Arg0 = "HT";
			int Arg1 = 2;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "T";
			int Arg1 = 0;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HHH";
			int Arg1 = 0;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HHTHHH";
			int Arg1 = 3;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HHHTTTHHHTTTHTHTH";
			int Arg1 = 12;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CoinFlipsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
