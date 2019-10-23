// BEGIN CUT HERE
/*
SRM 769 Div2 Easy (250)

PROBLEM STATEMENT

There once was a meadow:

................

Then, somebody dropped some balls onto the meadow:

.()...()().().()

Finally, some grass grew on the meadow, obscuring some of the balls:

.(|||.()(||||||)

You are given the string meadow with the final state of the meadow.
Return the smallest possible number of balls that were on the meadow.

Empty ground is the character '.', each ball is the string "()", and each blade of grass is the character '|'.
It is guaranteed that the balls did not overlap. For example, the input meadow = "(()" is invalid.
Formally, meadow was produced by taking a string of periods, changing some ".." into "()" and then changing some characters to '|'.


DEFINITION
Class:BallsOnAMeadow
Method:count
Parameters:string
Returns:int
Method signature:int count(string meadow)


CONSTRAINTS
-meadow will contain between 1 and 50 characters, inclusive.
-meadow will have the form described in the problem statement.


EXAMPLES

0)
".(|||.()(||||||)"

Returns: 4

The example from the problem statement. Even though in the problem statement there were five balls, the situation seen in this meadow can also be produced using only four balls.

1)
"()"

Returns: 1



2)
"||"

Returns: 0



3)
"(|(|(||)|)|)"

Returns: 6



4)
".....|||||....."

Returns: 0



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

class BallsOnAMeadow {
public:
	int count(string meadow) {
		int ans = 0;
		char prev = -1;
		for (char c : meadow) {
			ans += prev == '(' || c == ')';
			prev = c;
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
			string Arg0 = ".(|||.()(||||||)";
			int Arg1 = 4;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()";
			int Arg1 = 1;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "||";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(|(|(||)|)|)";
			int Arg1 = 6;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".....|||||.....";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BallsOnAMeadow ___test;
	___test.run_test(-1);
}
// END CUT HERE
