// BEGIN CUT HERE
/*
TCC India 2018 Qualification Round Hard (1000)

問題
-長さLの花壇がある。
-花壇に雨粒が何回か落ちる
-前回の雨粒の位置をP_prevとすると、次の雨粒の位置Pは (P_prev * M + A) modulo (L + 1) である
-雨粒が落ちた点から距離D以内を濡れたものと見なす
-花壇のすべての場所が濡れるのに必要な最小の時間を求めよ

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

class EllysRain {
	bool possible(int L, int D, int n, int P1, int M, int A) {
		if (n <= 0) {
			return false;
		}

		const LL MOD = L + 1;
		vector<LL> v(1, P1);
		for (int i = 1; i < n; ++i) {
			LL next = (v[i - 1] * M + A) % MOD;
			v.push_back(next);
		}
		sort(v.begin(), v.end());
		v.push_back(L);

		LL prev = 0;
		for (LL a : v) {
			if ((a - prev) > D) {
				return false;
			}
			prev = a;
		}
		return true;
	}

public:
	int getTime(int L, int D, int N, int P1, int M, int A) {
		int left = 0;
		int right = N + 1;
		while ((right - left) > 1) {
			int mid = (left + right) / 2;
			if (possible(L, D, mid, P1, M, A)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return right > N ? -1 : right;
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
			int Arg0 = 23;
			int Arg1 = 7;
			int Arg2 = 12;
			int Arg3 = 14;
			int Arg4 = 13;
			int Arg5 = 5;
			int Arg6 = 9;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 4;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 6;
			int Arg6 = -1;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 5;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 2;
			int Arg5 = 6;
			int Arg6 = 1;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1337;
			int Arg2 = 123456;
			int Arg3 = 424242;
			int Arg4 = 13;
			int Arg5 = 42;
			int Arg6 = 8484;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 10;
			int Arg1 = 1;
			int Arg2 = 10;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 1;
			int Arg6 = 9;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 100000;
			int Arg1 = 100;
			int Arg2 = 1000;
			int Arg3 = 1;
			int Arg4 = 1;
			int Arg5 = 100;
			int Arg6 = 1000;

			verify_case(n, Arg6, getTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysRain ___test;
	___test.run_test(-1);
}
// END CUT HERE
