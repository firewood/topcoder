// BEGIN CUT HERE
/*
SRM 743 Div1 Easy (300)

問題
- 2n個の整数がある
- 2個ずつ取り出してn個のペアを作る
- n個の数のGCDの最大値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

typedef long long LL;

class MaximizingGCD {
public:
	int maximumGCDPairing(vector <int> A) {
		int n = (int)A.size();
		if (n == 2) {
			return A[0] + A[1];
		}
		LL sum = accumulate(A.begin(), A.end(), 0LL);
		LL r = (LL)sqrt(sum);
		auto ok = [&](int f) {
			map<int, int> m;
			for (int i = 0; i < n; ++i) {
				m[A[i] % f] += 1;
			}
			for (auto kv : m) {
				if (kv.first) {
					if (kv.first == f - kv.first) {
						if (kv.second % 2) {
							return false;
						}
					} else {
						if (kv.second != m[f - kv.first]) {
							return false;
						}
					}
				}
			}
			return true;
		};
		LL ans = 0;
		for (LL a = 1; a <= r; ++a) {
			if ((sum % a) == 0) {
				if (ok(a)) {
					ans = max(ans, a);
				}
				if (ok(sum / a)) {
					ans = max(ans, sum / a);
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
			int Arr0[] = {5, 4, 13, 2};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {26, 23};
			int Arg1 = 49;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 200, 300, 500, 1100, 700};
			int Arg1 = 100;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {46, 78, 133, 92, 1, 23, 29, 67, 43, 111, 3908, 276, 13, 359, 20, 21};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 
65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608};
			int Arg1 = 16400;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumGCDPairing(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MaximizingGCD ___test;
	___test.run_test(-1);
}
// END CUT HERE
