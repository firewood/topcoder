// BEGIN CUT HERE
/*
SRM 614 Div1 Easy (250)

問題
-N個の座標がある
-それらのうち、K個以上の座標を含むように正方形で囲む
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

class MinimumSquare {
public:
	long long minArea(vector <int> x, vector <int> y, int K) {
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
			int Arr0[] = {0, 3};
			int Arr1[] = {0, 7};
			int Arg2 = 2;
			long long Arg3 = 81LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-4, 3, 1};
			int Arr1[] = {3 , -1, -2};
			int Arg2 = 2;
			long long Arg3 = 16LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 1, 1, 2, 2};
			int Arr1[] = {0, 1, 0, 1, 0, 1};
			int Arg2 = 4;
			long long Arg3 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
			int Arr1[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
			int Arg2 = 3;
			long long Arg3 = 4000000008000000004LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
			int Arr1[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
			int Arg2 = 8;
			long long Arg3 = 1695545329LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minArea(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinimumSquare ___test;
	___test.run_test(-1);
}
// END CUT HERE
