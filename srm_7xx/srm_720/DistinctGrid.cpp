// BEGIN CUT HERE
/*
SRM 720 Div1 Medium (450)

問題
-N行N列のマス目がある
-各行および各桁について、最大K個まで異なる数が使用できる
-全体として、異なる数の個数が最大となるよう、マス目の数値を構築せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DistinctGrid {
public:
	vector <int> findGrid(int n, int k) {
		vector <int> ans(n * n);
		int pos = 0;
		for (int i = 1; i < k; ++i) {
			for (int j = 0; j < n; ++j) {
				ans[pos % (n * n)] = pos + 1;
				pos += n + 1;
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
			int Arg0 = 3;
			int Arg1 = 1;
			int Arr2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGrid(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 3;
			int Arr2[] = {1, 0, 0, 0, 0, 2, 0, 3, 0, 0, 4, 0, 0, 0, 5, 6, 0, 0, 0, 0, 7, 8, 0, 0, 0, 9, 0, 0, 10, 0, 11, 0, 0, 0, 0, 12 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGrid(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arr2[] = {123, 999, 999, 999, 999, 999, 999, 456, 999, 789, 999, 999, 999, 999, 240, 999 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findGrid(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DistinctGrid ___test;
	___test.run_test(-1);
}
// END CUT HERE
