// BEGIN CUT HERE
/*
SRM 812 Div2 Hard (900)

PROBLEM STATEMENT

Two players are going to play a number guessing game.

Genevieve will generate an integer between 0 and N-1 uniformly at random.
Then, Adam will attempt to guess the number.

In each guess Adam announces an integer X and receives the correct one of the answers "less than X", "correct", and "greater than X".
Once he receives the message "correct", the game ends.

The payoff for the game is determined by a single real number P.
If Adam guesses correctly in guess number i, Genevieve will give him P-i dollars.
(Guesses are numbered starting from 1. If i is greater than P, this value will be negative and thus Adam actually loses money.)

Determine and return the real number P for which the game is fair: Adam's expected profit from playing the game should be exactly zero, assuming he plays the game optimally.


DEFINITION
Class:GuessForMoney
Method:balance
Parameters:long long
Returns:double
Method signature:double balance(long long N)


NOTES
-Your return value must have an absolute or a relative error at most 1e-9 in order to be accepted.


CONSTRAINTS
-N will be between 1 and 10^12, inclusive.


EXAMPLES

0)
2

Returns: 1.5

Adam will either get lucky and guess the correct number in his first guess, or he will get unlucky and he will guess it in the second guess. If we set P = 1.5, the game will be fair: Adam either gains or loses 0.5, each with 50 percent probability.


1)
7

Returns: 2.4285714285714284

Adam should follow the obvious strategy:

In the first round, guess 3.
If there is a second round, guess 1 if 3 was too large, or 5 if 3 was too small.
If there is a third round, guess the correct value among 0, 2, 4, 6.


2)
12

Returns: 3.0833333333333335


3)
1

Returns: 1.0

Even though Adam knows what the answer is already before the game starts, in order to win the game he must actually make a guess and get the answer "correct".

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GuessForMoney {
public:
	double balance(long long N) {
		long long r = N, x = 1, tot = 0;
		while (r > 0) {
			tot += r;
			r -= x;
			x *= 2;
		}
		return double(tot) / N;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			double Arg1 = 1.5;

			verify_case(n, Arg1, balance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			double Arg1 = 2.4285714285714284;

			verify_case(n, Arg1, balance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 12LL;
			double Arg1 = 3.0833333333333335;

			verify_case(n, Arg1, balance(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			double Arg1 = 1.0;

			verify_case(n, Arg1, balance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GuessForMoney ___test;
	___test.run_test(-1);
}
// END CUT HERE
