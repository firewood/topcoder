// BEGIN CUT HERE
/*
SRM 652 Div2 Medium (500)

問題
-1からNまでのN個の数を使った順列がある
-それぞれの値をp[1]からp[N]とする
-f(1)=p[1],f(m)=p[f(m-1)]とする
-順列がどのような並びでもf(x)=1となるためのxの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class ThePermutationGameDiv2 {
public:
	long long findMin(int N) {
		LL ans = 1;
		LL f[64] = {};
		for (LL i = 2; i <= N; ++i) {
			if (!f[i]) {
				for (LL j = i; j <= N; j += i) {
					f[j] = 1;
				}
				for (LL j = i; j <= N; j *= i) {
					ans *= i;
				}
			}
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
			int Arg0 = 2;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 6LL;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			long long Arg1 = 60LL;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			long long Arg1 = 27720LL;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 25;
			long long Arg1 = 26771144400LL;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThePermutationGameDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
