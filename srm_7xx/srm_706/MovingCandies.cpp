// BEGIN CUT HERE
/*
SRM 706 Div1 Easy (250)

問題
-升目にいくつかキャンディーが置いてある
-左上から、キャンディーのあるところだけをたどって右下まで移動する
-キャンディーを何個移動する必要があるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;

class MovingCandies {
	int H;
	int W;
	int total;
	vector <string> b;
	int cost[401][20][20];

	void dfs(int c, int u, int y, int x) {
		int dy[] = { 0,0,-1,1 };
		int dx[] = { -1,1,0,0 };
		for (int d = 0; d < 4; ++d) {
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
				int nc = c + (b[ny][nx] == '.');
				int nu = u + (b[ny][nx] == '#');
				if ((nc + nu) <= total && nc < cost[nu][ny][nx]) {
					cost[nu][ny][nx] = nc;
					dfs(nc, nu, ny, nx);
				}
			}
		}
	}

public:
	int minMoved(vector <string> t) {
		H = (int)t.size(), W = (int)t[0].length();
		b = t;
		memset(cost, 0x3f, sizeof(cost));
		total = 0;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				total += t[i][j] == '#';
			}
		}
		int c = (b[0][0] == '.');
		cost[!c][0][0] = c;
		dfs(c, !c, 0, 0);
		int ans = 0x3f3f3f3f;
		for (int i = 0; i <= 400; ++i) {
			ans = min(ans, cost[i][H - 1][W - 1]);
		}
		return ans < 0x3f3f3f3f ? ans : -1;
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
			string Arr0[] = {
"#...###",
"#...#.#",
"##..#.#",
".#....#"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"#...###",
"#...#.#",
"##..###",
".#....#"
};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".#..",
"##..",
"..#.",
"..#.",
"..##",
"..##"
};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".....",
".###.",
"####.",
"....."
};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
".#...#.###.#",
"#.#.##......",
".#.#......#.",
"..#.......#.",
"##.........."
};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"###.#########..#####",
".#######.###########"
};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"..",
".."
};
			int Arg1 = -1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minMoved(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MovingCandies ___test;
	___test.run_test(-1);
}
// END CUT HERE
