// BEGIN CUT HERE
/*
SRM 726 Div2 Medium (500)

問題
-盤面が与えられる
-左下からスタートして、右下がゴール
-右か下だけ進める
-二人で交互にひとつずつ升目を通れなくしていく
-ゴールに到達できない状態になった方が負け
-先手が勝つかどうかを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TurtleGame {
	bool win(vector <string> &board) {
		int f[20][20] = {};
		f[0][0] = 1;
		int i, j;
		for (i = 0; i != board.size(); ++i) {
			for (j = 0; j != board[0].length(); ++j) {
				if (board[i][j] == '.') {
					if ((j > 0 && f[i][j - 1]) || (i > 0 && f[i - 1][j])) {
						f[i][j] = 1;
					}
				}
			}
		}
		i = board.size() - 1, j = board[0].length() - 1;
		if (!f[i][j]) {
			return true;
		}
		while (i > 0 || j > 0) {
			f[i][j] = 2;
			if (i > 0 && f[i - 1][j]) {
				--i;
			} else {
				--j;
			}
		}
		for (i = 0; i != board.size(); ++i) {
			for (j = 0; j != board[0].length(); ++j) {
				if (board[i][j] == '.' && f[i][j] != 2) {
					board[i][j] = '#';
					return !win(board);
				}
			}
		}
		return false;
	}

public:
	string getwinner(vector <string> board) {
		board[0][0] = 'S';
		board[board.size() - 1][board[0].length()] = 'G';
		for (int i = 0; i != board.size(); ++i) {
			for (int j = 0; j != board[0].length(); ++j) {
				if (board[i][j] == '.') {
					vector <string> b = board;
					b[i][j] = '#';
					if (!win(b)) {
						return "Win";
					}
				}
			}
		}
		return "Lose";
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
			string Arr0[] = {"..",
 ".."};
			string Arg1 = "Win";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 ".#.",
 ".#.",
 "..."};
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".##",
 "..#",
 "#.."};
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"....",
 "...#",
 "#...",
 "...."};
			string Arg1 = "Win";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...#.",
 "....#",
 "#....",
 "..##."};
			string Arg1 = "Win";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..........",
 "........#."};
			string Arg1 = "Lose";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getwinner(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TurtleGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
