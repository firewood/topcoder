// BEGIN CUT HERE
/*
SRM 676 Div2 Medium (550)

問題
-r×cの升目がある
-出口EとトークンTが置かれている
-トークンは初期値kを持っていて、上下左右いずれかに動かすと1減る
-出口と重なるか、値がゼロになるとトークンは消滅する
-2人で交互に動かすとき、トークンを動かせなくなったほうが負け
-両者が最適な戦略を取るとき、勝者を求める

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

class BoardEscapeDiv2 {
	int W;
	int H;
	vector <string> b;
	int memo[64][64][8];

	int check(int x, int y, int k) {
		if (b[y][x] == 'E' || k <= 0) {
			return 0;
		}
		int &r = memo[y][x][k];
		if (r >= 0) {
			return r;
		}
		int g[8] = {};
		const int dx[] = { -1, 1, 0, 0 };
		const int dy[] = { 0, 0, -1, 1 };
		for (int d = 0; d < 4; ++d) {
			int xx = x + dx[d], yy = y + dy[d];
			if (xx >= 0 && xx < W && yy >= 0 && yy < H) {
				if (b[yy][xx] != '#') {
					g[check(xx, yy, k - 1)] = 1;
				}
			}
		}
		for (int i = 0; i < 8; ++i) {
			if (!g[i]) {
				r = i;
				break;
			}
		}
		return r;
	}

public:
	string findWinner(vector <string> s, int k) {
		if (k >= 4) {
			k = 4 + k % 4;
		}
		W = s[0].length();
		H = s.size();
		b = s;
		memset(memo, -1, sizeof(memo));
		int win = 0;
		for (int y = 0; y != s.size(); ++y) {
			for (int x = 0; x != s[0].length(); ++x) {
				if (s[y][x] == 'T') {
					win ^= check(x, y, k);
				}
			}
		}
		return win ? "Alice" : "Bob";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"T.#",
 "#.E"};
			int Arg1 = 3;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"E#E",
 "#T#",
 "E#E"};
			int Arg1 = 99;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#E...",
 "#...E",
 "E.T#.",
 "..#.."};
			int Arg1 = 13;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"TE"};
			int Arg1 = 50;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".T."};
			int Arg1 = 1;
			string Arg2 = "Alice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........................",
 "......EEE..EEE..E...E.....",
 ".....E.....E..E.EE.EE.....",
 "......EEE..EEE..E.E.E.....",
 ".........E.E.E..E...E.....",
 "......EEE..E..E.E...E.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......EEE..EEE...EEE......",
 ".....E........E.E.........",
 "......EEE.....E..EEE......",
 ".....E...E...E..E...E.....",
 "......EEE....E...EEE......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....EE...E...E..E.EEE.E...",
 "...E.....E...E..E.E...E...",
 "...E.EE..E...EEEE.EE..E...",
 "...E..E..E...E..E.E.......",
 "....EE...EEE.E..E.E...E...",
 "T........................."};
			int Arg1 = 100;
			string Arg2 = "Bob";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, findWinner(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoardEscapeDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
