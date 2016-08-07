// BEGIN CUT HERE
/*
SRM 588 Div2 Medium (500)

問題
-音程と長さからなる歌がいくつか与えられる
-連続して歌うとき、音程の差＋曲の長さの時間がかかる
-時間Tで歌える異なる曲の曲数の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class GUMIAndSongsDiv2 {
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		int ans = 0;

		IIVec v;
		for (int i = 0; i < (int)tone.size(); ++i) {
			v.push_back(II(tone[i], duration[i]));
		}
		sort(v.begin(), v.end());

		int dp[64][64];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < (int)v.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				for (int k = 1; k <= i; ++k) {
					dp[i][k + 1] = min(dp[i][k + 1], dp[j][k] + abs(v[i].first - v[j].first) + v[i].second);
					if (dp[i][k + 1] <= T) {
						ans = max(ans, k + 1);
					}
				}
			}
			dp[i][1] = v[i].second;
			if (v[i].second <= T) {
				ans = max(ans, 1);
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
			int Arr0[] = {3, 5, 4, 11};
			int Arr1[] = {2, 1, 3, 1};
			int Arg2 = 17;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 200, 300};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 10;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4};
			int Arr1[] = {1, 1, 1, 1};
			int Arg2 = 100;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 10, 10};
			int Arr1[] = {58, 58, 58};
			int Arg2 = 30;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 11, 7, 15, 9, 16, 7, 9};
			int Arr1[] = {3, 8, 5, 4, 2, 7, 4, 1};
			int Arg2 = 14;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
			int Arr1[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
			int Arg2 = 302606;
			int Arg3 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GUMIAndSongsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
