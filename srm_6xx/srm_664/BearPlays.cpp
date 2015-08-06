// BEGIN CUT HERE
/*
SRM 664 Div1 Easy (250)

問題
-何個かの石があり、2つの山にわける
-数が少ないほうをX個、数が多いほうをY個とする
-Y個の山からX個の山にX個移動する操作をK回行う
-少ないほうの山の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

static LL modpow(LL b, LL e, LL m) {
	LL r = 1;
	while (e > 0) {
		if (e & 1) {
			r = (r * b) % m;
		}
		e >>= 1;
		b = (b * b) % m;
	}
	return r;
}

class BearPlays {
	public:
	int pileSize(int A, int B, int K) {
		LL a = min(A, B);
		a = (a * modpow(2, K, A + B)) % (A + B);
		return (int)min(a, A + B - a);
	}

	int pileSize2(int A, int B, int K) {
		for (int k = 0; k < min(K, 10000); ++k) {
			int a = min(A, B);
			int b = max(A, B);
			A = a * 2;
			B = b - a;
		}
		return min(A, B);
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
			int Arg0 = 4;
			int Arg1 = 7;
			int Arg2 = 2;
			int Arg3 = 5;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 5;
			int Arg2 = 3;
			int Arg3 = 0;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 6;
			int Arg2 = 1;
			int Arg3 = 4;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 8;
			int Arg2 = 2000000000;
			int Arg3 = 2;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 900000000;
			int Arg1 = 350000000;
			int Arg2 = 3;
			int Arg3 = 300000000;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 4;
			int Arg2 = 7;
			int Arg3 = 2;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 999999997;
			int Arg2 = 2000000000;
			int Arg3 = 289882546;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 273704458;
			int Arg1 = 291906285;
			int Arg2 = 2000000000;
			int Arg3 = 30011859;

			verify_case(n, Arg3, pileSize(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPlays ___test;
	___test.run_test(-1);

#if 1
	for (int t = 0; t < 100000; ++t) {
		int a = rand() * 100;
		int b = rand() * 101;
		int k = (rand() * 1000) / (RAND_MAX + 1) + 1;

		int p = ___test.pileSize(a, b, k);
		int q = ___test.pileSize2(a, b, k);
		if (p != q) {
			printf("mine: %d, ref: %d\n", p, q);
			printf("a = %d, b = %d, k = %d\n", a, b, k);
			break;
		}
	}
#endif

}
// END CUT HERE
