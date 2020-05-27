// BEGIN CUT HERE
/*
SRM 784 Div2 Easy (250)

PROBLEM STATEMENT

You are in charge of a team of N other people.
Together, you are going to prepare decorations for a huge party.
In order to do that, each of you needs to have a pair of scissors.
You already have one, but none of your helpers do.

You have recently purchased N pairs of scissors from an online retailer.
They just arrived, but there is a small issue: each pair of scissors is wrapped in plastic.
Getting scissors out of the plastic wrap requires having another pair of scissors (that's not in plastic) and it takes 10 seconds.

Assume that everything other than opening the packages happens instantly.
(I.e., whenever a new pair of scissors has been opened, somebody can take it and immediately start opening another box.)

Calculate and return the shortest amount of time (in seconds) in which it is possible to release all the scissors from their plastic wraps.


DEFINITION
Class:Scissors
Method:openingTime
Parameters:int
Returns:int
Method signature:int openingTime(int N)


CONSTRAINTS
-N will be between 1 and 10^9, inclusive.


EXAMPLES

0)
3

Returns: 20

At the beginning you have the only free pair of scissors. It will take you 10 seconds to open a box containing another pair of scissors. At this point in time you have two pairs of scissors that are free and two that are still in plastic. Both other boxes with scissors can now be opened at the same time: one by you and one by somebody who took the pair of scissors you just liberated.


1)
10

Returns: 40

One possible optimal schedule:

First 10 seconds: open one box. You now have 2 scissors free + 9 in boxes.
Second 10 seconds: open two boxes. You now have 4 scissors free + 7 in boxes.
Third 10 seconds: open two boxes. You now have 6 scissors free + 5 in boxes.
Fourth 10 seconds: open the remaining five boxes.

There are other ways to open all scissors in 40 seconds but there is no way to do it faster.


2)
1234

Returns: 110

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

class Scissors {
public:
	int openingTime(int N) {
		int ans = 0;
		for (int c = 1; N > 0; c *= 2) {
			ans += 10;
			N -= c;
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
			int Arg1 = 20;

			verify_case(n, Arg1, openingTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 40;

			verify_case(n, Arg1, openingTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234;
			int Arg1 = 110;

			verify_case(n, Arg1, openingTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Scissors ___test;
	___test.run_test(-1);
}
// END CUT HERE
