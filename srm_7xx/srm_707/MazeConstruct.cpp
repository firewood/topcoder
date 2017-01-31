// BEGIN CUT HERE
/*
SRM 707 Div1 Easy (250)

PROBLEM STATEMENT
You may have solved the following classic task before:

Given is a rectangular board divided into n rows by m columns of cells.
Each cell is either empty or it contains an obstacle.
You start in the cell (0, 0).
In each step you can move to an adjacent cell (up, down, left, or right).
Obviously, you may not leave the board and you may not enter a cell with an obstacle.
You want to reach the cell (n-1, m-1).
What is the smallest number of steps you need?

In this task, you are going to solve the above task in reverse.
You are given an int k.
Design any rectangular board with the following properties:

The number of rows (n) must be between 1 and 50, inclusive.
The number of columns (m) must be between 1 and 50, inclusive.
The corner cells (0, 0) and (n-1, m-1) must both be empty.
It must be possible to reach the cell (n-1, m-1) from the cell (0, 0). Additionally, the shortest way of doing so must have exactly k steps.

For the constraints used in this task a solution always exists.
If there are multiple solutions, you may choose any of them.
Return the board you constructed as a vector <string> with n elements, each containing m characters.
Use the character '#' to represent an obstacle and the character '.' to represent an empty cell.


DEFINITION
Class:MazeConstruct
Method:construct
Parameters:int
Returns:vector <string>
Method signature:vector <string> construct(int k)


CONSTRAINTS
-k will be between 2 and 1,000, inclusive.


EXAMPLES

0)
3

Returns: {"...." }

There is more than one solution.
Any valid solution will be accepted.
For example, you may also return {"..", "..", ".."} or {"..", ".#", ".."}.


1)
4

Returns: {"...", "...", "..." }


2)
10

Returns: {"..#..", "#.#..", "..#..", ".#...", "....." }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MazeConstruct {
public:
	vector <string> construct(int k) {
		vector <string> ans;
		if (k <= 49) {
			ans.push_back(string(k + 1, '.'));
			return ans;
		}

		for (int h = 8; h <= 50; ++h) {
			for (int w = 2; w <= 12; ++w) {
				int cnt = h * 2 * w + w * 2 + h - 1;
				if (k >= (cnt - (h - 4)) && k <= cnt) {
					for (int i = 0; i < w; ++i) {
						ans.push_back(string(h, '.'));
						ans.push_back(string(h - 1, '#') + ".");
						ans.push_back(string(h, '.'));
						ans.push_back("." + string(h - 1, '#'));
					}
					ans.push_back(string(h, '.'));
					int pos = h - 2;
					while ((cnt - k) >= 1) {
						ans[1][pos--] = '.';
						cnt -= 2;
					}
					if (cnt < k) {
						ans.push_back(string(h - 1, '#') + ".");
					}
/*
					for (string s : ans) {
						cout << s << endl;
					}
					cout << cnt << endl;
//*/
					return ans;
				}
			}
		}

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
			int Arg0 = 3;
			string Arr1[] = {"...." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			string Arr1[] = {"...", "...", "..." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			string Arr1[] = {
				"..#..",
				"#.#..",
				"..#..",
				".#...",
				"....." };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			string Arr1[] = {
				"..........",
				"#######...",
				"..........",
				".#########",
				"..........",
				"#########.",
				"..........",
				".#########",
				"..........",
				"#########." };
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MazeConstruct ___test;
	___test.run_test(-1);
}
// END CUT HERE
