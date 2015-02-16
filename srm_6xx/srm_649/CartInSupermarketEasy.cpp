// BEGIN CUT HERE
/*
SRM 649 Div2 Medium (500)

問題
-N個の連結したショッピングカートがある
-1分毎に、それぞれの連結したカート毎に、2つに分離するか、1つ減らすことができる
-カートを0個にするまでの最小時間を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

typedef vector<int> IntVec;

class CartInSupermarketEasy {
public:
	int calc(int N, int K) {
		int ans = 0;
		IntVec v(1, N);
		while (v.size() > 0) {
			++ans;
			IntVec next;
			sort(v.rbegin(), v.rend());
			if ((v.front() - v.back()) >= 2) {
				for (int i = 0; i < v.size() / 2; ++i) {
					int a = v[i] + v[v.size() - i - 1];
					v[i] = a / 2;
					v[v.size() - i - 1] = a - v[i];
				}
			}
			sort(v.rbegin(), v.rend());
			for (int i = 0; i < v.size(); ++i) {
				int a = v[i];
				if (a >= 2 && K >= 1) {
					--K;
					next.push_back(a / 2);
					next.push_back(a - a / 2);
				} else if (a >= 2) {
					next.push_back(a - 1);
				}
			}
			v = next;
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
			int Arg0 = 5;
			int Arg1 = 0;
			int Arg2 = 5;

			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arg2 = 4;

			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 4;
			int Arg2 = 6;

			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arg1 = 100;
			int Arg2 = 4;

			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 45;
			int Arg1 = 5;
			int Arg2 = 11;

			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 100;
			int Arg1 = 100;
			int Arg2 = 8;

			verify_case(n, Arg2, calc(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CartInSupermarketEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
