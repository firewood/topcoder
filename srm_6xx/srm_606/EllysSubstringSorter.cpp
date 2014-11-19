// BEGIN CUT HERE
/*
SRM 606 Div2 Easy (250)

PROBLEM STATEMENT
Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.

The device does the following: The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then takes L letters of S, starting at index i, and puts these letters into alphabetical order.
Formally, the letters that get reordered are the letters S[i], S[i+1], and so on, until and including S[i+L-1].

For example, let S="TOPCODER" and let L=4. If the user chooses i=0, the selected substring will be "TOPC". These letters are rearranged into alphabetical order ("COPT") while the rest of the string remains unchanged ("....ODER"). Thus, the result would be the string "COPTODER". If the user were to choose i=2 instead, the resulting string would be "TOCDOPER". Here, "TO....ER" was left unchanged, and "PCOD" was changed into "CDOP".

Elly's magic device has a flaw: it can only be used once and then it self-destructs. You are given the string S and the int L described above. Return the lexicographically smallest string Elly can create by using the device exactly once.


DEFINITION
Class:EllysSubstringSorter
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string S, int L)


NOTES
-A string S1 is lexicographically smaller than a string S2 if S1 contains a smaller character than S2 at the first index where they differ.


CONSTRAINTS
-L will be between 2 and 50, inclusive.
-S will contain between L and 50 characters, inclusive.
-Each character of S will be an uppercase letter of the English alphabet ('A'-'Z').


EXAMPLES

0)
"TOPCODER"
4

Returns: "COPTODER"

The best we can do here is to sort the first 4 characters of the string.


1)
"ESPRIT"
3

Returns: "EPRSIT"

The best solution is obtained by choosing i=1, i.e., by sorting the letters in the substring "SPR".


2)
"AAAAAAAAA"
2

Returns: "AAAAAAAAA"

Sometimes sorting doesn't do anything.


3)
"ABRACADABRA"
5

Returns: "AAABCRDABRA"


4)
"BAZINGA"
6

Returns: "ABGINZA"


5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21

Returns: "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysSubstringSorter {
public:
	string getMin(string S, int L) {
		string ans = S;
		for (int i = 0; i <= (int)S.length() - L; ++i) {
			string a = S.substr(0, i);
			string b = S.substr(i, L);
			string c = S.substr(i + L);
			sort(b.begin(), b.end());
			ans = min(ans, a + b + c);
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
			string Arg0 = "TOPCODER";
			int Arg1 = 4;
			string Arg2 = "COPTODER";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			int Arg1 = 3;
			string Arg2 = "EPRSIT";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAAAAAAA";
			int Arg1 = 2;
			string Arg2 = "AAAAAAAAA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABRACADABRA";
			int Arg1 = 5;
			string Arg2 = "AAABCRDABRA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAZINGA";
			int Arg1 = 6;
			string Arg2 = "ABGINZA";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int Arg1 = 21;
			string Arg2 = "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysSubstringSorter ___test;
	___test.run_test(-1);
}
// END CUT HERE
