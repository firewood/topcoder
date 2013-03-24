// BEGIN CUT HERE
/*
SRM 572 Div1 Medium (500)

PROBLEM STATEMENT
Elly and Kristina play a game called "Bulls".
Initially each of them thinks of a non-negative integer with K digits, possibly containing leading zeroes.
Then they take alternating turns, trying to guess the opponent's number.
After each guess, the other person says how many positions were guessed correctly.
For example if Kristina's number was "1337" and Elly's guess was "1738", Kristina should answer 2,
since the digits at positions 0 and 2 (zero-based indices from the left) are correct.
A guessed position is called "bull's hit", or simply a "bull", thus the name of the game.

Elly has already made several guesses.
She wonders if the information she has is enough to uniquely determine Kristina's number.

You are given the guesses so far in a vector <string> guesses and the corresponding number of bull's hits in vector <int> bulls.
If a unique number satisfies the given information, return it as a string.
If there is more than one number that is valid according to the current guesses, return "Ambiguity" (quotes for clarity only).
If no number satisfies the given information, then Kristina has lied and you should return "Liar" instead.


DEFINITION
Class:EllysBulls
Method:getNumber
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getNumber(vector <string> guesses, vector <int> bulls)


NOTES
-The game "Bulls" is a simplification of a game played in Bulgaria, called "Kravi & Bikove" ("Cows & Bulls").


CONSTRAINTS
-guesses will contain between 1 and 50 elements, inclusive.
-Each element of guesses will contain between 2 and 9 characters, inclusive.
-All elements of guesses will contain the same number of characters.
-All elements of guesses will consist only of digits ('0'-'9').
-bulls will contain the same number of elements as guesses.
-Each element of bulls will be between 0 and K-1, inclusive, where K is the length of each element of guesses.


EXAMPLES

0)
{"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}
{2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}

Returns: "1337"

From {1234->2, 2222->0, 4444->0} it follows that the number is {1?3?}.
The additional information {4321->1} tells us that either the digit at position 1 (0-indexed) is 3,
or that the one at position 3 is 1. However, since {1111->1} and we already know that the 0-th digit is 1,
then the third digit cannot be 1. Now we know that the number is {133?}.
When trying {7777->1} we see that Kristina's number contains a 7, which cannot be anywhere else except in the last position.
Thus, her number is 1337.


1)
{"0000", "1111", "2222"}
{2, 2, 2}

Returns: "Liar"

There are supposed to be two 0s, two 1s and two 2s in a four-digit number. Thus, Kristina is clearly a liar.


2)
{"666666", "666677", "777777", "999999"}
{2, 3, 1, 0}

Returns: "Ambiguity"

Some of the possible configurations that satisfy the current results are the numbers 636172, 336617, 660007.
Thus, the answer is ambiguous.


3)
{"000", "987", "654", "321", "100", "010"}
{2, 1, 0, 0, 1, 1}

Returns: "007"

The guesses, as well as the answer, can have leading zeroes.


4)
{"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

Returns: "54"


5)
{"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}
{1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}

Returns: "4266642"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef map<IntVec, StrVec> IntVecStrVecMap;

class EllysBulls {
public:
	string getNumber(vector <string> guesses, vector <int> bulls) {
		string ans;
		int g = (int)guesses.size();
		int len_a = (int)guesses[0].length() / 2;
		int len_b = (int)guesses[0].length() - len_a;
		int i, j, k, m;
		char temp[64];

		IntVecStrVecMap ivsvm;

		m = (int)pow(10.0, (double)len_a);
		for (i = 0; i < m; ++i) {
			sprintf(temp, "%0*d", len_a, i);
			IntVec v = bulls;
			for (j = 0; j < g; ++j) {
				for (k = 0; k < len_a; ++k) {
					v[j] -= temp[k] == guesses[j][k];
				}
				if (v[j] < 0) {
					break;
				}
			}
			if (j >= g) {
				ivsvm[v].push_back(temp);
			}
		}

		m = (int)pow(10.0, (double)len_b);
		for (i = 0; i < m; ++i) {
			sprintf(temp, "%0*d", len_b, i);
			IntVec v(g);
			for (j = 0; j < g; ++j) {
				for (k = 0; k < len_b; ++k) {
					v[j] += temp[k] == guesses[j][len_a+k];
				}
			}
			IntVecStrVecMap::const_iterator it = ivsvm.find(v);
			if (it == ivsvm.end()) {
				continue;
			}

			if (!ans.empty() || it->second.size() > 1) {
				// answer is not unique
				return "Ambiguity";
			}

			ans = it->second[0];
			ans += temp;
		}

		return ans.empty() ? "Liar" : ans;
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
			string Arr0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
			int Arr1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
			string Arg2 = "1337";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0000", "1111", "2222"};
			int Arr1[] = {2, 2, 2};
			string Arg2 = "Liar";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"666666", "666677", "777777", "999999"};
			int Arr1[] = {2, 3, 1, 0};
			string Arg2 = "Ambiguity";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"000", "987", "654", "321", "100", "010"};
			int Arr1[] = {2, 1, 0, 0, 1, 1};
			string Arg2 = "007";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"};
			int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			string Arg2 = "54";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"};
			int Arr1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
			string Arg2 = "4266642";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysBulls ___test;
	___test.run_test(-1);
}
// END CUT HERE
