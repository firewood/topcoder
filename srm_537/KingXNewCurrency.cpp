// BEGIN CUT HERE
/*
// SRM 537 Div1 Easy (250)

// PROBLEM STATEMENT
// King Dengklek is the perfect king of Kingdom of Ducks, where slimes and
ducks live together in peace and harmony.

Kingdom of Ducks has a pretty strange currency system. There are only two coin
types: one with value A and one with value B, where A and B are different.
This currency system is denoted by {A, B}. These two coin types are sufficient
for daily transactions, because all prices in this kingdom are in the form of
(A*p + B*q) for some non-negative integers p and q. Therefore, slimes and ducks
can pay for any goods with a combination of the two coin types.

Bored with the current system, King Dengklek considered another currency system
with two coin types: one with value X and one with value Y, where X and Y are
different. Of course, with this new system, combinations of the two new coin
types must make it possible to pay all the prices one could pay with currency
system {A, B}. (Note that the new coin types may also make it possible to pay
some additional prices.)

You are given ints A, B, and X. Return the number of different positive
integers Y (other than X) such that the currency system {X, Y} can be used to
replace the currency system {A, B}. If there is an infinite number of possible
values for Y, return -1 instead.

DEFINITION
Class:KingXNewCurrency
Method:howMany
Parameters:int, int, int
Returns:int
Method signature:int howMany(int A, int B, int X)


CONSTRAINTS
-A, B, and X will each be between 1 and 200, inclusive.
-A and B will be different.


EXAMPLES

0)
5
8
5

Returns: 5

These are the 5 possible currency systems: {5, 1}, {5, 2}, {5, 3}, {5, 4}, and {5, 8}.


1)
8
4
2

Returns: -1

All prices are multiples of four. Since a coin type with value 2 alone can pay any price that is a multiple of four, there is an infinite number of possible values of Y.


2)
7
4
13

Returns: 1

The only possible currency system is {13, 1}.


3)
47
74
44

Returns: 2

The two possible currency systems are {44, 1} and {44, 3}.


4)
128
96
3

Returns: 65

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

class KingXNewCurrency {

public:
	int howMany(int A, int B, int X) {
		if ((A % X) == 0 && (B % X) == 0) {
			return -1;
		}
		int res = 0;
		int y;
		for (y = 1; y <= 200; ++y) {
			int Max = max(A, B);
			bool af = false, bf = false;
			int i, j;
			for (i = 0; i <= Max; ++i) {
				for (j = 0; j <= Max; ++j) {
					int z = X*i+y*j;
					if (z > Max) {
						break;
					}
					if (z == A) {
						af = true;
					}
					if (z == B) {
						bf = true;
					}
				}
			}
			res += af && bf;
		}
		return res;
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
			int Arg0 = 5;
			int Arg1 = 8;
			int Arg2 = 5;
			int Arg3 = 5;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arg1 = 4;
			int Arg2 = 2;
			int Arg3 = -1;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			int Arg2 = 13;
			int Arg3 = 1;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 74;
			int Arg2 = 44;
			int Arg3 = 2;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 128;
			int Arg1 = 96;
			int Arg2 = 3;
			int Arg3 = 65;

			verify_case(n, Arg3, howMany(Arg0, Arg1, Arg2));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingXNewCurrency ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
