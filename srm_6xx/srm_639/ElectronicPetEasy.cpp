// BEGIN CUT HERE
/*
SRM 639 Div2 Easy (250)

PROBLEM STATEMENT

Kirino has found a game in which she has to feed electronic pets.
There are two pets in the game.
You are given six ints st1,p1,t1,st2,p2,t2.
To win the game, Kirino must satisfy the following rules:

She must feed her first pet for the first time precisely at the time st1.
There must be exactly p1 seconds between any two consecutive feedings of the first pet.
She must feed the first pet exactly t1 times.
She must feed her second pet for the first time precisely at the time st2.
There must be exactly p2 seconds between any two consecutive feedings of the second pet.
She must feed the second pet exactly t2 times.

Feeding the pets is easy if Kirino never needs to feed both pets at the same time.
Return "Easy" (quotes for clarity) if feeding the pets is easy for the given inputs.
Otherwise, return "Difficult".
Note that the return value is case-sensitive.


DEFINITION
Class:ElectronicPetEasy
Method:isDifficult
Parameters:int, int, int, int, int, int
Returns:string
Method signature:string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)


CONSTRAINTS
-st1, p1, t1, st2, p2, and t2 will be between 1 and 1,000, inclusive.


EXAMPLES

0)
3
3
3
5
2
3

Returns: "Difficult"

Kirino must feed her first pet at the times 3, 6, and 9.
She must feed her second pet at the times 5, 7, and 9.
Feeding these two pets is difficult because she needs to feed both of them at the same time (at time 9).


1)
3
3
3
5
2
2

Returns: "Easy"

Kirino must feed her first pet at 3, 6, and 9, and her second pet at 5 and 7.
As all of these times are distinct, feeding these two pets is easy.


2)
1
4
7
1
4
7

Returns: "Difficult"


3)
1
1000
1000
2
1000
1000

Returns: "Easy"


4)
1
1
1
2
2
2

Returns: "Easy"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;
typedef set<int> IntSet;

class ElectronicPetEasy {
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2) {
		IntVec v;
		for (int i = 0; i < t1; ++i) {
			v.push_back(st1 + p1 * i);
		}
		IntSet s(v.begin(), v.end());
		for (int i = 0; i < t2; ++i) {
			if (s.find(st2 + p2 * i) != s.end()) {
				return "Difficult";
			}
		}
		return "Easy";
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
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 3;
			string Arg6 = "Difficult";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 3;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 2;
			string Arg6 = "Easy";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 4;
			int Arg2 = 7;
			int Arg3 = 1;
			int Arg4 = 4;
			int Arg5 = 7;
			string Arg6 = "Difficult";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1000;
			int Arg2 = 1000;
			int Arg3 = 2;
			int Arg4 = 1000;
			int Arg5 = 1000;
			string Arg6 = "Easy";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;
			int Arg4 = 2;
			int Arg5 = 2;
			string Arg6 = "Easy";

			verify_case(n, Arg6, isDifficult(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ElectronicPetEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
