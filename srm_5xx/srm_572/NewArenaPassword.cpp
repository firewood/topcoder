// BEGIN CUT HERE
/*
SRM 572 Div1 Easy (250)

問題
-新しいパスワードルールでは、先頭のK文字と末尾のK文字が一致する必要がある。
-古いパスワードが与えられる。
-ルールに適合するために変更しなければならない文字数を求める。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NewArenaPassword {
public:
	int minChange(string oldPassword, int K) {
		int sz = (int)oldPassword.length();
		int ans = 0;
		int i, j, k;
		if (K*2 <= sz) {
			for (i = 0; i < K; ++i) {
				ans += oldPassword[i] != oldPassword[sz-K+i];
			}
		} else {
			int T = sz - K;
			for (i = 0; i < T; ++i) {
				int f[256] = {};
				for (j = 0; (k=i+j*T) < sz; ++j) {
					f[(int)oldPassword[k]] += 1;
				}
				sort(f, f+256, greater<int>());
				ans += j - f[0];
			}
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
			string Arg0 = "topcoderopen";
			int Arg1 = 5;
			int Arg2 = 3;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "puyopuyo";
			int Arg1 = 4;
			int Arg2 = 0;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "loool";
			int Arg1 = 3;
			int Arg2 = 1;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "arena";
			int Arg1 = 5;
			int Arg2 = 0;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "amavckdkz";
			int Arg1 = 7;
			int Arg2 = 5;

			verify_case(n, Arg2, minChange(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NewArenaPassword ___test;
//	___test.run_test(0);
//	___test.run_test(1);
	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
