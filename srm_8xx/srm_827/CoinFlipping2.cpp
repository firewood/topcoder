// BEGIN CUT HERE
/*
SRM 827 Div1 Medium (500)

PROBLEM STATEMENT

There is a table with a rectangular top surface. 
The surface is divided into a grid of square cells.
Some cells are empty, others contain exactly one coin each.
Each coin is showing either heads or tails.

You are given the vector <string> layout describing the current configuration.
Each letter represents one cell: 'H' is a cell with a coin that shows heads, 'T' a coin that shows tails, and '.' is an empty cell.

Your goal is to have exactly desiredCount coins that show heads.

You can modify the current configuration in a series of steps.
In each step you can choose any row or column of cells and flip all coins that are in the selected region.
You can select each row and column arbitrarily many times and in any order you like.

If the goal cannot be achieved, return {-1}.
Otherwise, find and return any sequence of at most 100 moves that produces one configuration with the desired number of heads.
Return the sequence of moves formatted as a vector <int>.

If layout has R elements with C characters each, use the value x to denote the move that flips layout[x], and use the value R+y to denote the move that flips layout[r][y] for all r.


DEFINITION
Class:CoinFlipping2
Method:correctHeads
Parameters:vector <string>, int
Returns:vector <int>
Method signature:vector <int> correctHeads(vector <string> layout, int desiredCount)


NOTES
-You may assume that whenever a solution exists, a solution with at most 100 moves exists.


CONSTRAINTS
-layout will contain between 1 and 12 elements, inclusive.
-Each element in layout will contain the same number of characters.
-That number will be between 1 and 50, inclusive.
-Each character in layout will be 'H', 'T', or '.'.
-desiredCount will be between 0 and the number of coins on the table, inclusive.


EXAMPLES

0)
{"H.T.H",
 "TTTTT",
 "HHTHH"}
12

Returns: {1, 5 }

In our solution we flip the middle row (denoted 1) and then we flip the middle column (denoted 5). Below we show the intermediate state, the final state, and the numbers that correspond to individual rows and columns.


      initial:    intermediate:       final:
                                   
       34567          34567           34567
                                   
     0 H.T.H        0 H.T.H         0 H.H.H
     1 TTTTT        1 HHHHH         1 HHTHH
     2 HHTHH        2 HHTHH         2 HHHHH


1)
{"HT",
 "HH"}
2

Returns: {-1 }

Regardless of how you make the flips, there will always be three coins of one type and one of the other. It's not possible to have exactly two heads.


2)
{"HT",
 "HH"}
3

Returns: { }

One easy way to produce exactly three heads is to do nothing :)

Other valid return values include {1, 1, 2, 1, 2, 1} and {1, 3}. The first of these produces the initial configuration, the second a configuration in which only the coin in the bottom left corner is tails.


3)
{"T....",
 "...T.",
 "..T..",
 "....T",
 ".T..."}
4

Returns: {0, 9, 2, 6 }

Each of these coins can be toggled independently of the others, either by selecting its row or by selecting its column. In order to have four heads we can simply toggle any four of them.

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

class CoinFlipping2 {
public:
	vector <int> correctHeads(vector <string> layout, int desiredCount) {
		int h = layout.size(), w = layout[0].length();
		for (int b = 0; b < (1 << h); ++b) {
			vector<long long> dp(16 * 50 + 1, -1);
			dp[0] = 0;
			for (int j = 0; j < w; ++j) {
				vector<long long> next(16 * 50 + 1, -1);
				int c[2] = {};
				for (int i = 0; i < h; ++i) {
					if (layout[i][j] == '.') continue;
					c[(layout[i][j] == 'H') ^ ((b >> i) & 1)] += 1;
				}
				for (int i = 0; i <= 12 * 50; ++i) {
					if (dp[i] >= 0) {
						next[i + c[0]] = dp[i] | (1LL << j);
					}
				}
				for (int i = 0; i <= 12 * 50; ++i) {
					if (dp[i] >= 0) {
						next[i + c[1]] = dp[i];
					}
				}
				dp = next;
			}
			if (dp[desiredCount] >= 0) {
				vector <int> ans;
				for (int i = 0; i < h; ++i) {
					if ((1 << i) & b) {
						ans.emplace_back(i);
					}
				}
				for (int j = 0; j < w; ++j) {
					if ((1LL << j) & dp[desiredCount]) {
						ans.emplace_back(h + j);
					}
				}
				return ans;
			}
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
			string Arr0[] = {"H.T.H",
 "TTTTT",
 "HHTHH"};
			int Arg1 = 12;
			int Arr2[] = {1, 5 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, correctHeads(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HT",
 "HH"};
			int Arg1 = 2;
			int Arr2[] = {-1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, correctHeads(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HT",
 "HH"};
			int Arg1 = 3;
//			int Arr2[] = { };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
	//		vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg2;
			verify_case(n, Arg2, correctHeads(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"T....",
 "...T.",
 "..T..",
 "....T",
 ".T..."};
			int Arg1 = 4;
			int Arr2[] = {0, 9, 2, 6 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, correctHeads(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CoinFlipping2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
