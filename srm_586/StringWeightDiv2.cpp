// BEGIN CUT HERE
/*
SRM 586 Div2 Hard (1000)

PROBLEM STATEMENT
In this problem, all strings consist of uppercase English letters only.
That is, there are 26 distinct letters.

The weight of a string S can be computed as follows: 
for each letter that occurs at least once in S, its leftmost and rightmost occurrences L and R are found and the weight is increased by R-L.

For example, if S="ABCACAZ", the weight of S is (5-0) + (1-1) + (4-2) + (6-6) = 7.
(The leftmost occurrence of 'A' is at the index L=0, the rightmost one is at R=5, so 'A' contributes 5-0 = 5 to the weight of S. The only 'B' contributes 0, the pair of 'C's adds 2, and the only 'Z' adds 0.)

You are given a int L.
Consider all strings of length L.
Compute the weight of each of these strings.
The strings with the minimum weight among all of them are called light.
Your task is to count the number of light strings of length L.
Since this count may be very large, return it modulo 1,000,000,009.


DEFINITION
Class:StringWeightDiv2
Method:countMinimums
Parameters:int
Returns:int
Method signature:int countMinimums(int L)


CONSTRAINTS
-L will be between 1 and 1000, inclusive.


EXAMPLES

0)
1

Returns: 26

Any string of length 1 has weight equal to 0.


1)
2

Returns: 650

We can divide strings of length 2 into two classes: the strings with distinct first and second letter, and the strings with two equal letters. The strings composed of two equal letters have weight 1. All the other strings have weight 0. Thus, the number of strings of minimum weight is 26*26-26=650.


2)
50

Returns: 488801539

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

#define MOD 1000000009
#define COMBSZ 1024

class StringWeightDiv2 {
public:
	int countMinimums(int L) {
		static int C[COMBSZ][COMBSZ];
		memset(C, 0, sizeof(C));
		int i, j;
		for (i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
		}
		for (i = 1; i < COMBSZ; ++i) {
			for (j = 1; j < COMBSZ; ++j) {
				LL x = C[i-1][j-1];
				x += C[i-1][j];
				C[i][j] = (int)(x % MOD);
			}
		}

		LL ans = 1;
		if (L > 26) {
			for (i = 1; i <= 26; ++i) {
				ans *= i;
				ans %= MOD;
			}
			ans *= C[L - 1][25];
			ans = ans % MOD;
		} else {
			j = 26;
			for (i = 0; i < L; ++i) {
				ans *= j;
				ans %= MOD;
				--j;
			}
		}
		return (int)(ans % MOD);
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
			int Arg0 = 1;
			int Arg1 = 26;

			verify_case(n, Arg1, countMinimums(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 650;

			verify_case(n, Arg1, countMinimums(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 488801539;

			verify_case(n, Arg1, countMinimums(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringWeightDiv2 ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
