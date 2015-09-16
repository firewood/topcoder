// BEGIN CUT HERE
/*
SRM 668 Div1 Easy (250)

PROBLEM STATEMENT
Little Liz stepped in a bucket of green paint. Now she leaves green footprints wherever she walks.
Fortunately, her school just built a new room which is supposed to have a green floor.
Making the best of the situation, her teacher told her to paint the room by walking on its floor.

The floor is a grid of cells with R rows and C columns. Little Liz occupies a position in this grid.
She can move up, down, left, or right. (She cannot move diagonally.)
To ensure that each cell gets the appropriate amount of paint, Liz should visit each cell exactly K times.
Liz visits a cell whenever she moves into it. Liz also visits a cell if she begins her walk on it. Liz can begin and end on any cell.

If it is possible to paint the room in the required way, return "Paint".
Otherwise, return "Cannot paint". (All quotes are for clarity only.)


DEFINITION
Class:PaintTheRoom
Method:canPaintEvenly
Parameters:int, int, int
Returns:string
Method signature:string canPaintEvenly(int R, int C, int K)


CONSTRAINTS
-R will be between 1 and 50, inclusive.
-C will be between 1 and 50, inclusive.
-K will be between 1 and 50, inclusive.


EXAMPLES

0)
1
1
1

Returns: "Paint"

There is only one cell in this grid. By starting on the cell, Little Liz visits it once.


1)
1
1
2

Returns: "Cannot paint"

This is the same case as Example 0, but now the cell must be visited twice. This is impossible.


2)
1
2
2

Returns: "Paint"

There are two cells, and they are in the same row. One possible solution is to start on the left cell, then move right, then left, then right. This visits each cell twice, as required.


3)
2
2
3

Returns: "Paint"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class PaintTheRoom {
public:
	string canPaintEvenly(int R, int C, int K) {
		return K <= 1 || ((R * C) % 2) == 0 ? "Paint" : "Cannot paint";
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			string Arg3 = "Paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 2;
			string Arg3 = "Cannot paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
			int Arg2 = 2;
			string Arg3 = "Paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			string Arg3 = "Paint";

			verify_case(n, Arg3, canPaintEvenly(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PaintTheRoom ___test;
	___test.run_test(-1);
}
// END CUT HERE
