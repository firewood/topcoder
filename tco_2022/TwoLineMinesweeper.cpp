// BEGIN CUT HERE
/*
TCO22 R1B Hard (500)

PROBLEM STATEMENT

This problem references the well-known puzzle game Minesweeper. 
Prior knowledge of the game is not necessary, the problem statement explains everything you need to know.

You are playing Minesweeper on a small rectangular grid: two rows by N columns.

All the cells in the first row have already been revealed.
It turned out that none of them contained a mine.

In Minesweeper, once a cell is revealed, it contains a number.
The number shown in a revealed cell is the total number of mines in adjacent cells.
(Cells sharing a side or a corner with that cell count as adjacent cells.)

You are given the vector <int> firstLine with N elements: these revealed numbers, from left to right.

Your task is to reconstruct the second row: find out which cells contain mines and which ones are empty.

We will use the character '*' (asterisk) to denote a mine and the character '-' (dash) to denote an empty cell.
Using these characters we can describe the content of the second row as an N-character string.

It is possible that more than one configuration of mines corresponds to the given first row.
If there are more than 50 such configurations, return a vector <string> containing any 50 distinct valid configurations of mines.
If there are 50 or fewer, return a string containing all of them.

The return value must be sorted in ascending order.


DEFINITION
Class:TwoLineMinesweeper
Method:solve
Parameters:vector <int>
Returns:vector <string>
Method signature:vector <string> solve(vector <int> firstLine)


NOTES
-The sort order required is the standard sort order according to the characters' ASCII values. In this order, '*' < '-'. The standard sorting routine in each supported programming language should produce the correct order.


CONSTRAINTS
-firstLine will have between 1 and 50 elements, inclusive.
-Each element of firstLine will be between 0 and 3, inclusive.
-firstLine will correspond to at least one valid placement of mines into the second row.


EXAMPLES

0)
{0, 0, 0, 0, 0, 0}

Returns: {"------" }

If the first row is all zeros, there are no mines in the second row.


1)
{0, 0, 1, 1, 1, 0}

Returns: {"---*--" }

The second row must contain a single mine:

+---+---+---+---+---+---+
| 0 | 0 | 1 | 1 | 1 | 0 |
+---+---+---+---+---+---+
|   |   |   | * |   |   |
+---+---+---+---+---+---+

Three first row cells are adjacent to this mine.


2)
{1, 1}

Returns: {"*-", "-*" }

There are two solutions here:

+---+---+       +---+---+
| 1 | 1 |       | 1 | 1 |
+---+---+       +---+---+
| * |   |       |   | * |
+---+---+       +---+---+

Please note that the answers must be in sorted order. The string "*-" comes before the string "-*".


3)
{2, 2, 2, 2, 2}

Returns: {"**-**" }

+---+---+---+---+---+
| 2 | 2 | 2 | 2 | 2 |
+---+---+---+---+---+
| * | * |   | * | * |
+---+---+---+---+---+

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

int count(int pos, const string& s) {
	int c = 0;
	c += pos > 0 && s[pos - 1] == '*';
	c += s[pos] == '*';
	c += pos + 1 < s.length() && s[pos + 1] == '*';
	return c;
}

class TwoLineMinesweeper {

	vector <string> solve(vector <int> firstLine) {
		int N = (int)firstLine.size();
		set<string> s;
		s.insert("");
		const string types = "-*";
		for (int i = 0; i < N; ++i) {
			set<string> ns;
			for (auto x : s) {
				for (char ch : types) {
					string y = x + ch;
					if (i == 0 || count(i - 1, y) == firstLine[i - 1]) {
						if (count(i, y) == firstLine[i]) {
							ns.insert(y);
						}
						if (i < N - 1 && count(i, y) == firstLine[i] - 1) {
							ns.insert(y);
						}
					}
				}
			}
			s = ns;
		}
		vector <string> ans(s.begin(), s.end());
		if (ans.size() > 50) {
			ans.resize(50);
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
			int Arr0[] = {0, 0, 0, 0, 0, 0};
			string Arr1[] = {"------" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 1, 1, 1, 0};
			string Arr1[] = {"---*--" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1};
			string Arr1[] = {"*-", "-*" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 2, 2, 2};
			string Arr1[] = {"**-**" };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoLineMinesweeper ___test;
	___test.run_test(-1);
}
// END CUT HERE
