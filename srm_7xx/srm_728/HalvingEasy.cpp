// BEGIN CUT HERE
/*
SRM 728 Div2 Easy (250)

PROBLEM STATEMENT

Halving is an operation that takes a nonnegative integer X and transforms it into another nonnegative integer: the value X/2, rounded down if necessary.
For example, halving 16 produces 8, and halving 21 gives the result 10.

You are given a vector <int> S containing a collection of nonnegative integers.
You are also given a target: the int T.

Count the number of elements of S which can be transformed into T by halving them zero or more times.
Return this count.


DEFINITION
Class:HalvingEasy
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> S, int T)


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element of S will be between 1 and 109, inclusive.
-T will be between 1 and 109, inclusive.


EXAMPLES

0)
{6, 14, 11, 3, 1}
3

Returns: 3


6 can be transformed into 3 by halving it once.
14 can be transformed into 3 by halving it twice (14 halved is 7, and 7 halved is 3).
3 can be transformed into 3 by halving it zero times.
the other two elements of S (11 and 1) cannot be transformed into 3.


1)
{42, 10, 10, 10, 11, 11, 20, 21, 39, 40, 42, 43, 44}
10

Returns: 9

42, 10, 10, 10, 20, 21, 40, 42 and 43 can be transformed into 10. Note that all occurrences of 10 and 42 are counted towards the answer.


2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}
1

Returns: 20

Every positive integer can be transformed into 1 by halving zero or more times.


3)
{987654321, 1000000000, 998244353, 123456789, 999999999}
476

Returns: 3


4)
{987654321, 1000000000, 998244353, 123456789, 999999999}
1000000000

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class HalvingEasy {
public:
	int count(vector <int> S, int T) {
		int ans = 0;
		for (int a : S) {
			while (a > T) {
				a /= 2;
			}
			ans += a == T;
		}
		return ans;
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
			int Arr0[] = {6, 14, 11, 3, 1};
			int Arg1 = 3;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 10, 10, 10, 11, 11, 20, 21, 39, 40, 42, 43, 44};
			int Arg1 = 10;
			int Arg2 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
			int Arg1 = 1;
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {987654321, 1000000000, 998244353, 123456789, 999999999};
			int Arg1 = 476;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {987654321, 1000000000, 998244353, 123456789, 999999999};
			int Arg1 = 1000000000;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HalvingEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
