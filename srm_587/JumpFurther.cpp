// BEGIN CUT HERE
/*
SRM 587 Div1 Easy (250)

PROBLEM STATEMENT
Little Fox Jiro is standing at the bottom of a long flight of stairs.
The bottom of the stairs has number 0, the bottommost step has number 1,
the next step has number 2, and so on.
The staircase is so long that Jiro is guaranteed not to reach its top.

Jiro will now perform N consecutive actions.
The actions are numbered 1 through N, in order.
When performing action X, Jiro chooses between two options:
either he does nothing, or he jumps exactly X steps up the stairs.
In other words, if Jiro starts performing action X standing on step Y,
he will end it either on step Y, or on step Y+X.

For example, if N=3, Jiro will make three consecutive choices:
whether or not to jump 1 step upwards, 2 steps upwards, and then 3 steps upwards.

One of the steps is broken.
The number of this step is badStep.
Jiro cannot jump onto this step.

You are given the ints N and badStep.
Compute and return the number of the topmost step that can be reached by Jiro.


DEFINITION
Class:JumpFurther
Method:furthest
Parameters:int, int
Returns:int
Method signature:int furthest(int N, int badStep)


CONSTRAINTS
-N will be between 1 and 2,000, inclusive.
-badStep will be between 1 and 4,000,000, inclusive.


EXAMPLES

0)
2
2

Returns: 3

The optimal strategy is to jump upwards twice: from step 0 to step 1, and then from step 1 to step 3. This trajectory avoids the broken step.


1)
2
1

Returns: 2

In this case step 1 is broken, so Jiro cannot jump upwards as his first action. The optimal strategy is to first stay on step 0, and then to jump from step 0 to step 2.


2)
3
3

Returns: 5


3)
1313
5858

Returns: 862641


4)
1
757065

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class JumpFurther {
public:
	int furthest(int N, int badStep) {
		int ans = 0;
		for (int i = 1; i <= N; ++i) {
			ans += i;
			if (ans == badStep) {
				--ans;
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arg2 = 3;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 5;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1313;
			int Arg1 = 5858;
			int Arg2 = 862641;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 757065;
			int Arg2 = 1;

			verify_case(n, Arg2, furthest(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	JumpFurther ___test;
	___test.run_test(-1);
}
// END CUT HERE
