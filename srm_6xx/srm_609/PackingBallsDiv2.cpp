// BEGIN CUT HERE
/*
SRM 609 Div2 Medium (500)

PROBLEM STATEMENT
We have R red, G green, and B blue balls.
We want to divide them into as few packages as possible.
Each package must contain 1, 2, or 3 balls.
Additionally, each package must be either a "normal set" (all balls in the package have the same color), or a "variety set" (no two balls have the same color).
Compute and return the smallest possible number of packages.


DEFINITION
Class:PackingBallsDiv2
Method:minPacks
Parameters:int, int, int
Returns:int
Method signature:int minPacks(int R, int G, int B)


CONSTRAINTS
-R, G, and B will each be between 1 and 100, inclusive.


EXAMPLES

0)
4
2
4

Returns: 4

We have 4 red, 2 green, and 4 blue balls.
Clearly, we need at least four packages to store 10 balls.
One possibility of using exactly four packages looks as follows: RGB, RG, RR, BBB.
(I.e., the first package has 1 ball of each color, the second package has a red and a green ball, and so on.)


1)
1
7
1

Returns: 3

Here the only possible solution is to have one package with RGB and two packages with GGG each.


2)
2
3
5

Returns: 4


3)
78
53
64

Returns: 66


4)
100
100
100

Returns: 100

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PackingBallsDiv2 {
public:
	int minPacks(int R, int G, int B) {
		int ans = R + G + B;
		int m = max(R, max(G, B));
		for (int i = 0; i <= m; ++i) {
			int t = i + (R - i + 2) / 3 + (G - i + 2) / 3 + (B - i + 2) / 3;
			ans = min(ans, t);
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
			int Arg0 = 4;
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 4;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 7;
			int Arg2 = 1;
			int Arg3 = 3;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arg2 = 5;
			int Arg3 = 4;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 78;
			int Arg1 = 53;
			int Arg2 = 64;
			int Arg3 = 66;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 100;
			int Arg3 = 100;

			verify_case(n, Arg3, minPacks(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PackingBallsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
