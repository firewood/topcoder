// BEGIN CUT HERE
/*
SRM 610 Div1 Easy (250)
SRM 610 Div1 Medium (500)

PROBLEM STATEMENT

Alice and Bob are playing a game.
Alice has an a-sided die.
Bob has a b-sided die.
(The faces of an n-sided die have numbers 1 through n written on them.)



The game is simple:
Each player rolls their die, and the player who rolls a strictly larger number wins.
(It is possible that neither player wins.)



You are given the ints a and b.
The players already rolled their dice.
You do not know what numbers they rolled, but you know that Alice won the game.
Compute and return the expected value of the number Alice rolled.



DEFINITION
Class:FixedDiceGameDiv2
Method:getExpectation
Parameters:int, int
Returns:double
Method signature:double getExpectation(int a, int b)


NOTES
-Your return value must have absolute or relative error smaller than 1e-9.
-The expected value can be seen as the average of many experiments. In our case, suppose that you folow a lot of games, and each time Alice wins, you write down her score. As you watch more and more games, the average of all numbers you have written down will converge to the expected value you should return. 


CONSTRAINTS
-a and b will each be between 2 and 1000, inclusive.


EXAMPLES

0)
2
2

Returns: 2.0

Alice can only win if she rolls a 2 and Bob rolls a 1. Thus, if we know Alice wins, we know she rolled a 2.

1)
4
2

Returns: 3.2



2)
3
3

Returns: 2.6666666666666665



3)
11
13

Returns: 7.999999999999999



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

using namespace std;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
*/
// END CUT HERE

class FixedDiceGameDiv2 {
public:
	double getExpectation(int a, int b) {
		double cnt = 0, sum = 0;
		for (int i = 2; i <= a; ++i) {
			for (int j = 1; j < i && j <= b; ++j) {
				cnt += 1;
				sum += i;
			}
		}
		return sum / cnt;
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
			int Arg0 = 2;
			int Arg1 = 2;
			double Arg2 = 2.0;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			double Arg2 = 3.2;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			double Arg2 = 2.6666666666666665;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 13;
			double Arg2 = 7.999999999999999;

			verify_case(n, Arg2, getExpectation(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FixedDiceGameDiv2 ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
