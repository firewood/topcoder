// BEGIN CUT HERE
/*
// SRM 527 Div2 Hard (950)

問題
貨幣価値が2の累乗になっているN種類の硬貨がある。
ちょうどcoins_count枚の硬貨で、合計をcoins_sumをにしたい。
辞書順最小の組み合わせを求める。

*/
// END CUT HERE
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<LL> LLVec;

class P8XCoinChangeAnother {

public:
	vector<long long> solve(int N, long long coins_sum, long long coins_count) {
		LLVec v(N);
		v[0] = coins_sum;
		LL c = coins_sum;
		LL diff = c - coins_count;
		int i;
		for (i = 0; i < (N-1); ++i) {
			LL a = min(v[i] / 2, diff);
			if (a > 0) {
				v[i] -= a*2;
				v[i+1] += a;
				diff -= a;
			}
		}
		LLVec result;
		if (diff == 0) {
			result = v;
		}
		return result;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 4LL;
			long long Arg2 = 3LL;
			long long Arr3[] = {2, 1 };

			vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 6LL;
			long long Arg2 = 3LL;
			long long Arr3[] = {0, 3, 0 };

			vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 8LL;
			long long Arg2 = 1LL;
//			long long Arr3[] = { };

			vector<long long> Arg3;
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			long long Arg1 = 10000000000LL;
			long long Arg2 = 10000000000LL;
			long long Arr3[] = {10000000000 };

			vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, solve(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	P8XCoinChangeAnother ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
