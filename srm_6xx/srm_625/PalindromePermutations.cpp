// BEGIN CUT HERE
/*
// SRM 625 Div1 Easy (250)

// PROBLEM STATEMENT
A palindrome is a word that reads the same forwards and backwards.
For example, "a", "abba", and "zzz" are palindromes, while "ab" and "xxxyx" are not.

The anagram of a string S is any string we can obtain from S by rearranging its letters.
For example, the string "haha" has exactly six anagrams: "aahh", "ahah", "ahha", "haah", "haha", and "hhaa".

We are given a string word. We will choose one of its anagrams uniformly at random.
Return the probability that the chosen anagram will be a palindrome.


DEFINITION
Class:PalindromePermutations
Method:palindromeProbability
Parameters:string
Returns:double
Method signature:double palindromeProbability(string word)


NOTES
-The returned value must have an absolute or a relative error of less than 1e-9.


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-Each character of word will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"haha"

Returns: 0.3333333333333333

Each of the six anagrams of "haha" will be selected with probability 1/6.
Two of them are palindromes: "ahha" and "haah".
Hence, the probability of selecting a palindrome is 2/6.


1)
"xxxxy"

Returns: 0.2


2)
"xxxx"

Returns: 1.0

This word only has one anagram: "xxxx". That is a palindrome.


3)
"abcde"

Returns: 0.0

Regardless of how we rearrange the letters of "abcde", we will never get a palindrome.


4)
"hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"

Returns: 0.025641025641025637

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PalindromePermutations {

public:
	double palindromeProbability(string word) {
		int f[64] = {};
		int cnt[256] = {};
		int len = (int)word.length();
		for (int i = 0; i < len; ++i) {
			cnt[word[i]] += 1;
		}
		for (int i = len / 2 + 1; i <= len; ++i) {
			f[i] += 1;
		}
		int odds = 0;
		for (int i = 0; i < 256; ++i) {
			odds += (cnt[i] % 2);
			if (odds > 1) {
				return 0.0;
			}
			for (int j = cnt[i] / 2 + 1; j <= cnt[i]; ++j) {
				f[j] -= 1;
			}
		}
		long double ans = 1.0;
		for (int i = 1; i <= len; ++i) {
			for (int j = 0; j > f[i]; --j) {
				ans *= i;
			}
			for (int j = 0; j < f[i]; ++j) {
				ans /= i;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "haha";
			double Arg1 = 0.3333333333333333;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xxxxy";
			double Arg1 = 0.2;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "xxxx";
			double Arg1 = 1.0;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abcde";
			double Arg1 = 0.0;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
			double Arg1 = 0.025641025641025637;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbbbbaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa";
			double Arg1 = 2.3562121533422868E-5;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbbbbccaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa";
			double Arg1 = 5.746858910590944E-7;

			verify_case(n, Arg1, palindromeProbability(Arg0));
		}
		n++;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromePermutations ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
