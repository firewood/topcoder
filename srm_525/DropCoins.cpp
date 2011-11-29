// BEGIN CUT HERE
/*
// SRM 525 Div2 Medium 600)
// PROBLEM STATEMENT
// There is a rectangle divided into 1x1 cells. Each cell is either empty or it contains a single coin. 

You can apply the following operation repeatedly.

First, choose one of the directions: up, down, left, or right. 
Then, move all coins in the chosen direction by exactly 1 cell. If this would cause a coin to move out of the rectangle, the coin drops out from the rectangle and disappears. 

Your objective in this problem is to apply the operations so that the number of coins remaining on the rectangle becomes exactly K.

You are given the int K and a vector <string> board that describes the initial state of the rectangle. More precisely, character j of element i of board is 'o' if i-th row of j-th column of the rectangle contains a coin, and it is '.' otherwise.

Return the minimum number of operations you have to perform. If the objective is impossible, return -1.

DEFINITION
Class:DropCoins
Method:getMinimum
Parameters:vector <string>, int
Returns:int
Method signature:int getMinimum(vector <string> board, int K)


CONSTRAINTS
-board will contain between 1 and 30 elements, inclusive.
-Each element of board will contain between 1 and 30 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character in each element of board will be either '.' or 'o'.
-K will be between 1 and 900, inclusive.


EXAMPLES

0)
{".o.."
,"oooo"
,"..o."}

3

Returns: 2

One of the optimal solutions is to move coins to the right twice.

1)
{".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}

12

Returns: 3

One of the optimal solutions:

move coins up (1 coin drops, 13 remain) 
move coins down 
move coins down again (1 coin drops, 12 remain) 


2)
{"...."
,".oo."
,".oo."
,"...."}

3

Returns: -1

It is impossible to make the number of remaining coins exactly 3.

3)
{"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}

12

Returns: 4



4)
{"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}

58

Returns: 6



#line 112 "DropCoins.cpp"
*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class DropCoins {

public:
	int getMinimum(vector <string> board, int K) {
		int result = 32 * 32;
		int height = board.size();
		int width = board[0].length();

		char B[32][32];
		memset(B, 0, sizeof(B));
		int c = 0;
		int i, j, k, l;
		for (i = 0; i < height; ++i) {
			const string &s = board[i];
			for (j = 0; j < width; ++j) {
				B[i][j] = s[j] == 'o';
				c += B[i][j];
			}
		}
		if (K == c) {
			return 0;
		}
		if (K > c) {
			return -1;
		}

		for (i = 0; i <= height; ++i) {
			for (j = 0; j <= height; ++j) {
				if ((i + j) > height) {
					break;
				}
				int J = height - 1 - j;
				for (k = 0; k < width; ++k) {
					for (l = 0; l < width; ++l) {
						if ((k + l) > width) {
							break;
						}
						int L = width - 1 - l;
						int x, y;
						c = 0;
						for (y = i; y <= J; ++y) {
							for (x = k; x <= L; ++x) {
								c += B[y][x];
							}
						}
						if (K == c) {
							int r;
							int a = min(i, j);
							int b = max(i, j);
							r = b+a*2;
							a = min(k, l);
							b = max(k, l);
							r += b+a*2;
							result = min(result, r);
						}
					}
				}
			}
		}

		return result < 32*32 ? result : -1;
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
			string Arr0[] = {
				".o..",
				"oooo",
				"..o."
			};
			int Arg1 = 3;
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMinimum(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				".....o",
				"......",
				"oooooo",
				"oooooo",
				"......",
				"o....."
			};
			int Arg1 = 12;
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMinimum(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"....",
				".oo.",
				".oo.",
				"...."
			};
			int Arg1 = 3;
			int Arg2 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMinimum(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				".......",
				"..ooo..",
				"ooooooo",
				".oo.oo.",
				"oo...oo"
			};
			int Arg1 = 12;
			int Arg2 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMinimum(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				".................",
				".ooooooo...oooo..",
				".ooooooo..oooooo.",
				".oo.......oo..oo.",
				".oo.......oo..oo.",
				".ooooo.....oooo..",
				".ooooooo...oooo..",
				".....ooo..oo..oo.",
				"......oo..oo..oo.",
				".ooooooo..oooooo.",
				".oooooo....oooo..",
				"................."
			};
			int Arg1 = 58;
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMinimum(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DropCoins ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
