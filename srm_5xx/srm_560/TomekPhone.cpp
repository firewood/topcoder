// BEGIN CUT HERE
/*
// SRM 560 Div2 Medium (500)

問題
-新しいガラケーのキーボードをデザインしたい
-テキストの各文字のカウント、キーの最大数、各キーの最大ストローク数が与えられる
-テキストを入力したときの合計ストローク数を求める

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TomekPhone {

public:
	int minKeystrokes(vector <int> frequencies, vector <int> keySizes) {
		int res = 0;
		int sz = (int)frequencies.size();
		sort(frequencies.rbegin(), frequencies.rend());
		int i = 0, j, k;
		for (j = 1; j <= 50; ++j) {
			for (k = 0; k < (int)keySizes.size(); ++k) {
				if (keySizes[k] >= j) {
					res += j * frequencies[i];
					if (++i >= sz) {
						return res;
					}
				}
			}
		}
		return -1;
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
			int Arr0[] = {7,3,4,1};
			int Arr1[] = {2,2};
			int Arg2 = 19;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13,7,4,20};
			int Arr1[] = {2,1};
			int Arg2 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11,23,4,50,1000,7,18};
			int Arr1[] = {3,1,4};
			int Arg2 = 1164;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,1000,1,10};
			int Arr1[] = {50};
			int Arg2 = 1234;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			int Arr1[] = {10,10,10,10,10,10,10,10};
			int Arg2 = 3353;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minKeystrokes(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TomekPhone ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
