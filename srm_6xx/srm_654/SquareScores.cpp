// BEGIN CUT HERE
/*
SRM 654 Div1 Easy (250)

PROBLEM STATEMENT
A substring of a string is a contiguous sequence of characters from the string.
For example, each of the strings "ab", "bcd", and "e" is a substring of "abcde". 
On the other hand, "cba", "ace", and "f" are not substrings of "abcde".

The score of a string S is the number of ways in which we can select a non-empty substring of S such that all characters in the substring are the same.
If two substrings consist of the same letters but occur at different places in S, they are still considered different.
For example, the score of "aaaba" is 8: there are four occurrences of the substring "a", two occurrences of "aa", one occurrence of "aaa", and one of "b".

On her birthday, Maki got a string s from her friend Niko as a present.
Each character in this string is either a lowercase letter or a question mark ('?').

Maki is going to randomly change each question mark into a letter.
For each question mark and each i, the probability that she changes it into the (i+1)-st letter of the alphabet is p[i] percent.
(I.e., she will change it into an 'a' with probability p[0]/100, into a 'b' with probability p[1]/100, and so on.)
The choices for different question marks are mutually independent.

You are given the vector <int> p.
Note that p may have fewer than 26 elements.
In that case we assume that the missing probabilities are 0.

Calculate and return the expected score of the string after all the question marks are changed into letters.


DEFINITION
Class:SquareScores
Method:calcexpectation
Parameters:vector <int>, string
Returns:double
Method signature:double calcexpectation(vector <int> p, string s)


NOTES
-The solution is correct if the relative error or the absolute error is at most 1e-9.


CONSTRAINTS
-s will contain between 1 and 1,000 elements, inclusive.
-Each character in s will be '?' or a lowercase letter ('a'-'z').
-If a character in s is j'th lowercase letter(1-indexed), j will be between 1 and (the size of p), inclusive.
-p will contain between 1 and 26 characters, inclusive.
-Each element in p will be between 0 and 100, inclusive.
-The sum of all elements in p will be exactly 100.


EXAMPLES

0)
{1, 99}
"aaaba"

Returns: 8.0


1)
{10, 20, 70}
"aa?bbbb"

Returns: 15.0


2)
{10, 20, 30, 40}
"a??c?dc?b"

Returns: 11.117


3)
{25, 25, 21, 2, 2, 25}
"a??b???????ff??e"

Returns: 21.68512690712425


4)
{4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}
"??????????????????????????????"

Returns: 31.16931963781721


5)
{4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}
"makigotapresentfromniko"

Returns: 23.0

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class SquareScores {
	public:
	double calcexpectation(vector <int> p, string s) {
		long double ans = 0;
		for (LL c = 0; c < p.size(); ++c) {
			long double b[1024];
			long double dp[2][1024];
			for (LL i = 0; i < s.length(); ++i) {
				if (s[i] == '?') {
					b[i] = (long double)p[c] * 0.01;
				} else {
					b[i] = s[i] == ('a' + c);
				}
				dp[1][i] = b[i];
				ans += b[i];
			}
			for (LL n = 2; n <= s.length(); ++n) {
				for (LL i = n - 1; i < s.length(); ++i) {
					long double d = dp[(n - 1) % 2][i - 1] * b[i];
					dp[n % 2][i] = d;
					ans += d;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1.0e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 99};
			string Arg1 = "aaaba";
			double Arg2 = 8.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 70};
			string Arg1 = "aa?bbbb";
			double Arg2 = 15.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 30, 40};
			string Arg1 = "a??c?dc?b";
			double Arg2 = 11.117;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {25, 25, 21, 2, 2, 25};
			string Arg1 = "a??b???????ff??e";
			double Arg2 = 21.68512690712425;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4};
			string Arg1 = "??????????????????????????????";
			double Arg2 = 31.16931963781721;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3};
			string Arg1 = "makigotapresentfromniko";
			double Arg2 = 23.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, calcexpectation(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareScores ___test;
	___test.run_test(-1);
}
// END CUT HERE
