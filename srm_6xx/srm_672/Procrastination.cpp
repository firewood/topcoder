// BEGIN CUT HERE
/*
SRM 672 Div1 Easy (250)

問題
-Hugeソフトウェアには無限の従業員がいる
-従業員には2から連番の従業員番号がついている
-最初、従業員xにはタスクxが割り当てられる
-時間tに、2以上の整数kについて、従業員k×tと従業員k×t+1がタスクを交換する
-最終的にタスクnが割り当てられる従業員を求める

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

class Procrastination {
public:
	long long findFinalAssignee(long long n) {
		LL ans = n;
		LL x;
		for (x = 2; x * x <= n; ++x) {
			if (ans >= x * 2 && (ans % x) == 0) {
				++ans;
			} else if ((ans - 1) >= x * 2 && ((ans - 1) % x) == 0) {
				--ans;
			}
		}
		for (LL y = x; y >= 2; --y) {
			LL z = ans / y;
			if (z >= x) {
				if (ans >= z * 2 && (ans % z) == 0) {
					++ans;
				} else if ((ans - 1) >= z * 2 && ((ans - 1) % z) == 0) {
					--ans;
				}
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
			long long Arg0 = 3LL;
			long long Arg1 = 3LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 8LL;
			long long Arg1 = 11LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 20LL;
			long long Arg1 = 20LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 196248LL;
			long long Arg1 = 196259LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5587021440LL;
			long long Arg1 = 5587021440LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Procrastination ___test;
	___test.run_test(-1);
}
// END CUT HERE
