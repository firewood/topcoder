// BEGIN CUT HERE
/*
SRM 708 Div2 Easy (250)

PROBLEM STATEMENT
Limak is in a casino.
He has b dollars.
He wants to have at least c dollars (to be able to buy flowers for a girl he likes).
In order to achieve that, he must win the money he's missing.

The casino allows guests to risk some of their money on bets.
Limak can make as many bets as he likes, but he has to make them one after another.
Each time Limak makes a bet, he chooses the amount he wants to bet.
The amount must be a positive integer.
Each bet has two possible outcomes: either Limak loses the money, or he gets it back doubled.

For example, suppose Limak has 20 dollars.
If he bets 5, he will be left with 20 - 5 = 15 dollars.
If he loses the bet, that is his new total.
If he wins the bet, he'll get back 2*5 = 10 dollars, which will bring his total up to 15 + 10 = 25 dollars.

Limak doesn't want to lose all his money.
More precisely, he wants to make sure that at any moment he will have at least a dollars.
He will not make a bet if losing the bet would mean that he will have less than a dollars.

For example, suppose Limak currently has 20 dollars.
If a = 15, in the next round Limak can bet 1, 2, 3, 4, or 5 dollars.
Note that a bet of 6 dollars is not allowed: if he lost it, he would have 20 - 6 = 14 dollars, which is less than a.

You are given the ints a, b, and c.
We will assume that Limak follows the rules described above when choosing the amounts to bet.
Compute and return the smallest B such that Limak can reach his goal (i.e., have at least c dollars) after making B bets.

DEFINITION
Class:SafeBetting
Method:minRounds
Parameters:int, int, int
Returns:int
Method signature:int minRounds(int a, int b, int c)


CONSTRAINTS
-a, b and c will each be between 1 and 1000, inclusive.
-a will be smaller than b.
-b will be smaller than c.


EXAMPLES

0)
15
20
48

Returns: 3

Limak has 20 dollars.
He wants to have at least 48 dollars.
He can never have less than 15 dollars.

In the first round Limak can bet at most 5 dollars (as explained in the example in the problem statement).
If he bets 5 and wins, he will have 25 dollars.
In the second round he will be able to bet at most 10 dollars.
If he wins that round as well, he will have 35 dollars.
Finally, it is possible that in the third round Limak will bet 13 dollars and he will win the bet.
At that moment he will have exactly 48 dollars.

The correct return value is 3, because Limak needed to place at least 3 bets.
He cannot reach 48 dollars by placing fewer than 3 bets.


1)
10
400
560

Returns: 1


2)
5
7
21

Returns: 3


3)
5
7
22

Returns: 4


4)
17
30
1000

Returns: 7

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SafeBetting {
	public:
	int minRounds(int a, int b, int c) {
		int ans = 0;
		while (b < c) {
			++ans;
			b += (b - a);
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
			int Arg0 = 15;
			int Arg1 = 20;
			int Arg2 = 48;
			int Arg3 = 3;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 400;
			int Arg2 = 560;
			int Arg3 = 1;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 21;
			int Arg3 = 3;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			int Arg2 = 22;
			int Arg3 = 4;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 17;
			int Arg1 = 30;
			int Arg2 = 1000;
			int Arg3 = 7;

			verify_case(n, Arg3, minRounds(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SafeBetting ___test;
	___test.run_test(-1);
}
// END CUT HERE
