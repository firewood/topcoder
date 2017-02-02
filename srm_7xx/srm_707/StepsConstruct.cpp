// BEGIN CUT HERE
/*
SRM 707 Div2 Medium (500)

PROBLEM STATEMENT
There is a rectangular board that is divided into n rows by m columns of cells.
Each cell is either empty or it contains an obstacle.
You are given the description of the board in the vector <string> board.
Each character in board represents one cell.
More precisely, the character board[i][j] represents the cell at coordinates (row i, column j).
The character '#' represents an obstacle, the character '.' is an empty cell.

You would like to travel from the top left corner to the bottom right corner of the board in exactly k steps.
More precisely, you want to perform the following sequence of actions:

Enter the board by stepping onto the cell at coordinates (0, 0): the top left corner.
Make exactly k steps. In each step, you'll move from your current cell to one of the cells that share a side with your current cell. In other words, in each step you'll go one cell up, down, left, or right.
After the k-th step, you must be in the bottom right corner: at coordinates (n-1, m-1).

Note that you can only step onto empty cells.
You have to move in each step, it is not allowed to stay in the same cell.
You are allowed to visit each empty cell arbitrarily many times.
You are not allowed to leave the board while making the k steps.

You are given the vector <string> board and the int k.
Determine whether it is possible to reach the bottom right corner in the way described above.
If there is no solution, return an empty string.
If there are some solutions, choose any one of them and return a string containing its description.

If a solution exists, the returned string should consist of k characters, each describing one step.
Each character should be one of 'U' (up), 'D' (down), 'L' (left), and 'R' (right).


DEFINITION
Class:StepsConstruct
Method:construct
Parameters:vector <string>, int
Returns:string
Method signature:string construct(vector <string> board, int k)


NOTES
-The character 'U' represents a step that decreases your row number. The character 'L' represents a step that decreases your column number.


CONSTRAINTS
-n, m will be between 2 and 50, inclusive.
-board will contain exactly n elements.
-Each element in board will contain exactly m characters.
-Each character in board will be either '#' or '.'.
-k will be between 1 and 3,000, inclusive.


EXAMPLES

0)
{"...",
 ".#.",
 "..."}
4

Returns: "DDRR"

You need to get from (0,0) to (2,2) in exactly 4 steps.


1)
{"...",
 ".#.",
 "..."}
12

Returns: "DDRRUULLDDRR"

This time we want to get there in exactly 12 steps, one possible solution is to go around that obstacle once.


2)
{"...#.",
 "..#..",
 ".#..."}
100

Returns: ""

There is no way to get to (n-1, m-1) from (0,0).


3)
{"..#",
 "#.#",
 "..#",
 ".#.",
 "..."}
6

Returns: ""


4)
{".#...",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "...#."}
16

Returns: "DDDDRRUUUURRDDDD"


5)
{"#.", 
 ".."}
2

Returns: ""

There is no solution because you are not even able to enter the top left cell.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;

class StepsConstruct {

public:
	string construct(vector <string> board, int k) {
		int H = (int)board.size();
		int W = (int)board[0].length();
		int vis[50][50];
		memset(vis, -1, sizeof(vis));
		vector<II> q;
		if (board[0][0] == '.') {
			vis[0][0] = 0;
			q.push_back(II(0, 0));
		}
		for (int dist = 1; q.size(); ++dist) {
			vector<II> next;
			for (auto &v : q) {
				int dx[] = { -1,1,0,0 };
				int dy[] = { 0,0,-1,1 };
				for (int dir = 0; dir < 4; ++dir) {
					int nx = v.second + dx[dir], ny = v.first + dy[dir];
					if (nx >= 0 && nx < W && ny >= 0 && ny < H && board[ny][nx] == '.' && vis[ny][nx] < 0) {
						vis[ny][nx] = dist;
						next.push_back(II(ny, nx));
					}
				}
			}
			q = next;
		}
		int x = W - 1, y = H - 1;
		int g = vis[y][x];
		if (g < 0 || g > k || (g % 2) != (k % 2)) {
			return "";
		}
		string seq;
		for (int dist = vis[H - 1][W - 1]; dist > 0; --dist) {
			int dx[] = { -1,1,0,0 };
			int dy[] = { 0,0,-1,1 };
			const char *s = "RLDU";
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx >= 0 && nx < W && ny >= 0 && ny < H && vis[ny][nx] == (dist - 1)) {
					x = nx, y = ny, seq += s[dir];
					break;
				}
			}
		}
		while (g < k) {
			if (board[0][1] == '.') {
				seq += "LR";
			} else {
				seq += "UD";
			}
			g += 2;
		}
		reverse(seq.begin(), seq.end());
		return seq;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 ".#.",
 "..."};
			int Arg1 = 4;
			string Arg2 = "DDRR";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 ".#.",
 "..."};
			int Arg1 = 12;
			string Arg2 = "DDRRUULLDDRR";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...#.",
 "..#..",
 ".#..."};
			int Arg1 = 100;
			string Arg2 = "";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..#",
 "#.#",
 "..#",
 ".#.",
 "..."};
			int Arg1 = 6;
			string Arg2 = "";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#...",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "...#."};
			int Arg1 = 16;
			string Arg2 = "DDDDRRUUUURRDDDD";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.", 
 ".."};
			int Arg1 = 2;
			string Arg2 = "";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StepsConstruct ___test;
	___test.run_test(-1);
}
// END CUT HERE
