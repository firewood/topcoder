// BEGIN CUT HERE
/*
SRM 621 Div1 Easy (250)

問題
-16個の積み木がある
-それぞれの大きさは1×1×Hである
-4×4のグリッド状かつ縦に並べたとき、最大の表面積を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SixteenBricks {
public:
	int maximumSurface(vector <int> height) {
		sort(height.begin(), height.end());
		int h[6][6] = {};
		h[1][1] = height[15];
		h[1][3] = height[14];
		h[2][2] = height[13];
		h[2][4] = height[12];
		h[3][1] = height[11];
		h[3][3] = height[10];
		h[4][2] = height[9];
		h[4][4] = height[8];
		int seq[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		int ans = 0;
		do {
			h[1][2] = height[seq[0]];
			h[1][4] = height[seq[1]];
			h[2][1] = height[seq[2]];
			h[2][3] = height[seq[3]];
			h[3][2] = height[seq[4]];
			h[3][4] = height[seq[5]];
			h[4][1] = height[seq[6]];
			h[4][3] = height[seq[7]];
			int cnt = 16;
			for (int i = 1; i <= 4; ++i) {
				for (int j = 1; j <= 4; ++j) {
					cnt += max(0, h[i][j] - h[i - 1][j]);
					cnt += max(0, h[i][j] - h[i][j - 1]);
					cnt += max(0, h[i][j] - h[i][j + 1]);
					cnt += max(0, h[i][j] - h[i + 1][j]);
				}
			}
			ans = max(ans, cnt);
		} while (next_permutation(seq, seq + 8));
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
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			int Arg1 = 32;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumSurface(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
			int Arg1 = 64;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumSurface(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59};
			int Arg1 = 1798;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumSurface(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SixteenBricks ___test;
	___test.run_test(-1);
}
// END CUT HERE
