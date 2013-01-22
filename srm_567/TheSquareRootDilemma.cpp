// BEGIN CUT HERE
/*
SRM 567 Div1 Easy (250)

PROBLEM STATEMENT
Consider the function SSR (Squared Sum of square Roots) defined on two positive integer parameters:
SSR(A, B) = (sqrt(A)+sqrt(B))^2. We are interested in the cases when the value of the function is also an integer.

Given ints N and M, return the number of ordered pairs (A, B) such that 1 <= A <= N, 1 <= B <= M and SSR(A, B) is an integer.


DEFINITION
Class:TheSquareRootDilemma
Method:countPairs
Parameters:int, int
Returns:int
Method signature:int countPairs(int N, int M)


NOTES
-The answer to the problem is guaranteed to fit into signed 32-bit integer type under the given constraints.


CONSTRAINTS
-N will be between 1 and 77,777, inclusive.
-M will be between 1 and 77,777, inclusive.


EXAMPLES

0)
2
2

Returns: 2

Out of the four possible pairs (A, B), only two yield an integer result: SSR(1, 1) = 4 and SSR(2, 2) = 8.
On the other hand, SSR(1, 2) = SSR(2, 1) = 3+2*sqrt(2), which is not an integer.


1)
10
1

Returns: 3

SSR(1, 1), SSR(4, 1) and SSR(9, 1) are integers.


2)
3
8

Returns: 5

The valid pairs are (1, 1), (1, 4), (2, 2), (2, 8) and (3, 3).


3)
100
100

Returns: 310

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheSquareRootDilemma {

public:
	int countPairs(int N, int M) {
		int ans = 0;
		int i, j, k, n;

#if 1
		int f[77778] = {};
		for (i = 1; i <= N; ++i) {
			for (j = 1; (n = i*j*j) <= N; ++j) {
				if (!f[n]) {
					f[n] = 1;
					int r = M / i;
//					int m;
//					for (k = 1; (m = i*k*k) <= M; ++k) {
//						++ans;
//					}
					ans += floor(sqrt((double)r));
				}
			}
		}
#else
		for (i = 1; i <= N; ++i) {
			double a = sqrt((double)i);
			for (j = 1; j <= M; ++j) {
				double b = sqrt((double)j);
				double c = a+b;
				double d = c*c+0.000001;
				ans += fabs(d - floor(d)) <= 0.000002;
			}
		}
#endif

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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 2;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 1;
			int Arg2 = 3;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 8;
			int Arg2 = 5;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 310;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234;
			int Arg1 = 1234;
			int Arg2 = 5546;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 7777;
			int Arg1 = 7777;
			int Arg2 = 43513;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 77777;
			int Arg1 = 77777;
			int Arg2 = 543345;

			verify_case(n, Arg2, countPairs(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheSquareRootDilemma ___test;
	___test.run_test(-1);
}
// END CUT HERE
