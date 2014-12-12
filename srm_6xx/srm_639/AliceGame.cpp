// BEGIN CUT HERE
/*
SRM 639 Div1 Easy (250)

問題
-2人でターン制のゲームをする
-各ターンの勝者はターン番号×2－1ポイントを得る
-2人の総ポイントxとyが与えられる
-xポイントを取るための最小のターン数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;

class AliceGame {
public:

	long long findMinimumValue(long long x, long long y) {
		LL sum = x + y;
		LL r = (LL)sqrt(sum);
		if (r*r != sum || x == 2 || y == 2) {
			return -1;
		}
		if (x == 0) {
			return 0;
		}
		LL ans = 0;
		LL t = 0;
		for (LL i = r; i >= 1; --i) {
			++ans;
			t += i * 2 - 1;
			if (t >= x && (t % 2) == (x % 2)) {
				return ans;
			}
		}
		return -1;
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
			long long Arg0 = 8LL;
			long long Arg1 = 17LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 17LL;
			long long Arg1 = 8LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 9LL;
			long long Arg1 = 9LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 500000LL;
			long long Arg1 = 500000LL;
			long long Arg2 = 294LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 999999999999;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 500000000000;
			long long Arg1 = 500000000000;
			long long Arg2 = 292894LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			long long Arg0 = 21LL;
			long long Arg1 = 4LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 27LL;
			long long Arg1 = 9LL;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 2LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000LL;
			long long Arg1 = 0LL;
			long long Arg2 = 1000000LL;

			verify_case(n, Arg2, findMinimumValue(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
