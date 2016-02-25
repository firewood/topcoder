// BEGIN CUT HERE
/*
SRM 682 Div2 Easy (250)

PROBLEM STATEMENT
For the purposes of this problem, a DNA sequence is a string consisting of the letters A, C, G, and T.

You have been hired by researchers at TopBiologist to help them with some programming tasks. The researchers have found a sequence of uppercase letters, which is given to you in the string sequence. They have asked you to write a program which find the length of the longest DNA sequence that is a substring of sequence.

A substring can be obtained from sequence by deleting some (possibly zero) characters from the beginning or end. For example, suppose sequence is the string "TOPBOATER". Then "TOP", "PBOA", "T", and "AT" are some examples of substrings of sequence. Of these examples, "T" and "AT" are DNA sequences. The answer to the problem would be 2 because "AT" is the longest such sequence and its length is 2.

Please find and return the length of the longest DNA sequence that is a substring of sequence.


DEFINITION
Class:DNASequence
Method:longestDNASequence
Parameters:string
Returns:int
Method signature:int longestDNASequence(string sequence)


CONSTRAINTS
-sequence will contain between 1 and 50 characters, inclusive.
-Each character of sequence will be an upper-case English letter ('A'-'Z').


EXAMPLES

0)
"TOPBOATER"

Returns: 2

This is the example from the problem statement.


1)
"SUSHI"

Returns: 0

None of the substrings of "SUSHI" are DNA sequences, so the answer is 0.


2)
"GATTACA"

Returns: 7


3)
"GOODLUCK"

Returns: 1


4)
"VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA"

Returns: 6

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DNASequence {
public:
	int longestDNASequence(string sequence) {
		char a[256] = {};
		a['A'] = a['C'] = a['G'] = a['T'] = 1;
		int ans = 0, cnt = 0;
		for (char c : sequence) {
			if (a[c]) {
				ans = max(ans, ++cnt);
			} else {
				cnt = 0;
			}
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
			string Arg0 = "TOPBOATER";
			int Arg1 = 2;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SUSHI";
			int Arg1 = 0;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GATTACA";
			int Arg1 = 7;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GOODLUCK";
			int Arg1 = 1;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA";
			int Arg1 = 6;

			verify_case(n, Arg1, longestDNASequence(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DNASequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
