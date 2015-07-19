// BEGIN CUT HERE
/*
SRM 662 Div1 Easy (250)

問題
-N匹の狐がいて、それぞれの高さが与えられる
-狐を円卓に並べたとき、隣り合う狐の高さの差の最大値をDとする
-Dが最小となるときの並べ方を求める

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

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;

class FoxesOfTheRoundTable {

	int N;
	IIVec v;

	bool possible(int M, IntVec &ans) {
		ans[0] = 0;
		int l = 0, r = N;
		for (int i = 1; i < N; ++i) {
			if (ans[l] <= ans[r % N]) {
				if (v[i].first - v[ans[l]].first > M) {
					return false;
				}
				ans[++l] = i;
			} else {
				if (v[i].first - v[ans[r % N]].first > M) {
					return false;
				}
				ans[--r] = i;
			}
		}
		return true;
	}

public:
	vector <int> minimalDifference(vector <int> h) {
		N = (int)h.size();
		v.clear();
		IntVec ans(N);
		for (int i = 0; i < N; ++i) {
			v.push_back(II(h[i], i));
		}
		sort(v.begin(), v.end());
		for (int M = 1; M <= 1000; ++M) {
			if (possible(M, ans)) {
				break;
			}
		}
		for (int i = 0; i < N; ++i) {
			ans[i] = v[ans[i]].second;
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
			int Arr0[] = {1,99,50,50};
			int Arr1[] = {0, 3, 1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, minimalDifference(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123,456,789};
			int Arr1[] = {0, 1, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, minimalDifference(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,30,40,50,60};
			int Arr1[] = {0, 1, 4, 3, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, minimalDifference(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,8,12,13,14 };
			int Arr1[] = {0, 1, 2, 3, 5, 6, 7, 4 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, minimalDifference(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, minimalDifference(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxesOfTheRoundTable ___test;
	___test.run_test(-1);
}
// END CUT HERE
