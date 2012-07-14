// BEGIN CUT HERE
/*
// SRM 535 Div2 Hard (1000)

問題
0から1000000000000000000までの数を、桁の数値の和で、和が同じもの同士は辞書順で並べる。
idx番目の数値を求める。

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

#define MAX_DIGITS 18
#define MAX_SUM 9*MAX_DIGITS

typedef long long LL;

class FoxAndSorting {

	LL dp[MAX_DIGITS+1][MAX_SUM+1];

	LL rec(int digits, int sum) {
		LL &res = dp[digits][sum];
		if (res < 0) {
			res = 0;
			if (sum == 0) {
				++res;
			}

			int d;
			for (d = 0; d <= 9 && d <= sum; ++d) {
				if (digits > 0 && (d > 0 || digits < MAX_DIGITS)) {
					res += rec(digits - 1, sum - d);
				}
			}
		}
		return res;
	}

public:
	long long get(long long idx) {
		memset(dp, -1, sizeof(dp));

		int sum;
		for (sum = 0; idx > rec(MAX_DIGITS, sum) ; ++sum) {
			idx -= rec(MAX_DIGITS, sum);
		}

		LL ans = 0;
		int pos;
		for (pos = MAX_DIGITS; pos > 0; --pos) {
			if (sum == 0) {
				if (idx == 1) {
					break;
				} else {
					--idx;
				}
			}
			int d;
			for (d = 0; d <= 9 && d <= sum; ++d) {
				if (d > 0 || pos < MAX_DIGITS) {
					if (idx <= rec(pos-1, sum - d)) {
						ans = ans * 10 + d;
						sum -= d;
						break;
					}
					idx -= rec(pos-1, sum - d);
				}
			}
		}
		return ans;
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
			long long Arg0 = 10LL;
			long long Arg1 = 100000000LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			long long Arg1 = 999999999999999999LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 58LL;
			long long Arg1 = 100000000100LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 314159265358979LL;
			long long Arg1 = 646003042230121105LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 271828182845904523LL;
			long long Arg1 = 132558071125756493LL;

			verify_case(n, Arg1, get(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndSorting ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
