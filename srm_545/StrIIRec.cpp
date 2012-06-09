// BEGIN CUT HERE
/*
// SRM 545 Div1 Easy (275)

// PROBLEM STATEMENT
// For a given string S of length n an inversion is a pair of integers (i, j)
such that 0 <= i < j <= n-1 and S[i] > S[j]. (That is, the character at
0-based index i is greater than the character at 0-based index j.) For example,
the string "abcab" has 3 inversions: (1, 3), (2, 3), and (2, 4).

Given are ints n and minInv, and a string minStr.
We will consider all strings that are permutations of the first n lowercase English letters.
That is, these strings have length n and contain each of the first n letters exactly once.
Out of these strings, return the lexicographically smallest string R with the following two properties:

The number of inversions in R is at least minInv.
The string R is not lexicographically smaller than minStr.

If there is no such string, return an empty string instead.


DEFINITION
Class:StrIIRec
Method:recovstr
Parameters:int, int, string
Returns:string
Method signature:string recovstr(int n, int minInv, string minStr)


NOTES
-A string A is lexicographically smaller than a string B if A is a prefix of
 B or A contains a smaller character at the first position where the strings differ.


CONSTRAINTS
-n will be between 1 and 20, inclusive.
-minInv will be between 0 and n*(n-1)/2, inclusive.
-minStr will contain between 1 and n characters, inclusive.
-Each character in minStr will be one of the first n lowercase Latin letters.
-All characters in minStr will be unique.


EXAMPLES

0)
2
1
"ab"

Returns: "ba"

You must find the lexicographically smallest string that has at least 1 inversion and is not lexicographically smaller than "ab".


1)
9
1
"efcdgab"

Returns: "efcdgabhi"


2)
11
55
"debgikjfc"

Returns: "kjihgfedcba"

"kjihgfedcba" is the only string that has at least 55 inversions.


3)
15
0
"e"

Returns: "eabcdfghijklmno"


4)
9
20
"fcdebiha"

Returns: "fcdehigba"

*/
// END CUT HERE
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;

class StrIIRec {

	int N;
	int MinInv;
	int MaxChar;
	char work[32];

	int calc() {
		int c = 0;
		int i, j;
		for (i = 0; i < N; ++i) {
			for (j = i+1; j < N; ++j) {
				c += work[i] > work[j];
			}
		}
		return c;
	}

	string solve(int fixed_length) {
		char fixed_chars[128] = {};
		int i, j, k, l;
		for (i = 0; i < fixed_length; ++i) {
			fixed_chars[work[i]] = 1;
		}
		for (i = fixed_length; i < N; ++i) {
			for (j = 'a'; j <= MaxChar; ++j) {
				if (fixed_chars[j]) {
					continue;
				}
				char used[128];
				memcpy(used, fixed_chars, sizeof(used));
				work[i] = j;
				used[j] = 1;
				for (k = i+1; k < N; ++k) {
					for (l = MaxChar; l >= 'a'; --l) {
						if (!used[l]) {
							break;
						}
					}
					work[k] = l;
					used[l] = 1;
				}
				int c = calc();
				if (c == MinInv) {
					return work;
				}
				if (c >= MinInv) {
					break;
				}
			}
			fixed_chars[j] = 1;
		}
		return work;
	}

public:
	string recovstr(int n, int minInv, string minStr) {
		N = n;
		MinInv = minInv;
		MaxChar = 'a' + n - 1;
		memset(work, 0, sizeof(work));
		strcpy(work, minStr.c_str());
		int MinLen = minStr.length();
		int i, j, k, l;
		for (i = MinLen; i > 0; --i) {
			for (j = minStr[i-1]; j <= MaxChar; ++j) {
				work[i-1] = j;
				char used[128] = {};
				for (l = 0; l < i; ++l) {
					used[work[l]] = 1;
				}
				for (k = i; k < n; ++k) {
					for (l = MaxChar; l >= 'a'; --l) {
						if (!used[l]) {
							break;
						}
					}
					work[k] = l;
					used[l] = 1;
				}
				int c = calc();
				if (c == minInv) {
					return work;
				}
				if (c >= minInv) {
					return solve(i);
				}
			}
		}
		return "";
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
			int Arg0 = 2;
			int Arg1 = 1;
			string Arg2 = "ab";
			string Arg3 = "ba";

			verify_case(n, Arg3, recovstr(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 1;
			string Arg2 = "efcdgab";
			string Arg3 = "efcdgabhi";

			verify_case(n, Arg3, recovstr(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 55;
			string Arg2 = "debgikjfc";
			string Arg3 = "kjihgfedcba";

			verify_case(n, Arg3, recovstr(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 0;
			string Arg2 = "e";
			string Arg3 = "eabcdfghijklmno";

			verify_case(n, Arg3, recovstr(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 20;
			string Arg2 = "fcdebiha";
			string Arg3 = "fcdehigba";

			verify_case(n, Arg3, recovstr(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StrIIRec ___test;
//	___test.run_test(1);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
