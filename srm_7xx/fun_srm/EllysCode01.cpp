// BEGIN CUT HERE
/*
2017 TCO Algorithm Warsaw Regional Round
Fun SRM Medium (500)

問題
-最初にゼロをひとつ書く
-次に、書いてある全ての数字をビット反転し、付け加える
-L番目からR番目までの1の数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class EllysCode01 {
public:
	long long calc(long long x) {
		if (x <= 1) {
			return 0;
		}
		long long b = 1, r = 0;
		while (b <= x) {
			b *= 2;
		}
		b /= 2;
		r += b / 2;
		r += (x - b) / 2;
		if (x % 2) {
			bool f = false;
			--x;
			while (x > 0) {
				if (x >= b) {
					f = !f;
					x -= b;
				}
				b /= 2;
			}
			r += f;
		}
		return r;
	}
public:
	long long getOnes(long long L, long long R) {
		return calc(R + 1) - calc(L);
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
			long long Arg0 = 5LL;
			long long Arg1 = 15LL;
			long long Arg2 = 5LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 101LL;
			long long Arg1 = 185LL;
			long long Arg2 = 42LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1LL;
			long long Arg2 = 1LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1337LL;
			long long Arg1 = 1337LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 12345LL;
			long long Arg1 = 67890LL;
			long long Arg2 = 27772LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5192834871235435LL;
			long long Arg1 = 954971273487212547LL;
			long long Arg2 = 474889219307988557LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			long long Arg0 = 0LL;
			long long Arg1 = 2LL;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, getOnes(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysCode01 ___test;
	___test.run_test(-1);
}
// END CUT HERE
