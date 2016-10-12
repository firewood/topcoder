// BEGIN CUT HERE
/*
SRM 699 Div2 Easy (250)

PROBLEM STATEMENT
Limak is going to spend N days in the mountains.
The days will be numbered 1 through N.
In the morning of day 1 Limak starts his hike in the base camp at altitude 0.
In the evening of day N Limak must return back to altitude 0.
Limak carries a tent and a sleeping bag, so during the hike he can sleep at any altitude.

During each day of his hike, Limak either ascends or descends.
(Each day he has to choose one or the other, he cannot both ascend and descend on the same day.)
Additionally, there are two constraints:

He cannot ascend too quickly, to make acclimatization to higher altitudes easier.
More precisely, each day spent ascending can increase his altitude by at most A.
He cannot descend too quickly, otherwise his knees hurt.
More precisely, each day spent descending can decrease his altitude by at most B.

For example, suppose that Limak's altitude in the morning is 470, and suppose that A=100 and B=200.
In the evening of the same day Limak can be anywhere between the altitudes 270 and 570, inclusive.

You are given the ints N, A, and B.
Return the largest altitude Limak can reach.


DEFINITION
Class:UpDownHiking
Method:maxHeight
Parameters:int, int, int
Returns:int
Method signature:int maxHeight(int N, int A, int B)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-A and B will be between 1 and 50, inclusive.


EXAMPLES

0)
3
7
10

Returns: 10

The highest altitude Limak can reach is 10.
Here is one way to do so:

On day 1, Limak will start at altitude 0 and he will ascend to altitude 7.
On day 2, Limak will start at altitude 7 and he will ascend to altitude 10.
On day 3, Limak will start at altitude 10 and he will descend back to altitude 0.


1)
5
40
30

Returns: 80

In the five days of this hike Limak can change his altitude by +40, +40, -27, -27, and -26.
The highest altitude reached is 80.


2)
2
50
1

Returns: 1

Even though Limak can climb quickly, moving up even by 50 in one day, he can move down by at most 1 in the second day.
So, in the first day he should climb by 1 only.


3)
3
42
42

Returns: 42


4)
20
7
9

Returns: 77


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

class UpDownHiking {
public:
	int maxHeight(int N, int A, int B) {
		int ans = 0;
		for (int i = 1; i < N; ++i) {
			ans = max(ans, min(A * i, B * (N - i)));
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
			int Arg0 = 3;
			int Arg1 = 7;
			int Arg2 = 10;
			int Arg3 = 10;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 40;
			int Arg2 = 30;
			int Arg3 = 80;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 50;
			int Arg2 = 1;
			int Arg3 = 1;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 42;
			int Arg2 = 42;
			int Arg3 = 42;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 7;
			int Arg2 = 9;
			int Arg3 = 77;

			verify_case(n, Arg3, maxHeight(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UpDownHiking ___test;
	___test.run_test(-1);
}
// END CUT HERE
