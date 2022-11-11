// BEGIN CUT HERE
/*
SRM 710 Div1 Easy (841)

PROBLEM STATEMENT

We have a collection of regular dice. Different dice in this collection may have a different number of faces.

For each X, an X-sided die has faces numbered from 1 to X. When rolled, each face comes up with probability 1/X.

You are given the vector <int> dice: for each die in our collection the number of faces it has.

We are going to roll all dice in our collection (each of them exactly once) and then we'll compute the bitwise xor of all values rolled.

Calculate and return the expected value of the result we'll obtain.


DEFINITION
Class:DiceOperation
Method:solve
Parameters:vector <int>
Returns:double
Method signature:double solve(vector <int> dice)


NOTES
-The return value must have an absolute or a relative error at most 10^(-9).
-All dice rolls are mutually independent.
-See https://en.wikipedia.org/wiki/Expected_value if you need a definition of the expected value of a random variable.


CONSTRAINTS
-dice will contain between 1 and 10 elements, inclusive.
-Each element of dice will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{1, 1, 1, 1, 1}

Returns: 1.0

Five "dice", each of them is guaranteed to roll a 1. The xor of five 1s is 1.

1)
{1, 1, 1, 1, 1, 1}

Returns: 0.0

As above, but now the xor of six 1s is 0.

2)
{3, 3}

Returns: 1.3333333333333335


With probability 1/3 the two values rolled are equal and thus their xor is zero.
with probability 2/9 we get the values {1, 2}, their xor is 3.
with probability 2/9 we get the values {1, 3}, their xor is 2.
with probability 2/9 we get the values {2, 3}, their xor is 1.

Thus, the expected value of the result is (1/3)*0 + (2/9)*3 + (2/9)*2 + (2/9)*1 = 4/3.

3)
{3, 4}

Returns: 2.5

All the outcomes from the previous example are still possible but now they are somewhat less likely. Here it is also possible to roll {1,4}, {2,4}, or {3,4}, each with probability 1/12.

4)
{5, 9, 6}

Returns: 5.277777777777778



5)
{47}

Returns: 24.0

With a single die the final result is simply the value you rolled.

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

typedef long double LD;

class DiceOperation {
public:
	double solve(vector <int> dice) {
		int n = int(dice.size());
		LD ans = 0;
		for (int k = 0; k < 30; ++k) {
			int b = 1 << k, bm = b * 2 - 1;
			LD p0 = 1.0, p1 = 1.0 - p0;
			for (int d : dice) {
				int low = d & ~bm, z, o;
				if ((d & b) == 0) {
					o = low / 2, z = d - o;
				} else {
					z = low / 2 + b - 1, o = d - z;
				}
				LD pz = LD(z) / (z + o);
				p0 = p0 * pz + p1 * (1.0 - pz), p1 = 1.0 - p0;
			}
			ans += b * p1;
		}
		return ans;
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
			int Arr0[] = {1, 1, 1, 1, 1};
			double Arg1 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1};
			double Arg1 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 3};
			double Arg1 = 1.3333333333333335;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 4};
			double Arg1 = 2.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 9, 6};
			double Arg1 = 5.277777777777778;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {47};
			double Arg1 = 24.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DiceOperation ___test;
	___test.run_test(-1);
}
// END CUT HERE
