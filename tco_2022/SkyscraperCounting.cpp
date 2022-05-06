// BEGIN CUT HERE
/*
TCO22 R1A Hard (1000)

PROBLEM STATEMENT

There are N skyscrapers built in a row.
The bases of all N skyscrapers all stand on one line that goes from the west to the east.

Each skyscraper has between 1 and N floors, inclusive.
No two skyscrapers have the same number of floors.

An observer is looking at the row of skyscrapers from an observation point that is far to the west from all of them.
For this observer, some skyscrapers are at least partially visible while others are completely invisible.
More precisely, a skyscraper floor is visible to the observer if and only if no skyscraper to the west of this one has a floor of the same height.

Below is one sample scene. Arrows ("->") indicate the direction in which we look at the skyscrapers (west is on the left of the figure). There are seven skyscrapers, each shown as one column of 'X's and 'O's. Floors visible to the observer are shown as 'O', floors hidden behind other skyscrapers are shown as 'X'. 

->                   O
->                   O  X
->          O        X  X
->          O  X     X  X
->    O     X  X     X  X
->    O     X  X  X  X  X
->    O  X  X  X  X  X  X
=============================

You are given the string visibility with N characters.
For each skyscraper, from the west to the east, this string contains either the character 'O' (uppercase oh) or the character 'X'.
The character 'O' represents a skyscraper with some visible floors, the character 'X' a skyscraper with no visible floors.

For the sample scene shown above, visibility = "OXOXXOX".

In other words, visibility tells you what the scene with skyscrapers looks when viewed from above. 
For each skyscraper, from the left to the right, you are told whether its topmost floor is 'O' (visible from the west) or 'X' (hidden behind another skyscraper when looking from the west).

Count all permutations of skyscrapers that correspond to the given string visibility.
Return that count modulo (10^9 + 7).


DEFINITION
Class:SkyscraperCounting
Method:count
Parameters:string
Returns:int
Method signature:int count(string visibility)


CONSTRAINTS
-visibility will have between 1 and 100 characters, inclusive.
-Each character in visibility will be either 'O' or 'X'.


EXAMPLES

0)
"OXXXX"

Returns: 24

We can deduce that the leftmost skyscraper must be the tallest one (5 floors). Each of the 4! = 24 orders of the other four skyscrapers works.


1)
"OXOXXOX"

Returns: 72

This input corresponds to the figure in the problem statement. 
The skyscrapers shown in the figure have heights {3, 1, 5, 4, 2, 7, 6}, and this is one of the 72 permutations of heights that produce the given visibility pattern.

Some of the other permutations with the same visibility pattern:

{3, 1, 5, 2, 4, 7, 6}

{2, 1, 5, 3, 4, 7, 6}

{4, 3, 6, 5, 1, 7, 2}


2)
"XOXOXO"

Returns: 0

No such permutations: the westmost skyscraper is always visible.


3)
"OXXXXXXXXXXXXXO"

Returns: 227020758

Remember to compute the answer modulo 10^9 + 7.

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

const int64_t MOD = 1000000007;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class SkyscraperCounting {
public:
	int count(string visibility) {
		int N = (int)visibility.length();
		modint ans = 0;
		vector<vector<modint>> dp(101, vector<modint>(101, 0));
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			vector<vector<modint>> next(101, vector<modint>(101, 0));
			if (visibility[i] == 'O') {
				for (int h = 1; h <= N; ++h) {
					for (int i = 0; i < h; ++i) {
						for (int j = 0; j <= 100; ++j) {
							int k = j + h - i - 1;
							if (k <= 100) {
								next[h][k] += dp[i][j];
							}
						}
					}
				}
			} else {
				for (int h = 1; h <= N; ++h) {
					for (int j = 1; j <= 100; ++j) {
						next[h][j - 1] += dp[h][j] * j;
					}
				}
			}
			dp = next;
		}
		for (int i = 0; i <= 100; ++i) {
			ans += accumulate(dp[i].begin(), dp[i].end(), modint(0));
		}
		return ans;
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
			string Arg0 = "OXXXX";
			int Arg1 = 24;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "OXOXXOX";
			int Arg1 = 72;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "XOXOXO";
			int Arg1 = 0;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "OXXXXXXXXXXXXXO";
			int Arg1 = 227020758;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SkyscraperCounting ___test;
	___test.run_test(-1);
}
// END CUT HERE
