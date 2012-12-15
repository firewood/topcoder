// BEGIN CUT HERE
/*
// SRM 564 Div1 Easy (250)

// PROBLEM STATEMENT
// The knight is a chess piece that moves by jumping: two cells in one direction, one in the other.
Formally, a knight standing on the cell (x,y) can move to any of the following eight cells:
(x+2,y+1), (x+2,y-1), (x-2,y+1), (x-2,y-1), (x+1,y+2), (x+1,y-2), (x-1,y+2), and (x-1,y-2).
Of course, if the knight is close to the edge of the board, some of these cells might not be on the board.
It is not allowed to jump to a cell that is not on the board.

A knight circuit is a sequence of cells on a chessboard that starts and ends with the same cell.
Each consecutive pair of cells in the knight circuit must correspond to a single jump of the knight.
The knight circuit may visit each cell arbitrarily many times.
The size of a knight circuit is the number of different cells visited by the circuit.

You are given the ints w and h: the width (in columns) and the height (in rows) of a rectangular chessboard. Return the maximum knight circuit size that can be obtained on the given board.
You are free to choose any cell as the start of your circuit.


DEFINITION
Class:KnightCircuit2
Method:maxSize
Parameters:int, int
Returns:int
Method signature:int maxSize(int w, int h)


CONSTRAINTS
-w and h will each be between 1 and 45000, inclusive.


EXAMPLES

0)
1
1

Returns: 1

Note that a sequence that consists of a single cell is considered to be a valid knight circuit.


1)
15
2

Returns: 8

If you start at any corner of the board, it is possible to move the knight to visit 8 cells, and then do the same moves in reverse in order to return to the starting cell. One possibility for the first eight cells of an optimal knight circuit is shown below:


1...3...5...7..
..2...4...6...8


2)
100
100

Returns: 10000

It is possible to make a Knight circuit that contains all the cells on the board.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class KnightCircuit2 {

public:
	int maxSize(int w, int h) {
		int a = min(w, h);
		int b = max(w, h);
		if (a <= 1) {
			return a;
		}
		if (a == 2) {
			return (b+1)/2;
		}
		return w*h - (w==3 && h==3);
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
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 2;
			int Arg2 = 8;

			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 10000;

			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 14;
			int Arg1 = 2;
			int Arg2 = 7;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			int Arg1 = 2;
			int Arg2 = 7;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arg2 = 2;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 1;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 8;
			verify_case(n, Arg2, maxSize(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

void dfs(int &count, int (&visited)[256][256], const int &w, const int &h, int x, int y) {
	if (x >= 0 && x < w && y >= 0 && y < h && !visited[y][x]) {
		++count;
		visited[y][x] = 1;
		const int dx[] = {1,1,-1,-1,2,2,-2,-2};
		const int dy[] = {2,-2,2,-2,1,-1,1,-1};
		for (int n = 0; n < 8; ++n) {
			dfs(count, visited, w, h, x+dx[n], y+dy[n]);
		}
	}
}

// BEGIN CUT HERE
int main() {
	KnightCircuit2 ___test;
	___test.run_test(-1);

	int w, h;
	for (w = 1; w <= 80; ++w) {
		cout << "w=" << w;
		for (h = 1; h <= 80; ++h) {
			int visited[256][256] = {};
			int count = 0;
			dfs(count, visited, w, h, 0, 0);
			int s = ___test.maxSize(w, h);
			if (count == s) {
				cout << ".";
			} else {
				cout << "FAILED,h=" << h << "," << count << "," << s;
				break;
			}
		}
		cout << endl;
	}

	return 0;
}
// END CUT HERE
