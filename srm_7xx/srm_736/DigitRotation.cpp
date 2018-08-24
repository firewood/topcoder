// BEGIN CUT HERE
/*
SRM 736 Div1 Easy (250)

問題
-巨大な数Xが与えられる
-Xの三つのインデックスa, b, cを選ぶ (ただしa < b < cとする)
-X[a]を位置bに、X[b]を位置cに、X[c]を位置aに移動したもののうち、先頭が0でないものの合計値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

const int MOD = 998244353;

struct modll {
	long long v;
	modll() : v(0) { }
	modll(long long _v) : v(_v >= 0 ? _v : _v + MOD) { }
	long long operator+(const modll &r) const { return (v + r.v) % MOD; }
	long long operator-(const modll &r) const { return (v - r.v + MOD) % MOD; }
	long long operator*(const modll &r) const { return (v * r.v) % MOD; }
	modll operator+=(const modll &r) { v = (v + r.v) % MOD; return *this; }
	modll operator-=(const modll &r) { v = (v - r.v + MOD) % MOD; return *this; }
	modll operator*=(const modll &r) { v = (v * r.v) % MOD; return *this; }
//	friend modll operator+(int l, const modll &r) { return (l + r.v) % MOD; }
//	friend modll operator-(int l, const modll &r) { return (l - r.v + MOD) % MOD; }
//	friend modll operator*(int l, const modll &r) { return (l * r.v) % MOD; }
	static long long modinv(int a) { return modpow(a, MOD - 2); }
	static long long modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r.v;
	}
};

class DigitRotation {
public:
	int sumRotations(string X) {
		int n = (int)X.length();
		modll a = 1, sum = 0, tbl[512] = {}, ans = 0;
		int d[512];
		for (int i = n - 1; i >= 0; --i, a *= 10) {
			d[i] = X[i] - '0';
			sum += a * d[i];
			tbl[i] = a;
		}
		for (int i = 0; i < n; ++i) {
			modll x = sum + tbl[i] * -d[i];
			for (int j = i + 1; j < n; ++j) {
				modll y = x + tbl[j] * (d[i] - d[j]);
				for (int k = j + 1; k < n; ++k) {
					if (i > 0 || d[k]) {
						ans += y;
						ans += tbl[k] * (d[j] - d[k]);
						ans += tbl[i] * d[k];
					}
				}
			}
		}
		return (int)ans.v;
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
			string Arg0 = "123";
			int Arg1 = 312;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "3570";
			int Arg1 = 10407;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "5545";
			int Arg1 = 21208;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "1283749218734901238749213847902";
			int Arg1 = 867286291;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "4";
			int Arg1 = 0;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "123456789123456789123456789123456";
			int Arg1 = 938843585;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "998244353";
			int Arg1 = 215087324;

			verify_case(n, Arg1, sumRotations(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DigitRotation ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
