// BEGIN CUT HERE
/*
SRM 671 Div2 Easy (250)

PROBLEM STATEMENT
Limak is a little polar bear.
Today he found two things in the snow: a bucket of blue paint and a white rectangular grid with W times H square cells.

Limak is going to paint some (possibly even all) cells blue.
He wants to do it in such a way that the blue cells will form a completely filled blue rectangle.
He has enough paint for M cells.
What is the largest possible area of a blue rectangle he can paint?


DEFINITION
Class:BearPaints
Method:maxArea
Parameters:int, int, long long
Returns:long long
Method signature:long long maxArea(int W, int H, long long M)


CONSTRAINTS
-W and H will be between 1 and 10^6, inclusive.
-M will be between 1 and 10^12, inclusive.


EXAMPLES

0)
3
5
14

Returns: 12

Limak has a grid that is W = 3 cells wide and H = 5 cells tall.
He doesn't have enough paint to color all 15 cells.
He also cannot color just 14 or 13 cells in a way that would produce a blue rectangle.
The best he can do is to color four consecutive rows blue.
This will produce a blue rectangle.
Its area is 12 squares.


1)
4
4
10

Returns: 9

Here the best solution is to paint a rectangle of size 3 times 3 blue.
(A square is a valid rectangle.)


2)
1000000
12345
1000000000000

Returns: 12345000000

Limak has more than enough paint to make whole grid blue.


3)
1000000
1000000
720000000007

Returns: 720000000000

Limak's grid is a square with side 10^6.
Limak can paint a rectangle of size 800,000 times 900,000.


4)
1000000
1000000
999999999999

Returns: 999999000000

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class BearPaints {
public:
	long long maxArea(int W, int H, long long M) {
		LL ans = 0;
		LL a = min(W, H), b = max(W, H);
		for (LL c = 1; c <= a; ++c) {
			LL d = min(M / c, b);
			ans = max(ans, c * d);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			long long Arg2 = 14LL;
			long long Arg3 = 12LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			long long Arg2 = 10LL;
			long long Arg3 = 9LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 12345;
			long long Arg2 = 1000000000000LL;
			long long Arg3 = 12345000000LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			long long Arg2 = 720000000007LL;
			long long Arg3 = 720000000000LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			long long Arg2 = 999999999999LL;
			long long Arg3 = 999999000000LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPaints ___test;
	___test.run_test(-1);
}
// END CUT HERE
