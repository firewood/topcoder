// BEGIN CUT HERE
/*
SRM 590 Div2 Medium (500)

問題
-碁盤がある
-黒を1手打ったとき、白が取れる最大の個数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class FoxAndGo {

	int N;
	vector <string> b;
	int v[64][64];

	int dfs(int x, int y) {
		const int dx[] = {-1,1,0,0};
		const int dy[] = {0,0,-1,1};
		if (x < 0 || x >= N || y < 0 || y >= N) {
			return 0;
		}
		if (b[y][x] == 'x') {
			return 0;
		}
		if (b[y][x] == '.') {
			return -10000;
		}
		if (v[y][x]) {
			return 0;
		}
		v[y][x] = 1;
		int sum = 1;
		for (int i = 0; i < 4; ++i) {
			sum += dfs(x + dx[i], y + dy[i]);
		}
		return sum;
	}

public:
	int maxKill(vector <string> board) {
		N = (int)board.size();
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (board[i][j] == '.') {
					int sum = 0;
					b = board;
					b[i][j] = 'x';
					memset(v, 0, sizeof(v));
					for (int y = 0; y < N; ++y) {
						for (int x = 0; x < N; ++x) {
							sum += max(0, dfs(x, y));
						}
					}
					ans = max(ans, sum);
				}
			}
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
			string Arr0[] = {".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}
;
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}
;
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}
;
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}
;
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}
;
			int Arg1 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}
;
			int Arg1 = 12;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 ;
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;

		// test_case_8
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}
;
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;


		// test_case_17
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"oo.ooo", "oooooo", ".oo.oo", "oo.ooo", ".oo.oo", "ooooo."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxKill(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndGo ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
