// BEGIN CUT HERE
/*
SRM 607 Div1 Easy (250)

PROBLEM STATEMENT
Marco likes strings.
In particular, he likes strings that have a lot of palindromic substrings.
For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.

Right now, Marco has a string S composed of lowercase letters and question marks.
You are to reconstruct S from the given vector <string>s S1 and S2 as follows:

Concatenate all elements of S1 to make a string A.
Concatenate all elements of S2 to make a string B.
Finally, concatenate A and B to get S.

Marco is going to replace every question mark in S with a random lowercase letter ('a' - 'z').
Return the expected number of palindromic substrings in the resulting string.


DEFINITION
Class:PalindromicSubstringsDiv1
Method:expectedPalindromes
Parameters:vector <string>, vector <string>
Returns:double
Method signature:double expectedPalindromes(vector <string> S1, vector <string> S2)


NOTES
-For each question mark, the letter used to replace it is chosen uniformly at random. That is, the probability of choosing any particular letter is 1/26. All random choices are mutually independent.
-A palindromic string is a string that reads the same forwards and backwards.
-Your return value must have an absolute or a relative error of less than 1e-9.


CONSTRAINTS
-S1 and S2 will contain no more than 50 elements.
-Each element of S1 and S2 will contain no more than 50 characters.
-S will contain at least 1 character.
-S will contain only lowercase letters ('a' - 'z') and question marks ('?').


EXAMPLES

0)
{"a","a",""}
{"a"}

Returns: 6.0

This is the example given in the statement.


1)
{"z??"}
{}

Returns: 3.115384615384615

There are 26^2 = 676 equally likely possibilities for the letters used to replace the question marks.
Here are all possible outcomes:

The string "zzz" has 6 palindromic substrings.
Each of the 25 strings "zaz", "zbz", ..., "zyz" has 4 palindromic substrings.
Each of the 25 strings "zza", "zzb", ..., "zzy" has 4 palindromic substrings.
Each of the 25 strings "zaa", "zbb", ..., "zyy" has 4 palindromic substrings.
Each of the remaining 600 possible strings only has the 3 single-letter palindromic substrings.

The expected number of palindromic substrings can be computed simply as the average over all 676 possible cases.
Hence, the correct return value is (6 + 75*4 + 600*3) / 676.


2)
{"ab","c"}
{"??","a?"}

Returns: 7.315088757396449


3)
{}
{"?"}

Returns: 1.0


4)
{"ab?def","?"}
{"f??a"}

Returns: 12.545971779699588

*/
// END CUT HERE
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PalindromicSubstringsDiv1 {
public:
	double expectedPalindromes(vector <string> S1, vector <string> S2) {
		string S = accumulate(S2.begin(), S2.end(), accumulate(S1.begin(), S1.end(), string()));
		int len = (int)S.length();
		double ans = 0;
		for (int i = 0; i < len; ++i) {
			double p = 1.0;
			for (int j = 0; (i - j) >= 0 && (i + j) < len; ++j) {
				if (j > 0 && (S[i - j] == '?' || S[i + j] == '?')) {
					p *= (1.0 / 26.0);
				}
				else if (S[i - j] != S[i + j]) {
					p = 0;
				}
				ans += p;
			}
			p = 1.0;
			for (int j = 0; (i - j) >= 0 && (i + j + 1) < len; ++j) {
				if (S[i - j] == '?' || S[i + j + 1] == '?') {
					p *= (1.0 / 26.0);
				}
				else if (S[i - j] != S[i + j + 1]) {
					p = 0;
				}
				ans += p;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a","a",""};
			string Arr1[] = {"a"};
			double Arg2 = 6.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"z??"};
			// string Arr1[] = {};
			double Arg2 = 3.115384615384615;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab","c"};
			string Arr1[] = {"??","a?"};
			double Arg2 = 7.315088757396449;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			// string Arr0[] = {};
			string Arr1[] = {"?"};
			double Arg2 = 1.0;

			vector <string> Arg0;
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab?def","?"};
			string Arr1[] = {"f??a"};
			double Arg2 = 12.545971779699588;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromicSubstringsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
