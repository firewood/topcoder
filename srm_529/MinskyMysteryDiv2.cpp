// BEGIN CUT HERE
/*
// SRM 529 Div2 Hard (1000)

問題

あるルールに基づいて、5つの袋からビー玉を足したり引いたりする
0から10^12まで処理できるようにせよ

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

class MinskyMysteryDiv2 {

public:
	long long computeAnswerRef(long long N) {
		if (N <= 1) {
			return -1;
		}

		LL m[5] = {0};
		m[0] = N;
		m[1] += 1;
		while (true) {
			m[1] += 1;
			m[4] = 0;
			while (m[0]) {
				while (m[0] && m[1]) {
					m[0] -= 1;
					m[1] -= 1;
					m[2] += 1;
					m[3] += 1;
				}
				m[4] += 1;
				if (!m[0] && !m[1]) {
					return m[3] + m[4];
				}
				m[1] += m[3];
				m[3] = 0;
			}
			m[0] += m[2];
			m[2] = 0;
		}
	}

	long long computeAnswer(long long N) {
		if (N <= 1) {
			// infinite
			return -1;
		}
		if ((N % 2) == 0) {
			// even
			return N / 2 + 2;
		}

		LL x;
		for (x = 3; (x*x) <= N; x += 2) {
			if ((N % x) == 0) {
				// not a prime
				return x + N / x;
			}
		}

		// prime
		return N + 1;
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
			long long Arg1 = 3LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3LL;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 4LL;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 15LL;
			long long Arg1 = 8LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 24LL;
			long long Arg1 = 14LL;

			verify_case(n, Arg1, computeAnswer(Arg0));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MinskyMysteryDiv2 ___test;
	___test.run_test(-1);

	return 0;
}
// END CUT HERE
