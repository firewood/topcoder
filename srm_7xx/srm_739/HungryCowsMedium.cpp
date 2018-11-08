// BEGIN CUT HERE
/*
SRM 739 Div1 Medium (500)

問題
-直線状の農場に牛がいる
-牛が必要とする餌の量cowAppetitesと、餌場の座標barnPositionsで与えられる
-それぞれの餌場の供給量は無尽蔵である
-牛は単位時間に距離1を移動するか餌を1食べる
-他の牛が食べている餌場では食べられない
-全ての牛が餌を食べ終わるのに必要な最小時間を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class HungryCowsMedium {
	bool possible(vector <LL> &cows, vector <LL> &b, LL t) {
		int bs = (int)b.size();
		vector<LL> f(bs + 1);
		for (int i = 0; i < bs; ++i) {
			f[i] = max(0LL, t - b[i]);
		}
		for (LL c : cows) {
			LL r = c;
			for (int i = 0; r > 0 && i < bs; ++i) {
				if (b[i] + c <= t) {
					LL x = min(r, f[i]);
					r -= x;
					f[i] -= x;
				}
			}
			if (r) {
				return false;
			}
		}
		return true;
	}

public:
	long long getWellFedTime(vector <int> cowAppetites, vector <int> barnPositions) {
		sort(cowAppetites.begin(), cowAppetites.end());
		sort(barnPositions.rbegin(), barnPositions.rend());
		vector <LL> cc(cowAppetites.begin(), cowAppetites.end());
		vector <LL> bb(barnPositions.begin(), barnPositions.end());
		LL left = 0, right = 1LL << 61;
		while ((right - left) > 1) {
			LL mid = (left + right) / 2;
			if (possible(cc, bb, mid)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		for (LL ans = left; ans <= left + 2; ++ans) {
			if (possible(cc, bb, ans)) {
				return ans;
			}
		}
		return left + 1;
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
			int Arr0[] = {3};
			int Arr1[] = {5};
			long long Arg2 = 8LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1};
			int Arr1[] = {2,3};
			long long Arg2 = 5LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,4,4};
			int Arr1[] = {4,2};
			long long Arg2 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = {
				1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,
				1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000
			};
			int Arr1[] = { 1000000000,1000000000 };
			long long Arg2 = 11000000000LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 8,1 };
			int Arr1[] = { 1,3 };
			long long Arg2 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getWellFedTime(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HungryCowsMedium ___test;
	___test.run_test(-1);
}
// END CUT HERE
