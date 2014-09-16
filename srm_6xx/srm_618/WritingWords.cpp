// BEGIN CUT HERE
/*
SRM 618 Div1 Easy (250)

PROBLEM STATEMENT
Fox Ciel wants to type a word on her old cell phone. The cell phone has only one button. The letter A is typed by tapping the button once, B by tapping it twice in a row, and so on, in alphabetical order. Thus, the last letter Z is typed by tapping the button 26 times without a pause.

You are given a string word. Compute and return the answer to the following question: How many times will Ciel tap the button while typing this word?

DEFINITION
Class:WritingWords
Method:write
Parameters:string
Returns:int
Method signature:int write(string word)


NOTES
-While typing a word, Ciel has to make a short pause after typing each letter, so that the phone can tell when one letter ends and another letter begins. These pauses do not matter in this problem.


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character in word will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"A"

Returns: 1

One tap types the letter A.


1)
"ABC"

Returns: 6

To type ABC, Ciel will do the following:

Tap the button once to type A.
Tap the button twice to type B.
Tap the button three times to type C.

The total number of taps is 1+2+3 = 6.


2)
"VAMOSGIMNASIA"

Returns: 143


3)
"TOPCODER"

Returns: 96


4)
"SINGLEROUNDMATCH"

Returns: 183


5)
"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"

Returns: 1300

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WritingWords {
public:
	int write(string word) {
		int ans = 0;
		for (char c : word) {
			ans += c - 'A' + 1;
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
			string Arg0 = "A";
			int Arg1 = 1;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABC";
			int Arg1 = 6;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "VAMOSGIMNASIA";
			int Arg1 = 143;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			int Arg1 = 96;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "SINGLEROUNDMATCH";
			int Arg1 = 183;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
			int Arg1 = 1300;

			verify_case(n, Arg1, write(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WritingWords ___test;
	___test.run_test(-1);
}
// END CUT HERE
