// BEGIN CUT HERE
/*
SRM 633 Div2 Easy (250)

PROBLEM STATEMENT
Here at [topcoder], we call a contestant a "target" if their rating is 3000 or more.
In the arena, the targets have a red icon with a small target on it.
Do you want to become a target as well?
Sure you do.
But before you get there, let's start with something easier: drawing a target.

The target you need to draw consists of nested squares.
The innermost square is just a single '#' character.
The larger squares use alternatingly the character ' ' (space) and the character '#'.
Here is an example in which the side of the largest square is n = 5:

#####
#   #
# # #
#   #
#####

And here is an example for n = 9:

#########
#       #
# ##### #
# #   # #
# # # # #
# #   # #
# ##### #
#       #
#########

You will be given an int n.
Your method must return a vector <string> which contains a drawing of the target with side n.
More precisely, each element of the returned vector <string> must be one row of the drawing, in order.
Therefore, the returned vector <string> will consist of n elements, each with n characters.
(See the examples below for clarification.)

The value of n will be such that a target like the ones above can be drawn: 5, 9, 13, and so on.
Formally, n will be of the form 4k+1, where k is a positive integer.


DEFINITION
Class:Target
Method:draw
Parameters:int
Returns:vector <string>
Method signature:vector <string> draw(int n)


CONSTRAINTS
-n will be between 5 and 49, inclusive.
-n mod 4 will be 1.


EXAMPLES

0)
5

Returns: {"#####", "#   #", "# # #", "#   #", "#####" }


1)
9

Returns: {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" }


2)
13

Returns: {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" }


3)
17

Returns: {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" }

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Target {
public:
	vector <string> draw(int n) {
		vector <string> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = string(n, ' ');
		}
		for (int i = 0; i <= n / 2; i += 2) {
			for (int j = -i; j <= i; ++j) {
				ans[n / 2 - i][n / 2 + j] = '#';
				ans[n / 2 + i][n / 2 + j] = '#';
				ans[n / 2 + j][n / 2 - i] = '#';
				ans[n / 2 + j][n / 2 + i] = '#';
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
			int Arg0 = 5;
			string Arr1[] = {"#####", "#   #", "# # #", "#   #", "#####" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			string Arr1[] = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			string Arr1[] = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 17;
			string Arr1[] = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Target ___test;
	___test.run_test(-1);
}
// END CUT HERE
