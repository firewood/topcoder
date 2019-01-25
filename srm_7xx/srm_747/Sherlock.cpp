// BEGIN CUT HERE
/*
SRM 747 Div2 Easy (250)

PROBLEM STATEMENT

Computer, find "BENADRYL CUCUMBERPATCH".
Did you mean the actor who played Sherlock, Benedict Cumberbatch?


Benedict Cumberbatch is an actor who is famous not only because of his roles.
It is also known that you can misspell his name almost arbitrarily and people (and computers too!) will still recognize him.

In this problem, you are given the name of a person: the strings firstName and lastName.
We say that this name matches Benedict Cumberbatch if it has all properties listed below.

Each name must have at least seven letters.
The first name must start with 'B' and the last name must start with 'C'.
At least three characters of firstName must appear somewhere in the name "BENEDICT".
At least five characters of lastName must appear somewhere in the name "CUMBERBATCH".

In conditions 3 and 4 we count each occurrence of a letter, even if that letter occurs in the given name more times than in the actor's actual name.
For example, "BATAXXAT" is a valid first name because three of its characters ('B', 'T', 'T') appear in "BENEDICT".

Return "It is him" if all conditions are satisfied and "It is someone else" if they aren't.


DEFINITION
Class:Sherlock
Method:isItHim
Parameters:string, string
Returns:string
Method signature:string isItHim(string firstName, string lastName)


NOTES
-Note that the return value is case-sensitive.


CONSTRAINTS
-firstName and lastName will each consist of between 1 and 20 characters, inclusive.
-Each character in firstName and lastName will be an uppercase English letter ('A'-'Z').


EXAMPLES

0)
"BENEDICT"
"CUMBERBATCH"

Returns: "It is him"


1)
"BENADRYL"
"CUCUMBERPATCH"

Returns: "It is him"


2)
"HARSHIT"
"MEHTA"

Returns: "It is someone else"


3)
"BATAXXAT"
"CURMUDGEON"

Returns: "It is him"


4)
"BENEDI"
"CUMBER"

Returns: "It is someone else"

Both names are too short.


5)
"BAXAXAXY"
"CENTRIFUGAL"

Returns: "It is someone else"

The first name has too few characters in common with BENEDICT.


6)
"BUMBLESHACK"
"CRUMPLEHORN"

Returns: "It is him"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Sherlock {
public:
	string isItHim(string firstName, string lastName) {
		if (firstName.length() >= 7 && lastName.length() >= 7 && firstName[0] == 'B' && lastName[0] == 'C') {
			int cnt = 0;
			for (char c : firstName) {
				for (char n : "BENEDICT") {
					if (c == n) {
						++cnt;
						break;
					}
				}
			}
			if (cnt >= 3) {
				cnt = 0;
				for (char c : lastName) {
					for (char n : "CUMBERBATCH") {
						if (c == n) {
							++cnt;
							break;
						}
					}
				}
				if (cnt >= 5) {
					return "It is him";
				}
			}
		}
		return "It is someone else";
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
			string Arg0 = "BENEDICT";
			string Arg1 = "CUMBERBATCH";
			string Arg2 = "It is him";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BENADRYL";
			string Arg1 = "CUCUMBERPATCH";
			string Arg2 = "It is him";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HARSHIT";
			string Arg1 = "MEHTA";
			string Arg2 = "It is someone else";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BATAXXAT";
			string Arg1 = "CURMUDGEON";
			string Arg2 = "It is him";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BENEDI";
			string Arg1 = "CUMBER";
			string Arg2 = "It is someone else";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAXAXAXY";
			string Arg1 = "CENTRIFUGAL";
			string Arg2 = "It is someone else";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BUMBLESHACK";
			string Arg1 = "CRUMPLEHORN";
			string Arg2 = "It is him";

			verify_case(n, Arg2, isItHim(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Sherlock ___test;
	___test.run_test(-1);
}
// END CUT HERE
