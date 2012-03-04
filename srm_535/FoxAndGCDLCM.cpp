// BEGIN CUT HERE
/*
// SRM 535 Div2 Medium (500)

問題
最大公約数Gと最小公倍数Lが与えられる。
GとLを満たす数AとBの和の最小値を求める。

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
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;
typedef set<string> StrSet;
typedef set<int, int> IntMap;
typedef set<LL, LL> LLMap;
typedef set<string, string> StrMap;

class FoxAndGCDLCM {

	static LL gcd(LL a, LL b) {
		while (true) {
			a = a % b;
			if (a == 0) return b;
			b = b % a;
			if (b == 0) return a;
		}
    }

public:
	long long get(long long G, long long L) {
		if (G < 1 || L < 1 || (L < G) || (L % G)) {
			return -1;
		}
		LL M = L / G;
		LL Max = (LL)sqrt((double)M) + 1;
		bool f = false;
		LL res = M+1;
		LL i;
		for (i = 1; i <= Max; ++i) {
			if ((M % i) == 0) {
				LL j = M / i;
				if (gcd(i, j) == 1) {
					f = true;
					res = min(res, i + j);
				}
			}
		}
		res *= G;
		return f ? res : -1;
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
			long long Arg0 = 2LL;
			long long Arg1 = 20LL;
			long long Arg2 = 14LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 8LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000LL;
			long long Arg1 = 100LL;
			long long Arg2 = -1LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 1000LL;
			long long Arg2 = 700LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 10LL;
			long long Arg1 = 950863963000LL;
			long long Arg2 = 6298430LL;

			verify_case(n, Arg2, get(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndGCDLCM ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
