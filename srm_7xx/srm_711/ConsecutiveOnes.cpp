// BEGIN CUT HERE
/*
SRM 711 Div1 Easy (250)

問題
-N以上で、2進数表記で1がK個連続する最小の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class ConsecutiveOnes {
	public:
	long long get(long long n, int k) {
		LL ans = (1LL << 50) - 1;
		for (LL mask = (1LL << k) - 1; mask <= ans; mask <<= 1) {
			LL x = mask;
			for (LL b = 1LL << 49; b; b >>= 1) {
				if (n & b) {
					x |= b;
				} else if (x & b) {
					break;
				}
			}
			ans = min(ans, x);
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
			long long Arg0 = 1LL;
			int Arg1 = 2;
			long long Arg2 = 3LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			int Arg1 = 2;
			long long Arg2 = 6LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			int Arg1 = 2;
			long long Arg2 = 7LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 364269800189924LL;
			int Arg1 = 33;
			long long Arg2 = 364273356242943LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConsecutiveOnes ___test;
	___test.run_test(-1);
}
// END CUT HERE
