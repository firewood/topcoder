// BEGIN CUT HERE
/*
SRM 652 Div1 Easy (250)

問題
-1からNまでのN個の数を使った順列がある
-それぞれの値をp[1]からp[N]とする
-f(1)=p[1],f(m)=p[f(m-1)]とする
-順列がどのような並びでもf(x)=1となるためのxの最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

class ThePermutationGame {
public:
	int findMin(int N) {
		LL ans = 1;
		LL f[100001] = {};
		for (LL i = 2; i <= N; ++i) {
			if (!f[i]) {
				for (LL j = i; j <= N; j += i) {
					f[j] = 1;
				}
				for (LL j = i; j <= N; j *= i) {
					ans = (ans * i) % MOD;
				}
			}
		}
		return (int)ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 2;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 6;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 11;
			int Arg1 = 27720;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 102;
			int Arg1 = 53580071;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9999;
			int Arg1 = 927702802;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 100000;
			int Arg1 = 59814054;

			verify_case(n, Arg1, findMin(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThePermutationGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
