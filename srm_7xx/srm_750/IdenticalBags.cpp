// BEGIN CUT HERE
/*
SRM 750 Div1 Easy (250)

PROBLEM STATEMENT

You are preparing for Halloween.
You like to hand out bags of candy.
In order to prevent arguments between the kids who get them, you want all bags to be identical.

You have a supply of various candy.
Each element of candy is the number of pieces of a specific candy type.
You want to create bags that will contain bagSize pieces of candy each.
Compute and return the maximum number of identical bags you can make.


DEFINITION
Class:IdenticalBags
Method:makeBags
Parameters:vector<long long>, long long
Returns:long long
Method signature:long long makeBags(vector<long long> candy, long long bagSize)


CONSTRAINTS
-candy will contain between 1 and 100 elements, inclusive.
-Each element of candy will be between 1 and 10^18, inclusive.
-bagSize will be between 1 and 10^18, inclusive.


EXAMPLES

0)
{10, 11, 12}
3

Returns: 10

You can make 10 identical bags, each containing one candy of each type.


1)
{10, 11, 12, 1, 2, 3}
3

Returns: 10

We have a few more candy types than in Example #0, but the optimal solution remained the same.


2)
{100}
7

Returns: 14

This time you can make (100 div 7) bags, each containing 7 candies of the only type you have.


3)
{10000000000, 20000000000, 30000000000}
6

Returns: 10000000000

Watch out for integer overflow.

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

typedef long long LL;

class IdenticalBags {
	bool possible(vector<LL> c, LL b, LL x) {
		for (LL a : c) {
			b -= a / x;
		}
		return b <= 0;
	}

public:
	long long makeBags(vector<long long> candy, long long bagSize) {
		LL left = 0, right = 1000000000000000001LL;
		while ((right - left) > 1) {
			LL mid = (left + right) / 2;
			if (possible(candy, bagSize, mid)) {
				left = mid;
			} else {
				right = mid;
			}
		}
		return left;
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
			long Arr0[] = {10, 11, 12};
			long long Arg1 = 3LL;
			long long Arg2 = 10LL;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makeBags(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {10, 11, 12, 1, 2, 3};
			long long Arg1 = 3LL;
			long long Arg2 = 10LL;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makeBags(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {100};
			long long Arg1 = 7LL;
			long long Arg2 = 14LL;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makeBags(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arr0[] = {10000000000LL, 20000000000LL, 30000000000LL};
			long long Arg1 = 6LL;
			long long Arg2 = 10000000000LL;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makeBags(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			long long Arr0[] = {
				8589934592LL,8589934592LL
			};
			long long Arg1 = 8589934592LL;
			long long Arg2 = 2;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makeBags(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			long long Arr0[] = {
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL,
				1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL, 1000000000000000000LL
			};
			long long Arg1 = 1LL;
			long long Arg2 = 1000000000000000000LL;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, makeBags(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IdenticalBags ___test;
	___test.run_test(-1);
}
// END CUT HERE
