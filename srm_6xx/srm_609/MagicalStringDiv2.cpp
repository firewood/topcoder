// BEGIN CUT HERE
/*
SRM 609 Div2 Easy (250)

PROBLEM STATEMENT
Magical Girl Illy uses "magical strings" to cast spells.
For her, a string X is magical if and only if there exists a positive integer k such that X is composed of k consecutive '>' characters followed by k consecutive '<' characters.

Once Illy picked up a string S.
The length of S was even, and each character of S was either '<' or '>'.
Illy wants to change S into a magical string.
In each step, she can change a single '>' to a '<' or vice versa.
Compute and return the smallest number of steps in which she can change S into a magical string.


DEFINITION
Class:MagicalStringDiv2
Method:minimalMoves
Parameters:string
Returns:int
Method signature:int minimalMoves(string S)


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-S will contain even number of characters.
-Each character of S will be '<' or '>'.


EXAMPLES

0)
">><<><"

Returns: 2

She needs to change character 2 (0-based index) from '<' to '>', and character 4 from '>' to '<'.


1)
">>>><<<<"

Returns: 0

S is already a magical string, so no changes are needed.


2)
"<<>>"

Returns: 4


3)
"<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><"

Returns: 20

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MagicalStringDiv2 {
public:
	int minimalMoves(string S) {
		int ans = 0;
		int len = (int)S.length();
		for (int i = 0; i < len / 2; ++i) {
			ans += S[i] != '>';
		}
		for (int i = len / 2; i < len; ++i) {
			ans += S[i] != '<';
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
			string Arg0 = ">><<><";
			int Arg1 = 2;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ">>>><<<<";
			int Arg1 = 0;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<<>>";
			int Arg1 = 4;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><";
			int Arg1 = 20;

			verify_case(n, Arg1, minimalMoves(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalStringDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
