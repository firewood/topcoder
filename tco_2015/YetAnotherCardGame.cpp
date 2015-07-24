// BEGIN CUT HERE
/*
TCO 2015 Round 2C Easy (250)

問題
-1以上の整数が書かれたカードが何枚かある
-PetrとSnukeにN枚ずつ配り、交互に1枚ずつ出す
-場にカードがないか、場のカードより大きな数のときだけ積むことができる
-詰めないときはカードを捨てる
-場に積める枚数の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class YetAnotherCardGame {
public:
	int maxCards(vector <int> petr, vector <int> snuke) {
		int dp[101][101];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		int N = (int)petr.size();
		for (int i = 0; i < N * 2; ++i) {
			IntVec &v = (i & 1) ? snuke : petr;
			for (int j = 0; j <= 100; ++j) {
				if (dp[i][j] >= 0) {
					dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
					for (int k = 0; k < N; ++k) {
						if (v[k] > j) {
							dp[i + 1][v[k]] = max(dp[i][j] + 1, dp[i + 1][v[k]]);
						}
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= 100; ++i) {
			ans = max(ans, dp[N * 2][i]);
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
			int Arr0[] = {2, 5};
			int Arr1[] = {3, 1};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1};
			int Arr1[] = {1, 1, 1, 1, 1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 4, 6, 7, 3};
			int Arr1[] = {1, 7, 1, 5, 7};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29};
			int Arr1[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83};
			int Arg2 = 28;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCards(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	YetAnotherCardGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
