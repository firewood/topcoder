// BEGIN CUT HERE
/*
SRM 734 Div1 Easy (300)

問題
-二次元平面上の格子点を考える
-原点から距離がR以内の格子点のうち、原点からの直線状に他の格子点が存在しないものの個数を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class TheRoundCityDiv1 {
public:
	long long find(int _r) {
		LL r = _r;
		vector<LL> p(1000001);
		for (LL i = 2; i <= r; ++i) {
			if (!p[i]) {
				for (LL j = i; j <= r; j += i) {
					p[j] = i;
				}
			}
		}
		LL ans = 1;
		for (LL i = 1; i < r; ++i) {
			LL factors[16];
			LL fcnt = 0;
			LL m = (LL)sqrt(r * r - i * i);
			LL x = i;
			while (p[x]) {
				LL a = p[x];
				factors[fcnt++] = a;
				while ((x % a) == 0) {
					x /= a;
				}
			}
			LL bm = 1LL << fcnt;
			for (LL b = 1; b < bm; ++b) {
				LL y = 1, bcnt = 0;
				for (LL j = 0; j < fcnt; ++j) {
					if ((1LL << j) & b) {
						y *= factors[j];
						++bcnt;
					}
				}
				ans += (bcnt % 2) ? -m/y : m/y;
			}
			ans += m;
		}
		return ans * 4;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			long long Arg1 = 4LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 8LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 16LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 47;
			long long Arg1 = 4176LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1000000;
			long long Arg1 = 1909859313984LL;

			verify_case(n, Arg1, find(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheRoundCityDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
