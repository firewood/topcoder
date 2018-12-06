// BEGIN CUT HERE
/*
SRM 742 Div2 Medium (500)

問題
- 50×50のチェス盤がある
- 何か所かにクイーンが置いてある
- それぞれのクイーンは、他のクイーンと干渉してはならない
- 追加でadd個のクイーンを配置せよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SixteenQueens {
	int used[50][50] = {};
	void fill(int r, int c, int dy, int dx) {
		for (int i = -50; i <= 50; ++i) {
			int a = r + i * dy, b = c + i * dx;
			if (a >= 0 && a < 50 && b >= 0 && b < 50) {
				used[a][b] = 1;
			}
		}
	}
	void fill(int r, int c) {
		fill(r, c, 1, 0);
		fill(r, c, 0, 1);
		fill(r, c, 1, 1);
		fill(r, c, 1, -1);
	}
public:
	vector <int> addQueens(vector <int> row, vector <int> col, int add) {
		memset(used, 0, sizeof(used));
		for (int i = 0; i < (int)row.size(); ++i) {
			fill(row[i], col[i]);
		}
		vector <int> ans;
		for (int k = 0; k < add; ++k) {
			for (int i = 0; i < 50; ++i) {
				for (int j = 0; j < 50; ++j) {
					if (!used[i][j]) {
						ans.push_back(i);
						ans.push_back(j);
						fill(i, j);
						i = 50;
						break;
					}
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3};
			int Arr1[] = {5};
			int Arg2 = 1;
			int Arr3[] = {0, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {1};
			int Arg2 = 1;
			int Arr3[] = {4, 7 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {1};
			int Arg2 = 3;
			int Arr3[] = {4, 7, 15, 0, 49, 49 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {14, 19};
			int Arr1[] = {3, 47};
			int Arg2 = 0;
//			int Arr3[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3;
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			// int Arr0[] = {};
			// int Arr1[] = {};
			int Arg2 = 2;
			int Arr3[] = {0, 0, 1, 2 };

			vector <int> Arg0;
			vector <int> Arg1;
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arr1[] = {7,2,19};
			int Arg2 = 1;
			int Arr3[] = {0, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, addQueens(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SixteenQueens ___test;
	___test.run_test(-1);
}
// END CUT HERE
