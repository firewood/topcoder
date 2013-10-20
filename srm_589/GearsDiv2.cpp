// BEGIN CUT HERE
/*
SRM 589 Div2 Medium (500)

// PROBLEM STATEMENT
// Goose Tattarrattat has a machine that contains N gears (cogwheels).
The gears are numbered 0 through N-1.
Currently, the gears are arranged into a cycle: for each i, gear i meshes with gears i-1 and i+1 (counting modulo N).
In particular, gear 0 meshes with gear N-1.

Let X and Y be two meshing gears.
Note that if X is turning, Y must clearly be turning in the opposite direction (clockwise vs. counter-clockwise).

For each of the N gears we have a desired direction of turning.
You are given this information encoded as a string Directions.
Character i of Directions is 'R' if we want gear i to turn to the right (clockwise), and it is 'L' if we want it to turn to the left.

Of course, it may be impossible to satisfy all the desired directions of turning.
Return the minimal number of gears that have to be removed from the machine so that all remaining gears can turn in the desired directions at the same time.

DEFINITION
Class:GearsDiv2
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string Directions)


NOTES
-Removing a gear creates a gap between the other gears. For example, after removing the gear 7, gears 6 and 8 will not mesh.


CONSTRAINTS
-Directions will contain between 3 and 50 characters, inclusive.
-Each character of Directions will be 'R' or 'L'.


EXAMPLES

0)
"LRRR"

Returns: 1

Once we remove gear 2, the other three are free to turn in the desired directions.


1)
"RRR"

Returns: 2

Gear 0 meshes with gear 2. 


2)
"LRLR"

Returns: 0


3)
"LRLLRRLLLRRRLLLL"

Returns: 6


4)
"RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"

Returns: 14

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class GearsDiv2 {
public:
	int getmin(string Directions) {
		int a = 0;
		string s = Directions;
		s += Directions[0];
		for (int i = 1; i < (int)s.length(); ++i) {
			if (s[i-1] == s[i]) {
				++a;
				s[i] = 'x';
			}
		}

		int b = 1;
		s = Directions;
		for (int i = 2; i < (int)s.length(); ++i) {
			if (s[i-1] == s[i]) {
				++b;
				s[i] = 'x';
			}
		}

		return min(a, b);
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
			string Arg0 = "LRRR";
			int Arg1 = 1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRR";
			int Arg1 = 2;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLR";
			int Arg1 = 0;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLLRRLLLRRRLLLL";
			int Arg1 = 6;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR";
			int Arg1 = 14;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRRLLLRLLR";
			int Arg1 = 4;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GearsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
