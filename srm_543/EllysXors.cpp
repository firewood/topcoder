// BEGIN CUT HERE
/*
// SRM 543 Div1 Easy (250)

問題
LからRまでの全数のXORを求めよ

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class EllysXors {

	static LL f(LL x) {
		switch (x & 3) {
		case 0:
			return x;
		case 1:
			return 1;
		case 2:
			return x | 1;
		default:
			return 0;
		}
	}

public:
	long long getXor(long long L, long long R) {
#if 1
		LL res = f(L-1) ^ f(R);
#else
		LL res = 0;
		LL x;
		for (x = L; x <= R; ++x) {
			res ^= x;
			if ((R-x) >= 4 && (x&1) == 1) {
				x += (R-x) & ~3;
			}
		}
#endif
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
			long long Arg1 = 10LL;
			long long Arg2 = 8LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 5LL;
			long long Arg2 = 5LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 13LL;
			long long Arg1 = 42LL;
			long long Arg2 = 39LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 666LL;
			long long Arg1 = 1337LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1234567LL;
			long long Arg1 = 89101112LL;
			long long Arg2 = 89998783LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			long long Arg0 = 0LL;
			long long Arg1 = 0LL;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, getXor(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysXors ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
