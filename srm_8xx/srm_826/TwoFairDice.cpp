// BEGIN CUT HERE
/*
SRM 826 Div1 Easy (300)

PROBLEM STATEMENT

Alice and Bob are going to play a simple dice game.

In the game, each player has their own six-sided die. Each player rolls their die and they look at the numbers they rolled. Whoever has the bigger number wins. If both numbers are the same, the game ends in a tie (nobody wins).

Alice and Bob like to play the game with custom dice. These don't have numbers 1 to 6 on their sides. Instead, the players choose what numbers they put onto their dice. They can choose any integer between 0 and 1000, inclusive, for each face. They can also put the same number on multiple faces of their die.

The game is considered fair if each player has the same probability of winning it.

Alice has already chosen the numbers on her die. You are given these in the vector <int> A. Bob has already chosen some of the six numbers on his die. You are given these in the vector <int> B. 

Bob wants to choose the remaining numbers for his die so that his game with Alice will be fair. Can he do that? If yes, how many different options does he have? Count them and return their count.
Remember that each of Bob's missing numbers must also be an integer between 0 and 1000, inclusive.


DEFINITION
Class:TwoFairDice
Method:finish
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long finish(vector <int> A, vector <int> B)


NOTES
-Treat the ways of adding the numbers to Bob's die as ordered sequences of integers. For example, adding {1, 2, 2} and adding {2, 2, 1} should be counted as two separate options.
-(Equivalently, imagine that each of the faces of Bob's die is painted in a different color, and two ways are only equal if both numbers and colors match.)


CONSTRAINTS
-A will have exactly 6 elements.
-Each element of A will be between 0 and 1000, inclusive.
-B will have between 0 and 6 elements, inclusive.
-Each element of B will be between 0 and 1000, inclusive.


EXAMPLES

0)
{1, 2, 3, 4, 5, 6}
{6, 2, 3, 1, 5}

Returns: 1

The only way to make these two dice fair is to add the number 4 onto Bob's last face, thus creating two dice with the exact same probability distribution.


1)
{1, 2, 3, 4, 5, 6}
{7, 8, 9, 10}

Returns: 0

Regardless of what two numbers we add to Bob's die, he will be the favorite in the game. There is no way to make these two dice fair.


2)
{1, 2, 3, 4, 5, 6}
{7, 8, 9}

Returns: 1

The only way to make these two dice fair is to add three zeros.


3)
{500, 500, 500, 500, 500, 500}
{}

Returns: 312505625007500001

Some of the very many ways to create a fair die for Bob in this test case include {500, 500, 500, 500, 500, 500}, {500, 100, 500, 500, 987, 500}, {987, 100, 500, 500, 500, 500}, and {1, 2, 3, 999, 998, 997}.


4)
{2, 4, 6, 8, 10, 12}
{1, 3, 5, 9, 11, 13}

Returns: 1

Both dice are already complete and they happen to be fair, so there's exactly one valid way of finishing Bob's die: do nothing :)


5)
{10, 10, 11, 12, 12, 12}
{11, 12, 12}

Returns: 3

The only way that works here is adding a 12 and two 10s, thus making the two dice essentially equivalent. This should be counted as three ways: we can add {10, 10, 12}, {10, 12, 10}, or {12, 10, 10}.


6)
{10, 10, 11, 12, 12, 12}
{10, 10, 10, 12}

Returns: 1976

Here we cannot make the two dice have the same multiset of values: Bob's die already has more 10s than Alice. But we can still make the game fair: we have to add one 12 and one number greater than 12 (i.e., anything in the 13-1000 range).

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

class TwoFairDice {
public:
	long long finish(vector <int> A, vector <int> B) {
		long long ans;
		vector<long long> dp(100);
		dp[50] = 1;
		for (long long i = 0; i < A.size(); ++i) {
			vector<long long> next(100);
			for (long long j = 0; j <= 1000; ++j) {
				if (i >= B.size() || B[i] == j) {
					long long c = 0;
					for (int k = 0; k < A.size(); ++k) {
						c += j > A[k];
						c -= j < A[k];
					}
					for (long long k = 0; k < 100; ++k) {
						if (dp[k] > 0) {
							next[k + c] += dp[k];
						}
					}
				}
			}
			dp = next;
		}
		return dp[50];
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6};
			int Arr1[] = {6, 2, 3, 1, 5};
			long long Arg2 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6};
			int Arr1[] = {7, 8, 9, 10};
			long long Arg2 = 0LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6};
			int Arr1[] = {7, 8, 9};
			long long Arg2 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {500, 500, 500, 500, 500, 500};
			// int Arr1[] = {};
			long long Arg2 = 312505625007500001LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 4, 6, 8, 10, 12};
			int Arr1[] = {1, 3, 5, 9, 11, 13};
			long long Arg2 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 10, 11, 12, 12, 12};
			int Arr1[] = {11, 12, 12};
			long long Arg2 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 10, 11, 12, 12, 12};
			int Arr1[] = {10, 10, 10, 12};
			long long Arg2 = 1976LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, finish(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoFairDice ___test;
	___test.run_test(-1);
}
// END CUT HERE
