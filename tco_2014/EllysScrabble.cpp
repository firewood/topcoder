// BEGIN CUT HERE
/*
TCO 2014 Round 1A Medium (500)

PROBLEM STATEMENT
Elly is playing Scrabble with her family. The exact rules of the game are not important for this problem. You only need to know that Elly has a holder that contains a row of N tiles, and that there is a single letter on each of those tiles. (Tiles are small square pieces of wood. A holder is a tiny wooden shelf with room for precisely N tiles placed in a row.)

While Elly waits for the other players, she entertains herself in the following way. She slightly taps the table, causing the tiles on her holder jump a little and some of them switch places.
Formally, suppose that Elly has N tiles. There are N positions on the holder, we will label them 0 through N-1 from left to right.
When Elly taps the table, the tiles on her holder will form some permutation of their original order.
You are given an int maxDistance with the following meaning: in the permutation that Elly produces by tapping the table, no tile will be more than maxDistance positions away from its original position (in either direction).

For example, suppose that before a tap the letters in Elly's holder formed the string "TOPCODER" when read from left to right.
If maxDistance is 3, one possible string after Elly taps the table is "CODTEPOR".
This can happen in the following way:

The letter 'T' at position 0 moves three positions to the right (to position 3).
The letter 'O' at position 1 remains on its initial position (position 1).
The letter 'P' at position 2 moves three positions to the right (to position 5).
The letter 'C' at position 3 moves three positions to the left (to position 0).
The letter 'O' at position 4 moves two positions to the right (to position 6).
The letter 'D' at position 5 moves three positions to the left (to position 2).
The letter 'E' at position 6 moves two positions to the left (to position 4).
The letter 'R' at position 7 remains on its initial position (position 7).

Note that the letter 'D' (at position 5) cannot move to position 1, because this would require it to move more than the maximal distance 3.

It turns out that the string "CODTEPOR" is the lexicographically smallest one Elly can get from "TOPCODER" with a single tap and maxDistance = 3. Now you want to write a program that, given the string letters and the int maxDistance, returns the lexicographically smallest string the girl can get after a single tap.


DEFINITION
Class:EllysScrabble
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string letters, int maxDistance)


NOTES
-Given two different strings A and B of equal length, the lexicographically smaller one is the one that contains a smaller character at the first position where they differ.


CONSTRAINTS
-letters will contain between 1 and 50 characters, inclusive.
-letters will contain only uppercase letters from the English alphabet ('A'-'Z').
-maxDistance will be between 1 and 9, inclusive.


EXAMPLES

0)
"TOPCODER"
3

Returns: "CODTEPOR"

The example from the problem statement.


1)
"ESPRIT"
3

Returns: "EIPRST"

In this example the letters 'E', 'P', 'R', and 'T' stay on their initial places, and the letters 'S' and 'I' swap. Since the distance between them is exactly 3 (which also happens to be the maximal distance they can move), this is a valid final configuration.


2)
"BAZINGA"
8

Returns: "AABGINZ"

Note that the maximal distance may be greater than the number of letters Elly has. In such cases, the lexicographically smallest result is, obviously, the sorted sequence of letters.


3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
9

Returns: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

As the input letters are already sorted, we can assume they'll just fall back to their initial places.


4)
"GOODLUCKANDHAVEFUN"
7

Returns: "CADDGAHEOOFLUKNNUV"


5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
6

Returns: "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"


6)
"ABRACADABRA"
2

Returns: "AABARACBDAR"

The letter 'A' at position 0 remains on its initial place (position 0).
The letter 'B' at position 1 moves one position to the right (to position 2).
The letter 'R' at position 2 moves two positions to the right (to position 4).
The letter 'A' at position 3 moves two positions to the left (to position 1).
The letter 'C' at position 4 moves two positions to the right (to position 6).
The letter 'A' at position 5 moves two positions to the left (to position 3).
The letter 'D' at position 6 moves two positions to the right (to position 8).
The letter 'A' at position 7 moves two positions to the left (to position 5).
The letter 'B' at position 8 moves one position to the left (to position 7).
The letter 'R' at position 9 moves one position to the right (to position 10).
The letter 'A' at position 10 moves one position to the left (to position 9).

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysScrabble {
public:
	string getMin(string letters, int maxDistance) {
		int used[64] = {};
		char w[64] = {};
		int N = (int)letters.size();
		for (int i = 0; i < N; ++i) {
			int pos = i - maxDistance;
			if (pos >= 0 && !used[pos]) {
				;
			} else {
				pos = -1;
				int s = max(0, i - maxDistance);
				int e = min(N - 1, i + maxDistance);
				for (int j = s; j <= e; ++j) {
					if (!used[j]) {
						if (pos < 0 || letters[j] < letters[pos]) {
							pos = j;
						}
					}
				}
			}
			used[pos] = 1;
			w[i] = letters[pos];
		}
		return w;
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
			int Arg1 = 3;
			string Arg2 = "CODTEPOR";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ESPRIT";
			int Arg1 = 3;
			string Arg2 = "EIPRST";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAZINGA";
			int Arg1 = 8;
			string Arg2 = "AABGINZ";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int Arg1 = 9;
			string Arg2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GOODLUCKANDHAVEFUN";
			int Arg1 = 7;
			string Arg2 = "CADDGAHEOOFLUKNNUV";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int Arg1 = 6;
			string Arg2 = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABRACADABRA";
			int Arg1 = 2;
			string Arg2 = "AABARACBDAR";

			verify_case(n, Arg2, getMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysScrabble ___test;
	___test.run_test(-1);
}
// END CUT HERE
