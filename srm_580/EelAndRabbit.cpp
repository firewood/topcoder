// BEGIN CUT HERE
/*
SRM 580 Div1 Easy (250)

問題
-地点Xにうさぎがいる
-N匹のうなぎがいる
-それぞれの長さはLで、時間Tに地点Xに頭が到達する
-うさぎは、2回までうなぎをつかみどりできる
-うなぎを取れる最大数を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class EelAndRabbit {
public:
	int getmax(vector <int> l, vector <int> t) {
		int ans = 0;
		int i, j, k;
		for (i = 0; i < (int)t.size(); ++i) {
			for (j = 0; j < (int)t.size(); ++j) {
				int f[50] = {};
				for (k = 0; k < (int)t.size(); ++k) {
					f[k] |= t[i] >= t[k] && t[i] <= (t[k] + l[k]);
					f[k] |= t[j] >= t[k] && t[j] <= (t[k] + l[k]);
				}
				ans = max(ans, accumulate(f, f + t.size(), 0));
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
			int Arr0[] = {2, 4, 3, 2, 2, 1, 10};
			int Arr1[] = {2, 6, 3, 7, 0, 2, 0};
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1};
			int Arr1[] = {2, 0, 4};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
			int Arr1[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
			int Arg2 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2};
			int Arr1[] = {0,2,4,6};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getmax(Arg0, Arg1));
		}
		n++;





	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EelAndRabbit ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
