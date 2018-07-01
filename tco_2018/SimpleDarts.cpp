// BEGIN CUT HERE
/*
TCC India 2018 Qualification Round Easy (250)

PROBLEM STATEMENT

You are playing a game of darts.
The target in this particular game looks as follows:

There are F regular sectors. These are worth 1, 2, ..., F points.
There are F "double points" sectors. These are worth 2, 4, ..., 2*F points.
There are F "triple points" sectors. These are worth 3, 6, ..., 3*F points.
There is the bullseye in the middle of the target. The bullseye consists of two sectors: the outer bullseye (worth 25 points) and the inner bullseye (worth 50 points).

You have three darts. What is the largest total number of points you can get if you hit three different sectors?


DEFINITION
Class:SimpleDarts
Method:highestScore
Parameters:int
Returns:int
Method signature:int highestScore(int F)


CONSTRAINTS
-F will be between 1 and 100, inclusive.


EXAMPLES

0)
20

Returns: 171

A regular dartboard has numbers 1 through 20. If we want to produce the highest score we can by hitting three distinct sectors, we should hit the triple-20, triple-19, and triple-18 for a total of 3*20 + 3*19 + 3*18 = 171 points.


1)
1

Returns: 78

This tiny target has only five sectors. These are worth 1, 2, 3, 25, and 50 points. Clearly the optimal solution is to score 3 + 25 + 50 = 78 points.


2)
9

Returns: 102

Now the optimal play is to hit the inner bullseye (50), the outer bullseye (25), and the triple-9 (27 points).

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SimpleDarts {
public:
	int highestScore(int F) {
		int a[] = { 25, 50, F * 3, (F - 1) * 3, (F - 2) * 3 };
		sort(a, a + 5);
		return a[2] + a[3] + a[4];
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
			int Arg0 = 20;
			int Arg1 = 171;

			verify_case(n, Arg1, highestScore(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 78;

			verify_case(n, Arg1, highestScore(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 102;

			verify_case(n, Arg1, highestScore(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SimpleDarts ___test;
	___test.run_test(-1);
}
// END CUT HERE
