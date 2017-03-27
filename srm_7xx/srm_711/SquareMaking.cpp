// BEGIN CUT HERE
/*
SRM 711 Div2 Easy (250)

問題
-長さがa,b,c,dの4本の棒がある
-長さを1変更するのにコストが1かかる
-全ての棒を同じ長さにするための最小コストを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SquareMaking {
	public:
	int getMinimalPrice(int a, int b, int c, int d) {
		int m = max(max(a, b), max(c, d));
		int ans = 1 << 30;
		for (int i = 1; i <= m; ++i) {
			int cost = abs(a - i) + abs(b - i) + abs(c - i) + abs(d - i);
			ans = min(ans, cost);
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
			int Arg1 = 6;
			int Arg2 = 5;
			int Arg3 = 5;
			int Arg4 = 1;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 1;
			int Arg2 = 5;
			int Arg3 = 4;
			int Arg4 = 4;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2017;
			int Arg1 = 2017;
			int Arg2 = 2017;
			int Arg3 = 2017;
			int Arg4 = 0;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 705451;
			int Arg1 = 751563;
			int Arg2 = 608515;
			int Arg3 = 994713;
			int Arg4 = 432310;

			verify_case(n, Arg4, getMinimalPrice(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SquareMaking ___test;
	___test.run_test(-1);
}
// END CUT HERE
