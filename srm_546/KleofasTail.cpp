// BEGIN CUT HERE
/*
// SRM 546 Div1 Easy (250)

問題
ある数値を、偶数なら1/2、奇数なら-1していく。
範囲AからBまでの数Xについてその操作を行う。
一度でも数Kが出現するXの総数を求める。

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

typedef long long LL;

class KleofasTail {

public:
	long long countGoodSequences(long long K, long long A, long long B) {
		if (K <= 0) {
			return B - A + 1;
		}
		long long res = 0;
		LL low = K;
		LL high = K | 1;
		while (low <= B) {
			if (high >= A) {
				LL lower = max(low, A);
				LL upper = min(high, B);
				res += (upper - lower) + 1;
			}
			low <<= 1;
			high = (high << 1) | 1;
		}
		return res;
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
			long long Arg0 = 3LL;
			long long Arg1 = 4LL;
			long long Arg2 = 8LL;
			long long Arg3 = 2LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 23457LL;
			long long Arg2 = 123456LL;
			long long Arg3 = 100000LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1234567890123456LL;
			long long Arg1 = 10LL;
			long long Arg2 = 1000000LL;
			long long Arg3 = 0LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 2LL;
			long long Arg3 = 3LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 3LL;
			long long Arg2 = 3LL;
			long long Arg3 = 1LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 13LL;
			long long Arg1 = 12345LL;
			long long Arg2 = 67890123LL;
			long long Arg3 = 8387584LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 0LL;
			long long Arg2 = 10000LL;
			long long Arg3 = 10000LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4LL;
			long long Arg1 = 0LL;
			long long Arg2 = 16LL;
			long long Arg3 = 7LL;

			verify_case(n, Arg3, countGoodSequences(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KleofasTail ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
