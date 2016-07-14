// BEGIN CUT HERE

/*
TCO 2016 Round 1C Medium (500)

PROBLEM STATEMENT

This problem is about three programmers who work together on a project.
The programmers' names are Alice, Bob, and Charles.
We will use 'A', 'B', and 'C' to denote them.

Each day exactly one of the three programmers works on the project.
The code history is a string that specifies who worked on which day.
For example, the string "AAC" means that Alice worked on the project for two days in a row and then Charles worked for a day.

Alice is always able to work on the project.
Each time Bob spends a day working, he needs to take at least one day off before he is able to work again.
Each time Charles spends a day working, he needs to take at least two days off.

The above information means that not all strings are valid code histories.
For example, the string "BB" is not a valid code history because Bob cannot work two days in a row.

You are given a string code.
This may or may not be a valid code history.
Find any permutation of letters of code that produces a valid code history, and return that code history.
If there are multiple solutions, you may return any of them.
If there are no solutions, return "impossible" instead.


DEFINITION
Class:ThreeProgrammers
Method:validCodeHistory
Parameters:string
Returns:string
Method signature:string validCodeHistory(string code)


CONSTRAINTS
-code will contain between 1 and 50 characters, inclusive.
-Each character in code will be one of 'A', 'B', and 'C'.


EXAMPLES

0)
"CAB"

Returns: "BCA"

The input is a valid code history.
In fact, any permutation of this input is a valid code history, and you may return any of them.


1)
"CBB"

Returns: "BCB"

Bob cannot work on two consecutive days.
Hence, "BCB" is the only valid code history that is a permutation of the given input.


2)
"BB"

Returns: "impossible"


3)
"BBA"

Returns: "BAB"


4)
"CAC"

Returns: "impossible"


5)
"ACAC"

Returns: "CAAC"


6)
"ACABC"

Returns: "ACABC"


7)
"BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB"

Returns: "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ThreeProgrammers {

	int end_pos;
	char w[64];

	bool possible(int pos, int a, int b, int c) {
		int r = end_pos - pos;
		if (b > (r + 1) / 2) {
			return false;
		}
		if (c > (r + 2) / 3) {
			return false;
		}
		if (a > 0) {
			w[pos] = 'A';
			if (possible(pos + 1, a - 1, b, c)) {
				return true;
			}
		}
		if (b > 0 && w[pos - 1] != 'B') {
			w[pos] = 'B';
			if (possible(pos + 1, a, b - 1, c)) {
				return true;
			}
		}
		if (c > 0 && w[pos - 1] != 'C' && w[pos - 2] != 'C') {
			w[pos] = 'C';
			if (possible(pos + 1, a, b, c - 1)) {
				return true;
			}
		}
		return pos == end_pos;
	}

public:
	string validCodeHistory(string code) {
		end_pos = 2 + (int)code.length();
		memset(w, 0, sizeof(w));
		int cnt[256] = {};
		for (char c : code) {
			cnt[(int)c] += 1;
		}
		return possible(2, cnt['A'], cnt['B'], cnt['C']) ? (w + 2) : "impossible";
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
			string Arg0 = "CAB";
			string Arg1 = "BCA";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CBB";
			string Arg1 = "BCB";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BB";
			string Arg1 = "impossible";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BBA";
			string Arg1 = "BAB";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CAC";
			string Arg1 = "impossible";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACAC";
			string Arg1 = "CAAC";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACABC";
			string Arg1 = "ACABC";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB";
			string Arg1 = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreeProgrammers ___test;
	___test.run_test(-1);
}
// END CUT HERE
