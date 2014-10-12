// BEGIN CUT HERE
/*
SRM 617 Div2 Easy (250)

問題
-整数nが与えられる
-x+y=nを満たす合成数x,yを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SilverbachConjecture {
public:
	vector <int> solve(int n) {
		int p[2000] = {};
		p[2] = 1;
		for (int i = 3; i < 2000; ++i) {
			p[i] = 1;
			for (int j = 2; j < i; ++j) {
				if ((i % j) == 0) {
					p[i] = 0;
					break;
				}
			}
		}
		vector <int> ans(2);
		for (int i = 4; !ans[0] && i < 2000; ++i) {
			if (!p[i]) {
				for (int j = 4; j < 2000; ++j) {
					if (!p[j]) {
						if (i + j == n) {
							ans[0] = i;
							ans[1] = j;
							break;
						}
					}
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arr1[] = {8, 12 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 30;
			int Arr1[] = {15, 15 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 999;
			int Arr1[] = {699, 300 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 45;
			int Arr1[] = {15, 30 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SilverbachConjecture ___test;
	___test.run_test(-1);
}
// END CUT HERE
