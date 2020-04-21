// BEGIN CUT HERE
/*
TCO20 R1A Medium (500)

PROBLEM STATEMENT

Game of Life is a cellular automaton invented by the recently deceased mathematician John H. Conway. We included this problem into today's set to honor his memory.

In our version of the Game of Life the world is a rectangular array of cells.
Each cell is either alive ('X') or dead ('.').
Each cell has up to eight neighbors: horizontal, vertical, and diagonal.
Cells at the boundary have fewer than eight neighbors.

The world evolves in steps. In each step some living cells may die and some dead cells may become alive.
In particular, a cell that is currently dead will become a living cell in the next step if and only if it currently has exactly three neighbors that are alive.

You are given the int N.
Find any rectangular configuration of cells with dimensions at most 50x50 and with the following property: in the next step, exactly N of the dead cells will become living cells.
Return your configuration as a vector <string>.


DEFINITION
Class:ThreeNeighbors
Method:construct
Parameters:int
Returns:vector <string>
Method signature:vector <string> construct(int N)


NOTES
-For the given constraints a solution always exists, and any valid solution will be accepted.
-We only care about the number of cells that change from dead to living. All other parameters of your world (dimensions, the number of cells that die, the total number of cells, etc.) may be arbitrary.


CONSTRAINTS
-N will be between 1 and 500, inclusive.


EXAMPLES

0)
2

Returns: {".....", ".XX..", ".X.X.", ".X...", "....." }

The return value corresponds to a configuration of cells known as a "glider":

.....
.XX..
.X.X.
.X...
.....

Below, the two cells that will become alive in the next step are marked with asterisks. Each of these dead cells has exactly three neighbors that are alive.

.....
.XX..
*X.X.
.X*..
.....


1)
6

Returns: {"........", ".XXX..X.", "..X..X..", "..X..X..", "..X...X.", "........" }

..*.....
.XXX..X.
..X.*X*.
.*X*.X*.
..X...X.
........


2)
1

Returns: {"XXXX", "XXXX", ".XXX" }

XXXX
XXXX
*XXX

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

using namespace std;

int count(vector <string>& ans) {
	int h = (int)ans.size(), w = h > 0 ? (int)ans[0].length() : 0;
	int chg = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (ans[i][j] != '.') continue;
			int cnt = 0;
			for (int a = -1; a <= 1; ++a) {
				for (int b = -1; b <= 1; ++b) {
					if (a == 0 && b == 0) continue;
					int r = i + a, c = j + b;
					cnt += r >= 0 && r < h && c >= 0 && c < w && ans[r][c] == 'X';
				}
			}
			chg += cnt == 3;
		}
	}
	return chg;
}

class ThreeNeighbors {

public:
	vector <string> construct(int N) {
		vector <string> ans;
		while (true) {
			vector <string> temp = ans;
			temp.push_back(string(50, 'X'));
			temp.push_back(string(50, '.'));
			temp.push_back(string(50, '.'));
			if (count(temp) > N) {
				break;
			}
			ans = temp;
		}
		for (int r = N - count(ans); r > 0; ) {
			int row = (int)ans.size();
			ans.push_back(string(50, '.'));
			ans.push_back(string(50, '.'));
			ans.push_back(string(50, '.'));
			ans.push_back(string(50, '.'));
			for (int col = 0; r > 0 && col <= 50 - 4; col += 4) {
				--r;
				ans[row][col] = ans[row][col + 1] = ans[row + 1][col] = 'X';
			}
		}
		assert(ans.size() <= 50 && N == count(ans));
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			string Arr1[] = {".....", ".XX..", ".X.X.", ".X...", "....." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			string Arr1[] = {"........", ".XXX..X.", "..X..X..", "..X..X..", "..X...X.", "........" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arr1[] = {"XXXX", "XXXX", ".XXX" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreeNeighbors ___test;
	___test.run_test(-1);

	for (int n = 1; n <= 500; ++n) {
		___test.construct(n);
	}
}
// END CUT HERE
