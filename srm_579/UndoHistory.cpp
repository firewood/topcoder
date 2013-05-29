// BEGIN CUT HERE
/*
SRM 579 Div1 Easy (250)

// PROBLEM STATEMENT
// Bob is using a peculiar text editor to write a sequence of lines of text.
The editor consists of three parts: a results window, a text buffer and an undo history.
More details about the three parts follow.

The results window contains a sequence of strings: the lines of text you already wrote. Initially, the results window is empty.
The text buffer contains a string: the line you are writing at the moment. Initially, the string in the text buffer is empty.
The undo history contains a sequence of strings: all the past states of the text buffer. Initially, the undo history contains a single element: an empty string.


You are given a vector <string> lines.
Bob would like to print the contents of lines into the results window.
(At the end, the sequence of strings stored in the results window must be precisely equal to lines. Order of elements matters.)
Additionally, Bob would like to do so as quickly as possible.
He is able to take the following actions:


Bob may type a lowercase letter. The letter is appended to the text buffer. The new text buffer is then added as a new element of the undo history. (For example, if the text buffer currently contains "do", then pressing 'g' changes the text buffer to "dog" and then stores "dog" into the undo history.)
Bob may press Enter. When he does so, the current content of the text buffer is printed to the results window as a new line, after the lines that were printed earlier. The text buffer remains unmodified. (For example, if the text buffer contains "dog" and Bob presses Enter, "dog" will be appended to the results window, and the results buffer still contains "dog".)
Bob may use two mouse clicks to restore any entry from the undo history to the text buffer. This operation does not modify the undo history.


Return the minimum total number of button presses (keyboard and mouse) that Bob needs to print all the given lines into the results window.


DEFINITION
Class:UndoHistory
Method:minPresses
Parameters:vector <string>
Returns:int
Method signature:int minPresses(vector <string> lines)


CONSTRAINTS
-lines will contain between 1 and 50 elements, inclusive.
-Each element of lines will contain between 1 and 50 characters, inclusive.
-Each element of lines will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"tomorrow", "topcoder"}

Returns: 18


Type 't'. The text buffer now contains "t", and the undo history now contains "" and "t".
Type 'o'. The text buffer now contains "to", and the undo history now contains "", "t", and "to".
Using six more keypresses, type the letters in "morrow". The text buffer now contains "tomorrow" and the undo history contains all prefixes of "tomorrow". The results window is still empty.
Press Enter. The results window now contains one string: "tomorrow".
Click the mouse twice to restore "to" from undo history.
Using another six keypresses, type the letters in "pcoder".
Press Enter. The results window now contains "tomorrow" and "topcoder", in this order, and we are done.

The total number of button presses was 8 (typing "tomorrow") + 1 (Enter) + 2 (mouse) + 6 (typing "pcoder") + 1 (Enter) = 18.


1)
{"a","b"}

Returns: 6

After typing "a" and pressing enter, we need to restore the empty string (which is always present at the top of the undo buffer) before typing "b".


2)
{"a", "ab", "abac", "abacus" }

Returns: 10

There are times when it is not necessary to use the undo history at all.


3)
{"pyramid", "sphinx", "sphere", "python", "serpent"}

Returns: 39


4)
{"ba","a","a","b","ba"}


Returns: 13

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<string> StrSet;

class UndoHistory {
public:
	int minPresses(vector <string> lines) {
		StrSet h;
		h.insert("");
		int sz = (int)lines.size();

		string cur;
		int ans = 0;
		int i, j, k, l;
		for (i = 0; i < sz; ++i) {
			string &s = lines[i];
			l = (int)s.length();

			size_t types = 1000000000;
			if (cur.compare(s.substr(0, cur.length())) == 0) {
				// prefix matched with current string
				types = l - cur.length();
			}

			// search from history
			for (j = l; j >= 0; --j) {
				string r = s.substr(0, j);
				if (h.find(r) != h.end()) {
					// found from history
					size_t t = l - r.length();
					if (types >= (t+2)) {
						// paste from history
						ans += 2;
						cur = r;
					}
					break;
				}
			}

			// type remain characters
			for (k = (int)cur.length(); k < l; ++k) {
				cur += s[k];
				h.insert(cur);
				++ans;
			}
			// enter
			++ans;
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
			string Arr0[] = {"tomorrow", "topcoder"};
			int Arg1 = 18;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a","b"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a", "ab", "abac", "abacus" };
			int Arg1 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
			int Arg1 = 39;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ba","a","a","b","ba"}
;
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaaabbbb","aaaa","aaaabbbb"}
;
			int Arg1 = 15;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcde","a","abdef"}
;
			int Arg1 = 14;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UndoHistory ___test;
	___test.run_test(-1);
}
// END CUT HERE
