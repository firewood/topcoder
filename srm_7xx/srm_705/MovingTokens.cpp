// BEGIN CUT HERE
/*
SRM 705 Div1 Medium (450)

PROBLEM STATEMENT
Fox Ciel is going to play a game with tokens.
She has n bins, numbered 0 through n-1.
At the beginning of the game each bin contains a single token.
During the game each bin may contain arbitrarily many tokens.

Fox Ciel also has a rectangular matrix M with n rows and m columns.
You are given the ints n and m.
You are also given a vector <int> moves that encodes the content of M.
For each i from 0 to n-1, inclusive, and for each j between 0 and m-1, inclusive, M[i][j] = moves[j*n+i].

The matrix M describes the valid moves Ciel can make in the game.
Each turn of the game looks as follows:

Ciel chooses the value of j: an integer between 0 and m-1.
For each i between 0 and n-1, inclusive, Ciel moves all tokens from bin i into bin M[i][j].


Note that all movement in step 2 occurs simultaneously.
For example, if she wants to move all tokens from bin 0 to bin 1 and all tokens from bin 1 to bin 0, the bins 0 and 1 swap their content.

The game Fox Ciel plays consists of exactly 10^100 turns, each of the form described above.
Her goal is to minimize the number of bins that contain some tokens at the end of the game.
Calculate the best possible result she can obtain.
In other words, return the smallest K such that Ciel can play the game in such a way that at the end of the game only K of the bins contain some tokens.


DEFINITION
Class:MovingTokens
Method:move
Parameters:int, int, vector <int>
Returns:int
Method signature:int move(int n, int m, vector <int> moves)


CONSTRAINTS
-n will be between 1 and 50 inclusive.
-m will be between 1 and 50 inclusive.
-moves will contain exactly n * m elements.
-Each element of moves will be between 0 and n-1.


EXAMPLES

0)
2
2
{0,1,
0,1}

Returns: 2

There are two bins.
At the beginning of the game, each bin contains a token.
In each turn of the game Ciel will choose either j=0 or j=1.
Regardless of which j she chooses, the result will be that she should move all tokens from bin 0 to bin 0 and all tokens from bin 1 to bin 1.
That is, nothing changes, all tokens stay where they were.
Thus, after 10^100 turns we still have two bins that each contain a token.


1)
2
2
{0,0,
1,1}

Returns: 1

This is the same setting as in Example 0, only the matrix M is different.
The choice j=0 now means "put everything into bin 0" and the choice j=1 now means "put everything into bin 1".
Regardless of how Ciel plays the game, after 10^100 turns one of the bins will contain both tokens and the other bin will be empty.


2)
3
1
{0,1,1}

Returns: 2


3)
2
5
{0,0,
 0,0,
 0,0,
 1,1,
 1,1}

Returns: 1


4)
3
2
{0,2,2,
 1,1,0}

Returns: 1

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static const long long TC_SEC = 2800000000LL;
static const long long TC_TIME_LIMIT = (TC_SEC * 17) / 10;

#ifndef _MSC_VER
unsigned long long __rdtsc() {
	unsigned int low, high;
	__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
	return low | ((unsigned long long)high << 32);
}
#endif

class MovingTokens {
public:
	int move(int n, int m, vector <int> moves) {
		long long start = __rdtsc();
		int ans = n;
		while ((__rdtsc() - start) < TC_TIME_LIMIT) {
			int a[2][50];
			fill(a[0], a[0] + n, 1);
			for (int i = 0; i < 10000; ++i) {
				int prev = i & 1;
				int next = prev ^ 1;
				fill(a[next], a[next] + n, 0);
				int r = rand() % m;
				for (int j = 0; j < n; ++j) {
					if (a[prev][j]) {
						a[next][moves[r * n + j]] = 1;
					}
				}
			}
			ans = min(ans, accumulate(a[0], a[0] + n, 0));
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
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {0,1,
0,1};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, move(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {0,0,
1,1};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, move(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1;
			int Arr2[] = {0,1,1};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, move(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 5;
			int Arr2[] = {0,0,
 0,0,
 0,0,
 1,1,
 1,1};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, move(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arr2[] = {0,2,2,
 1,1,0};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, move(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 50;
			int Arr2[] = { 0, 0, 1, 0, 2, 0, 2, 2, 1, 5, 4, 9, 1, 11, 11, 7, 1, 12, 15, 14, 0, 10, 6, 22, 9, 45, 28, 41, 32, 30, 44, 32, 38, 41, 39, 42, 37, 49, 39, 40, 46, 42, 46, 48, 47, 47, 48, 48, 49, 49, 0, 0, 0, 1, 1, 4, 4, 0, 2, 2, 6, 2, 7, 4, 1, 12, 11, 14, 12, 0, 18, 11, 4, 4, 23, 45, 45, 29, 33, 44, 32, 42, 37, 37, 38, 40, 44, 40, 41, 42, 48, 45, 43, 47, 48, 49, 49, 49, 49, 49, 0, 0, 0, 0, 0, 2, 2, 5, 1, 3, 9, 0, 1, 10, 2, 1, 11, 9, 0, 0, 3, 2, 19, 3, 23, 27, 48, 29, 46, 49, 32, 44, 43, 40, 44, 43, 49, 48, 46, 49, 45, 46, 46, 45, 49, 47, 48, 48, 49, 49, 0, 0, 0, 1, 1, 0, 3, 1, 5, 6, 5, 2, 2, 6, 13, 4, 9, 11, 13, 13, 15, 18, 9, 6, 20, 48, 41, 31, 34, 46, 45, 34, 36, 46, 45, 40, 40, 45, 48, 42, 48, 47, 46, 48, 46, 46, 48, 49, 49, 49, 0, 0, 1, 2, 0, 2, 2, 0, 2, 7, 5, 10, 2, 7, 9, 4, 6, 7, 13, 14, 16, 17, 5, 2, 3, 43, 32, 47, 38, 49, 41, 49, 41, 48, 48, 43, 39, 39, 43, 49, 41, 48, 44, 49, 45, 48, 47, 48, 49, 49, 0, 0, 1, 1, 3, 1, 1, 5, 6, 6, 7, 6, 2, 5, 3, 2, 12, 16, 3, 3, 3, 2, 2, 13, 19, 41, 27, 35, 30, 44, 40, 37, 41, 48, 38, 41, 44, 42, 42, 47, 47, 46, 44, 49, 46, 46, 47, 49, 49, 49, 0, 0, 1, 2, 0, 3, 5, 4, 4, 0, 2, 0, 7, 11, 9, 14, 11, 5, 16, 6, 17, 14, 19, 16, 17, 44, 37, 33, 32, 30, 40, 42, 44, 37, 48, 47, 39, 49, 42, 49, 42, 49, 45, 48, 48, 47, 47, 48, 49, 49, 0, 0, 0, 0, 0, 2, 5, 4, 4, 2, 6, 2, 11, 5, 13, 0, 12, 16, 4, 3, 19, 5, 4, 8, 7, 40, 49, 35, 43, 42, 37, 46, 36, 49, 38, 44, 42, 48, 46, 44, 45, 49, 44, 47, 46, 47, 49, 49, 49, 49, 0, 0, 0, 2, 3, 3, 3, 2, 2, 3, 5, 5, 0, 3, 9, 6, 14, 14, 3, 2, 11, 2, 13, 22, 11, 32, 39, 37, 31, 43, 31, 32, 42, 47, 39, 39, 39, 47, 48, 41, 41, 47, 49, 45, 48, 47, 47, 48, 49, 49, 0, 0, 1, 1, 2, 2, 2, 6, 4, 5, 7, 6, 4, 8, 8, 1, 10, 10, 6, 2, 0, 1, 16, 5, 21, 41, 31, 39, 41, 43, 35, 33, 34, 39, 47, 37, 38, 48, 45, 42, 47, 47, 45, 44, 46, 46, 48, 49, 49, 49, 0, 0, 0, 0, 2, 3, 4, 4, 1, 6, 9, 10, 6, 4, 6, 0, 2, 4, 12, 2, 10, 6, 12, 19, 1, 26, 48, 43, 32, 47, 40, 45, 48, 34, 35, 47, 43, 45, 48, 44, 48, 46, 47, 48, 46, 49, 49, 49, 49, 49, 0, 0, 1, 1, 1, 4, 0, 2, 7, 6, 1, 8, 4, 0, 12, 10, 4, 3, 14, 1, 5, 10, 14, 10, 8, 43, 29, 45, 37, 30, 33, 42, 43, 42, 38, 40, 40, 45, 43, 42, 41, 49, 44, 47, 45, 46, 47, 49, 49, 49, 0, 0, 1, 1, 0, 3, 3, 4, 5, 6, 3, 7, 10, 0, 7, 10, 1, 2, 15, 11, 11, 18, 4, 6, 3, 43, 34, 29, 33, 38, 48, 37, 39, 44, 41, 41, 40, 44, 40, 49, 45, 49, 49, 44, 49, 47, 48, 48, 49, 49, 0, 0, 1, 0, 0, 2, 5, 3, 0, 7, 4, 4, 2, 5, 2, 10, 7, 7, 7, 12, 17, 7, 0, 8, 0, 48, 30, 38, 42, 38, 31, 32, 34, 37, 43, 39, 47, 41, 41, 45, 41, 43, 49, 44, 46, 48, 49, 49, 49, 49, 0, 0, 1, 1, 3, 4, 4, 2, 4, 7, 6, 0, 6, 6, 3, 8, 7, 14, 17, 10, 15, 10, 4, 12, 23, 48, 40, 29, 33, 44, 31, 33, 49, 37, 41, 49, 39, 43, 45, 46, 49, 46, 46, 46, 46, 46, 48, 48, 49, 49, 0, 0, 0, 2, 1, 1, 4, 0, 7, 6, 5, 3, 2, 3, 13, 5, 5, 7, 9, 6, 17, 2, 20, 13, 16, 48, 44, 37, 38, 32, 41, 42, 45, 38, 39, 47, 40, 49, 43, 48, 45, 48, 44, 45, 46, 47, 48, 48, 49, 49, 0, 0, 1, 1, 2, 3, 2, 3, 5, 8, 2, 9, 2, 8, 13, 8, 6, 5, 4, 14, 12, 0, 12, 12, 0, 29, 34, 28, 33, 35, 42, 47, 38, 42, 37, 40, 46, 42, 48, 47, 44, 49, 48, 48, 47, 47, 47, 49, 49, 49, 0, 0, 1, 2, 2, 3, 0, 1, 5, 3, 8, 1, 10, 7, 1, 8, 7, 11, 1, 6, 10, 18, 2, 11, 5, 40, 40, 47, 47, 43, 49, 41, 49, 43, 49, 40, 45, 43, 42, 40, 41, 49, 45, 48, 46, 47, 47, 49, 49, 49, 0, 0, 0, 0, 2, 1, 1, 2, 0, 8, 7, 4, 2, 9, 3, 12, 13, 4, 12, 15, 3, 0, 5, 19, 2, 45, 37, 37, 38, 46, 48, 45, 35, 48, 44, 42, 46, 47, 44, 41, 42, 46, 44, 45, 45, 46, 48, 48, 49, 49, 0, 0, 0, 0, 1, 2, 5, 2, 2, 2, 3, 0, 6, 8, 4, 7, 3, 11, 10, 9, 6, 1, 10, 2, 23, 47, 30, 42, 40, 30, 34, 45, 37, 43, 37, 40, 47, 41, 49, 49, 42, 44, 47, 44, 47, 48, 49, 49, 49, 49, 0, 0, 0, 2, 0, 2, 5, 5, 5, 2, 0, 1, 10, 0, 4, 14, 0, 13, 0, 17, 16, 17, 2, 14, 10, 27, 35, 29, 49, 41, 48, 35, 40, 45, 40, 45, 40, 45, 48, 40, 43, 48, 47, 45, 47, 47, 49, 48, 49, 49, 0, 0, 1, 0, 3, 3, 2, 6, 0, 6, 3, 5, 2, 11, 10, 11, 3, 3, 0, 8, 3, 11, 14, 6, 23, 39, 36, 44, 30, 38, 39, 46, 49, 44, 43, 39, 47, 47, 45, 45, 42, 49, 44, 45, 47, 46, 49, 48, 49, 49, 0, 0, 1, 2, 0, 4, 5, 6, 3, 0, 0, 1, 11, 2, 12, 4, 11, 10, 9, 18, 9, 7, 15, 20, 3, 32, 41, 30, 47, 47, 42, 37, 49, 34, 44, 42, 40, 49, 39, 42, 42, 44, 47, 45, 45, 49, 49, 48, 49, 49, 0, 0, 1, 1, 3, 3, 5, 0, 4, 5, 8, 1, 3, 8, 4, 2, 14, 13, 0, 11, 3, 15, 6, 14, 5, 43, 47, 37, 33, 35, 41, 49, 40, 39, 35, 45, 38, 42, 40, 43, 44, 42, 48, 49, 47, 48, 48, 49, 49, 49, 0, 0, 0, 2, 1, 0, 3, 0, 6, 2, 1, 7, 6, 9, 11, 13, 9, 4, 15, 7, 12, 13, 0, 20, 3, 46, 46, 43, 46, 47, 40, 42, 46, 38, 41, 39, 42, 42, 45, 42, 46, 49, 47, 45, 46, 49, 47, 48, 49, 49, 0, 0, 0, 0, 1, 0, 5, 4, 2, 2, 0, 2, 5, 8, 13, 7, 9, 2, 7, 4, 7, 2, 14, 10, 8, 30, 32, 37, 44, 46, 37, 49, 41, 40, 35, 49, 47, 39, 49, 46, 46, 48, 49, 45, 48, 47, 47, 49, 49, 49, 0, 0, 0, 0, 3, 3, 0, 0, 2, 3, 7, 0, 0, 11, 5, 10, 1, 13, 16, 4, 14, 14, 15, 4, 1, 45, 44, 41, 34, 43, 41, 36, 36, 42, 36, 40, 48, 48, 48, 40, 42, 42, 43, 46, 49, 46, 47, 48, 49, 49, 0, 0, 0, 0, 0, 4, 1, 1, 7, 7, 2, 5, 2, 3, 4, 14, 2, 0, 15, 3, 13, 14, 21, 22, 11, 26, 33, 47, 34, 46, 47, 39, 42, 34, 44, 46, 47, 44, 40, 47, 46, 48, 43, 47, 47, 47, 48, 48, 49, 49, 0, 0, 1, 2, 3, 1, 3, 0, 2, 8, 2, 5, 5, 4, 12, 2, 3, 2, 11, 15, 10, 17, 9, 20, 13, 30, 49, 44, 43, 36, 43, 43, 44, 49, 35, 49, 37, 49, 46, 49, 42, 45, 43, 45, 45, 46, 49, 49, 49, 49, 0, 0, 1, 1, 2, 2, 5, 4, 7, 8, 9, 4, 7, 8, 12, 2, 13, 16, 6, 1, 4, 20, 15, 19, 7, 32, 49, 45, 43, 32, 41, 38, 42, 34, 43, 49, 37, 44, 46, 41, 42, 46, 43, 44, 47, 48, 48, 49, 49, 49, 0, 0, 0, 2, 3, 2, 2, 3, 4, 1, 7, 7, 2, 1, 4, 13, 4, 1, 2, 13, 17, 1, 21, 2, 1, 34, 32, 34, 45, 39, 46, 41, 34, 37, 43, 48, 44, 49, 48, 48, 48, 45, 48, 47, 45, 48, 49, 49, 49, 49, 0, 0, 1, 1, 0, 0, 3, 2, 4, 7, 2, 7, 10, 3, 7, 2, 0, 9, 8, 7, 16, 0, 18, 10, 16, 42, 39, 49, 46, 49, 31, 42, 46, 40, 49, 48, 37, 38, 48, 48, 41, 45, 48, 45, 46, 47, 49, 49, 49, 49, 0, 0, 0, 2, 3, 3, 1, 5, 5, 2, 0, 6, 5, 2, 1, 14, 3, 5, 13, 0, 3, 6, 21, 0, 7, 32, 40, 39, 33, 40, 36, 35, 39, 48, 39, 48, 42, 47, 44, 46, 41, 46, 43, 47, 45, 47, 49, 48, 49, 49, 0, 0, 1, 1, 3, 4, 3, 0, 0, 1, 9, 6, 9, 5, 2, 14, 3, 4, 0, 7, 12, 7, 7, 11, 1, 39, 27, 45, 36, 33, 40, 37, 41, 36, 48, 48, 41, 44, 42, 46, 41, 49, 43, 48, 45, 46, 48, 49, 49, 49, 0, 0, 0, 2, 3, 1, 4, 2, 2, 1, 9, 9, 8, 1, 8, 6, 7, 4, 5, 3, 18, 12, 3, 16, 3, 34, 38, 38, 30, 47, 49, 45, 49, 35, 40, 42, 42, 49, 44, 44, 49, 45, 43, 48, 46, 46, 47, 49, 49, 49, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 25, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 0, 0, 0, 2, 0, 0, 3, 0, 7, 2, 4, 8, 3, 0, 6, 8, 8, 16, 2, 5, 3, 15, 18, 20, 0, 36, 28, 45, 35, 31, 44, 34, 33, 37, 41, 48, 47, 44, 47, 48, 48, 46, 49, 45, 45, 49, 49, 48, 49, 49, 0, 0, 1, 1, 3, 4, 2, 6, 7, 3, 2, 4, 6, 1, 1, 3, 8, 7, 15, 13, 17, 6, 10, 5, 1, 45, 41, 40, 39, 42, 38, 42, 37, 42, 48, 45, 41, 41, 49, 49, 49, 47, 47, 44, 49, 47, 48, 48, 49, 49, 0, 0, 1, 1, 2, 4, 2, 3, 6, 3, 8, 2, 6, 0, 2, 12, 4, 6, 14, 1, 4, 6, 13, 22, 10, 44, 35, 39, 47, 43, 46, 36, 46, 45, 47, 48, 49, 48, 46, 43, 49, 43, 47, 49, 49, 46, 47, 48, 49, 49, 0, 0, 0, 1, 1, 1, 3, 5, 2, 3, 5, 5, 7, 3, 4, 7, 7, 4, 3, 3, 4, 4, 5, 22, 10, 44, 30, 42, 37, 35, 48, 35, 37, 41, 36, 45, 45, 43, 47, 42, 44, 49, 48, 49, 46, 46, 48, 48, 49, 49, 0, 0, 0, 1, 3, 2, 2, 0, 3, 1, 5, 10, 4, 7, 11, 4, 8, 9, 8, 18, 11, 13, 4, 5, 12, 26, 48, 29, 44, 38, 44, 33, 43, 38, 40, 44, 49, 42, 46, 42, 44, 43, 48, 49, 48, 47, 48, 49, 49, 49, 0, 0, 1, 0, 0, 4, 2, 6, 3, 0, 6, 6, 11, 1, 12, 7, 13, 10, 17, 7, 18, 12, 12, 4, 20, 42, 44, 36, 46, 37, 43, 40, 45, 40, 41, 42, 42, 39, 40, 45, 41, 44, 48, 46, 46, 47, 49, 49, 49, 49, 0, 0, 0, 1, 1, 2, 2, 5, 3, 5, 8, 4, 0, 3, 8, 12, 9, 9, 15, 6, 1, 20, 9, 11, 4, 29, 39, 47, 32, 31, 38, 46, 42, 45, 37, 39, 42, 45, 45, 43, 46, 45, 49, 49, 49, 46, 48, 49, 49, 49, 0, 0, 0, 1, 3, 3, 3, 1, 4, 6, 9, 10, 9, 8, 7, 5, 15, 0, 2, 17, 15, 9, 14, 3, 20, 48, 44, 41, 48, 33, 44, 37, 45, 41, 36, 43, 48, 45, 44, 41, 48, 45, 49, 47, 47, 49, 48, 49, 49, 49, 0, 0, 1, 0, 1, 2, 5, 4, 1, 2, 5, 10, 10, 1, 13, 8, 3, 15, 1, 15, 17, 15, 17, 14, 18, 33, 46, 47, 34, 48, 33, 48, 38, 47, 38, 45, 38, 49, 47, 44, 42, 49, 49, 47, 48, 46, 48, 48, 49, 49, 0, 0, 1, 0, 2, 0, 5, 3, 4, 7, 3, 0, 10, 5, 13, 10, 1, 7, 1, 3, 2, 12, 2, 1, 1, 30, 39, 34, 37, 30, 38, 33, 33, 38, 49, 49, 42, 40, 48, 49, 42, 49, 47, 44, 47, 48, 49, 48, 49, 49, 0, 0, 0, 0, 3, 4, 1, 2, 4, 2, 5, 5, 6, 4, 13, 3, 4, 10, 12, 1, 18, 7, 18, 1, 2, 31, 41, 41, 29, 35, 45, 38, 48, 48, 35, 48, 43, 47, 44, 45, 47, 48, 48, 45, 46, 49, 49, 49, 49, 49, 0, 0, 0, 1, 2, 0, 2, 0, 0, 5, 3, 8, 10, 6, 3, 0, 9, 6, 6, 1, 19, 11, 0, 11, 19, 36, 38, 38, 39, 39, 47, 45, 42, 47, 37, 46, 42, 38, 46, 46, 43, 47, 49, 48, 49, 46, 47, 49, 49, 49, 0, 0, 0, 1, 2, 3, 4, 4, 7, 1, 4, 7, 10, 2, 4, 0, 1, 13, 0, 12, 17, 6, 8, 2, 8, 46, 47, 39, 45, 38, 46, 44, 47, 46, 35, 43, 42, 41, 49, 42, 42, 43, 49, 48, 46, 48, 48, 48, 49, 49, 0, 0, 0, 2, 1, 2, 1, 4, 5, 6, 7, 10, 8, 9, 7, 14, 13, 8, 2, 1, 2, 12, 21, 22, 10, 44, 47, 30, 35, 40, 41, 40, 47, 45, 40, 48, 40, 38, 40, 48, 45, 42, 49, 47, 49, 46, 49, 48, 49, 49 };
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, move(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MovingTokens ___test;
	___test.run_test(-1);
}
// END CUT HERE
