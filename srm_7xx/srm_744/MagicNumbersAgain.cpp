// BEGIN CUT HERE
/*
SRM 744 Div2 Medium (500)

PROBLEM STATEMENT

	Sequence (d1, d2, d3, ..., dt) is a digit representation of X (with no leading zeros) if the i-th digit of X is di. In particular, d1 is the most and dt is the least significant digit of X. For instance, the digit representation of X = 576 is (5, 7, 6).


	We say that an integer X is magic-square iff:


	X is a square of an integer, i.e., X = Y2 for some integer Y.
	For the digit representation (d1, d2, d3, ..., dt) of X it holds d1 < d2 > d3 < d4, and so on. That is, for each odd i < t it holds di < di + 1, and for each even i < t it holds di > di + 1.


	Given A and B, output how many magic-square integers between A and B there are.


DEFINITION
Class:MagicNumbersAgain
Method:count
Parameters:long long, long long
Returns:int
Method signature:int count(long long A, long long B)


CONSTRAINTS
-B will be between 1 and 10,000,000,000, inclusive.
-A will be between 1 and B, inclusive.


EXAMPLES

0)
1
64

Returns: 7

The magic numbers between 1 and 64 are: 1, 4, 9, 16, 25, 36, and 49. Although 64 is a square of an integer (64=8*8), 64 is not a magic number as its first digit is not smaller than its second one.


1)
50
60

Returns: 0

Between 50 and 60 there are no integers that are squares of other integers, hence in this range can not exist magic numbers neither.


2)
121
121

Returns: 1


3)
5679
1758030

Returns: 73


4)
1304164
2000000

Returns: 14

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

class MagicNumbersAgain {
public:
	int count(long long A, long long B) {
		int ans = 0;
		LL m = (LL)sqrt(B);
		for (LL i = 1; i <= m; ++i) {
			LL j = i * i;
			if (j >= A) {
				string s = to_string(j);
				int len = (int)s.length();
				int ok = 1;
				if (len % 2) {
					s += "@";
				}
				s += " @";
				for (int k = 0; k < len; k += 2) {
					if (s[k] >= s[k + 1] || s[k + 1] <= s[k + 2]) {
						ok = 0;
					}
				}
				ans += ok;
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
			long long Arg0 = 1LL;
			long long Arg1 = 64LL;
			int Arg2 = 7;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 50LL;
			long long Arg1 = 60LL;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 121LL;
			long long Arg1 = 121LL;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5679LL;
			long long Arg1 = 1758030LL;
			int Arg2 = 73;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1304164LL;
			long long Arg1 = 2000000LL;
			int Arg2 = 14;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicNumbersAgain ___test;
	___test.run_test(-1);
}
// END CUT HERE
