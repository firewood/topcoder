// BEGIN CUT HERE
/*
SRM 657 Div1 Easy (250)

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
Class:ProblemSets
Method:maxSets
Parameters:long long, long long, long long, long long, long long
Returns:long long
Method signature:long long maxSets(long long E, long long EM, long long M, long long MH, long long H)


CONSTRAINTS
-E, EM, M, MH, H will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.


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
1000000000000000000
1000000000000000000
1000000000000000000
1000000000000000000
1000000000000000000

Returns: 1666666666666666666

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

class ProblemSets {

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
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		LL low = -1, high = 1LL << 62;
		while ((high - low) > 1) {
			LL mid = (low + high) / 2;
			if (!possible(E, EM, M, MH, H, mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return low;
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
			long long Arg1 = 2LL;
			long long Arg2 = 1LL;
			long long Arg3 = 2LL;
			long long Arg4 = 2LL;
			long long Arg5 = 3LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 100LL;
			long long Arg2 = 100LL;
			long long Arg3 = 0LL;
			long long Arg4 = 0LL;
			long long Arg5 = 0LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 657LL;
			long long Arg1 = 657LL;
			long long Arg2 = 657LL;
			long long Arg3 = 657LL;
			long long Arg4 = 657LL;
			long long Arg5 = 1095LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 3LL;
			long long Arg3 = 4LL;
			long long Arg4 = 5LL;
			long long Arg5 = 3LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			long long Arg1 = 1000000000000000000LL;
			long long Arg2 = 1000000000000000000LL;
			long long Arg3 = 1000000000000000000LL;
			long long Arg4 = 1000000000000000000LL;
			long long Arg5 = 1666666666666666666LL;

			verify_case(n, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ProblemSets ___test;
	___test.run_test(-1);
}
// END CUT HERE
