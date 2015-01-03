// BEGIN CUT HERE
/*
SRM 637 Div1 Medium (500)

問題
-縦2マスの通路がある
-升目は白か黒で、白い升目だけ通れる
-2人で交互に升目を黒く塗る
-ただし左端から右端まで通れる状態を維持する必要がある
-塗れないほうが負け
-最善手のときの勝者を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef set<int> IntSet;

class PathGame {

	int W;
	int b[1002];
	int memo[3][1000][3];

	int get_grundy_number(int L, int N, int R) {
		if (N <= 1) {
			return N >= 1 && (L | R) < 3;
		}
		int &ret = memo[L][N][R];
		if (ret >= 0) {
			return ret;
		}

		IntSet s;
		for (int i = 0; i < N; ++i) {
			if (i == 0) {
				if ((L & 2) == 0) {
					s.insert(get_grundy_number(1, N-1, R));
				}
				if ((L & 1) == 0) {
					s.insert(get_grundy_number(2, N-1, R));
				}
			} else if (i == N-1) {
				if ((R & 2) == 0) {
					s.insert(get_grundy_number(L, N-1, 1));
				}
				if ((R & 1) == 0) {
					s.insert(get_grundy_number(L, N-1, 2));
				}
			} else {
				s.insert(get_grundy_number(L, i, 1) ^ get_grundy_number(1, N-i-1, R));
				s.insert(get_grundy_number(L, i, 2) ^ get_grundy_number(2, N-i-1, R));
			}
		}
		for (ret = 0; s.count(ret) > 0; ++ret) {
			;
		}
		return ret;
	}

	bool solve(void) {
		int g = 0;
		int pos = 1;
		while (pos <= W) {
			while (pos <= W && b[pos] != 0) {
				++pos;
			}
			int s = pos;
			while (pos <= W && b[pos] == 0) {
				++pos;
			}
			g ^= get_grundy_number(b[s - 1], pos - s, b[pos]);
		}
		return g != 0;
	}

public:
	string judge(vector <string> board) {
		W = (int)board[0].length();
		memset(b, 0, sizeof(b));
		memset(memo, -1, sizeof(memo));
		for (int i = 0; i < W; ++i) {
			b[i + 1] = (board[0][i] == '#') + (board[1][i] == '#') * 2;
		}
		return solve() ? "Snuke" : "Sothe";
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
			string Arr0[] = {"#..","..."};
			string Arg1 = "Snuke";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#","."};
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....","..#.."};
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#...","....."};
			string Arg1 = "Snuke";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".....#..#........##.......","..........#..........#...."};
			string Arg1 = "Snuke";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "..", ".." };
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "..#", "#.." };
			string Arg1 = "Sothe";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, judge(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PathGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
