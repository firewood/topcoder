// BEGIN CUT HERE
/*
SRM 630 Div2 Hard (1000)

PROBLEM STATEMENT
Suffix number i of a string S is the suffix that starts with the character S[i].
For example, for S="abcde" suffix 0 is "abcde" and suffix 3 is "de". 

The suffix array of a string S is defined as the permutation of suffix numbers that corresponds to their lexicographic order.
For example, suppose that S="abca".
If we order all suffixes of S lexicographically, we get the following: "a" < "abca" < "bca" < "ca".
The corresponding suffix numbers are 3, 0, 1, and 2, in this order.
Thus, for this string S the suffix array would be {3, 0, 1, 2}.
Note that the length of a suffix array is the same as the length of the original string.

In this problem, we will only consider strings of lowercase English letters ('a'-'z').
You are given a string s.
We are interested in a string t that is lexicographically smaller than s but has exactly the same suffix array.
Return "Exists" if at least one such string t exists, and "Does not exist" otherwise.


DEFINITION
Class:SuffixArrayDiv2
Method:smallerOne
Parameters:string
Returns:string
Method signature:string smallerOne(string s)


NOTES
-Given two different strings A and B of the same length, A is lexicographically smaller than B if we have A[i] < B[i] for the smallest i such that A[i] and B[i] differ.


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element in s will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"abca"

Returns: "Exists"

For example, "aaqa" < "abca" but their suffix arrays are the same.


1)
"bbbb"

Returns: "Exists"

Obviously, one of the strings smaller than "bbbb" with the same suffix array is "aaaa".


2)
"aaaa"

Returns: "Does not exist"

The string "aaaa" is already the lexicographically smallest 4-letter string.


3)
"examplesareveryweakthinktwicebeforesubmit"

Returns: "Exists"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SuffixArrayDiv2 {

	vector<int> calc(string &s) {
		vector<pair<string, int> >v;
		for (int i = 0; i < (int)s.length(); ++i) {
			v.push_back(make_pair(s.substr(i), i));
		}
		sort(v.begin(), v.end());
		vector<int> r;
		for (int i = 0; i < (int)v.size(); ++i) {
			r.push_back(v[i].second);
		}
		return r;
	}

public:
	string smallerOne(string s) {
		vector<int> a = calc(s);
		for (int i = 0; i < (int)s.length(); ++i) {
			string t = s;
			if (t[i] > 'a') {
				t[i] -= 1;
				vector<int> b = calc(t);
				if (a == b) {
					return "Exists";
				}
			}
		}
		return "Does not exist";
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
			string Arg0 = "abca";
			string Arg1 = "Exists";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbb";
			string Arg1 = "Exists";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaa";
			string Arg1 = "Does not exist";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "examplesareveryweakthinktwicebeforesubmit";
			string Arg1 = "Exists";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SuffixArrayDiv2 ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
