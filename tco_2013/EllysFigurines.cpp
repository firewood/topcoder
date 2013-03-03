// BEGIN CUT HERE
/*
TCO13 Round 1B Medium (500)

問題
-グリッド上のボードにいくつかの人形が置かれている
-一回の操作で、連続するR行またはC列の人形を取り除くことができる
-最小の操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EllysFigurines {
public:
	int getMoves(vector <string> board, int R, int C) {
		int ans = 2000000000;
		int i, j;
		int H = (int)board.size();
		int W = (int)board[0].length();

		int d[16] = {};
		for (i = 0; i < H; ++i) {
			for (j = 0; j < W; ++j) {
				if (board[i][j] != '.') {
					d[i] |= (1<<j);
				}
			}
		}

		int m = 1 << W;
		for (int b = 0; b < m; ++b) {
			int cnt = 0;
			for (i = 0; i < W; ++i) {
				if ((1<<i) & b) {
					++cnt;
					i += C - 1;
				}
			}
			for (i = 0; i < H; ++i) {
				if (d[i] & ~b) {
					++cnt;
					i += R - 1;
				}
			}
			ans = min(ans, cnt);
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
			string Arr0[] = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"};
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"};
			int Arg1 = 2;
			int Arg2 = 2;
			int Arg3 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXXXX"};
			int Arg1 = 2;
			int Arg2 = 3;
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."};
			int Arg1 = 1;
			int Arg2 = 2;
			int Arg3 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getMoves(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysFigurines ___test;
	___test.run_test(-1);
}
// END CUT HERE
