// BEGIN CUT HERE
/*
// SRM 555 Div1 Easy (250)

// PROBLEM STATEMENT
// We are in a distant future.
After the downfall of mankind, the Earth is now ruled by fairies.
The "Turing game Online" website is hot among fairies right now.
On this website, everyone can play the programming puzzle "Turing game".

Fairies love powers of 5, that is, the numbers 1, 5, 25, 125, 625, and so on.
In the Turing game, the player is given a string of bits (zeros and ones).
The ideal situation is when the string is represents a power of 5 in binary, with no leading zeros.
If that is not the case, the fairy player tries to cut the given string into pieces, each piece being a binary representation of a power of 5, with no leading zeros.
Of course, it may be the case that even this is impossible.
In that case, the fairy player becomes depressed, and bad things happen when a fairy gets depressed.
You, as one of the surviving humans, are in charge of checking the bit strings to prevent the bad things from happening.

You are given a string S that consists of characters '0' and '1' only.
S represents the string given to a player of the Turing game.
Return the smallest positive integer K such that it is possible to cut S into K pieces, each of them being a power of 5.
If there is no such K, return -1 instead.


DEFINITION
Class:CuttingBitString
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be either '0' or '1'.


EXAMPLES

0)
"101101101"

Returns: 3

We can split the given string into three "101"s.
Note that "101" is 5 in binary.


1)
"1111101"

Returns: 1

"1111101" is 5^3.


2)
"00000"

Returns: -1

0 is not a power of 5.


3)
"110011011"

Returns: 3

Split it into "11001", "101" and "1".


4)
"1000101011"

Returns: -1


5)
"111011100110101100101110111"

Returns: 5

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class CuttingBitString {

	int len;
	LL N;
	int memo[60];
	int rec(int pos) {
		int &res = memo[pos];
		if (res >= 0) {
			return res;
		}
		res = 9999;
		int r = len - pos;
		LL x = N & ((1LL << r) - 1);
		if (x & (1LL << (r-1))) {
			int i;
			for (i = 1; i <= r; ++i) {
				LL y = (x >> (r-i));
				while (y > 1 && ((y % 5) == 0)) {
					y /= 5;
				}
				if (y == 1) {
					res = min(res, 1 + rec(pos + i));
				}
			}
		}
		return res;
	}

public:
	int getmin(string S) {
		memset(memo, -1, sizeof(memo));
		len = (int)S.length();
		N = 0;
		int i;
		for (i = 0; i < (int)S.length(); ++i) {
			if (S[i] != '0') {
				N |= (1LL << (S.length() - i - 1));
			}
		}
		memo[S.length()] = 0;
		int res = rec(0);
		return res < 9999 ? res : -1;
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
			string Arg0 = "101101101";
			int Arg1 = 3;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1111101";
			int Arg1 = 1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "00000";
			int Arg1 = -1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "110011011";
			int Arg1 = 3;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1000101011";
			int Arg1 = -1;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "111011100110101100101110111";
			int Arg1 = 5;

			verify_case(n, Arg1, getmin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CuttingBitString ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
