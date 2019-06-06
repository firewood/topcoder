// BEGIN CUT HERE
/*
TCO19 R2B Medium (500)

PROBLEM STATEMENT
Given a positive integer N, find and return the length of the longest sequence a_1, ..., a_K of positive integers such that:

The sum of all a_i is N.
For each valid i, a_i < a_{i+1}.
For each valid i, a_i divides a_{i+1}.


DEFINITION
Class:DivisorSequences
Method:longest
Parameters:int
Returns:int
Method signature:int longest(int N)


CONSTRAINTS
-N will be between 1 and 2*10^9, inclusive.


EXAMPLES

0)
15

Returns: 4

The only optimal sequence is {1,2,4,8}. Clearly, 1 divides 2, 2 divides 4, 4 divides 8, and 1+2+4+8 = 15.


1)
12

Returns: 2

The are four distinct optimal sequences: {1,11}, {2,10}, {3,9}, and {4,8}. There is no valid sequence with more than two elements.


2)
34

Returns: 4

The only optimal sequence is {1, 3, 6, 24}.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DivisorSequences {
	vector<int> memo;

	int A167866(int n) {
		if (n <= 1) return 0;
		if (n < memo.size() && memo[n]) return memo[n];
		vector<int> f;
		for (int i = 1; i * i <= n; ++i) {
			if ((n % i) == 0) {
				f.push_back(i);
				f.push_back(n / i);
			}
		}
		int r = 0;
		for (int d : f) {
			if (d > 1) {
				r = max(r, 1 + A167866((n - d) / d));
			}
		}
		if (n < memo.size()) memo[n] = r;
		return r;
	}

public:
	int longest(int n) {
		if (memo.empty()) {
			memo.resize(2560000);
		}
		return max(A167866(n), A167866(n - 1) + 1);
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
			int Arg0 = 15;
			int Arg1 = 4;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 2;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 34;
			int Arg1 = 4;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1073741823;
			int Arg1 = 30;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1073741822;
			int Arg1 = 29;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1023;
			int Arg1 = 10;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1022;
			int Arg1 = 9;

			verify_case(n, Arg1, longest(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivisorSequences ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
