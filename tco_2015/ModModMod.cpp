// BEGIN CUT HERE
/*
TCO 2015 Round 2A Easy (300)

PROBLEM STATEMENT

Moose Mod has just learned about the mod operator.
Given two positive integers x and y, the mod operator returns the remainder when x is divided by y.
For example, 17 mod 5 = 2 because 17 = 3*5 + 2.

Moose Mod has just defined a function that applies a sequence of N mod operators to its input.
Formally, the function looks as follows:
f(x) = (((x mod m[0]) mod m[1]) ... mod m[N-1]).
For example, m = { 10, 3 } corresponds to the function f(x) = (x mod 10) mod 3.
For this function we have f(18) = (18 mod 10) mod 3 = 8 mod 3 = 2.

You are given the vector <int> m.
You are also given a int R.
Moose Mod is interested in finding the sum f(1) + f(2) + ... + f(R).
Compute and return its value.


DEFINITION
Class:ModModMod
Method:findSum
Parameters:vector <int>, int
Returns:long long
Method signature:long long findSum(vector <int> m, int R)


CONSTRAINTS
-m will have between 1 and 5,000 elements, inclusive.
-Each element of m will be between 1 and 10,000,000, inclusive.
-R will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
{5,3,2}
10

Returns: 4

The values of f from 1 to 10 are 1, 0, 0, 1, 0, 1, 0, 0, 1, 0. The sum of all these values is 4.


1)
{33, 15, 7, 10, 100, 9, 5}
64

Returns: 92


2)
{995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131}
992363

Returns: 12792005


3)
{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}
100

Returns: 4950


4)
{2934}
10000000

Returns: 14664070144

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
typedef vector<int> IntVec;

class ModModMod {
	int N;
	IntVec _m;
	
	LL calc(int i, LL r) {
		if (r <= 0) {
			return 0;
		}
		LL d = _m[i];
		LL a = r / d;
		LL b = r % d;
		if (i == (N - 1)) {
			return ((d - 1) * d) / 2 * a + ((b + 1) * b) / 2;
		}
		LL sum = a > 0 ? calc(i + 1, d - 1) * a : 0;
		return sum + calc(i + 1, b);
	}

public:
	long long findSum(vector <int> m, int R) {
		N = (int)m.size();
		_m = m;
		return calc(0, R);
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
			int Arr0[] = {5,3,2};
			int Arg1 = 10;
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {33, 15, 7, 10, 100, 9, 5};
			int Arg1 = 64;
			long long Arg2 = 92LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131};
			int Arg1 = 992363;
			long long Arg2 = 12792005LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
			int Arg1 = 100;
			long long Arg2 = 4950LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2934};
			int Arg1 = 10000000;
			long long Arg2 = 14664070144LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findSum(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ModModMod ___test;
	___test.run_test(-1);
}
// END CUT HERE
