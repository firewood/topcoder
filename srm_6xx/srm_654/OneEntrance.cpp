// BEGIN CUT HERE
/*
SRM 654 Div2 Medium (500)

問題
-N個の部屋があり、それぞれどこかの部屋につながっている
-入り口からN個の家具を運びこんで配置する
-それぞれの部屋には家具は一つだけ置ける
-すでに家具が配置された部屋は家具が通り抜けられない
-家具の配置のしかたの場合の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class OneEntrance {
	int N;
	int be_empty[10];
	int connected[10][10];

public:
	void dfs(int n, int f) {
		be_empty[n] = f;
		for (int i = 0; i < N; ++i) {
			if (connected[n][i]) {
				connected[n][i] = 0;
				connected[i][n] = 0;
				dfs(i, f | (1 << n));
			}
		}
	}

	int count(vector <int> a, vector <int> b, int s) {
		memset(be_empty, 0, sizeof(be_empty));
		memset(connected, 0, sizeof(connected));
		N = (int)a.size() + 1;
		for (int i = 0; i < N - 1; ++i) {
			connected[a[i]][b[i]] = connected[b[i]][a[i]] = 1;
		}
		dfs(s, 0);
		int ans = 0;
		int p[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
		do {
			bool possible = true;
			for (int i = 0; possible && i < N; ++i) {
				for (int j = 0; possible && j < N; ++j) {
					if (be_empty[i] & (1 << j)) {
						if (p[j] < p[i]) {
							possible = false;
						}
					}
				}
			}
			ans += possible;
		} while (next_permutation(p, p + N));
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
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 0;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 2;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0};
			int Arr1[] = {1, 2, 3, 4};
			int Arg2 = 0;
			int Arg3 = 24;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 4, 1, 0, 1, 1, 6, 0};
			int Arr1[] = {6, 6, 2, 5, 0, 3, 8, 4};
			int Arg2 = 4;
			int Arg3 = 896;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			// int Arr0[] = {};
			// int Arr1[] = {};
			int Arg2 = 0;
			int Arg3 = 1;

			vector <int> Arg0;
			vector <int> Arg1;
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OneEntrance ___test;
	___test.run_test(-1);
}
// END CUT HERE
