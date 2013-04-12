// BEGIN CUT HERE
/*
SRM 574 Div1 Easy (275)

// PROBLEM STATEMENT
// Manao has recently invented a brand new game called The Number Game. He usually plays this game against his friend.

Initially, Manao has an integer A and his friend has an integer B. Note that neither A nor B contain a zero digit in their base 10 representation.
The players make moves alternatively with Manao starting first.
In each move, the player can either reverse his current number, or he can divide it by 10 (using integer division).
For example, if the current number is 12849, the player can either reverse it to obtain 94821, or he can divide it by 10 to obtain 1284.
Note that we always round down when using integer division.
Also note that each player is only allowed to change his own number, and not the number of the other player.

If after some move the players' numbers become equal, Manao is declared the winner. If after 1000 moves (that is, 500 moves by Manao and 500 by his friend) Manao has not won, he loses. Given A and B, determine whether Manao would win if both players play optimally. Return "Manao wins" or "Manao loses" accordingly.


DEFINITION
Class:TheNumberGame
Method:determineOutcome
Parameters:int, int
Returns:string
Method signature:string determineOutcome(int A, int B)


CONSTRAINTS
-A will be between 1 and 999,999,999, inclusive.
-B will be between 1 and 999,999,999, inclusive.
-A and B will not contain a zero digit in base 10 representation.
-A and B will be distinct.


EXAMPLES

0)
45
4

Returns: "Manao wins"

Manao can win in one move by dividing his number by 10.

1)
45
5

Returns: "Manao wins"

There are several possible scenarios this game can follow:

Manao divides by 10 and obtains 4. Now his opponent can reverse his number and obtain 5 again. Obviously, no matter what Manao does in his next 499 moves, his opponent can evade him.
Manao reverses his number and obtains 54. His opponent reverses his 5. Manao divides 54 by 10 and obtains 5, thus making the numbers equal
Manao reverses his number and obtains 54. His opponent divides by 10 and obtains zero. Manao will win in three moves, dividing his number by 10 twice.

Obviously, Manao will not choose to divide by 10 in his first move and will win.


2)
99
123

Returns: "Manao loses"

No matter how Manao plays, the opponent can perform reverse moves until the end of the game.


3)
2356236
5666

Returns: "Manao loses"

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheNumberGame {

public:
	string determineOutcome(int A, int B) {
		char a[64];
		sprintf(a, "%d", A);
		char b[64];
		sprintf(b, "%d", B);
		string r = a;
		reverse(r.begin(), r.end());
		return (strstr(a, b) != NULL || strstr(r.c_str(), b) != NULL)
				? "Manao wins" : "Manao loses";
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
			int Arg0 = 45;
			int Arg1 = 4;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 45;
			int Arg1 = 5;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 99;
			int Arg1 = 123;
			string Arg2 = "Manao loses";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2356236;
			int Arg1 = 5666;
			string Arg2 = "Manao loses";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 12345;
			int Arg1 = 54321;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 12345;
			int Arg1 = 12345;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 11112;
			int Arg1 = 112;
			string Arg2 = "Manao wins";

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheNumberGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
