// BEGIN CUT HERE
/*
SRM 614 Div2 Medium (500)

問題
-N個の座標がある
-それらのうち、N-2個以上の座標を含むように正方形で囲む
-ただし辺の上にあるものは含めない
-最小の面積を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class MinimumSquareEasy {
public:
	long long minArea(vector <int> x, vector <int> y) {
		int K = (int)x.size() - 2;
		LL ans = 1LL << 62;
		for (int bottom : y) {
			for (int left : x) {
				LLVec d;
				for (int i = 0; i < (int)x.size(); ++i) {
					if (x[i] >= left && y[i] >= bottom) {
						d.push_back(max(x[i] - left, y[i] - bottom) + 2);
					}
				}
				if (d.size() >= K) {
					sort(d.begin(), d.end());
					ans = min(ans, d[K - 1] * d[K - 1]);
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {0, 1, 5};
			long long Arg2 = 4LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, -1, 0, 2, 0};
			int Arr1[] = {-2, -1, 0, -1, -2};
			long long Arg2 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, -1000000000, 1000000000, -1000000000};
			int Arr1[] = {1000000000, 1000000000, -1000000000, -1000000000};
			long long Arg2 = 4000000008000000004LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
			int Arr1[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
			long long Arg2 = 22801LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minArea(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinimumSquareEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
