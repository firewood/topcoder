// BEGIN CUT HERE
/*
SRM 698 Div1 Easy (250)

PROBLEM STATEMENT
A string S is called a square if there is some string T such that S = T + T.
For example, the strings "", aabaab" and "xxxx" are squares, but "a", "aabb" and "aabbaa" are not.

You are given a string s.
You want to change s into a square.
You may do the following operations:

Insert a new character anywhere into the string (including its beginning and end).
Remove a single character.
Replace a single character by another character.

Please compute and return the smallest number of operations needed to change the given s into a square.
Note that this is always possible: for example, you can remove all characters (one at a time).


DEFINITION
Class:RepeatString
Method:minimalModify
Parameters:string
Returns:int
Method signature:int minimalModify(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"aba"

Returns: 1

One of the optimal solutions is to remove the 'b'.
This changes the given s into the square "aa".


1)
"adam"

Returns: 1

Here, one optimal solution is to change the 'm' to 'd' to get "adad".


2)
"x"

Returns: 1

This time one optimal solution is to append another 'x' to get "xx".


3)
"aaabbbaaaccc"

Returns: 3

For example, we can change this string into "aaabbbaaabbb". Note that this requires three operations, not one.


4)
"repeatstring"

Returns: 6


5)
"aaaaaaaaaaaaaaaaaaaa"

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class RepeatString {

	int edit_distance(string a, string b) {
		int la = (int)a.length(), lb = (int)b.length();
		int dp[64][64];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i <= la; i++) dp[i][0] = i;
		for (int i = 0; i <= lb; i++) dp[0][i] = i;
		for (int i = 1; i <= la; i++) {
			for (int j = 1; j <= lb; j++) {
				dp[i][j] = min({ dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]) });
			}
		}
		return dp[la][lb];
	}

public:
	int minimalModify(string s) {
		int N = (int)s.length();
		int ans = N;
		for (int i = 1; i < N; ++i) {
			string a = s.substr(0, i);
			string b = s.substr(i);
			ans = min(ans, edit_distance(a, b));
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
			string Arg0 = "aba";
			int Arg1 = 1;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "adam";
			int Arg1 = 1;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "x";
			int Arg1 = 1;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaabbbaaaccc";
			int Arg1 = 3;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "repeatstring";
			int Arg1 = 6;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaaaaaaaaaaaaaaaaa";
			int Arg1 = 0;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "abcdefghijklmnopqrstuvwxy";
			int Arg1 = 13;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "eefxzefxzb";
			int Arg1 = 2;

			verify_case(n, Arg1, minimalModify(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RepeatString ___test;
	___test.run_test(-1);


	for (int t = 0; t < 1000; ++t) {
		int N = (rand() % 10) + 1;
		string a;
		for (int i = 0; i < N; ++i) {
			char c = (rand() % 26) + 'a';
			a += c;
		}
		string s = a;
		int x = rand() % 10;
		for (int r = 0; r < x; ++r) {
			int len = (int)a.length();
			int pos = rand() % len;
			char c = (rand() % 26) + 'a';
			switch (r % 3) {
			case 0:
				{
					string b = a.substr(0, pos);
					b += c;
					b += a.substr(pos);
					a = b;
				}
				break;
			case 1:
				{
					string b = a.substr(0, pos);
					b += a.substr(pos + 1);
					a = b;
				}
				break;
			case 2:
				a[pos] = c;
				break;
			}
		}
		int z = ___test.minimalModify(a + s);
		if (z > x) {
			cout << "ERROR: " << a << "," << s << "," << x << "," << z << endl;
			break;
		}
	}
}
// END CUT HERE
