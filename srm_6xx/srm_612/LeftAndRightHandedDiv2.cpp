// BEGIN CUT HERE
/*
SRM 612 Div2 Easy (250)

PROBLEM STATEMENT
Some students are seated in a row next to each other.
Each of them is either left-handed or right-handed.
You are given a string S that describes the row of students.
Each character of S is either 'L' or 'R', representing a left-handed or a right-handed person, respectively.
The characters describe the row from the left to the right: for all i, the person described by character i+1 sits to the right of the person described by character i.

The students are trying to write down lecture notes.
Whenever a left-handed person sits immediately to the right of a right-handed person, their elbows collide when they both try to write at the same time.
Compute and return the number of elbow collisions, assuming that all students in the row attempt to write at the same time.


DEFINITION
Class:LeftAndRightHandedDiv2
Method:count
Parameters:string
Returns:int
Method signature:int count(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character of S will be either 'L' or 'R'.


EXAMPLES

0)
"L"

Returns: 0

There's only one person in the row so there are no collisions.


1)
"RRR"

Returns: 0

Everybody is right-handed so there are no collisions.


2)
"LRLRLR"

Returns: 2

There will be two collisions: one of them between the second and the third person from the left (described by S[1] and S[2]) and the other between the fourth and the fifth person.


3)
"LLLRRR"

Returns: 0


4)
"RLRLRL"

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LeftAndRightHandedDiv2 {
public:
	int count(string S) {
		int ans = 0;
		for (int i = 1; i < (int)S.length(); ++i) {
			ans += S[i] == 'L' && S[i - 1] == 'R';
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
			string Arg0 = "L";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRR";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLRLR";
			int Arg1 = 2;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LLLRRR";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RLRLRL";
			int Arg1 = 3;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftAndRightHandedDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
