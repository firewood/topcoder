// BEGIN CUT HERE
/*
SRM 753 Div2 Medium (500)

PROBLEM STATEMENT

Mojtaba is Arpa's kind teacher.
Once, he gave Arpa a problem to solve.
The problem looked as follows:

There is an n times n chessboard, with both rows and columns numbered from 1 to n.
Some unit cubes are placed onto the chessboard in such a way that each cube occupies a single cell.
Each cube has a different color, and a different target cell it should occupy.
You can move cubes by sliding them.
More precisely, in a single move you can slide a single cube from its current cell into an empty adjacent cell.
Find one sequence of moves that will move all cubes to their target cells.

Arpa has already implemented his solution and he asked Mojtaba to test it.
As the solution is not unique, Mojtaba would need a checker.
But now he is occupied with the preparation of Qadir festival, so he kindly asked you to help and do that.

You are given the int n: the dimension of the chessboard.
You are also given the vector <int>s startRow, startCol, destRow, and destCol.
The length of startRow is the number of cubes.
For each valid i, there is a cube that starts in row startRow[i] and column startCol[i], and this cube should be pushed to row destRow, column destCol.
This is the input data for the problem, and you can assume that it is valid.

Finally, you are given the vector <int>s
moveStartRow, moveStartCol, moveDestRow, and moveDestCol.
These contain Arpa's solution.
Their meaning is as follows:
for each valid index i (starting with 0, 1, 2, ...), one should move the cube that is currently 
in row moveStartRow[i] and column moveStartCol[i], and slide this cube to row moveDestRow, column moveDestCol.

We already did some simple tests for you: we made sure that all four arrays that describe Arpa's solution have the same length and contain integers only.
The rest is up to you.

Return "valid" if the arrays move* contain a valid solution to the puzzle described by the other parameters.
Otherwise, return "invalid".


DEFINITION
Class:CCChecker2
Method:check
Parameters:int, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
Returns:string
Method signature:string check(int n, vector <int> startRow, vector <int> startCol, vector <int> destRow, vector <int> destCol, vector <int> moveStartRow, vector <int> moveStartCol, vector <int> moveDestRow, vector <int> moveDestCol)


CONSTRAINTS
-n will be between 1 and 6.
-Length of startRow, startCol, destRow, and, destCol will be equal, and it will be between 0 and 5, inclusive.
-Length of moveStartRow, moveStartCol, moveDestRow, and, moveDestCol will be equal, and they will be between 0 and 50, inclusive.
-Each element of startRow, startCol, destRow, and, destCol will be between 1 and n, inclusive.
-Each element of moveStartRow, moveStartCol, moveDestRow, and, moveDestCol can be any 32-bit integer.
-Start position of cubes will not coincide.
-Destinations of cubes will not coincide.


EXAMPLES

0)
2
{1}
{1}
{2}
{2}
{1, 1}
{1, 2}
{1, 2}
{2, 2}

Returns: "valid"

There is a single cube. It starts at (1,1) and we should move it to (2,2).
The last four arrays describe one valid solution: in step 0 we move a cube from (1,1) to (1,2), and in step 1 we then move a cube from (1,2) to (2,2).

1)
2
{1, 2}
{1, 2}
{1, 2}
{2, 1}
{2, 1, 2, 1, 2, 1, 2, 2}
{2, 1, 1, 2, 2, 1, 1, 2}
{1, 2, 2, 1, 1, 2, 2, 2}
{2, 1, 2, 1, 2, 1, 2, 1}

Returns: "valid"


Now there are two cubes: a red cube that should go from (1,1) to (1,2), and a blue cube that should go from (2,2) to (2,1).


Again, the move* arrays represent a valid solution. It's not the shortest solution possible, but that is not required.


2)
6
{}
{}
{}
{}
{}
{}
{}
{}

Returns: "valid"

If there are no cubes, then doing nothing is a valid solution.

3)
3
{1}
{1}
{1}
{1}
{-47}
{-42}
{125216547}
{125216547}

Returns: "invalid"


Arpa's program has produced some garbage. These are not even valid coordinates!


4)
3
{1}
{1}
{1}
{3}
{1}
{1}
{1}
{3}

Returns: "invalid"

In each step we have to move a cube by a single cell.

5)
6
{1}
{1}
{2}
{2}
{1}
{1}
{2}
{2}

Returns: "invalid"

Diagonal moves are not allowed either.

6)
3
{1,1}
{1,2}
{1,1}
{3,2}
{1,1}
{1,2}
{1,1}
{2,3}

Returns: "invalid"

Here we have two cubes. One starts at (1,1) and should end at (1,3), the other should start and end at (1,2).
The arrays move* describe two instructions: move a cube from (1,1) to (1,2), and move a cube from (1,2) to (1,3).
This is not a valid solution. In step 0 we cannot move the cube from (1,1) to (1,2), because this cell is currently occupied.

7)
3
{1,1}
{1,2}
{1,1}
{3,2}
{1,1}
{2,1}
{1,1}
{3,2}

Returns: "invalid"

This is the same collection of cubes and destinations as in the previous example. This solution is not valid either: the cubes are at the destination cells, but their positions are swapped. Remember that each cube has its own color and its own designated cell.

8)
3
{1,1}
{1,2}
{1,1}
{3,2}
{1,1,1,2}
{2,1,2,2}
{2,1,1,1}
{2,2,3,2}

Returns: "valid"

For the third time we have the same cubes and the same destinations. Now we have a valid solution: move the cube from (1,2) to row 2, in two moves get the cube from (1,1) to (1,3), and then return the other cube from (2,2) back to (1,2) where it belongs.

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
typedef map<II, int> IIIMap;

class CCChecker2 {
public:
	string check(int n, vector <int> startRow, vector <int> startCol, vector <int> destRow, vector <int> destCol, vector <int> moveStartRow, vector <int> moveStartCol, vector <int> moveDestRow, vector <int> moveDestCol) {
		IIIMap st, ed;
		for (int i = 0; i < (int)startRow.size(); ++i) {
			st[II(startRow[i], startCol[i])] = i + 1;
			ed[II(destRow[i], destCol[i])] = i + 1;
		}
		for (int i = 0; i < (int)moveStartRow.size(); ++i) {
			int row = moveStartRow[i], col = moveStartCol[i];
			int drow = moveDestRow[i], dcol = moveDestCol[i];
			if (row < 1 || row > n || col < 1 || col > n || drow < 1 || drow > n || dcol < 1 || dcol > n) {
				return "invalid";
			}
			II skey(row, col);
			II dkey(drow, dcol);
			if (!st[skey] || st[dkey] || abs(row-drow) + abs(col-dcol) != 1) {
				return "invalid";
			}
			st[dkey] = st[skey];
			st.erase(skey);
		}
		return st == ed ? "valid" : "invalid";
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
			int Arg0 = 2;
			int Arr1[] = {1};
			int Arr2[] = {1};
			int Arr3[] = {2};
			int Arr4[] = {2};
			int Arr5[] = {1, 1};
			int Arr6[] = {1, 2};
			int Arr7[] = {1, 2};
			int Arr8[] = {2, 2};
			string Arg9 = "valid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1, 2};
			int Arr2[] = {1, 2};
			int Arr3[] = {1, 2};
			int Arr4[] = {2, 1};
			int Arr5[] = {2, 1, 2, 1, 2, 1, 2, 2};
			int Arr6[] = {2, 1, 1, 2, 2, 1, 1, 2};
			int Arr7[] = {1, 2, 2, 1, 1, 2, 2, 2};
			int Arr8[] = {2, 1, 2, 1, 2, 1, 2, 1};
			string Arg9 = "valid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			// int Arr1[] = {};
			// int Arr2[] = {};
			// int Arr3[] = {};
			// int Arr4[] = {};
			// int Arr5[] = {};
			// int Arr6[] = {};
			// int Arr7[] = {};
			// int Arr8[] = {};
			string Arg9 = "valid";

			vector <int> Arg1;
			vector <int> Arg2;
			vector <int> Arg3;
			vector <int> Arg4;
			vector <int> Arg5;
			vector <int> Arg6;
			vector <int> Arg7;
			vector <int> Arg8;
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1};
			int Arr2[] = {1};
			int Arr3[] = {1};
			int Arr4[] = {1};
			int Arr5[] = {-47};
			int Arr6[] = {-42};
			int Arr7[] = {125216547};
			int Arr8[] = {125216547};
			string Arg9 = "invalid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1};
			int Arr2[] = {1};
			int Arr3[] = {1};
			int Arr4[] = {3};
			int Arr5[] = {1};
			int Arr6[] = {1};
			int Arr7[] = {1};
			int Arr8[] = {3};
			string Arg9 = "invalid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {1};
			int Arr2[] = {1};
			int Arr3[] = {2};
			int Arr4[] = {2};
			int Arr5[] = {1};
			int Arr6[] = {1};
			int Arr7[] = {2};
			int Arr8[] = {2};
			string Arg9 = "invalid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,1};
			int Arr2[] = {1,2};
			int Arr3[] = {1,1};
			int Arr4[] = {3,2};
			int Arr5[] = {1,1};
			int Arr6[] = {1,2};
			int Arr7[] = {1,1};
			int Arr8[] = {2,3};
			string Arg9 = "invalid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,1};
			int Arr2[] = {1,2};
			int Arr3[] = {1,1};
			int Arr4[] = {3,2};
			int Arr5[] = {1,1};
			int Arr6[] = {2,1};
			int Arr7[] = {1,1};
			int Arr8[] = {3,2};
			string Arg9 = "invalid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arr1[] = {1,1};
			int Arr2[] = {1,2};
			int Arr3[] = {1,1};
			int Arr4[] = {3,2};
			int Arr5[] = {1,1,1,2};
			int Arr6[] = {2,1,2,2};
			int Arr7[] = {2,1,1,1};
			int Arr8[] = {2,2,3,2};
			string Arg9 = "valid";

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0])));
			vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0])));
			vector <int> Arg8(Arr8, Arr8 + (sizeof(Arr8) / sizeof(Arr8[0])));
			verify_case(n, Arg9, check(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CCChecker2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
