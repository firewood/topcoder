// BEGIN CUT HERE
/*
TCO 2015 Round 1A Easy (250)

問題
-2つの数値について、10進数表記にしたとき共通する数字の数を類似性とする
-L以上R以下の異なる2つの数の類似性の最大値を求める

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

typedef set<int> IntSet;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class Similars {
public:
	int maxsim(int L, int R) {
		int cnt[1024] = {};
		for (int n = L; n <= R; ++n) {
			char d[64];
			sprintf(d, "%d", n);
			int len = strlen(d);
			int b = 0;
			for (int i = 0; i < len; ++i) {
				b |= (1 << (d[i] - '0'));
			}
			cnt[b] += 1;
		}
		int ans = 0;
		for (int i = 1; i < 1024; ++i) {
			if (cnt[i] <= 0) {
				continue;
			}
			if (cnt[i] >= 2) {
				ans = max(ans, popcount(i));
			}
			for (int j = i + 1; j < 1024; ++j) {
				if (cnt[j] > 0 && (i & j)) {
					ans = max(ans, popcount(i&j));
				}
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
			int Arg0 = 1;
			int Arg1 = 10;
			int Arg2 = 1;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 99;
			int Arg2 = 2;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 99;
			int Arg1 = 100;
			int Arg2 = 0;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1010;
			int Arg2 = 2;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 444;
			int Arg1 = 454;
			int Arg2 = 2;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100000;
			int Arg2 = 5;

			verify_case(n, Arg2, maxsim(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Similars ___test;
	___test.run_test(-1);
}
// END CUT HERE
