// BEGIN CUT HERE
/*
SRM 664 Div2 Medium (550)

問題
-何個かの石があり、3つの山にわける
-任意の2つの山を選び、数が少ないほうをX個、数が多いほうをY個とする
-Y個の山からX個の山にX個移動することを繰り返す
-3つの山の個数を等しくできるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;

class BearPlaysDiv2 {
	int T;
	set<II> memo;

	bool dfs(int a, int b) {
		int c = T - a - b;
		if (a == b && b == c) {
			return true;
		}
		II key(a, b);
		if (memo.find(key) != memo.end()) {
			return false;
		}
		memo.insert(key);
		int p = min(a, b);
		int q = max(a, b);
		if (dfs(p * 2, q - p)) {
			return true;
		}
		int r = min(p, c);
		int s = max(p, c);
		if (dfs(r * 2, s - r)) {
			return true;
		}
		return false;
	}

public:
	string equalPiles(int A, int B, int C) {
		T = A + B + C;
		memo.clear();
		return dfs(A, B) ? "possible" : "impossible";
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
			int Arg0 = 10;
			int Arg1 = 15;
			int Arg2 = 35;
			string Arg3 = "possible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 1;
			int Arg2 = 2;
			string Arg3 = "impossible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 6;
			int Arg2 = 8;
			string Arg3 = "impossible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 18;
			int Arg1 = 18;
			int Arg2 = 18;
			string Arg3 = "possible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 225;
			int Arg1 = 500;
			int Arg2 = 475;
			string Arg3 = "possible";

			verify_case(n, Arg3, equalPiles(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPlaysDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
