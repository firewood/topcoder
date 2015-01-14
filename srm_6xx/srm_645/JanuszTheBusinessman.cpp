// BEGIN CUT HERE
/*
SRM 645 Div1 Easy (250)

問題
-ホテルを経営している
-宿泊客の到着日と出発日の配列が与えられる
-宿泊客に特別なサービスをすると、良いレビューを残してくれる
-特別なサービスを受けた宿泊客に居合わせた宿泊客も良いレビューを残してくれる
-全員が良いレビューを残すために必要な特別サービスの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class JanuszTheBusinessman {
public:

	int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
		int used[64] = {};
		int N = (int)arrivals.size();
		int ans = 0;
		while (true) {
			int left = 1000;
			for (int i = 0; i < N; ++i) {
				if (!used[i]) {
					left = min(left, departures[i]);
				}
			}
			if (left >= 1000) {
				break;
			}
			++ans;
			int right = left;
			for (int i = 0; i < N; ++i) {
				if (arrivals[i] <= left) {
					right = max(right, departures[i]);
				}
			}
			for (int i = 0; i < N; ++i) {
				if (arrivals[i] <= right) {
					used[i] = 1;
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
			int Arr0[] = {2, 10, 6}	;
			int Arr1[] = {6, 11, 9};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 10, 23, 34, 45, 123, 1};
			int Arr1[] = {25, 12, 40, 50, 48, 187, 365};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 12, 20, 30, 54, 54, 68, 75};
			int Arr1[] = {13, 31, 30, 53, 55, 70, 80, 76};
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
			int Arr1[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
			int Arr1[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
			int Arg2 = 14;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, makeGuestsReturn(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	JanuszTheBusinessman ___test;
	___test.run_test(-1);
}
// END CUT HERE
