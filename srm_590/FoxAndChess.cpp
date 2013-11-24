// BEGIN CUT HERE
/*
SRM 590 Div1 Easy (250)

PROBLEM STATEMENT
Fox Ciel is playing a game with some chess pawns and a strip of paper.
The strip of paper is divided into a row of cells.
Each cell can contain at most one pawn.
The white pawns will be denoted 'R', because they are only allowed to move to the right.
The black pawns will be denoted 'L', because they are only allowed to move to the left.


You are given a string begin that describes the current state of the strip: 'R' and 'L' are cells with corresponding pawns, and '.' are empty cells.


You are now allowed to make some moves (as many as you wish, possibly zero).
In each move you may either take a 'R' pawn and move it one cell to the right, or take a 'L' pawn and move it one cell to the left.
Of course, both types of moves are only valid if the destination cell is currently empty.
Pawns are not allowed to move out of bounds.


You are also given a string target that represents the desired state of the strip.
If it is possible to reach target from begin by making some valid moves, return "Possible" (quotes for clarity), otherwise return "Impossible".

DEFINITION
Class:FoxAndChess
Method:ableToMove
Parameters:string, string
Returns:string
Method signature:string ableToMove(string begin, string target)


CONSTRAINTS
-begin will contain between 1 and 50 elements, inclusive.
-begin and target will contain the same number of elements.
-Each character in begin and target will be one of '.', 'L' and 'R'.


EXAMPLES

0)
"R..."
"..R."

Returns: "Possible"

You have to move the only pawn to the right twice.

1)
"..R."
"R..."

Returns: "Impossible"

Here target cannot be reached because the only pawn is only allowed to move to the right.

2)
".L.R.R."
"L...R.R"

Returns: "Possible"



3)
".L.R."
".R.L."

Returns: "Impossible"



4)
"LRLLRLRLLRLLRLRLRL"
"LRLLRLRLLRLLRLRLRL"

Returns: "Possible"



5)
"L"
"."

Returns: "Impossible"



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

using namespace std;

typedef long long LL;

class FoxAndChess {

	bool solve(string begin, string target) {
		int N = (int)begin.length();
		int i, j = 0;
		for (i = 0; i < N; ++i) {
			if (begin[i] == '.') {
				continue;
			}
			while (target[j] == '.') {
				++j;
				if (j >= N) {
					return false;
				}
			}
			if (begin[i] != target[j]) {
				return false;
			}
			if (begin[i] == 'R') {
				if (j < i) {
					return false;
				}
			} else {
				if (j > i) {
					return false;
				}
			}
			++j;
		}
		while (j < N) {
			if (target[j] != '.') {
				return false;
			}
			++j;
		}
		return true;
	}

public:
	string ableToMove(string begin, string target) {
		return solve(begin, target) ? "Possible" : "Impossible";
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
			string Arg0 = "R...";
			string Arg1 = "..R.";
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "..R.";
			string Arg1 = "R...";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".L.R.R.";
			string Arg1 = "L...R.R";
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".L.R.";
			string Arg1 = ".R.L.";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLLRLRLLRLLRLRLRL";
			string Arg1 = "LRLLRLRLLRLLRLRLRL";
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "L";
			string Arg1 = ".";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndChess ___test;
	___test.run_test(-1);
}
// END CUT HERE
