// BEGIN CUT HERE
/*
SRM 659 Div1 Easy (250)

問題
-N個のりんごまたはみかんを一列に並べる
-いくつかのりんごの初期配置がinfo[i]で与えられる
-連続したK個の果物のうち、りんごはK/2個以下であること
-りんごの総数の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ApplesAndOrangesEasy {
public:
	int maximumApples(int N, int K, vector <int> info) {
		int sum[2048] = {};
		int ap[2048] = {};
		for (int pos : info) {
			ap[pos - 1] = 1;
		}
		sum[0] = accumulate(ap, ap + K, 0);
		for (int i = 1; i <= N - K; ++i) {
			sum[i] = sum[i - 1] - ap[i - 1] + ap[i + K - 1];
		}
		int m = K / 2;
		for (int i = 0; i < N; ++i) {
			bool f = true;
			for (int j = max(0, i - K + 1); j <= min(N - K, i); ++j) {
				if (sum[j] >= m) {
					f = false;
					break;
				}
			}
			if (f && !ap[i]) {
				ap[i] = 1;
				for (int j = max(0, i - K + 1); j <= min(N - K, i); ++j) {
					sum[j] += 1;
				}
			}
		}
		return accumulate(ap, ap + N, 0);
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
			int Arg0 = 3;
			int Arg1 = 2;
			// int Arr2[] = {};
			int Arg3 = 2;

			vector <int> Arg2;
			verify_case(n, Arg3, maximumApples(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 3;
			int Arr2[] = {3, 8};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maximumApples(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 4;
			int Arr2[] = {1, 4};
			int Arg3 = 5;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maximumApples(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 4;
			int Arr2[] = {2, 4};
			int Arg3 = 4;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maximumApples(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 23;
			int Arg1 = 7;
			int Arr2[] = {3, 2, 9, 1, 15, 23, 20, 19};
			int Arg3 = 10;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, maximumApples(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ApplesAndOrangesEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
