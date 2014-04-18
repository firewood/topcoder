// BEGIN CUT HERE
/*
SRM 609 Div1 Easy (250)

PROBLEM STATEMENT
Magical Girl Illy uses "magical strings" to cast spells.
For her, a string X is magical if and only if there exists a non-negative integer k such that X is composed of k consecutive '>' characters followed by k consecutive '<' characters.
Note that the empty string is also magical (for k=0).

Once Illy picked up a string S.
Each character of S was either '<' or '>'.
Illy can change S by removing some of its characters.
(The characters she does not remove will remain in their original order.)
Illy wants to change S into a magical string by removing as few of its characters as possible.

You are given the string S.
Compute and return the length of the magical string Illy will obtain from S.


DEFINITION
Class:MagicalStringDiv1
Method:getLongest
Parameters:string
Returns:int
Method signature:int getLongest(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character of S will be '<' or '>'.


EXAMPLES

0)
"<><><<>"

Returns: 4

The longest magical string Illy can produce is ">><<".
Its length is 4.
To change S into ">><<", Illy must remove the characters at 0-based indices 0, 2, and 6.


1)
">>><<<"

Returns: 6

S is already a magical string. Therefore Illy doesn't have to remove any character.


2)
"<<<>>>"

Returns: 0

Illy has to remove all characters of S.


3)
"<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"

Returns: 24

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MagicalStringDiv1 {
public:
	int getLongest(string S) {
		int N = S.length();
		int ans = 0;
		for (int i = 1; i < N; ++i) {
			int a = count_if(S.begin(), S.begin() + i, [](char c){ return c == '>'; });
			int b = count_if(S.begin() + i, S.end(), [](char c){ return c == '<'; });
			ans = max(ans, min(a, b)*2);
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
			string Arg0 = "<><><<>";
			int Arg1 = 4;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ">>><<<";
			int Arg1 = 6;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<<<>>>";
			int Arg1 = 0;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>";
			int Arg1 = 24;

			verify_case(n, Arg1, getLongest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalStringDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
