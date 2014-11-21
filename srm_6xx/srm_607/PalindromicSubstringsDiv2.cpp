// BEGIN CUT HERE
/*
SRM 607 Div2 Medium (500)

PROBLEM STATEMENT
Marco recently learned about palindromic strings.
A palindromic string is a string that reads the same forwards and backwards.
For example, "radar" and "racecar" are palindromic strings.

Now Marco is excited about palindromic strings.
In particular, he likes strings that have a lot of palindromic substrings.
For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.

Right now, Marco has a string S composed of lowercase letters.
You are to reconstruct S from the given vector <string>s S1 and S2 as follows:

Concatenate in order all elements of S1 to make a string A.
Concatenate in order all elements of S2 to make a string B.
Finally, concatenate A and B to get S.

Return the number of palindromic substrings in S.


DEFINITION
Class:PalindromicSubstringsDiv2
Method:count
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int count(vector <string> S1, vector <string> S2)


CONSTRAINTS
-S1 and S2 will each contain no more than 50 elements.
-Each element of S1 and S2 will contain no more than 50 characters.
-S will contain at least 1 character.
-S will contain only lowercase letters ('a' - 'z').


EXAMPLES

0)
{"a","a",""}
{"a"}

Returns: 6

This is the example given in the statement, "aaa".


1)
{"zaz"}
{}

Returns: 4


2)
{"top"}
{"coder"}

Returns: 8


3)
{}
{"daata"}

Returns: 7

There are five palindromic substrings of length 1, one of length 2 ("aa" starting at index 1), and one of length 3 ("ata" starting at index 2).

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PalindromicSubstringsDiv2 {
public:
	int count(vector <string> S1, vector <string> S2) {
		string S = accumulate(S2.begin(), S2.end(), accumulate(S1.begin(), S1.end(), string()));
		int len = (int)S.length();
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			for (int j = 0; (i - j) >= 0 && (i + j) < len; ++j) {
				if (S[i - j] != S[i + j]) {
					break;
				}
				++ans;
			}
			for (int j = 0; (i - j) >= 0 && (i + j + 1) < len; ++j) {
				if (S[i - j] != S[i + j + 1]) {
					break;
				}
				++ans;
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
			string Arr0[] = {"a","a",""};
			string Arr1[] = {"a"};
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"zaz"};
			// string Arr1[] = {};
			int Arg2 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"top"};
			string Arr1[] = {"coder"};
			int Arg2 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			// string Arr0[] = {};
			string Arr1[] = {"daata"};
			int Arg2 = 7;

			vector <string> Arg0;
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromicSubstringsDiv2 ___test;
	___test.run_test(-1);

}
// END CUT HERE
