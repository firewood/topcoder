// BEGIN CUT HERE
/*
SRM 702 Div1 Easy (300)

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
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GridSortMax {
public:
	string findMax(int n, int m, vector <int> grid) {
		int row[2501], col[2501];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				row[grid[i * m + j]] = i;
				col[grid[i * m + j]] = j;
			}
		}
		int srcrow[50], dstrow[50], srccol[50], dstcol[50];
		memset(srcrow, -1, sizeof(srcrow));
		memset(dstrow, -1, sizeof(dstrow));
		memset(srccol, -1, sizeof(srccol));
		memset(dstcol, -1, sizeof(dstcol));
		string ans;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				int i = r * m + c + 1;
				if (srcrow[row[i]] < 0 && dstrow[r] < 0 && (srccol[col[i]] == c || (srccol[col[i]] < 0 && dstcol[c] < 0))) {
					srcrow[row[i]] = r;
					dstrow[r] = row[i];
				}
				if (srcrow[row[i]] == r && srccol[col[i]] < 0 && dstcol[c] < 0) {
					srccol[col[i]] = c;
					dstcol[c] = col[i];
				}
				ans += (srcrow[row[i]] == r && srccol[col[i]] == c) ? '1' : '0';
			}
		}
		return ans;
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
			string Arg3 = "1111";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 2,1,
 3,4
};
			string Arg3 = "1100";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;
			int Arr2[] = {
 4,2,
 3,1
};
			string Arg3 = "1001";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 10;
			int Arr2[] = {10,6,2,3,5,7,1,9,4,8};
			string Arg3 = "1111111111";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 5;
			int Arr2[] = {
 5,2,10,7,9,
 3,4,14,11,1,
 15,12,6,8,13
};
			string Arg3 = "101100100100000";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 2;
			int Arr2[] = {
 3,9,
 5,1,
 10,6,
 2,7,
 8,11,
 12,4
};
			string Arg3 = "100000101010";

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, findMax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GridSortMax ___test;
	___test.run_test(-1);
}
// END CUT HERE
