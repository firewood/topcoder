// BEGIN CUT HERE
/*
// SRM 560 Div2 Easy (250)

// PROBLEM STATEMENT
// 
Jakub is trying out a one-dimensional keyboard.
It consists of a single row of keys. 
The distance between any two adjacent keys is 1.
Each key contains a distinct letter of the English alphabet.
Jakub uses only one finger to type on the keyboard.
He wonders what is the smallest total distance he will have to move his finger while typing a given word.

For example, if the keyboard's only row is "qwertyuiop", and Jakub wants to type the word "potter", he will have to move his finger from 'p' to 'o' (distance 1), from 'o' to 't' (distance 4), from 't' to 't' (distance 0), from 't' to 'e' (distance 2) and from 'e' to 'r' (distance 1), for a total distance of 1 + 4 + 0 + 2 + 1 = 8.

You are given a string keyboard and a string word, describing the keyboard and the word Jakub wants to write. Return the minimum distance he will have to move his finger in order to type the word on the keyboard.


DEFINITION
Class:TypingDistance
Method:minDistance
Parameters:string, string
Returns:int
Method signature:int minDistance(string keyboard, string word)


NOTES
-When moving the finger from the i-th key to the j-th key, the distance covered by the move can be computed as |i-j|, that is, the positive difference between i and j.


CONSTRAINTS
-keyboard will contain between 1 and 26 characters, inclusive.
-Each character in keyboard will be a different lowercase letter of the English alphabet ('a'-'z').
-word will contain between 1 and 50 characters, inclusive.
-Each character in word will be present in keyboard.


EXAMPLES

0)
"qwertyuiop"
"potter"

Returns: 8

The example from the problem statement.


1)
"tc"
"tctcttccctccccttc"

Returns: 9


2)
"a"
"aaaaaaaaaaa"

Returns: 0


3)
"kwadrutove"
"rowerowe"

Returns: 39


4)
"qwertyuiopasdfghjklzxcvbnm"
"topcodersingleroundmatchgoodluckhavefun"

Returns: 322

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TypingDistance {

public:
	int minDistance(string keyboard, string word) {
		int res = 0;
		const char *k = keyboard.c_str();
		int i, prev = 0;
		for (i = 0; i < (int)word.size(); ++i) {
			int x = (int)(strchr(k, word[i]) - k);
			if (i > 0) {
				res += abs(prev - x);
			}
			prev = x;
		}
		return res;
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
			string Arg0 = "qwertyuiop";
			string Arg1 = "potter";
			int Arg2 = 8;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "tc";
			string Arg1 = "tctcttccctccccttc";
			int Arg2 = 9;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a";
			string Arg1 = "aaaaaaaaaaa";
			int Arg2 = 0;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "kwadrutove";
			string Arg1 = "rowerowe";
			int Arg2 = 39;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qwertyuiopasdfghjklzxcvbnm";
			string Arg1 = "topcodersingleroundmatchgoodluckhavefun";
			int Arg2 = 322;

			verify_case(n, Arg2, minDistance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TypingDistance ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
