// BEGIN CUT HERE
/*
SRM 744 Div1 Easy (250)

PROBLEM STATEMENT

We are looking at the first quadrant of an infinite square grid. Its rows and columns are numbered starting from zero. Each cell (r,c) contains the number (max(r,c) mod 3).

Compute and return the sum of all cells (r,c) such that r1 <= r <= r2 and c1 <= c <= c2.


DEFINITION
Class:ModularQuadrant
Method:sum
Parameters:int, int, int, int
Returns:long long
Method signature:long long sum(int r1, int r2, int c1, int c2)


CONSTRAINTS
-0 <= r1 <= r2 <= 10^9.
-0 <= c1 <= c2 <= 10^9.


EXAMPLES

0)
0
2
1
4

Returns: 13

We want rows 0 through 2 and columns 1 through 4. The corresponding part of the grid looks as follows:

2201
1201
1201


1)
2
2
0
7

Returns: 10

Now we are computing the sum of a single row that looks as follows:

22201201


2)
4
8
0
5

Returns: 37


222222
111111
000000
222222
111112


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

class ModularQuadrant {

	LL calc(int r, int c) {
		LL n = min(r, c), m = max(r, c);
		LL a = (n + 2) / 3;
		LL tot = a * a * 3;
		LL b = (n + 1) / 3;
		tot += b * b * 6 + 4 * b;
		if (n != m) {
			LL c = (m + 2) / 3 - a;
			tot += c * (n + 1);
			LL d = (m + 1) / 3 - b;
			tot += d * (n + 1) * 2;
		}
		return tot;
	}

public:
	long long sum(int r1, int r2, int c1, int c2) {
		LL ans = calc(r2, c2);
		if (c1 > 0) {
			ans -= calc(r2, c1 - 1);
		}
		if (r1 > 0) {
			ans -= calc(r1 - 1, c2);
		}
		if (r1 > 0 && c1 > 0) {
			ans += calc(r1 - 1, c1 - 1);
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
			int Arg0 = 0;
			int Arg1 = 2;
			int Arg2 = 1;
			int Arg3 = 4;
			long long Arg4 = 13LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 7;
			long long Arg4 = 10LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 8;
			int Arg2 = 0;
			int Arg3 = 5;
			long long Arg4 = 37LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 4;
			int Arg2 = 0;
			int Arg3 = 2;
			long long Arg4 = 16LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 2;
			long long Arg4 = 2LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 2;
			int Arg3 = 4;
			long long Arg4 = 4LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 1;
			int Arg2 = 0;
			int Arg3 = 3;
			long long Arg4 = 7LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 4;
			int Arg2 = 0;
			int Arg3 = 3;
			long long Arg4 = 17LL;

			verify_case(n, Arg4, sum(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ModularQuadrant ___test;
	___test.run_test(-1);
}
// END CUT HERE
