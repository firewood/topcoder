// BEGIN CUT HERE
/*
// SRM 525 Div2 Medium (600)

問題

升目にコインが乗っている。
盤全体を上下左右いずれかに動かすことにより、乗っているコインを落とせる。
残ったコインをK枚にするための最小の手数を答える。


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
