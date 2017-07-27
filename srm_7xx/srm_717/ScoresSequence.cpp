// BEGIN CUT HERE
/*
SRM 717 Div1 Easy (250)

問題
-トーナメントとは、完全グラフで、かつ、各辺が有効グラフであるものをいう
-各頂点の出次数が与えられる
-到達可能な2頂点の組の総数を求める

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

class ScoresSequence {
public:
	int count(vector <int> s) {
		int n = (int)s.size(), d[128][128] = {};
		sort(s.begin(), s.end());
		while (true) {
			int tot = accumulate(s.begin(), s.end(), 0);
			int nd[128][128] = {};
			vector <int> r = s;
			for (int i = n - 1; i > 0; --i) {
				if (r[i]) {
					for (int j = 0; j < min(4, r[i]); ++j) {
						int x = rand() % i;
						if (!nd[i][x]) {
							nd[i][x] = 1;
							nd[x][i] = -1;
							r[i]--;
							--tot;
						}
					}
				}
			}
			bool f = true;
			while (f && tot) {
				f = false;
				for (int i = 0; i < n; ++i) {
					for (int j = 0; r[i] && j < n; ++j) {
						if (i != j && !nd[i][j]) {
							nd[i][j] = 1;
							nd[j][i] = -1;
							r[i]--;
							--tot;
							f = true;
						}
					}
				}
			}
			if (!tot) {
				memcpy(d, nd, sizeof(d));
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			d[i][i] = 1;
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i != j && d[i][k] > 0 && d[k][j] > 0) {
						d[i][j] = 1;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans += d[i][j] > 0;
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
			int Arr0[] = {2, 0, 1};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0, 2};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			int Arg1 = 9;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6};
			int Arg1 = 55;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3};
			int Arg1 = 1422;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;





		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0 };
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 0,0,2 };
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 11, 2, 6, 3, 5, 4, 7, 7, 5, 5, 7, 4 };
			int Arg1 = 133;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 21, 39, 17, 36, 34, 31, 43, 29, 16, 12, 36, 38, 46, 17, 41, 42, 32, 20, 44, 15, 40, 22, 25, 27, 27, 24, 23, 16, 22, 18, 15, 35, 36, 15, 35, 13, 40, 21, 30, 11, 28, 16, 39, 33, 34, 13, 24, 17, 37, 42, 18, 42, 19, 22, 41, 34, 33 };
			int Arg1 = 3249;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 49, 46, 76, 52, 53, 31, 30, 25, 9, 25, 48, 38, 66, 74, 56, 77, 50, 42, 52, 73, 82, 30, 65, 40, 75, 82, 61, 54, 65, 57, 78, 19, 72, 19, 44, 45, 44, 28, 32, 61, 61, 36, 41, 23, 48, 31, 72, 63, 67, 57, 45, 85, 27, 55, 66, 60, 38, 22, 17, 77, 40, 15, 75, 41, 69, 24, 16, 54, 74, 38, 79, 66, 77, 36, 26, 24, 55, 54, 27, 37, 55, 46, 65, 65, 81, 36, 37, 53, 36, 70, 83, 82, 48, 55, 20, 25, 37, 17, 70, 26 };
			int Arg1 = 10000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ScoresSequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
