// BEGIN CUT HERE
/*
SRM 651 Div1 Easy (250)

問題
-月にロボットがいる
-有効な座標の範囲、および、ロボットと障害物の座標が与えられる
-上下左右のいずれからなる一連のコマンドを送信する
-コマンドの任意の部分が欠損する可能性がある
-ロボットが地図からはみ出さないコマンドの最大長を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RobotOnMoon {
public:
	int longestSafeCommand(vector <string> board) {
		int W = (int)board[0].length();
		int H = (int)board.size();
		for (int i = 0; i < H; ++i) {
			int x = (int)board[i].find('S');
			if (x >= 0) {
				if (board[i].find('#') != string::npos) {
					return -1;
				}
				for (int j = 0; j < H; ++j) {
					if (board[j][x] == '#') {
						return -1;
					}
				}
			}
		}
		return W + H - 2;
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
			string Arr0[] = {"#####",
 "#...#",
 "#.S.#",
 "#...#",
 "#####"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"S......"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.######",
 "#.#..S.#",
 "#.#.##.#",
 "#......#",
 "########"};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"S"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
				"........S......" };
			int Arg1 = 14;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, longestSafeCommand(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RobotOnMoon ___test;
	___test.run_test(-1);
}
// END CUT HERE
