// BEGIN CUT HERE
/*
SRM 636 Div1 Easy (250)

問題
-チョコレートを9分割する
-それぞれの部分の合計値がその部分の品質になる
-もっとも品質が低い部分の最高値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class ChocolateDividingEasy {

	int hsum[64][64];

	int calc(int sx, int sy, int ex, int ey) {
		int sum = 0;
		for (int i = sy; i <= ey; ++i) {
			sum += hsum[i][ex + 1] - hsum[i][sx];
		}
		return sum;
	}

public:
	int findBest(vector <string> chocolate) {
		memset(hsum, 0, sizeof(hsum));
		int W = chocolate[0].length(), H = chocolate.size();
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				hsum[i][j + 1] = hsum[i][j] + chocolate[i][j] - '0';
			}
		}
		int ans = 0;
		for (int i = 1; i < H; ++i) {
			for (int j = i + 1; j < H; ++j) {
				for (int k = 1; k < W; ++k) {
					for (int l = k + 1; l < W; ++l) {
						int m[9] = {
							calc(0, 0, k - 1, i - 1), calc(k, 0, l - 1, i - 1), calc(l, 0, W - 1, i - 1),
							calc(0, i, k - 1, j - 1), calc(k, i, l - 1, j - 1), calc(l, i, W - 1, j - 1),
							calc(0, j, k - 1, H - 1), calc(k, j, l - 1, H - 1), calc(l, j, W - 1, H - 1)
						};
						ans = max(ans, *min_element(m, m + 9));
					}
				}
			}
		}
		return ans;

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
"9768",
"6767",
"5313"
};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
};
			int Arg1 = 15;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {
"012",
"345",
"678"
};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findBest(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChocolateDividingEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
