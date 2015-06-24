// BEGIN CUT HERE
/*
SRM 661 Div2 Medium (500)

問題
-水平方向に接続されたノードが2組ある
-水平方向のノード間の移動コストが配列で与えられる
-2組のノードを縦に並べ、水平位置が同じノードを垂直に2箇所つなぐ
-つないだ場所の移動コストはゼロ
-任意のノードの移動コストの最大値Dが最も小さくなるように接続する
-Dの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class BridgeBuildingDiv2 {
public:
	int minDiameter(vector <int> a, vector <int> b, int K) {
		int ans = 1 << 30;
		int _d[22][22];
		memset(_d, 0x3f, sizeof(_d));
		int N = (int)a.size() + 1;
		for (int i = 0; i < N * 2; ++i) {
			_d[i][i] = 0;
		}
		for (int i = 1; i < N; ++i) {
			_d[i - 1][i] = _d[i][i - 1] = a[i - 1];
			_d[i + N - 1][i + N] = _d[i + N][i + N - 1] = b[i - 1];
		}
		int B = 1 << N;
		for (int b = 1; b < B; ++b) {
			if (popcount(b) != K) {
				continue;
			}
			int d[22][22];
			memcpy(d, _d, sizeof(d));
			for (int i = 0; i < N; ++i) {
				if ((1 << i) & b) {
					d[i][i + N] = d[i + N][i] = 0;
				}
			}
			for (int k = 0; k < N * 2; ++k) {
				for (int i = 0; i < N * 2; ++i) {
					for (int j = 0; j < N * 2; ++j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			int m = 0;
			for (int i = 0; i < N * 2; ++i) {
				for (int j = 0; j < N * 2; ++j) {
					m = max(m, d[i][j]);
				}
			}
			ans = min(ans, m);
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
			int Arr0[] = {2,1,1,1,2};
			int Arr1[] = {1,9,1,9,1};
			int Arg2 = 4;
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,50,1,50,1,50,1,50};
			int Arr1[] = {50,1,50,1,50,1,50,1};
			int Arg2 = 9;
			int Arg3 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,10,15,31,20,23,7,48,5,50};
			int Arr1[] = {2,5,1,8,3,2,16,11,9,1};
			int Arg2 = 3;
			int Arg3 = 124;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,4,10,2,2,22,30,7,28};
			int Arr1[] = {5,26,1,2,6,2,16,3,15};
			int Arg2 = 5;
			int Arg3 = 54;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minDiameter(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BridgeBuildingDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
