// BEGIN CUT HERE
/*
SRM 610 Div1 Easy (250)
SRM 610 Div1 Medium (500)

PROBLEM STATEMENT
A rotation of a string S is the operation of moving its first character to the end.
For example, if we rotate the string "abcde" we get the string "bcdea".

A cyclic shift of a string S is any string that can be obtained from S by a sequence of zero or more rotations.
For example, the strings "abcde", "cdeab", and "eabcd" are some of the cyclic shifts of the string "abcde".

Given two equally long strings, the smaller one is the one with a smaller character at the first index where they differ.
For example, "cable" < "cards" because 'b' < 'r'.

You are given a string s of lowercase letters and an int k.
You are allowed to change at most k letters of s into some other lowercase letters.
Your goal is to create a string that will have the smallest possible cyclic shift.
Compute and return that cyclic shift.

DEFINITION
Class:Cyclemin
Method:bestmod
Parameters:string, int
Returns:string
Method signature:string bestmod(string s, int k)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be between 'a' and 'z', inclusive.
-k will be between 0 and the length of s, inclusive.


EXAMPLES

0)
"aba"
1

Returns: "aaa"

We are allowed to change at most 1 character. Clearly, the optimal change is to change the 'b' into an 'a'.

1)
"aba"
0

Returns: "aab"

We are not allowed to change anything. In this case, the answer is the smallest cyclic shift of the given string s.

2)
"bbb"
2

Returns: "aab"



3)
"sgsgaw"
1

Returns: "aasgsg"

The optimal solution is to change the 'w' into an 'a', and then to take the cyclic shift that starts with the last two letters of s.

4)
"abacaba"
1

Returns: "aaaabac"



5)
"isgbiao"
2

Returns: "aaaisgb"



*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Cyclemin {
public:
	string bestmod(string s, int k) {
		string ans = s;
		int len = (int)s.length();
		for (int i = 0; i < len; ++i) {
			string a = s.substr(i, len - i) + s.substr(0, i);
			int cnt = 0;
			for (int j = 0; cnt < k && j < len; ++j) {
				if (a[j] != 'a') {
					a[j] = 'a';
					++cnt;
				}
			}
			ans = min(ans, a);
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
			string Arg0 = "aba";
			int Arg1 = 1;
			string Arg2 = "aaa";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			int Arg1 = 0;
			string Arg2 = "aab";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbb";
			int Arg1 = 2;
			string Arg2 = "aab";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "sgsgaw";
			int Arg1 = 1;
			string Arg2 = "aasgsg";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 1;
			string Arg2 = "aaaabac";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "isgbiao";
			int Arg1 = 2;
			string Arg2 = "aaaisgb";

			verify_case(n, Arg2, bestmod(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cyclemin ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
