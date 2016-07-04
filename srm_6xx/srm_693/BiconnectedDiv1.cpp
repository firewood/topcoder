// BEGIN CUT HERE
/*
SRM 693 Div1 Easy (250)

問題
-任意の頂点u,vについて、任意の辺eを取り除いてもuからvに到達可能なグラフを、2辺連結グラフと呼ぶ
-N個の頂点が与えられる
-頂点iとi+1には重みw1[i]の辺がある
-頂点iとi+2には重みw1[i]の辺がある
-2辺連結グラフを維持しながら、辺を除去するとき、重みの合計の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

static void update_min(int &a, int b) {
	if (a < 0 || b < a) {
		a = b;
	}
}

class BiconnectedDiv1 {

public:
	int minimize(vector <int> w1, vector <int> w2) {
		int N = (int)w1.size();
		w2.push_back(0);
		int dp[128][2];
		memset(dp, -1, sizeof(dp));
		dp[1][1] = w1[0] + w2[0];
		for (int i = 1; i < N; ++i) {
			if (dp[i][0] >= 0) {
				update_min(dp[i + 1][1], dp[i][0] + w1[i] + w2[i]);
			}
			if (dp[i][1] >= 0) {
				update_min(dp[i + 1][0], dp[i][1] + w1[i]);
				update_min(dp[i + 1][1], dp[i][1] + w2[i]);
			}
		}
		return dp[N][0];
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
			int Arr0[] = {1,2};
			int Arr1[] = {3};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,0,4};
			int Arr1[] = {1,2};
			int Arg2 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3,3,3};
			int Arr1[] = {3,6,3};
			int Arg2 = 18;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
			int Arr1[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
			int Arg2 = 46729;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimize(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BiconnectedDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
