// BEGIN CUT HERE
/*
SRM 707 Div2 Medium (500)

問題
-N×Mマスの盤面がある
-障害物がなければ上下左右に移動できる
-左上から右下まで、ちょうどKステップとなるような移動経路を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;

class StepsConstruct {

public:
	string construct(vector <string> board, int k) {
		int H = (int)board.size();
		int W = (int)board[0].length();
		int vis[50][50];
		memset(vis, -1, sizeof(vis));
		vector<II> q;
		if (board[0][0] == '.') {
			vis[0][0] = 0;
			q.push_back(II(0, 0));
		}
		for (int dist = 1; q.size(); ++dist) {
			vector<II> next;
			for (auto &v : q) {
				int dx[] = { -1,1,0,0 };
				int dy[] = { 0,0,-1,1 };
				for (int dir = 0; dir < 4; ++dir) {
					int nx = v.second + dx[dir], ny = v.first + dy[dir];
					if (nx >= 0 && nx < W && ny >= 0 && ny < H && board[ny][nx] == '.' && vis[ny][nx] < 0) {
						vis[ny][nx] = dist;
						next.push_back(II(ny, nx));
					}
				}
			}
			q = next;
		}
		int x = W - 1, y = H - 1;
		int g = vis[y][x];
		if (g < 0 || g > k || (g % 2) != (k % 2)) {
			return "";
		}
		string seq;
		for (int dist = vis[H - 1][W - 1]; dist > 0; --dist) {
			int dx[] = { -1,1,0,0 };
			int dy[] = { 0,0,-1,1 };
			const char *s = "RLDU";
			for (int dir = 0; dir < 4; ++dir) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx >= 0 && nx < W && ny >= 0 && ny < H && vis[ny][nx] == (dist - 1)) {
					x = nx, y = ny, seq += s[dir];
					break;
				}
			}
		}
		while (g < k) {
			if (board[0][1] == '.') {
				seq += "LR";
			} else {
				seq += "UD";
			}
			g += 2;
		}
		reverse(seq.begin(), seq.end());
		return seq;
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
			string Arr0[] = {"...",
 ".#.",
 "..."};
			int Arg1 = 4;
			string Arg2 = "DDRR";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...",
 ".#.",
 "..."};
			int Arg1 = 12;
			string Arg2 = "DDRRUULLDDRR";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...#.",
 "..#..",
 ".#..."};
			int Arg1 = 100;
			string Arg2 = "";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..#",
 "#.#",
 "..#",
 ".#.",
 "..."};
			int Arg1 = 6;
			string Arg2 = "";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {".#...",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "...#."};
			int Arg1 = 16;
			string Arg2 = "DDDDRRUUUURRDDDD";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"#.", 
 ".."};
			int Arg1 = 2;
			string Arg2 = "";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, construct(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StepsConstruct ___test;
	___test.run_test(-1);
}
// END CUT HERE
