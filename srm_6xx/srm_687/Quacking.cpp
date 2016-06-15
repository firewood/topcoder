// BEGIN CUT HERE
/*
SRM 687 Div2 Medium (500)

PROBLEM STATEMENT

Ducks have started mysteriously appearing in your room.
All ducks make the same sound: "quack".
Each duck makes the sound one or more times, one after another.
For example, valid sounds for a single duck are "quack", "quackquackquackquack", "quackquack", etc.

You have lost count of how many ducks are in your room.
The ducks are quacking, and the sounds of their quacks are getting mixed up.
You have recorded the sounds, obtaining a string of characters.
When you later listened to the recording, you realized that the quacking of each individual duck forms a (not necessarily contiguous) subsequence of the recording.
You also noticed that each letter in the recording belongs to exactly one duck.
For example, if there were two ducks, you may have recorded "quqacukqauackck".

You are given a string s that contains an arbitrary recording.
Find and return the smallest number of ducks that could have produced the recording.
Note that it is possible that the given recording is not a valid recording of quacking ducks.
In such case, return -1.


DEFINITION
Class:Quacking
Method:quack
Parameters:string
Returns:int
Method signature:int quack(string s)


CONSTRAINTS
-s will have between 5 and 2,500 characters, inclusive.
-Each character of s will be 'q', 'u', 'a', 'c', or 'k'.


EXAMPLES

0)
"quqacukqauackck"

Returns: 2

This is the same as the one from the problem statement.


1)
"kcauq"

Returns: -1

A backward duck is not a real duck.


2)
"quackquackquackquackquackquackquackquackquackquack"

Returns: 1

A single duck can make arbitrarily many quack sounds.


3)
"qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk"

Returns: 10


4)
"quqaquuacakcqckkuaquckqauckack"

Returns: 3

This is one possible solution with 3 ducks.

Mixed: quqaquuacakcqckkuaquckqauckack
Duck1: ____q_u__a___ck_______________
Duck2: __q__u_ac_k_q___ua__ckq_u__ack
Duck3: qu_a_______c___k__qu___a_ck___

Here, we can verify that each letter comes from exactly one duck.


5)
"quackqauckquack"

Returns: -1

Note that the second quack is misspelled.

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Quacking {
public:
	int quack(string s) {
		int len = (int)s.length(), r = len;
		int u[2500] = {};
		const char quack[] = "quack";
		int ans = 0;
		while (r > 0) {
			++ans;
			int p = 0;
			for (int i = 0; i < len; ++i) {
				if (!u[i]) {
					if (s[i] == quack[p % 5]) {
						--r;
						u[i] = 1;
						++p;
					} else if (p == 0) {
						return -1;
					}
				}
			}
			if (p % 5) {
				return -1;
			}
		}
		return r > 0 ? -1 : ans;
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
			string Arg0 = "quqacukqauackck";
			int Arg1 = 2;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "kcauq";
			int Arg1 = -1;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "quackquackquackquackquackquackquackquackquackquack";
			int Arg1 = 1;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk";
			int Arg1 = 10;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "quqaquuacakcqckkuaquckqauckack";
			int Arg1 = 3;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "quackqauckquack";
			int Arg1 = -1;

			verify_case(n, Arg1, quack(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Quacking ___test;
	___test.run_test(-1);
}
// END CUT HERE
