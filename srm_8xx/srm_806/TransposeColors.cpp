// BEGIN CUT HERE
/*
SRM 806 Div1 Easy (300)

PROBLEM STATEMENT

We have an array with N rows and N columns, both numbered starting from 0.
We also have one temporary storage space.
Each cell of the array contains a token, the temporary storage is empty.
There are N colors: for each i, all tokens in row i have color i.

We want to transpose the colors. More precisely, we want to rearrange the tokens so that for each i all tokens in column i will have color i.
We have to do this in a sequence of steps.
In each step we must take one of the tokens and move it to the only available free space.
Find and return any shortest sequence of such moves that transposes the colors in the given array.

(Tokens that share the same color are identical. In the final solution they can be placed in any order. In particular, their final order from the top to the bottom of the column does not have to match their initial order from the left to the right of the row.)

Cells of the array are numbered in row major order starting from 0, so the cell (row r, column c) has the number r*N+c.
The temporary storage space has the next available number: N*N.

Return a vector <int> describing your solution: for each move, output the number of the location from which you move the token. (Specifying the destination for the move is not necessary, as there is always exactly one empty location.)


DEFINITION
Class:TransposeColors
Method:move
Parameters:int
Returns:vector <int>
Method signature:vector <int> move(int N)


CONSTRAINTS
-N will be between 1 and 40, inclusive.


EXAMPLES

0)
1

Returns: { }

There is a single purple token on the cell (0, 0). For N = 1 this is also the desired final configuration, so it is optimal to do nothing.


1)
2

Returns: {2, 1, 4 }

The return value describes the following solution:

move a token from row 1, column 0 (location 2) to the empty temporary storage space
move a token from row 0, column 1 (location 1) to the now-empty location 2
move the token from the temporary storage space (location 4) to the now-empty location 1

This sequence of operations takes three moves. It essentially uses the temporary storage space as a temporary variable and swaps the tokens in the top right and the bottom left corner of the board.

There is one other correct answer for this test case: the sequence {1, 2, 4} that swaps the same two tokens but does so in the opposite order.


2)
3

Returns: {1, 5, 6, 2, 7, 3, 9 }

Below we show a sequence of what the array looks like in the beginning, and then after each step.
The letters A, B, C represent the three token colors. In the first step we move one token of color A into the temporary location, in the last step we return it back. A period denotes an empty space.

AAA   A.A   ABA   ABA   AB.   ABC   ABC   ABC
BBB   BBB   BB.   BBC   BBC   BBC   .BC   ABC
CCC   CCC   CCC   .CC   ACC   A.C   ABC   ABC

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

typedef pair<int, int> II;

class TransposeColors {
public:
	vector <int> move(int N) {
		vector<int> ans;
		if (N > 1) {
			vector<vector<int>> b(N, vector<int>(N));
			vector<vector<int>> done(N, vector<int>(N));
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					b[i][j] = i;
				}
			}
			II prev(N - 1, N - 2);
			int pc = N - 1;
			b[N - 1][N - 2] = -1;
			ans.emplace_back((N - 1) * N + N - 2);
			for (int i = 0; i < N * N; ++i) {
				for (int r = 0; r < N; ++r) {
					for (int c = 0; c < N; ++c) {
						if (b[r][c] == c) continue;
						if (b[r][c] == -1) continue;
						if (b[r][c] == prev.second) {
							ans.emplace_back(r * N + c);
							prev = II(r, c);
							b[r][c] = -1;
							pc = r;
							goto done;
						}
					}
				}
			done:
				{
				}
			}
			ans.emplace_back(N * N);
		}
		return ans;
	}

	bool verify(int N, vector<int> q) {
		vector<vector<int>> b(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				b[i][j] = i;
			}
		}
		II prev(-1, -1);
		int pc = -1;
		for (int x : q) {
			int r = x / N, c = x % N;
			if (x == N * N) {
				if (pc < 0) return false;
				if (prev.first < 0) return false;
				b[prev.first][prev.second] = pc;
				pc = -1;
				prev = II(-1, -1);
				continue;
			}
			if (b[r][c] < 0) return false;
			if (prev.first < 0) {
				pc = b[r][c];
			} else {
				b[prev.first][prev.second] = b[r][c];
			}
			b[r][c] = -1;
			prev = II(r, c);
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (b[i][j] != j) return false;
			}
		}
		return true;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			vector<int> Arg1;
			verify_case(n, Arg1, move(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {2, 1, 4 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, move(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1, 5, 6, 2, 7, 3, 9 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, move(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TransposeColors ___test;
	___test.run_test(-1);

	for (int n = 1; n <= 40; ++n) {
		vector<int> ans = ___test.move(n);
		if (!___test.verify(n, ans)) {
			cout << "FAILED: " << n << endl;
		}
	}
}
// END CUT HERE
