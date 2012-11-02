// BEGIN CUT HERE
/*
// SRM 557 Div1 Easy (250)

問題
スタート地点の高さがh0で終点の高さがhnの登山路がある。
登山路はなだらかで±1の高低差からなる。
部分的なアップダウンの情報が与えられる。
登山路が成り立つかどうかを求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndMountainEasy {

public:
	string possible(int n, int h0, int hn, string history) {
		int cnt = 0;
		int h = h0;
		int sz = (int)history.length();
		int i;
		for (i = 0; i < sz; ++i) {
			if (history[i] == 'U') {
				++h;
			} else {
				--h;
				if (h < 0) {
					h = 0;
					++cnt;
				}
			}
		}
		int rcnt = n - (sz+cnt);
		int rh = abs(hn - h);
		if (rcnt < rh || (rcnt&1) != (rh&1)) {
			return "NO";
		}
		return "YES";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 4;
			string Arg3 = "UU";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 4;
			string Arg3 = "D";
			string Arg4 = "NO";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 100000;
			int Arg2 = 100000;
			string Arg3 = "DDU";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 0;
			int Arg2 = 0;
			string Arg3 = "DDU";
			string Arg4 = "NO";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 20;
			int Arg2 = 20;
			string Arg3 = "UDUDUDUDUD";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 0;
			int Arg2 = 0;
			string Arg3 = "UUUUUUUUUU";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 0;
			int Arg2 = 0;
			string Arg3 = "UUUUUUUUUUU";
			string Arg4 = "NO";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 5650;
			int Arg1 = 1397;
			int Arg2 = 969;
			string Arg3 = "UDUUUDUDDDDUDDUUDUUUUDDUUUUDUDUDUDUDDDD";
			string Arg4 = "YES";

			verify_case(n, Arg4, possible(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndMountainEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
