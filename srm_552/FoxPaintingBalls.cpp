// BEGIN CUT HERE
/*
// SRM 552 Div1 Easy (250)

問題
無色のボールをR、G、Bの3色に塗る。
隣り合うボールは異なる色で塗る。
R、G、Bの個数と塗るボールの段数が与えられる。
塗れるセット数を求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class FoxPaintingBalls {

public:
	long long theMax(long long R, long long G, long long B, int N) {
		LL sum = (R+G+B);
		LL n = N;
		if (N <= 1) {
			return sum * N;
		}
		LL need = ((n+1)*n)/2;
		LL a = need / 3;
		LL b = min(R, min(G, B));
		return min(b / a, (sum / need));
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
			long long Arg0 = 2LL;
			long long Arg1 = 2LL;
			long long Arg2 = 2LL;
			int Arg3 = 3;
			long long Arg4 = 1LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 2LL;
			long long Arg2 = 3LL;
			int Arg3 = 3;
			long long Arg4 = 0LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 8LL;
			long long Arg1 = 6LL;
			long long Arg2 = 6LL;
			int Arg3 = 4;
			long long Arg4 = 2LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 6LL;
			long long Arg2 = 7LL;
			int Arg3 = 4;
			long long Arg4 = 2LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 100LL;
			long long Arg2 = 100LL;
			int Arg3 = 4;
			long long Arg4 = 30LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 19330428391852493LL;
			long long Arg1 = 48815737582834113LL;
			long long Arg2 = 11451481019198930LL;
			int Arg3 = 3456;
			long long Arg4 = 5750952686LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1LL;
			long long Arg2 = 1LL;
			int Arg3 = 1;
			long long Arg4 = 3LL;

			verify_case(n, Arg4, theMax(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxPaintingBalls ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
