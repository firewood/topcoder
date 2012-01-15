// BEGIN CUT HERE
/*
// SRM 529 Div2 Hard (1000)
// PROBLEM STATEMENT
// 
Marvin plays a simple game. The game is played with an infinite supply of marbles and five bags,
labeled "bag 0" through "bag 4".

At the beginning, Marvin takes N marbles (where N is a nonnegative integer) and places them into bag 0.
The remaining four bags are left empty.
Marvin then follows this simple algorithm:

    Add a marble into bag 1.
    Repeat forever:
        Add a marble into bag 1.
        Empty bag 4.
        While there are marbles in bag 0:
            While there are marbles both in bag 0 and in bag 1:
                Remove a marble from bag 0.
                Remove a marble from bag 1.
                Add a marble into bag 2.
                Add a marble into bag 3.
            End While
            Add a marble into bag 4.
            If bags 0 and 1 are both empty:
                Move all marbles from bag 3 to bag 4.
                TERMINATE THE GAME
            End If
            Move all marbles from bag 3 to bag 1.
        End While
        Move all marbles from bag 2 to bag 0.
    End Repeat

You are given a long long N. Return a long long containing the number of marbles that will be
in bag 4 at the end of Marvin's game. If Marvin's game does not terminate for the given N,
return -1 instead.


DEFINITION
Class:MinskyMysteryDiv2
Method:computeAnswer
Parameters:long long
Returns:long long
Method signature:long long computeAnswer(long long N)


NOTES
-You may assume that the answer always fits into a long long.
-Note that N is allowed to be zero.


CONSTRAINTS
-N will be between 0 and 10^12, inclusive.


EXAMPLES

0)
2

Returns: 3



1)
3

Returns: 4



2)
4

Returns: 4



3)
15

Returns: 8



4)
24

Returns: 14

#line 94 "MinskyMysteryDiv2.cpp"
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

class MinskyMysteryDiv2 {

public:
	long long computeAnswerRef(long long N) {
		if (N <= 1) {
			return -1;
		}

		LL m[5] = {0};
		m[0] = N;
		m[1] += 1;
		while (true) {
			m[1] += 1;
			m[4] = 0;
			while (m[0]) {
				while (m[0] && m[1]) {
					m[0] -= 1;
					m[1] -= 1;
					m[2] += 1;
					m[3] += 1;
				}
				m[4] += 1;
				if (!m[0] && !m[1]) {
					return m[3] + m[4];
				}
				m[1] += m[3];
				m[3] = 0;
			}
			m[0] += m[2];
			m[2] = 0;
		}
	}

	long long computeAnswer(long long N) {
		if (N <= 1) {
			// infinite
			return -1;
		}
		if ((N % 2) == 0) {
			// even
			return N / 2 + 2;
		}

		LL x;
		for (x = 3; (x*x) <= N; x += 2) {
			if ((N % x) == 0) {
				// not a prime
				return x + N / x;
			}
		}

		// prime
		return N + 1;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 3LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3LL;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4LL;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 15LL;
			long long Arg1 = 8LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 24LL;
			long long Arg1 = 14LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinskyMysteryDiv2 ___test;
	___test.run_test(-1);

	return 0;
}
// END CUT HERE
