// BEGIN CUT HERE
/*
// SRM 563 Div1 Easy (250)

// PROBLEM STATEMENT
// We say that a string Z can be obtained by shuffling two strings X and Y together, if it is possible to interleave the letters of X and Y so that Z is obtained. It is not allowed to change the order of letters in X and Y.
For example, you can shuffle the strings X="abcd" and Y="efg" to produce any of the strings "abcdefg", "aebfcgd", "abcefgd", or "eabcfdg", but you cannot produce the string "bacdefg".

Formally, let Shuffle(X,Y) be the set of all strings that can be produced by shuffling X and Y together.
We can define Shuffle inductively as follows:

for any string X: Shuffle("",X) = Shuffle(X,"") = { X }
for any letters a, b and any strings X, Y:
Shuffle(aX,bY) = { aZ : Z belongs to Shuffle(X,bY) } united with { bZ : Z belongs to Shuffle(aX,Y) }.

Fox Ciel wants to register on TopCoder.
In order to do that, she has to pick a handle.
Ciel has a pet cat called S.
As her handle, Ciel wants to use a string H with the following property:
S can be obtained by shuffling H and some permutation of H together.
For example, if S="ceiiclel", one possible handle would be H="ciel":
she can permute H to obtain H'="eicl", and then shuffle these H and H' together to produce S.

You are given the string S.
The constraints guarantee that there is at least one possible handle H with the above property.
Find and return the lexicographically smallest valid H.


DEFINITION
Class:FoxAndHandle
Method:lexSmallestName
Parameters:string
Returns:string
Method signature:string lexSmallestName(string S)


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').
-Each letter ('a'-'z') will occur in S an even number of times.


EXAMPLES

0)
"foxfox"

Returns: "fox"

There are five possible handles for Fox Ciel in this test case: "fox", "fxo", "ofx", "oxf", and "xfo".
The lexicographically smallest one is "fox".


1)
"ccieliel"

Returns: "ceil"

Note that "ciel" is also a valid handle, but "ceil" is lexicographically smaller.


2)
"abaabbab"

Returns: "aabb"


3)
"bbbbaaaa"

Returns: "bbaa"


4)
"fedcbafedcba"

Returns: "afedcb"


5)
"nodevillivedon"

Returns: "deilvon"

*/
// END CUT HERE
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef map<int, int> IntMap;

class FoxAndHandle {

	bool check(IntMap &s, IntMap &m) {
		IntMap::const_iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			if (it->second > m[it->first]) {
				return false;
			}
		}
		return true;
	}

public:
	string lexSmallestName(string S) {
		IntMap m[51];
		int len = (int)S.length();
		int i, j;
		for (i = len-1; i >= 0; --i) {
			m[i] = m[i+1];
			m[i][S[i]] += 1;
		}
		IntMap s = m[0];
		IntMap::iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			it->second /= 2;
		}
		string ans;
		i = 0;
		while ((int)ans.length() < len/2) {
			char c;
			for (c = 'a'; c <= 'z'; ++c) {
				if (s[c] <= 0) continue;
				j = (int)S.find(c, i);		// j >= 0
				if (check(s, m[j])) {
					ans += c;
					s[c] -= 1;
					i = j+1;
					break;
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
			string Arg0 = "foxfox";
			string Arg1 = "fox";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ccieliel";
			string Arg1 = "ceil";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abaabbab";
			string Arg1 = "aabb";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbbaaaa";
			string Arg1 = "bbaa";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fedcbafedcba";
			string Arg1 = "afedcb";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "nodevillivedon";
			string Arg1 = "deilvon";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "bkbkaajaajkkmfmfliffajaelhihlihajaeohggholihoggo";
			string Arg1 = "baaaajkkfmfehhlihjgglioo";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndHandle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
