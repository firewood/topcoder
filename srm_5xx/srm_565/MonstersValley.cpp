// BEGIN CUT HERE
/*
// SRM 565 Div1 Easy (250)

問題
N匹のモンスターに順番に遭遇する
それぞれのモンスターは1～2枚の金貨で買収できる
遭遇したモンスターの恐ろしさが、買収したモンスターの恐ろしさの合計値を
超えている場合、モンスターを買収する必要があり、そうでない場合は
買収してもしなくてもよい
必要な金貨の枚数の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class MonstersValley {

public:
	int minimumPrice(vector<long long> dread, vector <int> price) {
		LL dp[51][101] = {};
		dp[0][price[0]] = dread[0];
		int sz = (int)dread.size();
		int i, j;
		for (i = 1; i < sz; ++i) {
			for (j = 1; j <= 100; ++j) {
				if (dp[i-1][j] > 0) {
					if (dp[i-1][j] >= dread[i]) {
						dp[i][j] = max(dp[i][j], dp[i-1][j]);
					}
					dp[i][j+price[i]] = max(dp[i][j+price[i]], dp[i-1][j]+dread[i]);
				}
			}
		}
		for (j = 1; j <= 100; ++j) {
			if (dp[sz-1][j] > 0) {
				break;
			}
		}
		return j;
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
			long Arr0[] = {8, 5, 10};
			int Arr1[] = {1, 1, 2};
			int Arg2 = 2;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimumPrice(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {1, 2, 4, 1000000000};
			int Arr1[] = {1, 1, 1, 2};
			int Arg2 = 5;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimumPrice(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {200, 107, 105, 206, 307, 400};
			int Arr1[] = {1, 2, 1, 1, 1, 2};
			int Arg2 = 2;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimumPrice(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long Arr0[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
			int Arr1[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
			int Arg2 = 5;

			vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimumPrice(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MonstersValley ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
