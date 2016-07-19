// BEGIN CUT HERE
/*
SRM 695 Div1 Easy (300)

PROBLEM STATEMENT
A substring of a string is any non-empty contiguous subsequence of its characters.
For example, both "abc" and "bcd" are substrings of "abcde", but "ace" is not a substring of "abcde".

A string is called constant if all of its characters are the same.
For example, "a" and "bbbbb" are constant strings, but "aba" is not a constant string.

Two substrings of the same string are considered distinct if they start or end at a different position.
For example, the string "ababab" contains three distinct copies of the substring "ab", and the string "aaaa" contains two distinct copies of the substring "aaa".

Bear Limak is creating a new account and he needs to choose a password.
His password should satisfy the following security requirements:

The password must be a string of length N.
Each character of the password must be either 'a' or 'b'.
For each i between 1 and N, inclusive, the password must contain exactly x[i-1] constant substrings of length i.


You are given the vector <int> x with N elements.
Help Limak: find and return a valid password!
If there are many valid passwords, return the lexicographically smallest of them.
If there are no valid passwords, return "" (i.e., an empty string).


DEFINITION
Class:BearPasswordLexic
Method:findPassword
Parameters:vector <int>
Returns:string
Method signature:string findPassword(vector <int> x)


NOTES
-N will be between 1 and 50, inclusive.
-x will contain exactly N elements.
-Each element in x will be between 0 and N, inclusive.


EXAMPLES

0)
{5,0,0,0,0}

Returns: "ababa"

Since the given vector <int> x has five elements, the password must contain exactly five characters.
A password must contain x[0] = 5 constant substrings of length 1, and 0 constant substrings of bigger lengths.
The only two valid passwords are "ababa" and "babab".
The first one is smaller lexicographically.


1)
{4,2,1,0}

Returns: "aaab"


2)
{3,1,1}

Returns: ""


3)
{4,3,2,1}

Returns: "aaaa"


4)
{0}

Returns: ""


5)
{4,0,3,2}

Returns: ""

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class BearPasswordLexic {
	int N;
	IntVec xx;
	int cnt[64];

	bool check(int pos, int r) {
		if (pos == 0) {
			cnt[0] = r;
			return r >= 0;
		}
		int c = 0;
		for (int i = pos + 1; i < N; ++i) {
			c += cnt[i] * (i - pos + 1);
		}
		int d = xx[pos] - c;
		if (d == 0) {
			return check(pos - 1, r);
		}
		if (d < 0) {
			return false;
		}
		int n = (pos + 1) * d;
		if (n > r) {
			return false;
		}
		cnt[pos] = d;
		return check(pos - 1, r - n);
	}

public:
	string findPassword(vector <int> x) {
		N = (int)x.size();
		if (x[0] != N) {
			return "";
		}
		xx = x;
		memset(cnt, 0, sizeof(cnt));
		string ans;
		if (check(N - 1, N)) {
			for (int i = N - 1; i >= 0; --i) {
				while (cnt[i] > 0) {
					char f = 'a';
					if (!ans.empty() && ans.back() == 'a') {
						int j;
						for (j = 0; j < i; ++j) {
							if (cnt[j]) {
								break;
							}
						}
						if (j < i) {
							--cnt[j];
							ans += string(j + 1, 'b');
						} else {
							f = 'b';
						}
					}
					--cnt[i];
					ans += string(i + 1, f);
				}
			}
		}
		return ans;
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
			int Arr0[] = {5,0,0,0,0};
			string Arg1 = "ababa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2,1,0};
			string Arg1 = "aaab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,1,1};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,3,2,1};
			string Arg1 = "aaaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,0,3,2};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 8,5,3,1,0,0,0,0 };
			string Arg1 = "aaaabaaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 10,6,4,2,1,0,0,0,0,0 };
			string Arg1 = "aaaaabaaab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 7,5,3,1,0,0,0 };
			string Arg1 = "aaaabbb";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			string Arg1 = "ababababababababababababababababababababababababab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			string Arg1 = "aababababababababababababababababababababababababa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			string Arg1 = "aabaababababababababababababababababababababababab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPasswordLexic ___test;
	___test.run_test(-1);
}
// END CUT HERE
