// BEGIN CUT HERE
/*
// SRM 526.5 Div2 Easy (250)

問題

2n個の石がある。
2つの素数の和で表せるかどうかを求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
typedef set<int> IntSet;

class MagicStonesStore {
	IntSet prime;

	void gen_prime(int n) {
		prime.insert(2);
		int i, j;
		for (i = 3; i <= n; i += 2) {
			for (j = 3; (i % j) && j*j <= i; j += 2) {
				;
			}
			if (j*j > i) {
				prime.insert(i);
			}
		}
	}

public:
	MagicStonesStore(void) {
		gen_prime(2001);
	}

	string ableToDivide(int n) {
		n *= 2;
		IntSet::const_iterator it;
		for (it = prime.begin(); it != prime.end(); ++it) {
			int x = n - *it;
			if (x < 2) {
				break;
			}
			if (prime.find(x) != prime.end()) {
				return "YES";
			}
		}
		return "NO";
	}
	
// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arg1 = "NO";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			string Arg1 = "YES";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			string Arg1 = "YES";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			string Arg1 = "YES";

			verify_case(n, Arg1, ableToDivide(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicStonesStore ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
