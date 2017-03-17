// BEGIN CUT HERE
/*
SRM 491 Div1 Easy (250)

問題
-6面ダイスを作る
-各面は正の整数で、すべて異なること
-裏側の数値との合計がK以上であること
-ありうる組み合わせの総数を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class FoxMakingDice {

public:
	long long theCount(int N, int K) {
		LL ans = 0, i, j, k;
		LL f[2002] = {};
		for (i = 1; i <= N; ++i) {
			for (j = i + 1; j <= N; ++j) {
				f[i+j] += 1;
			}
		}
		for (k = K; k <= N*2; ++k) {
			if (f[k] >= 3) {
				ans += f[k] * (f[k] - 1) * (f[k] - 2) / 3;
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
			int Arg0 = 6;
			int Arg1 = 7;
			long long Arg2 = 2LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 7;
			long long Arg2 = 0LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000;
			int Arg1 = 1;
			long long Arg2 = 20625666000LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 456;
			int Arg1 = 123;
			long long Arg2 = 879075732LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 913;
			int Arg1 = 1014;
			long long Arg2 = 4506149340LL;

			verify_case(n, Arg2, theCount(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxMakingDice ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
