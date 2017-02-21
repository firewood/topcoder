// BEGIN CUT HERE
/*
SRM 702 Div2 Medium (500)

問題
-N行M列の升目がある
-1行目の1列目に1,2,3,...、2行目にM+1,M+2,M+3,...と番号をつける
-N行M列に並んだ数値が与えられる
-各升目の数値と番号が一致するときを1、そうでないときを0とする
-それら一致したかどうかの値をすべて結合したものを類似性文字列とする
-任意の行または任意の列が交換できるとき、辞書順最大の類似性文字列を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GridSort {
public:
	string sort(int n, int m, vector <int> grid) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (grid[j * m] < grid[i * m]) {
					for (int k = 0; k < m; ++k) {
						swap(grid[i * m + k], grid[j * m + k]);
					}
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				if (grid[j] < grid[i]) {
					for (int k = 0; k < n; ++k) {
						swap(grid[k * m + i], grid[k * m + j]);
					}
				}
			}
		}
		for (int i = 0; i < n * m; ++i) {
			if (grid[i] != (i + 1)) {
				return "Impossible";
			}
		}
		return "Possible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 1,2,
 3,4
};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 3,4,
 1,2
};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 4,3,
 1,2
};
			string Arg3 = "Impossible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arr2[] = {4,5,1,2,9,8,3,10,7,6};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = {
 10,6,8,9,7,
 5,1,3,4,2,
 15,11,13,14,12
};
			string Arg3 = "Possible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;
			int Arr2[] = {
 11,12,
 2,1,
 9,10,
 7,8,
 6,5,
 3,4
};
			string Arg3 = "Impossible";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, sort(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GridSort ___test;
	___test.run_test(-1);
}
// END CUT HERE
