// BEGIN CUT HERE
/*
SRM 619 Div2 Medium (500)

問題
-N人の従業員がいる
-その中の一人を適当に選びたい
-1ターンに一人ずつ減らしていく
-tターン目はt^3番目の人を減らす
-最後に残るのが何番目の人か求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class ChooseTheBestOne {
public:
	int countNumber(int N) {
		int u[5000] = {};
		int pos = 0;
		for (LL i = 1; i < N; ++i) {
			LL r = N - i + 1;
			LL sel = (i * i * i) % r;
			if (sel == 0) {
				sel = r;
			}
			int cnt = 0;
			for (;; pos = (pos + 1) % N) {
				if (!u[pos]) {
					if (++cnt == sel) {
						u[pos] = 1;
						break;
					}
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			if (!u[i]) {
				return i + 1;
			}
		}
		return -1;
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
			int Arg0 = 3;
			int Arg1 = 2;

			verify_case(n, Arg1, countNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arg1 = 6;

			verify_case(n, Arg1, countNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arg1 = 8;

			verify_case(n, Arg1, countNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1234;
			int Arg1 = 341;

			verify_case(n, Arg1, countNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChooseTheBestOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
