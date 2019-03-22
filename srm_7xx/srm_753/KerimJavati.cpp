// BEGIN CUT HERE
/*
SRM 753 Div2 Easy (250)

PROBLEM STATEMENT

Kerim Javati is one of the most careless coders in his university.
He never knows what to type, and he relies on his friends to tell him when he's wrong.
Here is how he types a letter of a command into the computer:

He types the letter 'a' and looks at his friend. If that is the right letter, the friend nods and Kerim moves on to typing the next letter.
If the friend shook his head, meaning that 'a' was not the correct letter, Kerim presses backspace to erase the 'a' and he types 'b' instead. Then, he looks at his friend again.
If 'b' wasn't correct either, he will press backspace to erase it and type 'c'. And so on, through the whole alphabet.


You are given the string text.
Determine the number of keystrokes Kerim will perform while typing this text.
Both letters and backspaces count as keystrokes.


DEFINITION
Class:KerimJavati
Method:howLong
Parameters:string
Returns:int
Method signature:int howLong(string text)


CONSTRAINTS
-Length of text will be between 1 and 50, inclusive.
-text will consist of lowercase English letters only ('a'-'z').


EXAMPLES

0)
"aaa"

Returns: 3

Kerim will simply press the letter 'a' three times and he will be done.


1)
"d"

Returns: 7

Kerim will make the following sequence of keystrokes: 'a', backspace, 'b', backspace, 'c', backspace, 'd'.
The total number of keystrokes is 7.


2)
"bad"

Returns: 11


3)
"topcoder"

Returns: 184


4)
"hajikerim"

Returns: 159

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class KerimJavati {
public:
	int howLong(string text) {
		int ans = 0;
		for (char c : text) {
			ans += (c - 'a') * 2 + 1;
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
			string Arg0 = "aaa";
			int Arg1 = 3;

			verify_case(n, Arg1, howLong(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "d";
			int Arg1 = 7;

			verify_case(n, Arg1, howLong(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bad";
			int Arg1 = 11;

			verify_case(n, Arg1, howLong(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			int Arg1 = 184;

			verify_case(n, Arg1, howLong(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "hajikerim";
			int Arg1 = 159;

			verify_case(n, Arg1, howLong(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KerimJavati ___test;
	___test.run_test(-1);
}
// END CUT HERE
