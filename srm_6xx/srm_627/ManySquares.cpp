// BEGIN CUT HERE
/*
SRM 627 Div2 Easy (250)

PROBLEM STATEMENT
You found a box from an old game.
The box contains a lot of sticks and a manual.
Frustrated by the fact the manual was unreadable, you decided to invent your own game with the sticks.
In your game, the goal is to use the sticks to build as many squares as possible.
There are only two rules:

Each stick can only be used in one square.
Each square must consist of exactly 4 sticks. That is, you cannot combine two or more sticks to create one side of the square.

You are given a vector <int> sticks.
The elements of sticks are the lengths of the sticks you have.
Return the maximum number of squares you can make.


DEFINITION
Class:ManySquares
Method:howManySquares
Parameters:vector <int>
Returns:int
Method signature:int howManySquares(vector <int> sticks)


NOTES
-If you can't make any square, return 0.


CONSTRAINTS
-sticks will contain between 1 and 50 elements.
-Each element of sticks will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,1,2,2,1,1,2}

Returns: 1

You can build a square with side 1.


1)
{3, 1, 4, 4, 4, 10, 10, 10, 10}


Returns: 1

You can build a square with side 10. You cannot build a square with side 4. (Note that you are not allowed to use 3+1 instead of a 4.)


2)
{1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3}

Returns: 3


3)
{1,1,1,2,2,2,3,3,3,4,4,4}

Returns: 0

Sometimes you can't make any square.


4)
{1,1,1,2,1,1,1,3,1,1,1}

Returns: 2


5)
{2,2,4,4,8,8}

Returns: 0

You are also not allowed to break the sticks.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ManySquares {
public:
	int howManySquares(vector <int> sticks) {
		sort(sticks.begin(), sticks.end());
		int cnt = 1;
		int ans = 0;
		for (int i = 1; i < (int)sticks.size(); ++i) {
			if (sticks[i - 1] == sticks[i]) {
				++cnt;
				if (cnt >= 4) {
					++ans;
					cnt = 0;
				}
			} else {
				cnt = 1;
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
			int Arr0[] = {1,1,2,2,1,1,2};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 1, 4, 4, 4, 10, 10, 10, 10}
;
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,2,2,2,3,3,3,4,4,4};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,2,1,1,1,3,1,1,1};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,4,4,8,8};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1,2,1,2,1,2,1,2 };
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, howManySquares(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ManySquares ___test;
	___test.run_test(-1);
}
// END CUT HERE
