// BEGIN CUT HERE
/*
SRM 635 Div2 Medium (500)

PROBLEM STATEMENT

"Němec's quadratic law: how many minutes the teacher was late to the lesson, that many minutes squared he'll end the lesson earlier."

In other words, if the teacher is t minutes late (for some non-negative integer t), he should end the lesson t2 minutes early. Of course, this means the teacher can't be too late, because a lesson can't end before even starting. It is, however, possible for the teacher to arrive and end the lesson immediately (in fact, he then only arrives to tell the students that the lesson's cancelled).

You're given a long long d. The lesson was supposed to take d minutes. Compute and return the largest non-negative integer t such that the teacher can be t minutes late.


DEFINITION
Class:QuadraticLaw
Method:getTime
Parameters:long long
Returns:long long
Method signature:long long getTime(long long d)


CONSTRAINTS
-d will be between 1 and 1,000,000,000,000,000,000, inclusive.


EXAMPLES

0)
1

Returns: 0

The lesson was supposed to take 1 minute. The teacher can only be 0 minutes late, in which case he ends the lesson 0 minutes early (i.e. he arrives and ends the lecture on time).

1)
2

Returns: 1

It's possible for the teacher to be 1 minute late and end the lecture 1 minute early (so there's no lecture at all).

2)
5

Returns: 1



3)
6

Returns: 2



4)
7

Returns: 2



5)
1482

Returns: 38



6)
1000000000000000000

Returns: 999999999



7)
31958809614643170

Returns: 178770270



*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class QuadraticLaw {
public:
	long long getTime(long long d) {
		LL t = sqrt(d);
		LL ans = 0;
		for (LL a = max(0LL, t - 2); a <= t + 1; ++a) {
			if (a*a+a <= d) {
				ans = a;
			}
		}
		return ans;
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
			long long Arg0 = 1LL;
			long long Arg1 = 0LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 6LL;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1482LL;
			long long Arg1 = 38LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			long long Arg1 = 999999999LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 31958809614643170LL;
			long long Arg1 = 178770270LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	QuadraticLaw ___test;
	___test.run_test(-1);
}
// END CUT HERE
