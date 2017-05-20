// BEGIN CUT HERE
/*
TCO 2017 R2A Easy (250)

PROBLEM STATEMENT
Fox Ciel has c cherries and s strawberries.
She wants to bake some cakes.
While doing so, she wants to follow some rules:

She must use exactly all cherries and all strawberries she has.
The number of cakes can be arbitrary (i.e., any positive integer).
Different cakes may contain different amounts of cherries and strawberries.
Each cake must contain at least one cherry and at least one strawberry.
A cake will taste bad if the number of cherries and the number of strawberries it contains happen to be coprime. Therefore, the numbers of cherries and strawberries in a cake must never be coprime. (Two positive integers are coprime if their greatest common divisor is 1.)

You are given the ints c and s.
Return "Possible" if Ciel can bake cakes according to the above rules, or "Impossible" if she cannot do so.


DEFINITION
Class:FoxAndCake2
Method:isPossible
Parameters:int, int
Returns:string
Method signature:string isPossible(int c, int s)


CONSTRAINTS
-c will be between 1 and 1,000,000,000, inclusive.
-s will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
74
109

Returns: "Possible"

One possible solution is to bake 3 cakes as follows:

A cake with 21 cherries and 14 strawberries.
A cake with 20 cherries and 40 strawberries.
A cake with 33 cherries and 55 strawberries.


1)
1000000000
1000000000

Returns: "Possible"

Here Ciel can simply make one huge cake with 1000000000 cherries and 1000000000 strawberries.


2)
1
58

Returns: "Impossible"

Ciel only has 1 cherry, so the only option is to bake one cake with 1 cherry and 58 strawberries.
However, 1 and 58 are coprime, so this is not a good cake.

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

class FoxAndCake2 {

	bool possible(int c, int s) {
		if (c > s) {
			swap(c, s);
		}
		switch (c) {
		case 0:
		case 1:
			return false;
		case 2:
		case 4:
			return s % 2 == 0;
		case 3:
			return s % 3 == 0;
		case 5:
			return s != 6;
		case 6:
			return (s % 6) != 1 && (s % 6) != 5;
		}
		return true;
	}

public:
	string isPossible(int c, int s) {
		return possible(c, s) ? "Possible" : "Impossible";
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 74;
			int Arg1 = 109;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 1000000000;
			string Arg2 = "Possible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 58;
			string Arg2 = "Impossible";

			verify_case(n, Arg2, isPossible(Arg0, Arg1));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndCake2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
