// BEGIN CUT HERE
/*
// TCO 2012 R2A Easy (300)

// PROBLEM STATEMENT
// There are N switches and N lamps in Cucumberman's house. Each switch is
connected to a single lamp. Different switches are connected to different lamps.
Switches are numbered 0 through N-1. Lamps are also numbered 0 through N-1,
but not necessarily in the same order as their corresponding switches.
Switches and lamps have two states: ON and OFF. When a switch is in the ON state,
the lamp connected to the switch is ON. When a switch is in the OFF state,
the lamp connected to the switch is OFF.

Cucumberman decided to perform some experiments in order to figure out the
connection between switches and lamps. In each experiment he first sets the states
of all switches as he wants to, and then he writes down the states of all lamps.

He has already performed some experiments. You are given the results in
two vector <string>s switches and lamps. If the j-th character of the i-th
element of switches is 'Y', the j-th switch was ON in the i-th experiment.
If the j-th character of the i-th element of switches is 'N', the j-th switch was
OFF in the i-th experiment. lamps gives the information of lamps in the same format.

If the results of experiments are inconsistent, return -1. (I.e., return -1 if
no way of assigning switches to lamps matches all the experiments.) Otherwise,
return the minimal number of additional experiments required to figure out
the connection between switches and lamps. In other words, return the smallest
nonnegative integer X with the following property: It is possible to design X
additional experiments in such a way that after Cucumberman executes them and tells
you the results you will surely be able to match each switch to its corresponding lamp.


DEFINITION
Class:SwitchesAndLamps
Method:theMin
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int theMin(vector <string> switches, vector <string> lamps)


CONSTRAINTS
-switches will contain between 1 and 50 elements, inclusive.
-Each element of switches will contain between 1 and 50 characters, inclusive.
-Each element of switches will contain the same number of characters.
-lamps will contain the same number of elements as switches.
-Each element of lamps will contain the same number of characters, and it will be
 equal to the number of characters of elements in switches.
-Each character in switches and lamps will be 'Y' or 'N'.
-For each i, the number of 'Y' in switches[i] and the number of 'Y' in lamps[i] will be equal.


EXAMPLES

0)
{"NYNN", "NNYN"}
{"NNNY", "NNYN"}

Returns: 1

He can figure out that switch 1 is connected to lamp 3 and switch 2 is connected to lamp 2.
He needs one more experiment to figure out which of the switches 0 and 3 is connected to lamp 0.


1)
{"YYN", "YNY", "YYN"}
{"YNY", "NYY", "YNY"}

Returns: 0

He can figure out that switch 0 is connected to lamp 2, switch 1 is connected to lamp 0,
and switch 2 is connected to lamp 1. No additional experiments are necessary.


2)
{"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"}
{"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"}

Returns: -1

The same experiment cannot give different results when executed twice.


3)
{"YYNNN", "NNYYN"}
{"NYNNY", "NNNYY"}

Returns: -1


4)
{"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"}
{"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"}

Returns: 2

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555) + (bits >>  1 & 0x5555555555555555);
	bits = (bits & 0x3333333333333333) + (bits >>  2 & 0x3333333333333333);
	bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >>  4 & 0x0f0f0f0f0f0f0f0f);
	bits = (bits & 0x00ff00ff00ff00ff) + (bits >>  8 & 0x00ff00ff00ff00ff);
	bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
	bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
	return (int)bits;
}

class SwitchesAndLamps {

public:
	int theMin(vector <string> switches, vector <string> lamps) {
		int H = switches.size();
		int W = switches[0].length();

		LL b, sw[64] = {}, la[64] = {};
		int i, j;
		for (i = 0; i < H; ++i) {
			b = 1;
			for (j = 0; j < W; ++j, b <<= 1) {
				if (switches[i][j] == 'Y') {
					sw[i] |= b;
				}
				if (lamps[i][j] == 'Y') {
					la[i] |= b;
				}
			}
		}

		LL mask = (1LL << W) - 1;
		int Max = 0;
		b = 1;
		for (j = 0; j < W; ++j, b <<= 1) {
			LL s = -1, l = -1;
			for (i = 0; i < H; ++i) {
				if (sw[i] & b) {
					s &= sw[i];
					l &= la[i];
				} else {
					s &= ~sw[i];
					l &= ~la[i];
				}
			}
			int ps = popcount(s & mask);
			int pl = popcount(l & mask);
			if (ps != pl) {
				return -1;
			}
			Max = max(Max, ps);
		}

		int res = 0;
		while (Max > 1) {
			Max -= Max / 2;
			++res;
		}
		return res;
	}

// BEGIN CUT HERE
private:
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYNN", "NNYN"};
			string Arr1[] = {"NNNY", "NNYN"};
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYN", "YNY", "YYN"};
			string Arr1[] = {"YNY", "NYY", "YNY"};
			int Arg2 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"};
			string Arr1[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"};
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YYNNN", "NNYYN"};
			string Arr1[] = {"NYNNY", "NNNYY"};
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"};
			string Arr1[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"};
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, theMin(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SwitchesAndLamps ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
