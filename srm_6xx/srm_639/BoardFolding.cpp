// BEGIN CUT HERE
/*
SRM 639 Div1 Medium (500)

問題
-升目上に白か黒が書かれた紙がある
-模様が完全に重なるとき、端から折りたたむことができる
-折りたたみの状態数を求める
*/
// END CUT HERE

#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BoardFolding {
	int H;
	int W;
	int b[256][256];
	int same[256][256];
	int l_foldable[256][256];
	int r_foldable[256][256];
	int vis[256][256];
	int ways;

	unsigned int tonumber(char c) {
		if (c >= '0' && c <= '9') {
			return c - '0';
		}
		if (c >= 'a' && c <= 'z') {
			return c - 'a' + 10;
		}
		if (c >= 'A' && c <= 'Z') {
			return c - 'A' + 36;
		}
		if (c == '#') {
			return 62;
		}
		return 63;
	}

	void dfs(int s, int e) {
		if (vis[s][e]) {
			return;
		}
		++ways;
		vis[s][e] = 1;
		int w = (e - s) / 2;
		for (int i = 1; i <= w; ++i) {
			if (r_foldable[s][i]) {
				dfs(s + i, e);
			}
		}
		for (int i = 1; i <= w; ++i) {
			if (l_foldable[e][i]) {
				dfs(s, e - i);
			}
		}
	}

	void setup(int height, int width) {
		H = height, W = width;
		memset(l_foldable, 0, sizeof(l_foldable));
		memset(r_foldable, 0, sizeof(r_foldable));
		memset(vis, 0, sizeof(vis));
		ways = 0;
		for (int i = 0; i < W; ++i) {
			same[i][i] = 0;
			for (int j = i+1; j < W; ++j) {
				int k;
				for (k = 0; k < H; ++k) {
					if (b[k][i] != b[k][j]) {
						break;
					}
				}
				same[i][j] = same[j][i] = k >= H;
			}
		}
		for (int i = 1; i < W; ++i) {
			for (int j = 1; j <= i && i+j <= W; ++j) {
				if (!same[i-j][i+j-1]) {
					break;
				}
				l_foldable[i+j][j] = 1;
				r_foldable[i-j][j] = 1;
			}
		}
	}

public:
	int howMany(int N, int M, vector <string> compressedPaper) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				b[i][j] = (tonumber(compressedPaper[i][j/6]) >> (j % 6)) & 1;
			}
		}
		setup(N, M);
		dfs(0, M);
		int ans = ways;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				b[j][i] = (tonumber(compressedPaper[i][j/6]) >> (j % 6)) & 1;
			}
		}
		setup(M, N);
		dfs(0, N);
		ans *= ways;
		return ans;
	}

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }
// END CUT HERE
};

// BEGIN CUT HERE
int main() {
	BoardFolding ___test;
	___test.run_test(-1);
}
// END CUT HERE
