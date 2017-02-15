// BEGIN CUT HERE
/*
SRM 708 Div2 Medium (500)

PROBLEM STATEMENT
The score of a string is its length multiplied by the number of different characters in the string.
For example, the score of "abbcdxc" is 7 * 5 = 35.
This is because the length of this string is 7 and there are five different characters: a, b, c, d, x.

Bear Limak wants to find a sequence of strings satisfying the following conditions: 

There number of strings is between 1 and 50, inclusive.
The length of each string is between 1 and 50, inclusive.
The sum of scores of the strings is exactly K.
Each character in each string is a lowercase English letter ('a' - 'z').

You are given the int K.
Compute and return any sequence of strings with the above properties.
If there are multiple solutions, you may return any one of them.


DEFINITION
Class:BuildingStrings
Method:findAny
Parameters:int
Returns:vector <string>
Method signature:vector <string> findAny(int K)


NOTES
-The answer exists for every value of K allowed by the constraints.


CONSTRAINTS
-K will be between 1 and 50,000, inclusive.


EXAMPLES

0)
49

Returns: {"little", "limak" }

The length of "little" is 6 and the number of different characters in "little" is 4.
The length of "limak" is 5 and the number of different characters in "limak" is 5.
Thus, the total score of the output shown above is 6*4 + 5*5 = 24 + 25 = 49.


1)
15

Returns: {"azz", "xyz" }

3 * 2 + 3 * 3 = 15


2)
704

Returns: {"aaaaaaaaaa", "abcdefghijklmnopqrstuvwxyz", "aabbcc" }

10 * 1 + 26 * 26 + 6 * 3 = 10 + 676 + 18 = 704


3)
37521

Returns: {"aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "abcd", "aa", "a", "a", "a" }


4)
1

Returns: {"a" }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<string> StrVec;

int score(StrVec &v) {
	int r = 0;
	for (string &s : v) {
		set<char> m;
		for (char c : s) {
			m.insert(c);
		}
		r += s.length() * m.size();
	}
	return r;
}

class BuildingStrings {
public:
	vector <string> findAny(int K) {
		vector <string> ans;
		while (K >= 25 * 25) {
			string s = "abcdefghijklmnopqrstuvwxy";
			for (int i = 25; i < K / 25 && s.length() < 50; ++i) {
				s += "a";
			}
			ans.push_back(s);
			K -= s.length() * 25;
		}
		while (K >= 5 * 5) {
			string s = "abcde";
			for (int i = 5; i < K / 5 && s.length() < 50; ++i) {
				s += "a";
			}
			ans.push_back(s);
			K -= s.length() * 5;
		}
		while (K >= 1) {
			string s(min(50, K), 'a');
			ans.push_back(s);
			K -= s.length();
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 49;
			string Arr1[] = {"little", "limak" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			string Arr1[] = {"azz", "xyz" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 704;
			string Arr1[] = {"aaaaaaaaaa", "abcdefghijklmnopqrstuvwxyz", "aabbcc" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 37521;
			string Arr1[] = {"aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "abcd", "aa", "a", "a", "a" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arr1[] = {"a" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50000;
			string Arr1[] = { "a" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingStrings ___test;
	___test.run_test(-1);

	for (int t = 1; t <= 50000; ++t) {
		StrVec r = ___test.findAny(t);
		int s = score(r);
		if (r.size() > 50 || s != t) {
			cout << "ERROR: " << t << endl;
		}
	}
}
// END CUT HERE
