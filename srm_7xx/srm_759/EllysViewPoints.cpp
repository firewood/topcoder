// BEGIN CUT HERE
/*
SRM 759 Div2 Easy (250)

PROBLEM STATEMENT

Elly has a rectangular matrix with N rows and M columns. Each of the cells in the matrix can be either blocked (denoted '#') or free (denoted '.'). 

An empty cell is called a view point if we can see outside the matrix when looking directly in each of the four cardinal directions: north, south, east, and west. 
In other words, a cell C is a view point if and only if all cells in those four directions from cell C are free.

Below is an example matrix that contains six view points. One of these is marked by an asterisk ('*').

..#......
.....*...
.###..#..
.#.##..#.
...#..#..
.........

The girl has given you the ints N and M, as well as the vector <string> matrix. Return the number of view points in the given matrix.


DEFINITION
Class:EllysViewPoints
Method:getCount
Parameters:int, int, vector <string>
Returns:int
Method signature:int getCount(int N, int M, vector <string> matrix)


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-M will be between 1 and 50, inclusive.
-matrix will contain exactly N elements.
-Each element of matrix will contain exactly M characters.
-Each character in matrix will be either '#' or '.'.


EXAMPLES

0)
6
9
{"..#......",
 ".........",
 ".###..#..",
 ".#.##..#.",
 "...#..#..",
 "........."}

Returns: 6

The example from the problem statement.


1)
1
1
{"."}

Returns: 1

It's pretty obvious which cell is the view point.


2)
7
4
{"####",
 "####",
 "####",
 "####",
 "####",
 "####",
 "####"}

Returns: 0

With everything blocked, there are obviously no view points.


3)
9
48
{"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "................................................",
 ".#####...###...###.......##....###....##..#####.",
 "...#....#.....#...#.....#..#..#...#..#.#..#...#.",
 "...#....#.....#...#........#..#...#....#..#####.",
 "...#....#.....#...#......#....#...#....#......#.",
 "...#.....###...###......####...###.....#..#####.",
 "................................................",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#."}

Returns: 18

Good luck!

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysViewPoints {
public:
	int getCount(int N, int M, vector <string> matrix) {
		int rows[64] = {}, cols[64] = {};
		for (int i = 0; i < N; ++i) {
			int cnt = 0;
			for (int j = 0; j < M; ++j) {
				cnt += matrix[i][j] == '.';
			}
			rows[i] = cnt >= M;
		}
		for (int j = 0; j < M; ++j) {
			int cnt = 0;
			for (int i = 0; i < N; ++i) {
				cnt += matrix[i][j] == '.';
			}
			cols[j] = cnt >= N;
		}
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				ans += rows[i] && cols[j];
			}
		}
		return ans;
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
			int Arg0 = 6;
			int Arg1 = 9;
			string Arr2[] = {"..#......",
 ".........",
 ".###..#..",
 ".#.##..#.",
 "...#..#..",
 "........."};
			int Arg3 = 6;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			string Arr2[] = {"."};
			int Arg3 = 1;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 4;
			string Arr2[] = {"####",
 "####",
 "####",
 "####",
 "####",
 "####",
 "####"};
			int Arg3 = 0;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 48;
			string Arr2[] = {"#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.",
 "................................................",
 ".#####...###...###.......##....###....##..#####.",
 "...#....#.....#...#.....#..#..#...#..#.#..#...#.",
 "...#....#.....#...#........#..#...#....#..#####.",
 "...#....#.....#...#......#....#...#....#......#.",
 "...#.....###...###......####...###.....#..#####.",
 "................................................",
 "#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#.#."};
			int Arg3 = 18;

			vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, getCount(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysViewPoints ___test;
	___test.run_test(-1);
}
// END CUT HERE
