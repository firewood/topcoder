// BEGIN CUT HERE
/*
SRM 566 Div1 Easy (250)

問題
-ペンギンのパーシーがペンギンそり用のコースを設計する
-コースにはいくつかのチェックポイントがあり、それらを直線で結ぶ
-チェックポイントが同一直線状にないことは保証されている
-チェックポイントの座標の精度は非常に悪い可能性がある
-パーシーは慎重なので、直線が交わる可能性を排除したい
-直線が存在しないケースも含めて、何通りの設計がありうるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
#define COMBSZ 60

class PenguinSledding {
	public:
	long long countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2) {
		LL C[COMBSZ][COMBSZ] = {};
		int i, j, k;
		for (i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
		}
		for (i = 1; i < COMBSZ; ++i) {
			for (j = 1; j < COMBSZ; ++j) {
				C[i][j] = (C[i-1][j-1] + C[i-1][j]);
			}
		}

		int cnt[50] = {};
		int f[50][50] = {};
		int sz = checkpoint1.size();
		for (i = 0; i < sz; ++i) {
			cnt[checkpoint1[i]-1] += 1;
			cnt[checkpoint2[i]-1] += 1;
			f[checkpoint1[i]-1][checkpoint2[i]-1] = 1;
			f[checkpoint2[i]-1][checkpoint1[i]-1] = 1;
		}

		LL ans = 1;
		for (i = 0; i < numCheckpoints; ++i) {
			if (cnt[i] > 0) {
				for (j = 1; j <= cnt[i]; ++j) {
					ans += C[cnt[i]][j];
				}
			}
		}
		ans -= sz;

		for (i = 0; i < numCheckpoints; ++i) {
			for (j = i+1; j < numCheckpoints; ++j) {
				for (k = j+1; k < numCheckpoints; ++k) {
					if (f[i][j] && f[j][k] && f[k][i]) {
						++ans;
					}
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
			int Arg0 = 2;
			int Arr1[] = {1};
			int Arr2[] = {2};
			long long Arg3 = 2LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countDesigns(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arr1[] = {1,2,3};
			int Arr2[] = {2,3,4};
			long long Arg3 = 6LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countDesigns(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {1,3,6};
			int Arr2[] = {2,4,4};
			long long Arg3 = 5LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countDesigns(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arr1[] = {40, 40, 40, 40, 40, 40, 40, 40, 
 40, 40, 40, 40, 50, 40, 40, 40, 
 23, 4, 24, 40, 22, 40, 8, 40, 40,
 40, 34, 21, 40, 40, 38, 40, 40, 
 40, 40, 40, 28, 40, 40, 40, 40, 
 46, 13, 40, 40, 40, 47, 40, 40};
			int Arr2[] = {45, 42, 20, 48, 12, 32, 25, 10, 
 26, 39, 16, 2, 19, 43, 37, 17, 
 19, 19, 19, 18, 19, 27, 19, 29, 
 11, 36, 19, 19, 1, 41, 19, 35, 
 14, 33, 49, 3, 19, 7, 5, 19, 31, 
 19, 19, 6, 9, 15, 19, 44, 30};
			long long Arg3 = 68719493118LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countDesigns(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 36;
			int Arr1[] = {13, 24, 24, 20, 31, 16, 10, 36, 34, 32, 
 28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19, 
 21, 8, 1, 26, 27, 25, 15, 22, 30, 30, 
 6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18, 
 13, 14, 17, 35, 3};
			int Arr2[] = {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
 2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
 4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
 21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
 8, 36, 26, 23};
			long long Arg3 = 162LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countDesigns(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
int Arr1[] = {
 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
 40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
 40, 40, 40, 40, 40, 40, 40, 40, 40 
};
int Arr2[] = {
 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
 21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
 31, 32, 33, 34, 35, 36, 37, 38, 39, 41,
 42, 43, 44, 45, 46, 47, 48, 49, 50
};
			long long Arg3 = 562949953421312LL;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, countDesigns(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PenguinSledding ___test;
	___test.run_test(-1);
}
// END CUT HERE

