// BEGIN CUT HERE
/*
SRM 641 Div2 Easy (250)

問題
問題
-月にロボットがいる
-有効な座標の範囲、および、ロボットと障害物の座標が与えられる
-上下左右のいずれからなる一連のコマンドが与えられる
-コマンドの実行の結果、ロボットが有効な座標の範囲にいるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RobotOnMoonEasy {
public:
	bool check(const vector <string> &board, const string &S) {
		int W = (int)board[0].length();
		int H = (int)board.size();
		for (int y = 0; y < H; ++y) {
			int x = (int)board[y].find('S');
			if (x >= 0) {
				for (char c : S) {
					int dx, dy;
					switch (c) {
					case 'U': dx = 0, dy = -1; break;
					case 'D': dx = 0, dy = 1; break;
					case 'L': dx = -1, dy = 0; break;
					case 'R': dx = 1, dy = 0; break;
					}
					if (x + dx < 0 || x + dx >= W || y + dy < 0 || y + dy >= H) {
						return false;
					}
					if (board[y + dy][x + dx] != '#') {
						x += dx, y += dy;
					}
				}
				return true;
			}
		}
		return false;
	}

	string isSafeCommand(vector <string> board, string S) {
		return check(board, S) ? "Alive" : "Dead";
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
			string Arr0[] = {".....",
 ".###.",
 "..S#.",
 "...#."};
			string Arg1 = "URURURURUR";
			string Arg2 = "Alive";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isSafeCommand(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."};
			string Arg1 = "URURURURUR";
			string Arg2 = "Dead";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isSafeCommand(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....",
 ".###.",
 "..S..",
 "...#."};
			string Arg1 = "URURU";
			string Arg2 = "Alive";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isSafeCommand(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"};
			string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
			string Arg2 = "Alive";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isSafeCommand(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#.###"};
			string Arg1 = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
			string Arg2 = "Dead";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isSafeCommand(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"S"};
			string Arg1 = "R";
			string Arg2 = "Dead";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, isSafeCommand(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RobotOnMoonEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
