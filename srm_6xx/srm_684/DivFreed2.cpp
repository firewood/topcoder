// BEGIN CUT HERE
/*
SRM 684 Div2 Medium (600)

問題
-N個の要素からなる配列がある
-各要素の範囲は[1-K]である
-隣り合う2つの要素をA,Bとしたとき、全ての2要素がA <= Bまたは(A mod B) != 0を満たすとき、良い配列とする
-与えられたN,Kにおいて良い配列の総数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

#define MOD 1000000007LL

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
};

class DivFreed2 {
public:
	int count(int n, int k) {
		modll dp[2][100001] = {}, sum[2] = {};
		for (int i = 1; i <= k; ++i) {
			dp[1][i] = 1;
		}
		sum[1] = k;
		for (int i = 1; i < n; ++i) {
			int prev = i & 1, curr = prev ^ 1;
			sum[curr] = dp[curr][1] = dp[prev][1];
			for (int j = 2; j <= k; ++j) {
				modll s = 0;
				for (int l = j * 2; l <= k; l += j) {
					s += dp[prev][l];
				}
				dp[curr][j] = sum[prev] - s;
				sum[curr] += dp[curr][j];
			}
		}
		modll ans = 0;
		for (int i = 1; i <= k; ++i) {
			ans += dp[n & 1][i];
		}
		return ans;
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
			int Arg2 = 3;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 1;
			int Arg2 = 1;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arg2 = 15;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 107;
			int Arg2 = 107;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 10;
			int Arg2 = 83;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 1234;
			int Arg2 = 1515011;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 8;
			int Arg2 = 326;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 100000;
			int Arg2 = 526882214;

			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivFreed2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
