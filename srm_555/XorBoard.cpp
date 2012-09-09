// BEGIN CUT HERE
/*
// SRM 555 Div1 Medium (500)

// PROBLEM STATEMENT
// Fox Jiro has a rectangular grid with H rows and W columns
(i.e., the grid has H*W cells in total).
Initially, each cell in the grid contained the character '0'.

A row flip is an operation in which Jiro picks a row of the grid, and
in that row he changes all '0's to '1's and vice versa.
Similarly, a column flip is an operation in which Jiro does the same to a column of the grid.
Jiro took the grid that contained '0's everywhere.
He performed a row flip Rcount times, and then a column flip Ccount times.
(It is possible that Jiro flipped the same row or column multiple times.)
At the end, Jiro noticed that there are exactly S '1's in the grid.

You are given the ints H, W, Rcount, Ccount, and S.
We are interested in the number of different ways in which Jiro could have
flipped the rows and columns of the grid.
Two ways of flipping are considered different if there is a row or a column
that was flipped a different number of times.
(That is, the order in which the rows and columns are flipped does not matter.)
Return the number of different ways of flipping that match the given situation,
modulo 555,555,555.


DEFINITION
Class:XorBoard
Method:count
Parameters:int, int, int, int, int
Returns:int
Method signature:int count(int H, int W, int Rcount, int Ccount, int S)


CONSTRAINTS
-H will be between 1 and 1,555, inclusive.
-W will be between 1 and 1,555, inclusive.
-Rcount will be between 0 and 1,555, inclusive.
-Ccount will be between 0 and 1,555, inclusive.
-S will be between 0 and H*W, inclusive.


EXAMPLES

0)
2
2
2
2
4

Returns: 4

In two of the four ways, Jiro flips each row once, and then the same column twice.
In the other two ways he first flips the same row twice, and then each column once.


1)
2
2
0
0
1

Returns: 0

Without any flips, all cells still contain '0's, so S=1 is impossible.


2)
10
20
50
40
200

Returns: 333759825

Rcount and Ccount may be greater than H and W.


3)
1200
1000
800
600
4000

Returns: 96859710


4)
555
555
555
555
5550

Returns: 549361755

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

#define MOD 555555555
#define COMBSZ 2500

typedef long long LL;

class XorBoard {

public:
	int count(int H, int W, int Rcount, int Ccount, int S) {
		// generate combination table
		static int C[COMBSZ][COMBSZ];
		memset(C, 0, sizeof(C));
		int i, j;
		for (i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
		}
		for (i = 1; i < COMBSZ; ++i) {
			for (j = 1; j < COMBSZ; ++j) {
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
			}
		}
		// enumerate
		int res = 0;
		for (i = 0; i <= Rcount; ++i) {
			for (j = 0; j <= Ccount; ++j) {
				int rr = Rcount-i, cr = Ccount-j;
				if ((i*W + j*H - 2*i*j) == S && (rr%2) == 0 && (cr%2) == 0) {
					LL cnt = C[H][i];
					cnt = (cnt * C[rr/2 + H-1][H-1]) % MOD;
					cnt = (cnt * C[W][j]) % MOD;
					cnt = (cnt * C[cr/2 + W-1][W-1]) % MOD;
					res = (res + (int)cnt) % MOD;
				}
			}
		}
		return res;
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
			int Arg3 = 2;
			int Arg4 = 4;
			int Arg5 = 4;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 0;
			int Arg3 = 0;
			int Arg4 = 1;
			int Arg5 = 0;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 20;
			int Arg2 = 50;
			int Arg3 = 40;
			int Arg4 = 200;
			int Arg5 = 333759825;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1200;
			int Arg1 = 1000;
			int Arg2 = 800;
			int Arg3 = 600;
			int Arg4 = 4000;
			int Arg5 = 96859710;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 555;
			int Arg1 = 555;
			int Arg2 = 555;
			int Arg3 = 555;
			int Arg4 = 5550;
			int Arg5 = 549361755;

			verify_case(n, Arg5, count(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	XorBoard ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
