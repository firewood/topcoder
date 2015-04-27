// BEGIN CUT HERE
/*
SRM 655 Div2 Medium (500)

PROBLEM STATEMENT

You have a rectangular piece of paper.
Its dimensions are W times H.
You want to have a paper with area A instead.
Therefore, you decided to fold the paper you have.
In each step you can fold the paper according to a straight line.
There are two restrictions: First, that line must always be parallel to one of the rectangle's sides.
Second, after each fold both dimensions of the new rectangle must be integers again.

For example, suppose that your paper is 5 units wide and 3 units tall.
If you fold it according to a vertical line that is 4 units to the right of its left side, you will obtain a rectangle that is 4 units wide and 3 units tall.
If you fold it according to a horizontal line that is 1 unit below the top of the rectangle, you will get a rectangle that is 5 units wide and 2 units tall.

You are given the ints W, H, and A.
If it is impossible to fold the paper into a valid rectangle with area A, return -1.
Otherwise, return the smallest number of times you need to fold the paper.


DEFINITION
Class:FoldingPaper2
Method:solve
Parameters:int, int, int
Returns:int
Method signature:int solve(int W, int H, int A)


CONSTRAINTS
-H, W will be between 1 and 1,000,000,000, inclusive.
-A will be between 1 and 100,000, inclusive.


EXAMPLES

0)
5
3
12

Returns: 1

The solution in this case is the first example mentioned above.


1)
2
2
3

Returns: -1

A 2x2 square cannot be folded into a rectangle with area 3. Note that a rectangle that is 1.5 units wide and 2 units tall is not a solution: both dimensions of all rectangles you produce must be integers.


2)
4
4
1

Returns: 4


3)
127
129
72

Returns: 8


4)
1
100000
100000

Returns: 0

The paper already has the desired area, so no folding is necessary.


5)
1
1
2

Returns: -1

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FoldingPaper2 {
public:
	int solve(int W, int H, int A) {
		int ans = -1;
		for (int h = 1; h <= A; ++h) {
			if (h > H) {
				break;
			}
			int w = A / h;
			if (w * h != A || w > W) {
				continue;
			}
			int c = 0, x = W, y = H;
			while (x > w) {
				x -= x / 2;
				c += 1;
			}
			while (y > h) {
				y -= y / 2;
				c += 1;
			}
			if (ans < 0) {
				ans = c;
			} else {
				ans = min(ans, c);
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
			int Arg0 = 5;
			int Arg1 = 3;
			int Arg2 = 12;
			int Arg3 = 1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = -1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arg2 = 1;
			int Arg3 = 4;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 127;
			int Arg1 = 129;
			int Arg2 = 72;
			int Arg3 = 8;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100000;
			int Arg2 = 100000;
			int Arg3 = 0;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = -1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 999999999;
			int Arg1 = 999999999;
			int Arg2 = 55566;
			int Arg3 = -1;

			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoldingPaper2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
