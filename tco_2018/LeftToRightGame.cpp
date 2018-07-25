// BEGIN CUT HERE
/*
TCO18 R3A Easy (250)

PROBLEM STATEMENT
Alice and Bob are playing a simple game. They take alternating turns writing the digits of a positive integer, from the left to the right. Alice starts. The number is not allowed to start with a zero, hence Alice must choose one of the digits 1 through 9 as her first move.

The game ends when the number has exactly length digits. Bob wins the game if that number is divisible by divisor. Alice wins in all other cases.

You are given the ints length and divisor. Return the name of the player who wins if both of them play the game optimally.


DEFINITION
Class:LeftToRightGame
Method:whoWins
Parameters:int, int
Returns:string
Method signature:string whoWins(int length, int divisor)


CONSTRAINTS
-length will be between 1 and 1000, inclusive.
-divisor will be between 1 and 1000, inclusive.


EXAMPLES

0)
4
10

Returns: "Bob"

Alice and Bob are creating a 4-digit number. Bob wins if the number ends up being divisible by 10. As he is the one who will write down the last digit of the number, he has a very obvious winning strategy.


1)
3
1000

Returns: "Alice"

A positive three-digit integer will never be divisible by 1000. Alice wins this game regardless of how she and Bob play it.


2)
2
3

Returns: "Bob"


3)
147
47

Returns: "Alice"

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class LeftToRightGame {
public:
	bool win(int length, int divisor) {
		int st = 1;
		while (length > 4) {
			st = 0;
			length -= 2;
		}
		bool ok = false;
		switch (length) {
		case 1:
		{
			for (int i = st; i <= 9; ++i) {
				if (i % divisor) {
					ok = true;
				}
			}
		}
		break;
		case 2:
		{
			for (int i = st; i < 10; ++i) {
				bool f = false;
				for (int j = 0; j < 10; ++j) {
					int m = i * 10 + j;
					if ((m % divisor) == 0) {
						f = true;
						break;
					}
				}
				if (!f) {
					ok = true;
					break;
				}
			}
		}
		break;
		case 3:
		{
			for (int i = st; i < 10; ++i) {
				int a = 0;
				for (int j = 0; j < 10; ++j) {
					for (int k = 0; k < 10; ++k) {
						int m = i * 100 + j * 10 + k;
						if (m % divisor) {
							++a;
							break;
						}
					}
				}
				if (a >= 10) {
					ok = true;
					break;
				}
			}
		}
		break;
		case 4:
		{
			for (int i = st; i < 10; ++i) {
				int a = 0;
				for (int j = 0; j < 10; ++j) {
					for (int k = 0; k < 10; ++k) {
						int b = 1;
						for (int l = 0; l < 10; ++l) {
							int m = i * 1000 + j * 100 + k * 10 + l;
							if ((m % divisor) == 0) {
								b = 0;
								break;
							}
						}
						if (b) {
							++a;
							break;
						}
					}
				}
				if (a >= 10) {
					ok = true;
					break;
				}
			}
		}
		break;
		}
		return ok;
	}

	string whoWins(int length, int divisor) {
		return win(length, divisor) ? "Alice" : "Bob";
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
			int Arg0 = 4;
			int Arg1 = 10;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1000;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 147;
			int Arg1 = 47;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;




		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1000;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 12;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 11;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			int Arg1 = 1;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 11;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 12;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 6;
			int Arg1 = 12;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftToRightGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
