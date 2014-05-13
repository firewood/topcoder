// BEGIN CUT HERE
/*
TCO 2014 Round 1A Easy (250)

PROBLEM STATEMENT
Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.

The device is used in the following way. The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then performs the following changes:

It leaves the first i characters (i.e., characters with indices 0 through i-1) untouched.
It rearranges the next L characters (i.e., characters with indices i through i+L-1) into alphabetical order.
It erases all the remaining characters (i.e., characters with indices i+L and more). Note that for i=length(S)-L no characters are erased.

The girl can use this "sorting trimmer" as many times as she likes. After each use she is left with the new version of the string.

In the examples below we use brackets to highlight the region that shall be sorted. For example, "ABRA[CADAB]RA" means that L=5 and Elly chose i=4. The device keeps the letters in front of the brackets, sorts the letters in the brackets, and throws away the rest.

Here is one way how Elly could have used a device with L = 5, starting with the string S = "ABRACADABRA":

"ABRAC[ADABR]A" -> "ABRACAABDR"
"ABR[ACAAB]DR" -> "ABRAAABC"
"A[BRAAA]BC" -> "AAAABR"


You are given the string S and the int L. Return the lexicographically smallest string Elly can obtain.

DEFINITION
Class:EllysSortingTrimmer
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string S, int L)


NOTES
-A string A is lexicographically smaller than string B if A contains a smaller character in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.

CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-L will be between 2 and |S|, inclusive, where |S| denotes the number of characters in S.
-S will consist of uppercase characters of the English alphabet, only ('A'-'Z').


EXAMPLES

0)
"ABRACADABRA"
5

Returns: "AAAAA"

Please note that the example in the problem statement does not obtain the lexicographically smallest string. In fact, it is optimal to start by using the device on the last five characters of the string, transforming it from ABRACA[DABRA] to ABRACAAABDR.


1)
"ESPRIT"
3

Returns: "EIP"

We can obtain the answer in the following steps:

ES[PRI]T -> ESIPR
E[SIP]R -> EIPS
[EIP]S -> EIP
 

2)
"BAZINGA"
7

Returns: "AABGINZ"

We can use the sorting trimmer on the entire word.


3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
13

Returns: "ABCDEFGHIJKLM"

Even though the string is already sorted, shorter strings are considered lexicographically smaller, so we can use the device once to make the string as short as possible.


4)
"GOODLUCKANDHAVEFUN"
10

Returns: "AACDDEFGHK"


5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21

Returns: "AAAAAAAAABBDDDDDDDEEI"

6)
"TOPCODER"
3

Returns: "CDT"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysSortingTrimmer {
public:
	string getMin(string S, int L) {
		for (int i = S.length() - L; i >= 0; --i) {
			sort(S.begin() + i, S.begin() + i + L);
		}
		return S.substr(0, L);
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
			string Arg0 = "ABRACADABRA";
			int Arg1 = 5;
			string Arg2 = "AAAAA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			int Arg1 = 3;
			string Arg2 = "EIP";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAZINGA";
			int Arg1 = 7;
			string Arg2 = "AABGINZ";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int Arg1 = 13;
			string Arg2 = "ABCDEFGHIJKLM";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GOODLUCKANDHAVEFUN";
			int Arg1 = 10;
			string Arg2 = "AACDDEFGHK";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int Arg1 = 21;
			string Arg2 = "AAAAAAAAABBDDDDDDDEEI";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "TOPCODER";
			int Arg1 = 3;
			string Arg2 = "CDT";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysSortingTrimmer ___test;
	___test.run_test(-1);
}
// END CUT HERE
