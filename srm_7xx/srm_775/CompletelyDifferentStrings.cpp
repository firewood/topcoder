// BEGIN CUT HERE
/*
SRM 775 Div2 Easy (250)

PROBLEM STATEMENT

You are given an int S and a vector <string> forbidden.
The strings in forbidden only use the first S lowercase English letters, and all these strings have the same length L.

Two strings of length L are called completely different if they differ at every index.
For example, X="abcd" and Y="bcda" are completely different but X="frog" and Y="plow" are not because X[2] = Y[2] = 'o'.

Compute and return the total number of strings with the following properties:

The length of the string is L. (That is, its length is the same as the length of the strings in forbidden.)
Each character of the string is one of the first S lowercase English letters.
The string is completely different from every string in forbidden.


DEFINITION
Class:CompletelyDifferentStrings
Method:count
Parameters:int, vector <string>
Returns:int
Method signature:int count(int S, vector <string> forbidden)


CONSTRAINTS
-S will be between 1 and 26, inclusive.
-forbidden will contain between 1 and 30 elements, inclusive.
-All elements of forbidden will have the same length L.
-L will be between 1 and 6, inclusive.
-Each character in each element of forbidden will be one of the first S lowercase English letters.


EXAMPLES

0)
3
{"ab"}

Returns: 4

As S = 3, we are only using the first three lowercase English letters: 'a', 'b', and 'c'.

We are looking for strings of length 2 that are completely different from "ab".
There are four such strings: "ba", "bc", "ca", and "cc".


1)
1
{"aaaaa", "aaaaa"}

Returns: 0

The only string of length 5 is "aaaaa", but this string is not completely different from the (identical) forbidden string "aaaaa". Thus, there are no strings with all the properties we need.


2)
7
{"baba", "babe", "cage", "cafe", "feed", "deed", "deaf", "dead"}

Returns: 90


3)
3
{"abacaa", "abacaa", "acabab"}

Returns: 8

Note that the strings in forbidden are not necessarily distinct.

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

class CompletelyDifferentStrings {
public:
	int count(int S, vector <string> forbidden) {
		int ans = 1;
		for (int i = 0; i < (int)forbidden[0].length(); ++i) {
			vector<int> available(S, 1);
			for (int j = 0; j < (int)forbidden.size(); ++j) {
				available[forbidden[j][i] - 'a'] = 0;
			}
			ans *= accumulate(available.begin(), available.end(), 0);
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
			int Arg0 = 3;
			string Arr1[] = {"ab"};
			int Arg2 = 4;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arr1[] = {"aaaaa", "aaaaa"};
			int Arg2 = 0;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			string Arr1[] = {"baba", "babe", "cage", "cafe", "feed", "deed", "deaf", "dead"};
			int Arg2 = 90;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arr1[] = {"abacaa", "abacaa", "acabab"};
			int Arg2 = 8;

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CompletelyDifferentStrings ___test;
	___test.run_test(-1);
}
// END CUT HERE
