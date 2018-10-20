// BEGIN CUT HERE
/*
SRM 737 Div2 Medium (500)

問題
-二人でNIMゲームを行う
-いくつかの石からなるいくつかの山がある
-プレイヤーは一つの山を選び、一つ以上の石を取る
-最後の石を取ったプレイヤーが勝つ
-石の状態が与えられる
-勝てる初手の総数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class AliceAndBobMedium {
public:
	int count(vector <int> a) {
		int ans = 0, n = (int)a.size(), x = 0;
		for (int i = 0; i < n; ++i) {
			x ^= a[i];
		}
		if (x) {
			for (int i = 0; i < n; ++i) {
				int y = x ^ a[i];
				ans += a[i] >= y;
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
			int Arr0[] = {737};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,3,7};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,7,3,7};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AliceAndBobMedium ___test;
	___test.run_test(-1);
}
// END CUT HERE
