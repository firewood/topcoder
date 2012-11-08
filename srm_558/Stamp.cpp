// BEGIN CUT HERE
/*
// SRM 558 Div1 Easy (275)

問題
升目をスタンプで3色に塗る。
スタンプを作るコストと塗るコストが与えられる。
最小のコストを求める。

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

class Stamp {

public:
	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		int sz = (int)desiredColor.length();
		int res = stampCost + pushCost * sz;
		int i, j, k, L;

		int maxlen[50];
		for (i = 0; i < sz; ++i) {
			k = '*';
			for (j = i; j < sz; ++j) {
				if (k != desiredColor[j] && desiredColor[j] != '*') {
					if (k != '*') {
						break;
					}
					k = desiredColor[j];
				}
			}
			maxlen[i] = j-i;
		}

		int dp[51];
		for (L = 2; L <= sz; ++L) {
			memset(dp, 0x7f, sizeof(dp));
			dp[0] = 0;
			for (i = L; i <= sz; ++i) {
				for (j = L; j <= i; ++j) {
					if (maxlen[i-j] >= j) {
						dp[i] = min(dp[i], dp[i-j] + pushCost * ((j+L-1)/L));
					}
				}
			}
			res = min(res, stampCost * L + dp[sz]);
		}

		return res;
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
			string Arg0 = "RRGGBB";
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 5;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R**GB*";
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 5;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BRRB";
			int Arg1 = 2;
			int Arg2 = 7;
			int Arg3 = 30;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R*RR*GG";
			int Arg1 = 10;
			int Arg2 = 58;
			int Arg3 = 204;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "*B**B**B*BB*G*BBB**B**B*";
			int Arg1 = 5;
			int Arg2 = 2;
			int Arg3 = 33;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
			int Arg1 = 7;
			int Arg2 = 1;
			int Arg3 = 30;

			verify_case(n, Arg3, getMinimumCost(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Stamp ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
