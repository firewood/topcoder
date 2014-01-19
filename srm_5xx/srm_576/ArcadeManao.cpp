// BEGIN CUT HERE
/*
SRM 576 Div1 Easy (256)

問題
-古いアーケードゲーム
-水平のプレートがある
-プレート上の水平移動か、梯子でプレート間の垂直移動ができる
-プレート上のどこかにコインがある
-コインを取るのに最小の長さの梯子を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;

class ArcadeManao {

	int _r;
	int _c;
	int _w;
	int _h;
	StrVec _lev;
	int f[51][51];

	bool dfs(int x, int y, int len) {
		f[y][x] = 1;
		if (x == _c && y == _r) {
			return true;
		}
		int i, j;
		for (i = -1; i <= 1; i += 2) {
			j = x + i;
			if (j >= 0 && j < _w && !f[y][j] && _lev[y][j] == 'X') {
				if (dfs(j, y, len)) {
					return true;
				}
			}
		}
		for (i = -len; i <= len; ++i) {
			j = y + i;
			if (j >= 0 && j < _h && !f[j][x] && _lev[j][x] == 'X') {
				if (dfs(x, j, len)) {
					return true;
				}
			}
		}
		return false;
	}

public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
		_r = coinRow - 1;
		_c = coinColumn - 1;
		_w = (int)level[0].length();
		_h = (int)level.size();
		_lev = level;
		int len;
		for (len = 0; len <= 50; ++len) {
			memset(f, 0, sizeof(f));
			if (dfs(0, _h - 1, len)) {
				break;
			}
		}
		return len;
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
			string Arr0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
			int Arg1 = 2;
			int Arg2 = 4;
			int Arg3 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXX",
 "...X",
 "XXXX"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
			int Arg1 = 1;
			int Arg2 = 3;
			int Arg3 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"X"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, shortestLadder(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ArcadeManao ___test;
	___test.run_test(-1);
}
// END CUT HERE
