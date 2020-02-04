// BEGIN CUT HERE
/*
SRM 777 Div1 Easy (250)

PROBLEM STATEMENT

A recursive sequence A is defined as follows:
A[0] = 0, and for all n >= 0, A[n+1] is the distance between the last two occurrences of A[n], or defaultValue if the value A[n] doesn't have any previous occurrence.

For example, if defaultValue = 7, the sequence begins as follows:
0, 7, 7, 1, 7, 2, 7, 2, 2, 1, 6, 7, 5, 7, 2, 6, 5, ...

A[0] = 0 is given.
A[1] = 7 because the previous term (0) only occurs once.
A[2] = 7 because the previous term (7) only occurs once.
A[3] = 1 because the previous term (7) occurs at indices 2 and 1, and 2-1 = 1.
A[4] = 7 because the previous term (1) only occurs once.
A[5] = 2 because the last two occurrences of the previous term (7) are at indices 4 and 2, and 4-2 = 2.
and so on

Find the index of the first occurrence of query.
Return -1 if query never occurs in A.


DEFINITION
Class:PreviousOccurrence
Method:findValue
Parameters:int, int
Returns:int
Method signature:int findValue(int defaultValue, int query)


NOTES
-It is guaranteed that for the given constraints the correct return value always fits into a signed 32-bit integer.


CONSTRAINTS
-defaultValue will be between 0 and 1000, inclusive.
-query will be between 0 and 7000, inclusive.


EXAMPLES

0)
7
0

Returns: 0

We have the example sequence from the problem statement and we are looking for the first occurrence of the value 0. This value occurs at the very beginning.


1)
7
2

Returns: 5

Same sequence. As we saw in the example, the first occurrence of the value 2 is at index 5.


2)
7
47

Returns: 1261

Still the same sequence. The value 47 first occurs a bit farther into the sequence.


3)
47
7

Returns: 66


4)
47
6763

Returns: 540153

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

class PreviousOccurrence {
public:
	int findValue(int defaultValue, int query) {
		vector<int> prev(10000001, -1), curr(10000001, -1);
		int x = 0;
		curr[x] = 0;
		for (int i = 0; i < 10000000; ++i) {
			if (query == x) {
				return i;
			}
			if (prev[x] >= 0 && curr[x] >= 0) {
				x = curr[x] - prev[x];
			} else {
				x = defaultValue;
			}
			prev[x] = curr[x];
			curr[x] = i + 1;
		}
		return -1;
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
			int Arg0 = 7;
			int Arg1 = 0;
			int Arg2 = 0;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 2;
			int Arg2 = 5;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 47;
			int Arg2 = 1261;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 7;
			int Arg2 = 66;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			int Arg1 = 6763;
			int Arg2 = 540153;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 513;
			int Arg2 = 2514;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 449;
			int Arg1 = 6830;
			int Arg2 = 1261723;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 500;
			int Arg1 = 6839;
			int Arg2 = 1459521;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = -1;

			verify_case(n, Arg2, findValue(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PreviousOccurrence ___test;
	___test.run_test(-1);
}
// END CUT HERE
