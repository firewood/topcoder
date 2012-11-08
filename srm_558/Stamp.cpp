// BEGIN CUT HERE
/*
// SRM 558 Div1 Easy (275)

// PROBLEM STATEMENT
// Little Fox Jiro has a rectangular board.
On the board there is a row of N unit cells.
The cells are numbered 0 through N-1 from the left to the right.
Initially, the cells are not colored.
Jiro must color each of the cells red, green, or blue.

You are given a string desiredColor with N characters.
For each i, character i of desiredColor represents the color Jiro must use for cell i.
If a character is one of 'R' (as red), 'G' (as green), and 'B' (as blue), it means that Jiro must use that particular color.
If a character is '*', Jiro may use any of the three colors for the particular cell.

You are also given the ints stampCost and pushCost that describe the cost of the coloring process.
The coloring process consists of two phases.
In the first phase, Jiro must pick a single stamp he will then use to color all the cells.
The length L of the stamp can be any integer between 1 and N, inclusive.
A stamp of length L costs L*stampCost.

In the second phase, Jiro must repeatedly use the stamp to color the cells.
Each use of the stamp works as follows:

Jiro picks one of the three colors and pushes the stamp into ink of the chosen color C.
Jiro picks a segment of L contiguous cells such that each of them is either uncolored or already has the color C.
The segment must be completely inside the board.
That is, the leftmost cell of the segment must be one of the cells 0 through N-L.
Jiro pushes the stamp onto the chosen segment of cells. All the cells now have color C.

Each use of the stamp costs pushCost.

Return the smallest possible total cost of coloring all the cells using the above process.


DEFINITION
Class:Stamp
Method:getMinimumCost
Parameters:string, int, int
Returns:int
Method signature:int getMinimumCost(string desiredColor, int stampCost, int pushCost)


CONSTRAINTS
-desiredColor will contain between 1 and 50 characters, inclusive.
-Each character of desiredColor will be either 'R' or 'G' or 'B' or '*'.
-stampCost will be between 1 and 100,000, inclusive.
-pushCost will be between 1 and 100,000, inclusive.


EXAMPLES

0)
"RRGGBB"
1
1

Returns: 5

The optimal solution is to choose L=2 and then stamp three times: using red color for cells [0,1], green for [2,3], and blue for [4,5].
The stamp costs 2*1 = 2, each of the three uses costs 1, so the total costs is 2*1 + 3*1 = 5.


1)
"R**GB*"
1
1

Returns: 5

The optimal solution is the same as in the previous example.
Note that you must color all the cells, so choosing L=1 and then using the stamp three times is not a valid solution.


2)
"BRRB"
2
7

Returns: 30

Also, note that once a cell is colored, you are not allowed to stamp over it using a different color.
Therefore, you can only choose L=1 in this case.


3)
"R*RR*GG"
10
58

Returns: 204

It is allowed to stamp the same cell multiple times if all of those stamps use the same color.


4)
"*B**B**B*BB*G*BBB**B**B*"
5
2

Returns: 33


5)
"*R*RG*G*GR*RGG*G*GGR***RR*GG"
7
1

Returns: 30

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Stamp {

public:
	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		int sz = (int)desiredColor.length();
		int res = stampCost + pushCost * sz;
		int i, j, k, L;

		int maxlen[50];
		for (i = 0; i < sz; ++i) {
			k = '*';
			for (j = i; j < sz; ++j) {
				if (k != desiredColor[j] && desiredColor[j] != '*') {
					if (k != '*') {
						break;
					}
					k = desiredColor[j];
				}
			}
			maxlen[i] = j-i;
		}

		int dp[51];
		for (L = 2; L <= sz; ++L) {
			memset(dp, 0x7f, sizeof(dp));
			dp[0] = 0;
			for (i = L; i <= sz; ++i) {
				for (j = L; j <= i; ++j) {
					if (maxlen[i-j] >= j) {
						dp[i] = min(dp[i], dp[i-j] + pushCost * ((j+L-1)/L));
					}
				}
			}
			res = min(res, stampCost * L + dp[sz]);
		}

		return res;
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
			string Arg0 = "RRGGBB";
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 5;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R**GB*";
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 5;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BRRB";
			int Arg1 = 2;
			int Arg2 = 7;
			int Arg3 = 30;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R*RR*GG";
			int Arg1 = 10;
			int Arg2 = 58;
			int Arg3 = 204;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "*B**B**B*BB*G*BBB**B**B*";
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 33;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
			int Arg1 = 7;
			int Arg2 = 1;
			int Arg3 = 30;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Stamp ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
