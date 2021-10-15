// BEGIN CUT HERE
/*
SRM 816 Div1 Easy (300)

PROBLEM STATEMENT

An airplane has S seats in each row.
There are R rows of seats.

Below, a section will represent any non-empty contiguous sequence of rows, and a column will represent a collection of seats that are at the same position from the left in different rows. (I.e., columns of seats are orthogonal to rows of seats, just as you would expect.)

Each seat of the plane is either empty or occupied.

A section is called left-to-right balanced if within that section each column contains the same number of passengers.

You are given S, R, and the vector <int> A that encodes the positions of occupied seats.
Count all left-to-right balanced sections on this airplane, and return their count.

In the array A, we use bitmasks to encode occupied seats.
Each element of A is a S-bit integer that represents one row of seats, from the front to the back.
Within each element of A, the individual bits (lowest to highest) represent occupied seats (1) and empty seats (0) from the left of the row to the right.

In order to keep the input size small, A is pseudorandom. Use the following pseudocode to generate it:

L = length(Aprefix)
for i = 0 to L-1:
    A[i] = Aprefix[i]

state = Aprefix[L-1]
for i = L to N-1:
    state = (state * 1103515245 + 12345) modulo 2^31
    A[i] = state >> (31 - S)


DEFINITION
Class:BalancedAirplane
Method:count
Parameters:int, int, vector <int>
Returns:long long
Method signature:long long count(int S, int R, vector <int> Aprefix)


NOTES
-In your implementation of the pseudocode, watch out for integer overflow. In particular, "state" should be at least a 64-bit integer variable.
-In the pseudocode, >> denotes the right shift operator. An equivalent operation is dividing by 2^(31 - S) and rounding down (truncating).
-The reference solution does not depend on the input being pseudorandom.


CONSTRAINTS
-S will be between 1 and 30, inclusive.
-R will be between 1 and 100,000, inclusive.
-Aprefix will have between 1 and min(R, 200) elements, inclusive.
-Each element of Aprefix will be between 0 and (2^S)-1, inclusive.


EXAMPLES

0)
4
10
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: 55

This small airplane is empty. All its sections are balanced.


1)
6
11
{1, 0, 2, 0, 4, 0, 8, 0, 16, 0, 32}

Returns: 6

There are six people in this entire airplane: one in each column. The entire airplane is balanced, and each section that consists of a single empty row is also balanced.


2)
6
11
{63, 0, 63, 0, 63, 4, 0, 63, 0, 63, 0}

Returns: 30

This airplane has alternating full and empty rows, except for the middle row with just a single passenger. Any section that does not contain the middle row is balanced.


3)
4
7
{12, 3, 14, 1, 7, 8, 7}

Returns: 7


4)
1
100000
{1}

Returns: 5000050000


5)
6
20
{42}

Returns: 1

A = {42, 37, 33, 29, 49, 27, 2, 26, 51, 39, 45, 11, 33, 35, 15, 58, 7, 42, 21, 11, }
The only balanced section consists of two rows close to the end of the airplane (the rows represented by bitmasks 42 and 21).

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

class BalancedAirplane {
public:
	long long count(int S, int R, vector <int> Aprefix) {
		int64_t ans = 0, state = Aprefix.back();
		map<vector<int>, int> m;
		vector<int> z(S), sum(S);
		m[z] = 1;
		for (int i = 0; i < R; ++i) {
			int64_t a;
			if (i < Aprefix.size()) {
				a = Aprefix[i];
			} else {
				state = (state * 1103515245 + 12345) % (1LL << 31);
				a = state >> (31 - S);
			}
			for (int j = 0; j < S; ++j) {
				sum[j] += (a >> j) & 1;
			}
			for (int j = S - 1; j >= 0; --j) {
				sum[j] -= sum[0];
			}
			ans += m[sum];
			m[sum] += 1;
		}
		return ans;
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
			int Arg0 = 4;
			int Arg1 = 10;
			int Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			long long Arg3 = 55LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 11;
			int Arr2[] = {1, 0, 2, 0, 4, 0, 8, 0, 16, 0, 32};
			long long Arg3 = 6LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 11;
			int Arr2[] = {63, 0, 63, 0, 63, 4, 0, 63, 0, 63, 0};
			long long Arg3 = 30LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 7;
			int Arr2[] = {12, 3, 14, 1, 7, 8, 7};
			long long Arg3 = 7LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100000;
			int Arr2[] = {1};
			long long Arg3 = 5000050000LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 20;
			int Arr2[] = {42};
			long long Arg3 = 1LL;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BalancedAirplane ___test;
	___test.run_test(-1);
}
// END CUT HERE
