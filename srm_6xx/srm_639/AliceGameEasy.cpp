// BEGIN CUT HERE
/*
SRM 639 Div2 Medium (500)

問題
-2人でターン制のゲームをする
-各ターンの勝者はターン番号と同じポイントを得る
-2人の総ポイントxとyが与えられる
-xポイントを取るための最小の勝利ターン数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class AliceGameEasy {
public:
	long long findMinimumValue(long long x, long long y) {
		LL r = (LL)sqrt(2.0 * (x + y));
		if (r * (r + 1) / 2 != (x + y)) {
			return -1;
		}
		if (x <= 1) {
			return x;
		}
		LL ans = 0;
		LL a = x;
		for (LL i = r; i >= 1; --i) {
			if (a >= i) {
				++ans;
				a -= i;
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
			long long Arg0 = 7LL;
			long long Arg1 = 14LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 0LL;
			long long Arg2 = 4LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 932599670050LL;
			long long Arg1 = 67400241741LL;
			long long Arg2 = 1047062LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 13LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100000LL;
			long long Arg1 = 400500LL;
			long long Arg2 = 106LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceGameEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
