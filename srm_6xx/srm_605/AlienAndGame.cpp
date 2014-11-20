// BEGIN CUT HERE
/*
SRM 605 Div2 Medium (500)

問題
-エイリアンのFredは地球を滅ぼす前にゲームで遊ぶことにした
-黒か白の升目がある
-任意の行の色を反転することができる
-同じ色の最大の長方形の大きさを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AlienAndGame {
public:
	int getNumber(vector <string> board) {
		int H = (int)board.size();
		int W = (int)board[0].length();
		int cnt[64][64] = {};
		int ans = 1;
		for (int i = 0; i < H; ++i) {
			cnt[i][0] = 1;
			for (int j = 1; j < W; ++j) {
				if (board[i][j-1] == board[i][j]) {
					int k = cnt[i][j-1] + 1;
					cnt[i][j] = k;
					int l;
					for (l = 1; l <= i; ++l) {
						k = min(k, cnt[i-l][j]);
						if (k <= l) {
							break;
						}
						ans = max(ans, (l+1)*(l+1));
					}
				} else {
					cnt[i][j] = 1;
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
			string Arr0[] = {"BB",
 "WW"};
			int Arg1 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"WBBB",
 "WBBB",
 "WWWW"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"W",
 "B",
 "W",
 "W",
 "W"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"BWBBWBB",
 "WWBWWBW",
 "BBBBBBW",
 "WBBBBWB",
 "BBWWWWB",
 "WWWWWWW",
 "BBWWBBB"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlienAndGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
