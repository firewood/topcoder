// BEGIN CUT HERE
/*
TCO18 R1A Easy (250)

PROBLEM STATEMENT

Red Dragon Inn is a board game in which the players' characters spend time in an inn brawling and drinking.

At any moment each character has some gold coins.
If a character has "too much fun" during the game, they pass out.
When that happens, the gold they have is divided between the inn and all other characters who are left standing.
This works as follows:

The inn takes half of the coins, rounded up to the nearest integer.
The remaining coins, if any, are split evenly among the remaining characters.
The remaining coins, if any, are taken by the inn again. (This occurs whenever in step 2 the number of coins isn't divisible by the number of players.)

A character just passed out.
Let C be the number of coins they had.
You do not know the value of C.
You are given the int N: the number of characters who are still standing.
You are also given the int X: the number of gold coins each of those characters received when the C coins were split between the inn and the players.
Determine and return the largest possible value of C.


DEFINITION
Class:RedDragonInn
Method:maxGold
Parameters:int, int
Returns:int
Method signature:int maxGold(int N, int X)


CONSTRAINTS
-N will be between 2 and 100, inclusive.
-X will be between 1 and 100,000, inclusive.


EXAMPLES

0)
3
2

Returns: 17

The process of dividing 17 coins between the inn and three characters looks as follows:

First, the inn gets 9 coins (half of all coins, rounded up).
Next, the remaining 8 coins are divided between the three characters. This means that each of them gets 2 coins (i.e., 8/3, rounded down).
Finally, the inn takes the 2 coins that were left over.

It can be shown that 17 is the largest initial amount of coins for which the players receive two coins each.
For example, when dividing 18 coins the inn takes 9 and then each player takes 3.


1)
8
13

Returns: 223


2)
42
1234

Returns: 103739

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RedDragonInn {
public:
	int maxGold(int N, int X) {
		int t;
		for (t = N * X; ; ++t) {
			int r = t / 2;
			int c = r / N;
			if (c > X) {
				break;
			}
		}
		return t - 1;
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
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 17;

			verify_case(n, Arg2, maxGold(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 13;
			int Arg2 = 223;

			verify_case(n, Arg2, maxGold(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 42;
			int Arg1 = 1234;
			int Arg2 = 103739;

			verify_case(n, Arg2, maxGold(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RedDragonInn ___test;
	___test.run_test(-1);
}
// END CUT HERE
