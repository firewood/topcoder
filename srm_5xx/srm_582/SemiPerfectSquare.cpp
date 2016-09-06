// BEGIN CUT HERE
/*
SRM 582 Div2 Easy (250)

PROBLEM STATEMENT
Magical Girl Iris loves perfect squares.
A positive integer n is a perfect square if and only if there is a positive integer b >= 1 such that b*b = n.
For example, 1 (=1*1), 16 (=4*4), and 169 (=13*13) are perfect squares, while 2, 54, and 48 are not.

Iris also likes semi-squares.
A positive integer n is called a semi-square if and only if there are positive integers a >= 1 and b > 1 such that a < b and a*b*b = n.
For example, 81 (=1*9*9) and 48 (=3*4*4) are semi-squares, while 24, 63, and 125 are not.
(Note that we require that a < b.
Even though 24 can be written as 6*2*2, that does not make it a semi-square.)

You are given a int N.
Return "Yes" (quotes for clarity) if N is a semi-square number.
Otherwise, return "No".


DEFINITION
Class:SemiPerfectSquare
Method:check
Parameters:int
Returns:string
Method signature:string check(int N)


NOTES
-The return value is case-sensitive. Make sure that you return the exact strings "Yes" and "No".


CONSTRAINTS
-N will be between 2 and 1000, inclusive.


EXAMPLES

0)
48

Returns: "Yes"

48 can be expressed as 3 * 4 * 4. Therefore, 48 is a semi-square.


1)
1000

Returns: "No"

1000 can be represented as 10 * 10 * 10, but it doesn't match the definition of semi-perfect squares.


2)
25

Returns: "Yes"


3)
47

Returns: "No"


4)
847

Returns: "Yes"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

// BEGIN CUT HERE
/*
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<II> IIVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<II> IISet;
typedef set<string> StrSet;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
#define MOD 1000000007LL
#define MOD 1000000009LL
*/
// END CUT HERE

class SemiPerfectSquare {
public:
	string check(int N) {
		for (int i = 100; i > 1; --i) {
			int a = (N / i / i);
			if (a < i && a * i * i == N) {
				return "Yes";
			}
		}
		return "No";
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
			int Arg0 = 48;
			string Arg1 = "Yes";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			string Arg1 = "No";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 25;
			string Arg1 = "Yes";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			string Arg1 = "No";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 847;
			string Arg1 = "Yes";

			verify_case(n, Arg1, check(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SemiPerfectSquare ___test;
	___test.run_test(-1);
}
// END CUT HERE
