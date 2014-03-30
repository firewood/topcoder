// BEGIN CUT HERE
/*
SRM 602 Div1 Easy (250)

問題
-LowerはTypoCoderに参加している
-レーティング2200未満が水色、2200以上が茶色である
-一回の増減が配列Dで与えられる
-増えるか減るかのどちらかを選べる
-0未満にはならない
-2回連続で茶色になりたくない
-レーティングの変化回数の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class TypoCoderDiv1 {
public:
	int getmax(vector <int> D, int X) {
		int N = (int)D.size();
		int dp[64][2200];
		memset(dp, -1, sizeof(dp));
		dp[0][X] = 0;
		for (int i = 0; i < N; ++i) {
			for (int r = 0; r < 2200; ++r) {
				if (dp[i][r] >= 0) {
					// win
					int next = r + D[i];
					if (next >= 2200) {
						if (i == N-1) {
							// any rating is OK
							dp[N][0] = max(dp[N][0], dp[i][r] + 1);
						} else {
							int nn = max(0, next - D[i+1]);
							if (nn < 2200) {
								dp[i+2][nn] = max(dp[i+2][nn], dp[i][r] + 2);
							}
						}
					} else {
						dp[i+1][next] = max(dp[i+1][next], dp[i][r]);
					}
					// lose
					next = max(0, r - D[i]);
					dp[i+1][next] = max(dp[i+1][next], dp[i][r]);
				}
			}
		}

		int ans = 0;
		for (int r = 0; r < 2200; ++r) {
			ans = max(ans, dp[N][r]);
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
			int Arr0[] = {100,200,100,1,1};
			int Arg1 = 2000;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0};
			int Arg1 = 2199;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
			int Arg1 = 0;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000,1000000000,10000,100000,2202,1};
			int Arg1 = 1000;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
			int Arg1 = 2199;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
			int Arg1 = 1223;
			int Arg2 = 29;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
			int Arg1 = 1328;
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TypoCoderDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
