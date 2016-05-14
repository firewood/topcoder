// BEGIN CUT HERE
/*
SRM 689 Div2 Easy (250)

PROBLEM STATEMENT
Each competitor on Topcoder must have a handle.
Sometimes, different people may choose handles that look too similar to each other.
For example, consider the handles "TOPCODER" and "T0PCODER".
These two handles are different: the second character in the first handle is the letter 'O' (big oh),
while the second character in the second handle is the digit '0' (zero).

In this problem, all handles are nonempty strings.
Each character in a handle must be a letter ('a'-'z', 'A'-'Z') or a digit ('0'-'9').
We will consider two groups of characters that look too similar to each other.
The first group are the characters 'O' (big oh) and '0' (zero) mentioned above.
The second group are the characters '1' (one), 'l' (lowercase ell), and 'I' (uppercase i).

Strings S and T are called similar if we can change S into T by repeatedly replacing a character by another character from the same group.

You are given the vector <string> handles.
Return "Similar handles found" if there is at least one pair of similar handles in handles.
Otherwise, return "Similar handles not found".
Note that the quotes are for clarity only and that the return value is case sensitive.


DEFINITION
Class:SimilarUserDetection
Method:haveSimilar
Parameters:vector <string>
Returns:string
Method signature:string haveSimilar(vector <string> handles)


CONSTRAINTS
-handles will contain between 2 and 50 elements, inclusive.
-Each element in handles will contain between 1 and 50 characters, inclusive.
-Each character in handles will be '0'-'9', 'a'-'z' or 'A'-'Z'.


EXAMPLES

0)
{"top", "coder", "TOPCODER", "TOPC0DER"}

Returns: "Similar handles found"

"TOPCODER" and "TOPC0DER" are similar.


1)
{"Topcoder", "topcoder", "t0pcoder", "topcOder"}

Returns: "Similar handles not found"

No two of these handles are similar. Note that case matters: the letter 'o' (lowercase oh) is not in the group with 'O' and '0'.


2)
{"same", "same", "same", "different"}

Returns: "Similar handles found"

Any two identical strings are similar.


3)
{"0123", "0I23", "0l23", "O123", "OI23", "Ol23"}

Returns: "Similar handles found"

These six handles are all similar to each other.


4)
{"i23", "123", "456", "789", "000", "o", "O"}

Returns: "Similar handles not found"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SimilarUserDetection {
public:
	string haveSimilar(vector <string> handles) {
		set<string> m;
		for (string h : handles) {
			for (int i = 0; i != h.length(); ++i) {
				if (h[i] == '0') h[i] = 'O';
				if (h[i] == '1') h[i] = 'I';
				if (h[i] == 'l') h[i] = 'I';
			}
			m.insert(h);
		}
		return handles.size() == m.size() ? "Similar handles not found" : "Similar handles found";
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
			string Arr0[] = {"top", "coder", "TOPCODER", "TOPC0DER"};
			string Arg1 = "Similar handles found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Topcoder", "topcoder", "t0pcoder", "topcOder"};
			string Arg1 = "Similar handles not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"same", "same", "same", "different"};
			string Arg1 = "Similar handles found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0123", "0I23", "0l23", "O123", "OI23", "Ol23"};
			string Arg1 = "Similar handles found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"i23", "123", "456", "789", "000", "o", "O"};
			string Arg1 = "Similar handles not found";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, haveSimilar(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SimilarUserDetection ___test;
	___test.run_test(-1);
}
// END CUT HERE
