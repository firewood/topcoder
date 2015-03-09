// BEGIN CUT HERE
/*
SRM 652 Div1 Easy (250)

PROBLEM STATEMENT

Alice and Bob are playing a game called "The Permutation Game".
The game is parameterized with the int N.
At the start of the game, Alice chooses a positive integer x, and Bob chooses a permutation of the first N positive integers.
Let p be Bob's permutation.
Alice will start at 1, and apply the permutation to this value x times.
More formally, let f(1) = p[1], and f(m) = p[f(m-1)] for all m >= 2.
Alice's final value will be f(x).

Alice wants to choose the smallest x such that f(x) = 1 for any permutation Bob can provide.

Compute and return the value of such x modulo 1,000,000,007.


DEFINITION
Class:ThePermutationGame
Method:findMin
Parameters:int
Returns:int
Method signature:int findMin(int N)


NOTES
-A permutation of the first N positive integers is a sequence of length N that contains each of the integers 1 through N exactly once. The i-th (1-indexed) element of a permutation p is denoted by p[i].


CONSTRAINTS
-N will be between 1 and 100,000 inclusive.


EXAMPLES

0)
2

Returns: 2

Bob can choose the permutations (1,2) or (2,1).
If Alice chooses 1, then, Bob can choose the permutation (2,1), which would would make f(1) = 2.
However, if Alice chooses 2, no matter which permutation Bob chooses, Alice will get f(2) = 1.
Thus the answer in this case is 2.


1)
3

Returns: 6


2)
11

Returns: 27720


3)
102

Returns: 53580071


4)
9999

Returns: 927702802

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
#include <string.h>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

class ThePermutationGame {
public:
	int findMin(int N) {
		LL ans = 1;
		LL f[100001] = {};
		for (LL i = 2; i <= N; ++i) {
			if (!f[i]) {
				for (LL j = i; j <= N; j += i) {
					f[j] = 1;
				}
				for (LL j = i; j <= N; j *= i) {
					ans = (ans * i) % MOD;
				}
			}
		}
		return (int)ans;
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
			int Arg0 = 2;
			int Arg1 = 2;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 6;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 27720;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 102;
			int Arg1 = 53580071;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9999;
			int Arg1 = 927702802;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 59814054;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThePermutationGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
