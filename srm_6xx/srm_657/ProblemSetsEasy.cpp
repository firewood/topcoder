// BEGIN CUT HERE
/*
SRM 657 Div2 Medium (500)

PROBLEM STATEMENT
Cat Snuke came up with some problems. He wants to construct as many problem sets as possible using those problems.

Each problem set must contain exactly three problems: one for the Easy slot, one for the Medium slot, and one for the Hard slot. Each problem can only be assigned to a single slot in a single problem set. He came up with E + EM + M + MH + H problems in total. The distribution of the problems is as follows:

E problems can only be used in the Easy slot.
EM problems can be used either in the Easy slot or the Medium slot.
M problems can only be used in the Medium slot.
MH problems can be used either in the Medium slot or the Hard slot.
H problems can only be used in the Hard slot.

Return the maximal number of problem sets he can construct.


DEFINITION
Class:ProblemSetsEasy
Method:maxSets
Parameters:int, int, int, int, int
Returns:int
Method signature:int maxSets(int E, int EM, int M, int MH, int H)


CONSTRAINTS
-E, EM, M, MH, H must be between 0 and 100000, inclusive.


EXAMPLES

0)
2
2
1
2
2

Returns: 3

One of EM problems should be used for the Easy slot, and the other should be used for the Medium slot.
One of MH problems should be used for the Medium slot, and the other should be used for the Hard slot.


1)
100
100
100
0
0

Returns: 0

Unfortunately, no problem can be used for the Hard slot.


2)
657
657
657
657
657

Returns: 1095


3)
1
2
3
4
5

Returns: 3


4)
100000
100000
100000
100000
100000

Returns: 166666

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

typedef long long LL;

class ProblemSetsEasy {

	bool possible(LL E, LL EM, LL M, LL MH, LL H, LL total) {
		LL a = min(E, min(M, H));
		E -= a, M -= a, H -= a, total -= a;
		EM -= max(0LL, total - E);
		if (EM < 0) {
			return false;
		}
		MH -= max(0LL, total - (EM + M));
		if (MH < 0) {
			return false;
		}
		return (MH + H) >= total;
	}

public:
	int maxSets(int E, int EM, int M, int MH, int H) {
		for (LL i = 1; ; ++i) {
			if (!possible(E, EM, M, MH, H, i)) {
				return i - 1;
			}
		}
		return -1;
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
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 2;
			int Arg5 = 3;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 0;
			int Arg4 = 0;
			int Arg5 = 0;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 657;
			int Arg1 = 657;
			int Arg2 = 657;
			int Arg3 = 657;
			int Arg4 = 657;
			int Arg5 = 1095;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 4;
			int Arg4 = 5;
			int Arg5 = 3;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 100000;
			int Arg2 = 100000;
			int Arg3 = 100000;
			int Arg4 = 100000;
			int Arg5 = 166666;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ProblemSetsEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
