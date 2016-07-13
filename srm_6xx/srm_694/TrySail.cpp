// BEGIN CUT HERE
/*
SRM 694 Div1 Easy (250)

問題
-N人の生徒がいる
-各生徒の強さが非負の整数で与えられる
-3グループにわける
-各グループの強さは、グループ内の生徒の強さのXORである
-3グループの強さの最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TrySail {
public:
	int get(vector <int> strength) {
		int N = (int)strength.size();
		int dp[60][256][256] = {};
		dp[0][0][0] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 256; ++j) {
				for (int k = 0; k < 256; ++k) {
					if (dp[i][j][k]) {
						dp[i + 1][j][k] = 1;
						dp[i + 1][j ^ strength[i]][k] = 1;
						dp[i + 1][j][k ^ strength[i]] = 1;
					}
				}
			}
		}
		int tot = 0;
		for (int i = 0; i < N; ++i) {
			tot ^= strength[i];
		}
		int ans = 0;
		for (int j = 0; j < 256; ++j) {
			for (int k = 0; k < 256; ++k) {
				if (dp[N][j][k]) {
					ans = max(ans, j + k + (tot ^ j ^ k));
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
			int Arr0[] = {2,3,3};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,3,5,2};
			int Arg1 = 17;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13,13,13,13,13,13,13,13};
			int Arg1 = 26;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {114,51,4,191,9,81,0,89,3};
			int Arg1 = 470;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
			int Arg1 = 567;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrySail ___test;
	___test.run_test(-1);
}
// END CUT HERE
