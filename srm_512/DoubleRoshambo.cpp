// BEGIN CUT HERE
/*
// SRM 512 Div2 Hard (1024)

// PROBLEM STATEMENT
// Ash and Elsh invented a new variant of the game Rock-Paper-Scissors called
DoubleRoshambo. In the normal game, each of the two players change their
right hand into one of these gestures: rock, paper, or scissors.
Rock beats scissors; scissors beat paper; paper beats rock. For example,
if Ash plays rock and Elsh plays paper, then Elsh wins.

In DoubleRoshambo, each player uses both hands. Each hand may play different
gestures. A player scores:

2 points, if his right hand beats his opponent's right hand, and his left
hand beats his opponent's left hand.
1 point, if his right hand beats his opponent's right hand, and his left
hand plays the same gesture as his opponent's left hand.
0 points, in all other cases.

Ash and Elsh played DoubleRoshambo several rounds. You are given
two vector <string>s A and E, representing the gestures that Ash and Elsh
played, respectively. Each element of A and E will contain two characters.
The first character is for their left hand and the second character is for
their right hand. For each hand, the character will be one of 'R', 'P', or 'S',
representing rock, paper, or scissors, respectively.

However, the gestures are given in no specific order. Return the maximum
points Ash could have possibly scored.

DEFINITION
Class:DoubleRoshambo
Method:maxScore
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int maxScore(vector <string> A, vector <string> E)


CONSTRAINTS
-A and E will both contain the same number of elements, between 1 and 50, inclusive.
-Each element of both A and E will contain exactly 2 characters.
-Each character in both A and E will be one of 'R', 'P', or 'S'.


EXAMPLES

0)
{"RR"}
{"SS"}

Returns: 2

They played one round. Ash played RR while Elsh played SS, so Ash scored 2 points.


1)
{"SR", "PP"}
{"PR", "RS"}

Returns: 1

They might have played like this:

Ash played SR and Elsh played RS, so Ash scored 0 points.
Ash played PP and Elsh played PR, so Ash scored 1 point.


In total, Ash scored 1 point.


2)
{"PP", "PP", "PP", "PP"}
{"RR", "PR", "SS", "SP"}

Returns: 3


3)
{"PS", "RS", "PP", "SP", "RR", "SS", "SP"}
{"RP", "SP", "RR", "SR", "RS", "SP", "SS"}

Returns: 10

*/
// END CUT HERE
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class DoubleRoshambo {

public:
	int maxScore(vector <string> A, vector <string> E) {
		int result = 0;

		char win[128];
		win['R'] = 'S', win['P'] = 'R', win['S'] = 'P';

		int x[64] = {}, y[64] = {};

		int i, j;
		for (i = 0; i < (int)A.size(); ++i) {
			for (j = 0; j < (int)E.size(); ++j) {
				if (!y[j] && win[A[i][1]] == E[j][1] && win[A[i][0]] == E[j][0]) {
					x[i] = 1;
					y[j] = 1;
					result += 2;
					break;
				}
			}
		}

		for (i = 0; i < (int)A.size(); ++i) {
			if (!x[i]) {
				for (j = 0; j < (int)E.size(); ++j) {
					if (!y[j] && win[A[i][1]] == E[j][1] && A[i][0] == E[j][0]) {
						y[j] = 1;
						result += 1;
						break;
					}
				}
			}
		}

		return result;
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
			string Arr0[] = {"RR"};
			string Arr1[] = {"SS"};
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"SR", "PP"};
			string Arr1[] = {"PR", "RS"};
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PP", "PP", "PP", "PP"};
			string Arr1[] = {"RR", "PR", "SS", "SP"};
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PS", "RS", "PP", "SP", "RR", "SS", "SP"};
			string Arr1[] = {"RP", "SP", "RR", "SR", "RS", "SP", "SS"};
			int Arg2 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleRoshambo ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
