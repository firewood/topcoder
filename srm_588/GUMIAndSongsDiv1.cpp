// BEGIN CUT HERE
/*
SRM 588 Div1 Easy (250)

問題
-音程と長さからなる歌がいくつか与えられる
-連続して歌うとき、音程の差＋曲の長さの時間がかかる
-時間Tで歌える最大の曲数を求める

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

class GUMIAndSongsDiv1 {
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		IIVec v;
		int N = (int)tone.size();
		int i, j, k;
		for (i = 0; i < N; ++i) {
			v.push_back(II(tone[i], duration[i]));
		}
		sort(v.begin(), v.end());

#define INF 0x3f3f3f3f
		int dp[64][64] = {};
		memset(dp, 0x3f, sizeof(dp));
		for (i = 0; i < N; ++i) {
			for (j = 0; j < i; ++j) {
				for (k = 1; k <= i; ++k) {
					dp[i][k+1] = min(dp[i][k+1], dp[j][k] + v[i].first-v[j].first + v[i].second);
				}
			}
			dp[i][1] = v[i].second;
		}

		int ans = 0;
		for (k = 1; k <= N; ++k) {
			for (i = 0; i < N; ++i) {
				if (dp[i][k] <= T) {
					ans = k;
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
			int Arg2 = 99;
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
			int Arr0[] = {9, 11, 13, 17};
			int Arr1[] = {2, 1, 3, 4};
			int Arg2 = 20;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, maxSongs(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {87,21,20,73,97,57,12,80,86,97,98,85,41,12,89,15,41,17,68,37,21,1,9,65,4,
 67,38,91,46,82,7,98,21,70,99,41,21,65,11,1,8,12,77,62,52,69,56,33,98,97};
			int Arr1[] = {88,27,89,2,96,32,4,93,89,50,58,70,15,48,31,2,27,20,31,3,23,86,69,12,59,
 61,85,67,77,34,29,3,75,42,50,37,56,45,51,68,89,17,4,47,9,14,29,59,43,3};
			int Arg2 = 212;
			int Arg3 = 12;

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
	GUMIAndSongsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
