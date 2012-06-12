// BEGIN CUT HERE
/*
// SRM 525 Div1 Hard (950)

// PROBLEM STATEMENT
// You are going to fill 9 strings into the cells of a 3x3 square. Rows of the
square are numbered 0 to 2 from top to bottom, and columns of the square are
numbered 0 to 2 from left to right. Let S[i][j] be the string you'll enter
into the cell in row i, column j. The strings S[i][j] do not have to be
distinct. It is also allowed to use empty strings.

You are given two vector <string>s rowStrings and columnStrings. For each i,
the concatenation of strings in row i must be equal to rowStrings[i]. The same
must hold for columns and columnStrings. Formally, the strings in the cells
must satisfy the following conditions:

For all 0<=i<=2, S[i][0]+S[i][1]+S[i][2] = rowStrings[i].
For all 0<=j<=2, S[0][j]+S[1][j]+S[2][j] = columnStrings[j].

Here, '+' represents a string concatenation.

Return the number of ways in which the strings S[i][j] can be chosen so that
all conditions are satisfied.

DEFINITION
Class:MagicalSquare
Method:getCount
Parameters:vector <string>, vector <string>
Returns:long long
Method signature:long long getCount(vector <string> rowStrings, vector <string> columnStrings)


CONSTRAINTS
-rowStrings and columnStrings will each contain exactly 3 elements.
-Each element of rowStrings will contain between 0 and 50 characters, inclusive.
-Each element of columnStrings will contain between 0 and 50 characters, inclusive.
-rowStrings and columnStrings will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"f", "o", "x"}

{"f", "o", "x"}


Returns: 1

The only valid way to choose the strings:

 --- --- ---
| f |   |   |
 --- --- ---
|   | o |   |
 --- --- ---
|   |   | x |
 --- --- ---

That is, S[0][0]="f", S[1][1]="o", S[2][2]="x", and all other S[i][j] are empty.


1)
{"x", "x", "x"}
{"x", "", "xx"}

Returns: 3

These are the three valid possibilities:

 --- --- ---    --- --- ---    --- --- ---
| x |   |   |  |   |   | x |  |   |   | x |
 --- --- ---    --- --- ---    --- --- ---
|   |   | x |  | x |   |   |  |   |   | x |
 --- --- ---    --- --- ---    --- --- ---
|   |   | x |  |   |   | x |  | x |   |   |
 --- --- ---    --- --- ---    --- --- ---


2)
{"cd", "cd", "cd"}
{"dvd", "dvd", "dvd"}

Returns: 0

In this case there is no way to satisfy all conditions.


3)
{"abab", "ab", "abab"}
{"abab", "ab", "abab"}

Returns: 11


4)
{"qwer", "asdf", "zxcv"}
{"qaz", "wsx", "erdfcv"}

Returns: 1

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MagicalSquare {

public:
	long long getCount(vector <string> rowStrings, vector <string> columnStrings) {
		long long res = 0;
		int r00, r01, r10, r11;
		for (r00 = 0; r00 <= (int)rowStrings[0].length(); ++r00) {
			if (rowStrings[0].compare(0, r00, columnStrings[0], 0, r00) != 0) {
				break;
			}
			for (r01 = r00; r01 <= (int)rowStrings[0].length(); ++r01) {
				int l01 = r01 - r00;
				if (rowStrings[0].compare(r00, l01, columnStrings[1], 0, l01) != 0) {
					continue;
				}
				int l02 = (int)rowStrings[0].length() - r01;
				if (rowStrings[0].compare(r01, l02, columnStrings[2], 0, l02) != 0) {
					continue;
				}
				for (r10 = 0; r10 <= (int)rowStrings[1].length(); ++r10) {
					if (rowStrings[1].compare(0, r10, columnStrings[0], r00, r10) != 0) {
						break;
					}
					int l20 = (int)columnStrings[0].length() - r00 - r10;
					if (l20 < 0) {
						break;
					}
					if (rowStrings[2].compare(0, l20, columnStrings[0], r00+r10, l20) != 0) {
						continue;
					}
					for (r11 = r10; r11 <= (int)rowStrings[1].length(); ++r11) {
						int l11 = r11 - r10;
						if (rowStrings[1].compare(r10, l11, columnStrings[1], l01, l11) != 0) {
							continue;
						}
						int l12 = (int)rowStrings[1].length() - r11;
						if (rowStrings[1].compare(r11, l12, columnStrings[2], l02, l12) != 0) {
							continue;
						}
						int l21 = (int)columnStrings[1].length() - l01 - l11;
						if (l21 < 0) {
							continue;
						}
						if (rowStrings[2].compare(l20, l21, columnStrings[1], l01+l11, l21) != 0) {
							continue;
						}
						int l22 = (int)columnStrings[2].length() - l02 - l12;
						if (l22 < 0) {
							continue;
						}
						if (rowStrings[2].length() != l20+l21+l22) {
							continue;
						}
						if (columnStrings[2].length() != l02+l12+l22) {
							continue;
						}
						if (rowStrings[2].compare(l20+l21, l22, columnStrings[2], l02+l12, l22) != 0) {
							continue;
						}
						++res;
					}
				}
			}
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"f", "o", "x"}
;
			string Arr1[] = {"f", "o", "x"}
;
			long long Arg2 = 1LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"x", "x", "x"};
			string Arr1[] = {"x", "", "xx"};
			long long Arg2 = 3LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"cd", "cd", "cd"};
			string Arr1[] = {"dvd", "dvd", "dvd"};
			long long Arg2 = 0LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abab", "ab", "abab"};
			string Arr1[] = {"abab", "ab", "abab"};
			long long Arg2 = 11LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"qwer", "asdf", "zxcv"};
			string Arr1[] = {"qaz", "wsx", "erdfcv"};
			long long Arg2 = 1LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"xx", "xxx", "xx"};
			string Arr1[] = {"xx", "xx", "xx"};
			long long Arg2 = 0LL;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getCount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalSquare ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
