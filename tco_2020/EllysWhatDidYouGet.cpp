// BEGIN CUT HERE
/*
TCO20 R1B Medium (500)

PROBLEM STATEMENT
Choose a number between 1 and 9, inclusive. Multiply it by 3. Add 3 to it. Multiply it again by 3. Sum its digits. You got 9, right?

Elly was intrigued by this "magic trick" (that is actually just pure number theory). 
She now wants to generalize it.
In her version you should initially choose a number between 1 and N, inclusive, then you should multiply it by X, add Y, multiply that result by Z, and finally sum the digits of the number you got.
If all choices of the initial number lead to the same final result, the girl is satisfied by the triplet (X, Y, Z).

Elly will only consider X, Y, and Z which are positive integers between 1 and 50, inclusive - otherwise the calculations become too difficult for her taste. There is no restriction on whether X, Y, and Z should be equal or not. In the example above X = Y = Z = 3, but (X = 9, Y = 9, Z = 5), (X = 10, Y = 1, Z = 9), or (X = 42, Y = 48, Z = 33) also work for N = 9.

Let's consider the last example in more detail. You may choose any starting value between 1 and 9, inclusive. Suppose you chose the starting value 3. First you multiply it by 42, which gives you 126. Then you add 48, which gives you 174. In the third step you multiply that by 33, getting 5742. Your final answer is the sum of digits of 5742, which is 5+7+4+2 = 18. Starting from the value 1 gives us 1*42 = 42, 42+48 = 90, 90*33 = 2970, and 2+9+7+0 = 18. Similarly, each of the seven other possible starting values produces the final answer 18.

Given the int N, return the number triplets of positive integers (X, Y, Z) having 1 ? X, Y, Z ? 50, for which all initial numbers between 1 and N yield the same final answer after the sequence of operations described above.


DEFINITION
Class:EllysWhatDidYouGet
Method:getCount
Parameters:int
Returns:int
Method signature:int getCount(int N)


CONSTRAINTS
-N will be an integer between 1 and 100, inclusive.


EXAMPLES

0)
9

Returns: 952


1)
5

Returns: 3515


2)
13

Returns: 456


3)
42

Returns: 149

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysWhatDidYouGet {
public:
	int getCount(int N) {
		int ans = 0;
		for (int x = 1; x <= 50; ++x) {
			for (int y = 1; y <= 50; ++y) {
				for (int z = 1; z <= 50; ++z) {
					if ([&]() -> bool {
						int prev = -1;
						for (int n = 1; n <= N; ++n) {
							int a = n * x;
							a += y;
							a *= z;
							int sum = 0;
							for (char c : to_string(a)) {
								sum += c - '0';
							}
							if (prev < 0) {
								prev = sum;
							}
							if (prev != sum) {
								return false;
							}
						}
						return true;
					}()) {
						ans += 1;
					}
				}
			}
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
			int Arg0 = 9;
			int Arg1 = 952;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 3515;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 456;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 42;
			int Arg1 = 149;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysWhatDidYouGet ___test;
	___test.run_test(-1);
}
// END CUT HERE
