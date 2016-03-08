// BEGIN CUT HERE
/*
SRM 684 Div2 Easy (250)

PROBLEM STATEMENT
Hero came up with an interesting way to calculate the value of any string.
It works as follows:

Find all distinct characters that appear in the string.
For each of those characters, count the number of occurrences.
Square each of those counts.
Sum all those squares to get the value of the string.


For example, suppose Hero has the string "abacaba".
This string contains 4 'a's, 2 'b's, and 1 'c'.
Thus, its value is 4*4 + 2*2 + 1*1 = 21.

You are given a string s and an int k.
You are allowed to remove at most k characters from s.
Your goal is to produce a string with the smallest possible value.
Compute and return that value.


DEFINITION
Class:Istr
Method:count
Parameters:string, int
Returns:int
Method signature:int count(string s, int k)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character in s will be a lowercase letter ('a'-'z').
-k will be between 0 and the length of s, inclusive.


EXAMPLES

0)
"aba"
1

Returns: 2

The optimal strategy is to erase one of the two 'a's.
This produces a string with value 1*1 + 1*1 = 2.


1)
"abacaba"
0

Returns: 21


2)
"abacaba"
1

Returns: 14


3)
"abacaba"
3

Returns: 6


4)
"abc"
3

Returns: 0


5)
"wersrsresesrsesrawsdsw"
11

Returns: 23

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Istr {
public:
	int count(string s, int k) {
		int cnt[256] = {};
		for (char c : s) {
			cnt[c] += 1;
		}
		for (int i = 0; i < k; ++i) {
			sort(cnt, cnt + 256);
			cnt[255] = max(0, cnt[255] - 1);
		}
		int ans = 0;
		for (int i = 0; i < 256; ++i) {
			ans += cnt[i] * cnt[i];
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
			int Arg2 = 2;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 0;
			int Arg2 = 21;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 1;
			int Arg2 = 14;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			int Arg1 = 3;
			int Arg2 = 6;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wersrsresesrsesrawsdsw";
			int Arg1 = 11;
			int Arg2 = 23;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Istr ___test;
	___test.run_test(-1);
}
// END CUT HERE
