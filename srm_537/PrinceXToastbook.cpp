// BEGIN CUT HERE
/*
// SRM 537 Div2 Hard (925)

問題
N冊の本がある。
そのうちの何冊かは、別の本を読んでからでないと理解できない。
ランダムにN冊読むとき、理解できる冊数の期待値を求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

class PrinceXToastbook {

	double factorial(double n) {
		if (n > 1) {
			n *= factorial(n-1);
		}
		return n;
	}

public:
	double eat(vector <int> prerequisite) {
		double result = 0;
		int i;
		for (i = 0; i < (int)prerequisite.size(); ++i) {
			int depth = 0;
			int parent = i;
			while (true) {
				++depth;
				if (depth > (int)prerequisite.size()) {
					break;
				}
				parent = prerequisite[parent];
				if (parent < 0) {
					result += 1.0 / factorial(depth);
					break;
				}
			}
		}
		return result;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 0};
			double Arg1 = 1.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 0, 1};
			double Arg1 = 1.6666666666666667;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, -1, 1};
			double Arg1 = 2.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 0};
			double Arg1 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, -1};
			double Arg1 = 2.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7, 5, 5, 7, 2, 3, 4, 1};
			double Arg1 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, eat(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PrinceXToastbook ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
