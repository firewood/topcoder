// BEGIN CUT HERE
/*
SRM 615 Div2 Medium (500)

PROBLEM STATEMENT
Limit is a flea. He can do two types of jumps: small jumps that have length 1 millimeter, and big jumps that have length B millimeters.

Limit is going to make exactly T jumps, all of them in the same direction. He would like to travel exactly D millimeters in those jumps. Is this possible?

You are given a long long D, and ints T and B. Return "Possible" (quotes for clarity) if there is a combination of T jumps forward that has a total length of exactly D millimeters. Otherwise, return "Impossible".

DEFINITION
Class:LongLongTripDiv2
Method:isAble
Parameters:long long, int, int
Returns:string
Method signature:string isAble(long long D, int T, int B)


CONSTRAINTS
-D will be between 1 and 10^18, inclusive.
-T will be between 1 and 1,000,000,000, inclusive.
-B will be between 2 and 1,000,000,000, inclusive.


EXAMPLES

0)
10
6
3

Returns: "Possible"

Limit must make 6 jumps that have a total length of 10 millimeters. This is possible: two of the jumps must be long and the other four must be short.


1)
10
5
3

Returns: "Impossible"


2)
50
100
2

Returns: "Impossible"


3)
120
10
11

Returns: "Impossible"


4)
10
10
9999

Returns: "Possible"


5)
1000
100
10

Returns: "Possible"


6)
1000010000100001
1100011
1000000000

Returns: "Possible"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class LongLongTripDiv2 {

	bool check(LL D, LL T, LL B) {
		LL low = -1, high = T;
		while (high - low > 1) {
			int med = (low + high) / 2;
			LL x = med * B + (T - med);
			if (x < D) {
				low = med;
			} else {
				high = med;
			}
		}
		return high * B + (T - high) == D;
	}

public:
	string isAble(long long D, int T, int B) {
		return check(D, T, B) ? "Possible" : "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			int Arg1 = 6;
			int Arg2 = 3;
			string Arg3 = "Possible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			int Arg1 = 5;
			int Arg2 = 3;
			string Arg3 = "Impossible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 50LL;
			int Arg1 = 100;
			int Arg2 = 2;
			string Arg3 = "Impossible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 120LL;
			int Arg1 = 10;
			int Arg2 = 11;
			string Arg3 = "Impossible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			int Arg1 = 10;
			int Arg2 = 9999;
			string Arg3 = "Possible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000LL;
			int Arg1 = 100;
			int Arg2 = 10;
			string Arg3 = "Possible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000010000100001LL;
			int Arg1 = 1100011;
			int Arg2 = 1000000000;
			string Arg3 = "Possible";

			verify_case(n, Arg3, isAble(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongLongTripDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
