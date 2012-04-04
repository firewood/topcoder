// BEGIN CUT HERE
/*
// TCO12 Round 1A Medium (500)

問題
約分できない分数A/Bを既約分数と呼ぶ。
A×Bがnの階乗で表せるとき、それを「階乗分数」と呼ぶことにする。
数Nが与えられるとき、A×BがN!以下の階乗分数の総数を求める。

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

static int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223,
227, 229, 233, 239, 241, 251};

class EllysFractions {

public:
	long long getCount(int N) {
		if (N < 2) {
			return 0;
		}

		LL res = 1;

		int i;
		int f[256] = {};
		for (i = 0; i < (sizeof(p)/sizeof(p[0])); ++i) {
			f[p[i]] = 1;
		}

		LL cnt = 1;
		for (i = 3; i <= N; ++i) {
			if (f[i]) {
				cnt *= 2;
			}
			res += cnt;
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
			int Arg0 = 1;
			long long Arg1 = 0LL;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 3LL;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			long long Arg1 = 9LL;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			long long Arg1 = 177431885LL;

			verify_case(n, Arg1, getCount(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysFractions ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
