// BEGIN CUT HERE
/*
SRM 741 Div2 Medium (500)

問題
-関数g(n, p)は任意の整数nと素数pで以下のように定義される。
  - nがpで割り切れないとき、g(n,p)は0
  - そうでないとき、g(n,p)はnを超えない最大のpの累乗
-関数f(n)は、全ての素数pについてのg(n,p)の総和である
-数Xが与えられる
-f(1) + f(2) + ... + f(X)を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

vector<int> gen_primes(int m) {
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= m; i += 2) {
		for (int prime : primes) {
			if (i < prime * prime) {
				primes.push_back(i);
				break;
			}
			if ((i % prime) == 0) {
				break;
			}
		}
	}
	return primes;
}

class SimpleMathProblemDiv2 {
public:
	long long calculate(int X) {
		LL x = X, ans = 0;
		vector<LL> primes;
		primes.push_back(2);
		for (LL i = 2; i <= x; ++i) {
			for (LL prime : primes) {
				if (i < prime * prime) {
					primes.push_back(i);
					LL prev = 0;
					for (LL j = i; j <= x; j *= i) {
						LL y = min(j * i - 1, x) / i;
						ans += (y - prev) * j;
						prev = y;
					}
					break;
				}
				if ((i % prime) == 0) {
					break;
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
			int Arg0 = 1;
			long long Arg1 = 0LL;

			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			long long Arg1 = 36LL;

			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			long long Arg1 = 128LL;

			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 77444;
			long long Arg1 = 3296580744LL;

			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 444777;
			long long Arg1 = 111293895799LL;

			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			long long Arg1 = 5;

			verify_case(n, Arg1, calculate(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SimpleMathProblemDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
