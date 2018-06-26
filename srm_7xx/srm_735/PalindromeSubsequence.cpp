// BEGIN CUT HERE
/*
SRM 735 Div1 Easy (250)

PROBLEM STATEMENT

A palindrome is a string that is identical to its reverse. For example, "a", "abba", "aaaaa", and "abbabba" are all palindromes.

A subsequence of a string s is any string of the form s[i1]s[i2]...s[ik] such that the sequence of indices is strictly increasing.
(Formally, 0 <= i1 < i2 ... < ik <= |s|-1.)

For example, the strings "", "b", "ace", and "abcde" are all subsequences of the string "abcde", but the strings "bb" and "cba" are not subsequences of "abcde".

A partition of a string s is a set of subsequences that is constructed in such a way that each index into s is used for exactly one of the subsequences.

For example, let s = "aaabb". Then:

{"aaabb"} is a valid partition of s.
{"ab", "aab"} is a valid partition of s.
{"a", "b", "a", "b", "a"} is a valid partition of s.
{"ab", "abb"} is not a valid partition of s because you would have to use some 'b' multiple times.
{"ba", "aab"} is not a valid partition of s because "ba" is not a subsequence of s.
{"a", "a", "b", "b"} is not a valid partition of s because some letter of s remained unused.

The size of a partition is the number of strings it contains. For example, the size of {"aaabb"} is 1, the size of {"ab", "aab"} is 2, and the size of {"a", "ab", "ab"} is 3.

You are given a string s.
Each character in s is either 'a' or 'b'.
Find a partition of s such that:

Each string in the partition is a palindrome.
The size of the partition is as small as possible.

Suppose that you found a solution that uses k subsequences.
Number those subsequences from 1 to k in any order.
Return a vector <int> with |s| elements.
For each valid i, element i of your return value should be the number of the subsequence that contains the character at index i in the string s.
(See the examples for a clarification.)

If there are multiple optimal solutions, you may return any of them.


DEFINITION
Class:PalindromeSubsequence
Method:optimalPartition
Parameters:string
Returns:vector <int>
Method signature:vector <int> optimalPartition(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Every character of s will be either 'a' or 'b'.


EXAMPLES

0)
"bababba"

Returns: {1, 2, 2, 1, 2, 1, 2 }

Here, it is obvious that there is no valid partition of size 1.
There are multiple valid partitions of size 2.
The sample output describes one of them, as follows:

      string s = b a b a b b a
  return value = 1 2 2 1 2 1 2
------------------------------
 subsequence 1 = b     a   b
 subsequence 2 =   a b   b   a
 
In other words, we partitioned the string "bababba" into {"bab", "abba"}.
Both "bab" and "abba" are palindromes, so this is a valid solution.


1)
"abba"

Returns: {1, 1, 1, 1 }

Here the input is already palindrome, thus the optimum is 1.


2)
"b"

Returns: {1 }


3)
"babb"

Returns: {1, 1, 1, 2 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PalindromeSubsequence {
public:
	vector <int> optimalPartition(string s) {
		int n = (int)s.length();
		vector <int> ans(n, 1);
		string r = s;
		reverse(r.begin(), r.end());
		if (r != s) {
			for (int i = 0; i < n; ++i) {
				ans[i] = s[i] - 'a' + 1;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bababba";
			int Arr1[] = {1, 2, 2, 1, 2, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abba";
			int Arr1[] = {1, 1, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "b";
			int Arr1[] = {1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "babb";
			int Arr1[] = {1, 1, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromeSubsequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
