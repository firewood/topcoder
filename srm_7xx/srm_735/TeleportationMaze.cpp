// BEGIN CUT HERE
/*
SRM 735 Div2 Medium (600)

問題
-升目状に区切られた2次元の迷路がある
-各升目は空白 . か壁 # である。
-上下左右の隣接する空白の升目へ移動するのに1秒かかる
-上下左右方向で最も近い空白の升目へワープするのに2秒かかる
-初期位置と目標位置が与えられる
-目標位置に移動する最小の時間を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TeleportationMaze {
	vector <string> b;
	int gy;
	int gx;
	unsigned int cost[50][50];
	unsigned int dfs(int y, int x, int c) {
		unsigned int r = -1;
		cost[y][x] = c;
		if (y == gy && x == gx) {
			return c;
		}
		const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
		for (int d = 0; d < 4; ++d) {
			for (int i = 1; i < 50; ++i) {
				int ny = y + dy[d] * i, nx = x + dx[d] * i;
				if (ny >= 0 && ny < b.size() && nx >= 0 && nx < (int)b[0].length() && b[ny][nx] != '#') {
					unsigned int nc = c + (i == 1 ? 1 : 2);
					if (nc < cost[ny][nx]) {
						r = min(r, dfs(ny, nx, nc));
					}
					break;
				}
			}
		}
		return r;
	}

public:
	int pathLength(vector <string> a, int r1, int c1, int r2, int c2) {
		memset(cost, -1, sizeof(cost));
		b = a, gy = r2, gx = c2;
		return dfs(r1, c1, 0);
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
			string Arr0[] = {".##.",
 ".###",
 ".###",
 "...."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 3;
			int Arg4 = 3;
			int Arg5 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.",
 ".#"};
			int Arg1 = 0;
			int Arg2 = 1;
			int Arg3 = 1;
			int Arg4 = 0;
			int Arg5 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"......",
 "#####.",
 "#.###.",
 "#####.",
 "#.###.",
 "#####.",
 "#....."};
			int Arg1 = 0;
			int Arg2 = 0;
			int Arg3 = 6;
			int Arg4 = 1;
			int Arg5 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg5, pathLength(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TeleportationMaze ___test;
	___test.run_test(-1);
}
// END CUT HERE
