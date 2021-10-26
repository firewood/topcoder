// BEGIN CUT HERE
/*
SRM 817 Div1 Easy (300)

PROBLEM STATEMENT

A word search puzzle is a rectangular grid of letters.
The goal of the puzzle is to look for words in the grid.
Words can be placed in eight cardinal directions (horizontally, vertically, or diagonally).

A dog search puzzle is a word search puzzle in which each letter is 'D', 'O', or 'G'.
The goal in a dog search puzzle is to find the occurrences of the word "DOG".

Below is an example of a dog search puzzle.

	DGODD
	OOGOG
	GOGDD

The example puzzle contains four dogs: one in column 0 downwards, one in row 0 right-to-left, one on the diagonal from the top left corner, and one on the diagonal from the top right corner.

Given N, construct any dog search puzzle with at most 40 rows, at most 40 columns, and exactly N dogs.
Return the puzzle as a vector <string>.


DEFINITION
Class:DogsInAGrid
Method:construct
Parameters:int
Returns:vector <string>
Method signature:vector <string> construct(int N)


NOTES
-For the chosen constraints a solution always exists.
-Remember that only the letters 'D', 'O', and 'G' are allowed in the grid. Also, the grid must be rectangular and no dimension of the grid may exceed 40.


CONSTRAINTS
-N will be between 0 and 2,222, inclusive.



EXAMPLES

0)
4

Returns: {"DGODD", "OOGOG", "GOGDD" }

The returned grid is the example grid from the problem statement. We have already seen that it contains exactly four dogs, so it is one of the acceptable answers for this test case.


1)
2

Returns: {"OOOOO", "OODOO", "ODOGO", "OOGOO", "OOOOO" }

The returned grid, formatted as a grid:

	{"OOOOO",
	 "OODOO",
	 "ODOGO",
	 "OOGOO",
	 "OOOOO" }

One dog is in the middle column, one is in the middle row.


2)
7

Returns: {"DOGDOGDOGDOGDOGODOG" }

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

class DogsInAGrid {
public:

	int count(const vector<string>& b) {
		int cnt = 0;
		int h = b.size();
		int w = b[0].length();
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (b[i][j] == 'O') {
					for (int dy = -1; dy <= 1; ++dy) {
						for (int dx = -1; dx <= 1; ++dx) {
							if (dx || dy) {
								int r = i + dy, c = j + dx;
								int rr = i - dy, cc = j - dx;
								if (r >= 0 && rr >= 0 && r < h && rr < h && c >= 0 && cc >= 0 && c < w && cc < w) {
									cnt += b[r][c] == 'D' && b[rr][cc] == 'G';
								}
							}
						}
					}
				}
			}
		}
		return cnt;
	}

	vector <string> construct(int N) {
		const string dogo = "DOGO";
		vector<string> ans(40, string(40, 'O'));
		for (int i = 0; i < 40 && count(ans) < N; ++i) {
			char c = 'O';
			if (i % 4 == 1) c = 'D';
			if (i % 4 == 3) c = 'G';
			ans[i] = string(40, c);
		}
		for (int i = 0; i < 40 && count(ans) > N; ++i) {
			ans[1][i] = 'O';
		}
		for (int i = 0; i < 40 && count(ans) < N; ++i) {
			ans[0][i] = dogo[i % 4];
		}

		if (N != count(ans)) {
			N += 0;
		}


		return ans;
	}

	// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T>& V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, int Expected, const vector <string>& Received) {
		cerr << "Test Case #" << Case << "...";
		if (Expected == count(Received)) cerr << "PASSED" << endl;
		else { cerr << "FAILED" << endl; cerr << "\tExpected: " << Expected << endl; cerr << "\tReceived: " << count(Received) << endl; }
	}

public:
	void run_test(int Case) {
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			string Arr1[] = { "DGODD", "OOGOG", "GOGDD" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			string Arr1[] = { "OOOOO", "OODOO", "ODOGO", "OOGOO", "OOOOO" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 7;
			string Arr1[] = { "DOGDOGDOGDOGDOGODOG" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, construct(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000;
			string Arr1[] = { "DOGDOGDOGDOGDOGODOG" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, construct(Arg0));
		}
		n++;


	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DogsInAGrid ___test;
#ifndef _DEBUG
	for (int i = 0; i < 2222; ++i) {
		vector<string> ans = ___test.construct(i);
		if (___test.count(ans) != i) {
			cerr << "FAILED: " << i << endl;
			return 0;
		}
	}
	cerr << "OK" << endl;
#endif
	___test.run_test(-1);
}
// END CUT HERE
