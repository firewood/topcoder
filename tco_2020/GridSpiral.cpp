// BEGIN CUT HERE
/*
TCO20 R2A Easy (300)

PROBLEM STATEMENT

There is an infinite square grid. Each cell of the grid contains a non-negative integer, and each non-negative integer appears in exactly one cell.

Two cells of the grid are called adjacent if they share a side.

The integers are arranged into a spiral that starts with the number 0.
For each n, the cells that contain numbers n and n+1 are adjacent.
If you start at 0 and walk along the spiral, your sequence of steps will be as follows: 1 step up, 1 step right, 2 steps down, 2 steps left, 3 steps up, 3 steps right, 4 steps down, and so on.

Beginning of the spiral:

    9 10 11 12
    8  1  2 13
    7  0  3 14
..  6  5  4 15
.. .. .. .. 16

You are given the int D: a difference we want to find in the grid.
Find and return the smallest x such that the cells that contain x and x+D are adjacent.
If there is no such x, return -1 instead.


DEFINITION
Class:GridSpiral
Method:findCell
Parameters:int
Returns:long long
Method signature:long long findCell(int D)


NOTES
-It is guaranteed that whenever an answer exists, it fits into a long long.


CONSTRAINTS
-D will be between 1 and 10^9, inclusive.


EXAMPLES

0)
5

Returns: 0

Cells with values 0 and 5 are adjacent: a step down from cell 0 will take you to cell 5.


1)
11

Returns: 2

The cell with value 13 is to the right of the cell with value 2. Cells 0 and 11 are not adjacent and neither are 1 and 12, so 2 is the smallest cell with the desired property.


2)
47

Returns: 110


3)
100

Returns: -1

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
typedef pair<LL, LL> LLLL;

class GridSpiral {
public:
	long long findCell(int D) {
		if (D % 2 == 0) return -1;
		if (D <= 7) return 0;
		LL d = D / 4 - 1;
		return (d * (d - 1)) + ((D - d * 4 - 3) / 2) * d;
	}

	// BEGIN CUT HERE
	long long findCell2(int D) {
		if (D == 1 || D == 3 || D == 5 || D == 7) return 0;
		if ((D % 2) == 0) return -1;

		LL last = 6;
		int step = 3, sc = 0, index = 0;
		LLLL v[5] = { {0,0},{1,1},{2,2},{3,4},{5,6} };
		while (step < 1e7) {
			LL next = last + 1;
			if (next - v[index].second == D) {
				return v[index].second;
			}
			last = next + step - 1;
			if (next + 1 - v[(index + 1) % 5].first == D) {
				return v[(index + 1) % 5].first;
			}
			v[index].first = next;
			v[index].second = last;
			index = (index + 1) % 5;
			if (++sc == 2) {
				sc = 0;
				++step;
			}
		}
		return -1;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			long long Arg1 = 0LL;

			verify_case(n, Arg1, findCell(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, findCell(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			long long Arg1 = 110LL;

			verify_case(n, Arg1, findCell(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findCell(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 9;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, findCell(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 999999999;
			long long Arg1 = 62499999250000002LL;
			verify_case(n, Arg1, findCell(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GridSpiral ___test;
	___test.run_test(-1);

	for (int a = 1; a <= 1000; ++a) {
		if (___test.findCell(a) != ___test.findCell2(a)) {
			++a;
			break;
		}
	}

	return 0;
}
// END CUT HERE
