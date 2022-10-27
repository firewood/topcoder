// BEGIN CUT HERE
/*
SRM 840 Div2 Medium (450)

PROBLEM STATEMENT

Barong and Rangda are characters from Balinese mythology. Barong, the king of spirits, represents good, while Rangda, the demon queen, represents evil.

We know that Barong is stronger than Rangda.

While traveling in Bali, we were pondering hypothetical fights between two teams, each consisting of some Barongs and some Rangdas.

Suppose there are two teams:

Team 1 consists of B1 Barongs and R1 Rangdas.
Team 2 consists of B2 Barongs and R2 Rangdas.

Consider the following statement: "Team 1 is stronger than team 2."

There are three possible scenarios, listed below. Determine which scenario occurs and return the corresponding message. (See Notes below if you need a more formal definition of the problem.)

If we can be sure that the statement is correct, return "correct".
If we can be sure that the statement is not correct, return "incorrect".
In all other cases, return "unknown".


DEFINITION
Class:BarongAndRangda
Method:compare
Parameters:int, int, int, int
Returns:string
Method signature:string compare(int B1, int R1, int B2, int R2)


NOTES
-All Barongs on both teams are identical copies of the same Barong and thus they all have the same strength: a positive real number b.
-The same is true about all the Rangdas: the strength of each Rangda is the same positive real number r.
-We don't know the exact values of b and r, we only know that b > r.
-The strength of a team is the sum of the strengths of individuals that form the team.


CONSTRAINTS
-B1 will be between 0 and 10^8, inclusive.
-R1 will be between 0 and 10^8, inclusive.
-B2 will be between 0 and 10^8, inclusive.
-R2 will be between 0 and 10^8, inclusive.


EXAMPLES

0)
1
0
0
1

Returns: "correct"

Team 1 has one Barong, team 2 has one Rangda. Team 1 is obviously stronger than team 2.


1)
0
1
1
0

Returns: "incorrect"

Team 1 has one Rangda, team 2 has one Barong. The statement "Team 1 is stronger than team 2." is obviously false.


2)
0
0
0
0

Returns: "incorrect"

Both teams are empty, and thus they have the exact same strength. Therefore the statement "Team 1 is stronger than team 2." is false.


3)
4
7
1
1

Returns: "correct"

A team with 4 Barongs and 7 Rangdas is clearly stronger than a team with just one being of each type.


4)
9
0
0
10

Returns: "unknown"

Are 9 Barongs stronger than 10 Rangdas? We don't know: it's possible that they are, but it's also possible that they aren't.

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


class BarongAndRangda {
public:
	string compare(int B1, int R1, int B2, int R2) {
		if (B1 + R1 >= B2 + R2) {
			if (B1 > B2 && (R1 + B1 - B2) >= R2) {
				return "correct";
			}
			if (B1 >= B2 && R1 > R2) {
				return "correct";
			}
		}
		if (B1 + R1 == B2 + R2) {
			if (B1 > B2) {
				return "correct";
			} else {
				return "incorrect";
			}
		}
		if (B1 < B2 && R1 <= (R2 + B2 - B1)) {
			return "incorrect";
		}
		if (B1 <= B2 && R1 < R2) {
			return "incorrect";
		}
		return "unknown";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 1;
			string Arg4 = "correct";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 0;
			string Arg4 = "incorrect";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 0;
			string Arg4 = "incorrect";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 7;
			int Arg2 = 1;
			int Arg3 = 1;
			string Arg4 = "correct";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 10;
			string Arg4 = "unknown";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;




		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 3;
			int Arg2 = 10;
			int Arg3 = 2;
			string Arg4 = "incorrect";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 0;
			int Arg1 = 8;
			int Arg2 = 9;
			int Arg3 = 1;
			string Arg4 = "incorrect";

			verify_case(n, Arg4, compare(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BarongAndRangda ___test;
	___test.run_test(-1);
}
// END CUT HERE
