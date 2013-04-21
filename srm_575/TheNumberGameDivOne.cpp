// BEGIN CUT HERE
/*
SRM 575 Div1 Easy (250)

PROBLEM STATEMENT
John and Brus play a game with a number.
The game starts with a positive integer n.
The two players take alternating turns, John starts.
Each move looks as follows:
Let C be the current value of the integer.
The current player has to choose a positive divisor of the number C, other than 1 and C.
Once he chooses the divisor, he has to subtract it from C.
The result is the new number with which the other player now starts his move.
If a player cannot make a valid move, he loses the game.


For example, if they start with n=15, one possible gameplay can look as follows:

John takes the number 15, chooses its divisor 3, and decreases the number to 15-3 = 12.
Brus takes the number 12, chooses its divisor 4, and decreases the number to 12-4 = 8.
John takes the number 8, chooses its divisor 2, and decreases the number to 8-2 = 6.
Brus takes the number 6, chooses its divisor 3, and decreases the number to 6-3 = 3.
John takes the number 3, and as there are no divisors other than 1 and 3, he has no valid move and thus he loses the game.


You are given the long long n.
Assume that both players use the optimal strategy while playing the game.
Return "John" (quotes for clarity) if John wins the game and "Brus" otherwise.


DEFINITION
Class:TheNumberGameDivOne
Method:find
Parameters:long long
Returns:string
Method signature:string find(long long n)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.


EXAMPLES

0)
6

Returns: "John"

John has two possible moves: either decrease 6 by 2 or decrease 6 by 3.
If he chooses the second option, Brus will have no possible moves, hence John will win the game.


1)
2

Returns: "Brus"


2)
747

Returns: "Brus"


3)
128

Returns: "Brus"

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class TheNumberGameDivOne {

public:
	string find(long long n) {
		while (n % 8 == 0) {
			n /= 4;
		}
		return (n % 2) == 0 && n != 2 ? "John" : "Brus";
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
			long long Arg0 = 6LL;
			string Arg1 = "John";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			string Arg1 = "Brus";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 747LL;
			string Arg1 = "Brus";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 128LL;
			string Arg1 = "Brus";

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4LL;
			string Arg1 = "John";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 8LL;
			string Arg1 = "Brus";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 16LL;
			string Arg1 = "John";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 32LL;
			string Arg1 = "Brus";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 64LL;
			string Arg1 = "John";
			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheNumberGameDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
