// BEGIN CUT HERE
/*
SRM 635 Div2 Medium (500)

問題
-教師がt分遅刻してくるときには、授業をt^2分早く終わらせなければならない
-授業の長さd分が与えられる。何分まで遅刻できるかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class QuadraticLaw {
public:
	long long getTime(long long d) {
		LL t = sqrt(d);
		LL ans = 0;
		for (LL a = max(0LL, t - 2); a <= t + 1; ++a) {
			if (a*a+a <= d) {
				ans = a;
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
			long long Arg0 = 1LL;
			long long Arg1 = 0LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 2LL;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 6LL;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 7LL;
			long long Arg1 = 2LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1482LL;
			long long Arg1 = 38LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1000000000000000000LL;
			long long Arg1 = 999999999LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 31958809614643170LL;
			long long Arg1 = 178770270LL;

			verify_case(n, Arg1, getTime(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	QuadraticLaw ___test;
	___test.run_test(-1);
}
// END CUT HERE
