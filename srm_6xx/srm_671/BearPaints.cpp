// BEGIN CUT HERE
/*
SRM 671 Div2 Easy (250)

問題
-W×Hのセルがある
-Mセル塗れる
-四角形に塗るとき、最大の面積を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class BearPaints {
public:
	long long maxArea(int W, int H, long long M) {
		LL ans = 0;
		LL a = min(W, H), b = max(W, H);
		for (LL c = 1; c <= a; ++c) {
			LL d = min(M / c, b);
			ans = max(ans, c * d);
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
			int Arg0 = 3;
			int Arg1 = 5;
			long long Arg2 = 14LL;
			long long Arg3 = 12LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			long long Arg2 = 10LL;
			long long Arg3 = 9LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 12345;
			long long Arg2 = 1000000000000LL;
			long long Arg3 = 12345000000LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			long long Arg2 = 720000000007LL;
			long long Arg3 = 720000000000LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000;
			int Arg1 = 1000000;
			long long Arg2 = 999999999999LL;
			long long Arg3 = 999999000000LL;

			verify_case(n, Arg3, maxArea(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPaints ___test;
	___test.run_test(-1);
}
// END CUT HERE
