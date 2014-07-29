// BEGIN CUT HERE
/*
SRM 628 Div1 Easy (250)

問題
-数Nの約数の総数をd(N)とする
-Nのd(N)乗をh(N)とする
-数nが与えられる
-h(x) = nとなるxの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

int divisors(LL n) {
	int cnt = 1;
	LL x;
	for (x = 2; x*x < n; ++x) {
		cnt += (n % x) == 0;
	}
	return 2 * cnt + (x*x == n);
}

class DivisorsPower {

public:
	long long findArgument(long long n) {
		for (LL x = 2; x <= 1000000; ++x) {
			LL a = x;
			for (int y = 2; ; ++y) {
				LL prev = a;
				a *= x;
				if (a == n && a/x == prev && divisors(x) == y) {
					return x;
				}
				if (a > n || prev > a) {
					break;
				}
			}
		}
		LL a = (LL)sqrt((long double)n);
		if (a*a == n && divisors(a) == 2) {
			return a;
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
			long long Arg0 = 4LL;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = -1LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 64LL;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10000LL;
			long long Arg1 = 10LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2498388559757689LL;
			long long Arg1 = 49983883LL;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 6756327210616080LL;
			long long Arg1 = -1;

			verify_case(n, Arg1, findArgument(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivisorsPower ___test;
	___test.run_test(-1);
}
// END CUT HERE
