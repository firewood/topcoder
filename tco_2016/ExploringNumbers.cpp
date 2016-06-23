// BEGIN CUT HERE
/*
TCO 2016 Round 1B Easy (250)

問題
-数Nが与えられる
-以下のステップを繰り返す
-数Nを書く
-Nが素数ならNで終了
-数をN個書いていれば-1で終了
-終わりでない場合、Nの各桁の二乗の和をNとする
-最終結果を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ExploringNumbers {

	vector<int> primes;

	void gen_prime(int N) {
		primes.push_back(2);
		primes.push_back(3);
		int n;
		for (n = 5; n <= N; n += 2) {
			const int *r = &primes[1];
			int p;
			while (((p = *r++) * p) < n && (n % p) != 0) {
				;
			}
			if ((p * p) > n) {
				primes.push_back(n);
			}
		}
	}

	bool is_prime(int n) {
		if (n <= 1) {
			return false;
		}
		for (int p : primes) {
			if (p >= n) {
				break;
			}
			if ((n % p) == 0) {
				return false;
			}
		}
		return true;
	}

public:
	int numberOfSteps(int n) {
		if (primes.size() <= 0) {
			gen_prime(32000);
		}
		set<int> p(primes.begin(), primes.end());
		set<int> m;
		int a = n;
		for (int i = 0; i < n; ++i) {
			if (m.find(a) != m.end()) {
				return -1;
			}
			m.insert(a);
			if (is_prime(a)) {
				return i + 1;
			}
			int b = a;
			a = 0;
			while (b) {
				a += (b % 10) * (b % 10);
				b /= 10;
			}
		}
		return -1;
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
			int Arg0 = 5;
			int Arg1 = 1;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 57;
			int Arg1 = 4;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = -1;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6498501;
			int Arg1 = 2;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 989113;
			int Arg1 = 6;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12366;
			int Arg1 = -1;

			verify_case(n, Arg1, numberOfSteps(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ExploringNumbers ___test;
	___test.run_test(-1);
}
// END CUT HERE
