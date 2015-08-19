// BEGIN CUT HERE
/*
SRM 665 Div1 Easy (250)

問題
-4か7だけからなる数がラッキーナンバー
-ラッキーナンバー同士の和をラッキーサムとする
-数値または?からなる文字列noteが与えられる
-?は任意の数字、ただし先頭は0ではない
-noteの条件を満たす最小のラッキーサムを求める

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

typedef long long LL;
typedef set<LL> LLSet;

class LuckySum {

	int len;
	int d[16];

	inline bool isLucky(LL a) {
		while (a > 0) {
			LL r = a % 10;
			if (r != 4 && r != 7) {
				return false;
			}
			a /= 10;
		}
		return true;
	}

	inline bool isValid(int st, int ed, LL a) {
		LL r;
		for (int i = st; i < ed; ++i) {
			r = a % 10;
			if (a <= 0 || d[i] >= 0 && d[i] != r) {
				return false;
			}
			a /= 10;
		}
		return true;
	}

public:
	long long construct(string note) {
		len = (int)note.length();
		for (int i = 0; i < 16; ++i) {
			d[i] = (i >= len || note[len - i - 1] == '?') ? -1 : (note[len - i - 1] - '0');
		}

		LLSet a, b;
		for (LL i = 4; i <= 7777777; ++i) {
			if (isLucky(i)) {
				a.insert(i);
				if (i >= 4444444) {
					b.insert(i);
				}
			}
		}

		LL m[8] = { -1 };
		LLSet::const_iterator c, d, e, f;
		int maxlen = min(len, 7);
		LL maximum = (LL)pow(10, maxlen);
		for (c = a.begin(); c != a.end(); ++c) {
			for (d = c; d != a.end(); ++d) {
				LL sum = *c + *d;
				if (isValid(0, maxlen, sum)) {
					int idx = (*c >= 1000000) + (*d >= 1000000) * 2 + (sum >= maximum) * 4;
					if (m[idx] <= 0) {
						m[idx] = sum;
					}
				}
			}
		}
		if (len <= 7) {
			return m[0];
		}

		maximum = (LL)pow(10, len - 7);
		LL minimum = maximum / 10;
		a.insert(0);
		LL ans = 1LL << 60;
		for (c = a.begin(); c != a.end(); ++c) {
			for (d = c; d != a.end(); ++d) {
				LL sum = *c + *d;
				if (sum < minimum) {
					continue;
				}
				if (sum >= maximum) {
					break;
				}
				if (isValid(7, len, sum)) {
					int idx = (*c > 0) + 2;
					if (m[idx] > 0) {
						ans = min(ans, sum * 10000000 + m[idx]);
					}
				}
				if (isValid(7, len, sum + 1)) {
					int idx = (*c > 0) + 2 + 8;
					if (m[idx] > 0) {
						ans = min(ans, sum * 10000000 + m[idx]);
					}
				}
			}
		}
		return ans < (1LL << 60) ? ans : -1;
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
			string Arg0 = "?";
			long long Arg1 = 8LL;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "?1";
			long long Arg1 = 11LL;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "4?8";
			long long Arg1 = 448LL;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "2??";
			long long Arg1 = -1LL;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "??????????????";
			long long Arg1 = 11888888888888LL;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "???????";
			long long Arg1 = 1188888;

			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LuckySum ___test;
	___test.run_test(-1);
}
// END CUT HERE
