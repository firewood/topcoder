// BEGIN CUT HERE
/*
SRM 491 Div1 Easy (250)

PROBLEM STATEMENT
Fox Jiro likes dice. He wants to make his own dice. Each die he wants to make is a cube. Each of the 6 faces has an integer between 1 and N, inclusive. No two faces have same number. Also the following condition must be satisfied: for all faces, the sum of the numbers on opposite faces must be equal and the sum must be greater than or equal to K.

He realized that there are many ways to make such dice. He wants to know how many ways there are. Please help Jiro to make a program that is given two integers N and K and returns the number of different dice satisfying the condition mentioned above.

Two dice are considered the same if you can rotate one to form the other.


DEFINITION
Class:FoxMakingDice
Method:theCount
Parameters:int, int
Returns:long long
Method signature:long long theCount(int N, int K)


NOTES
-The answer will always fit in a signed 64-bit integer.


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-K will be between 1 and 2,000, inclusive.


EXAMPLES

0)
6
7

Returns: 2

You can make normal dice. There are two ways to arrange the numbers.


1)
5
7

Returns: 0

You cannot make 6 sided dice with 5 numbers.


2)
1000
1

Returns: 20625666000


3)
456
123

Returns: 879075732


4)
913
1014

Returns: 4506149340

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class FoxMakingDice {

public:
	long long theCount(int N, int K) {
		LL ans = 0, i, j, k;
		LL f[2002] = {};
		for (i = 1; i <= N; ++i) {
			for (j = i + 1; j <= N; ++j) {
				f[i+j] += 1;
			}
		}
		for (k = K; k <= N*2; ++k) {
			if (f[k] >= 3) {
				ans += f[k] * (f[k] - 1) * (f[k] - 2) / 3;
			}
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
			int Arg0 = 6;
			int Arg1 = 7;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1;
			long long Arg2 = 20625666000LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 456;
			int Arg1 = 123;
			long long Arg2 = 879075732LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 913;
			int Arg1 = 1014;
			long long Arg2 = 4506149340LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxMakingDice ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
