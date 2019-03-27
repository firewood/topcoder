// BEGIN CUT HERE
/*
SRM 749 Div2 Medium (600)

PROBLEM STATEMENT
Lucyanna loves puzzles and she is always eager to invent new ones. She has recently invented a puzzle on a rectangular board.The board is divided into a grid of unit square cells. Each cell is painted either black or white. The rows are numbered starting from 0, from top to bottom. The columns are numbered starting from 0, from left to right.
The puzzle is played in a sequence of steps. In each step Lucyanna must choose exactly two distinct cells. Additionally, those two cells must lie either in the same row or in the same column. Let cell A be the chosen cell that is closer to the top left corner and let cell B be the other one. If both cells currently share the same color, paint cell B white. Otherwise, paint cell B black. After painting cell B using the previous rules, paint cell A white.
You are given the vector <string> start, the initial coloring of the board. The cell located in row r, column c is black if start[r][c] = '#' and it is white if the corresponding character is '.'.
You are also given the vector <string> target in the same form: the target coloring of the board Lucyanna wants. If Lucyanna cannot get the target board, return the vector <int> {-1}. Otherwise, return any vector <int> answer that satisfies all conditions listed below.

The vector <int> answer encodes one possible sequence of steps that solves the puzzle.
The length of answer must be the same as the number of steps in your solution.
The length of answer must be between 0 and 947, inclusive.
If in step i (numbered starting from 0) you chose the cells (r1, c1) and (r2, c2), answer[i] should be equal to (r1 * 1000000 + c1 * 10000 + r2 * 100 + c2).


DEFINITION
Class:TransformBoardDiv2
Method:getOperations
Parameters:vector <string>, vector <string>
Returns:vector <int>
Method signature:vector <int> getOperations(vector <string> start, vector <string> target)


NOTES
-Whenever there is a solution, there is a solution that has 947 or fewer steps.
-Any valid solution will be accepted. It is not necessary to minimize the number of steps.


CONSTRAINTS
-N will be between 1 and 4, inclusive.
-M will be between 1 and 4, inclusive.
-start will contain exactly N elements.
-Each element of start will contain exactly M characters.
-target will contain exactly N elements.
-Each element of target will contain exactly M characters.
-No element of start and target will contain characters other than '#' and '.'.


EXAMPLES

0)
{"#.",".."}
{"..",".#"}

Returns: {1, 10101 }


The example output describes a solution that consists of two steps.
This is it:


In the beginning:

    #.
    ..

Step 0: we choose the cells (0,0) and (0,1).

    .#
    ..

Step 1: we choose the cells (0,1) and (1,1).

    ..
    .#


1)
{"..",".#"}
{"#.",".."}

Returns: {-1 }


2)
{"#..#","#..."}
{"....","...#"}

Returns: {3, 1000103 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TransformBoardDiv2 {

public:
	vector <int> getOperations(vector <string> start, vector <string> target) {
		vector<int> parent(65536, -1);
		vector<int> moves(65536);
		int n = start.size();
		int m = start[0].size();
		int init_state = 0, target_state = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (start[i][j] == '#') {
					init_state |= 1 << (i * 4 + j);
				}
				if (target[i][j] == '#') {
					target_state |= 1 << (i * 4 + j);
				}
			}
		}
		vector<int> q({ init_state });
		while (q.size() > 0) {
			vector<int> nq;
			for (int x : q) {
				if (x == target_state) {
					vector <int> ans;
					while (x != init_state) {
						ans.push_back(moves[x]);
						x = parent[x];
					}
					reverse(ans.begin(), ans.end());
					return ans;
				}
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						for (int k = i; k < n; ++k) {
							for (int l = j; l < m; ++l) {
								if ((i != k || j != l) && (k == i || l == j)) {
									int a = 1 << (i * 4 + j);
									int b = 1 << (k * 4 + l);
									int y = x & ~a;
									if (((x & a) != 0) == ((x & b) != 0)) {
										y &= ~b;
									} else {
										y |= b;
									}
									if (parent[y] < 0) {
										parent[y] = x;
										moves[y] = i * 1000000 + j * 10000 + k * 100 + l;
										nq.push_back(y);
									}
								}
							}
						}
					}
				}
			}
			q = nq;
		}
		return { -1 };
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
			string Arr0[] = {"#.",".."};
			string Arr1[] = {"..",".#"};
			int Arr2[] = {1, 10101 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getOperations(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..",".#"};
			string Arr1[] = {"#.",".."};
			int Arr2[] = {-1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getOperations(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#..#","#..."};
			string Arr1[] = {"....","...#"};
			int Arr2[] = {3, 1000103 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getOperations(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "#..#", "...#", ".##.", "####" };
			string Arr1[] = { "#..#", "...#", ".##.", "###." };
			int Arr2[] = { -1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, getOperations(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TransformBoardDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
