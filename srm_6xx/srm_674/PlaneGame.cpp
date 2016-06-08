// BEGIN CUT HERE
/*
SRM 674 Div2 Medium (500)

問題
-二次元座標上に何個かの点がある
-平行移動または回転ができる
-任意の移動と回転操作をしたのち、X軸とY軸上の点を一掃する
-消せる点の個数の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef set<LL> LLSet;
typedef map<II, LLSet> IILLSetMap;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555LL) + (bits >> 1 & 0x5555555555555555LL);
	bits = (bits & 0x3333333333333333LL) + (bits >> 2 & 0x3333333333333333LL);
	bits = (bits & 0x0f0f0f0f0f0f0f0fLL) + (bits >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	bits = (bits & 0x00ff00ff00ff00ffLL) + (bits >> 8 & 0x00ff00ff00ff00ffLL);
	bits = (bits & 0x0000ffff0000ffffLL) + (bits >> 16 & 0x0000ffff0000ffffLL);
	bits = (bits & 0x00000000ffffffffLL) + (bits >> 32 & 0x00000000ffffffffLL);
	return (int)bits;
}

class PlaneGame {
public:
	int bestShot(vector <int> x, vector <int> y) {
		LL mx = (1LL << (x.size())) - 1;
		IILLSetMap m;
		for (int i = 0; i != x.size(); ++i) {
			for (int j = i + 1; j != x.size(); ++j) {
				int dx = x[j] - x[i], dy = y[j] - y[i], g = gcd(abs(dx), abs(dy));
				dx /= g, dy /= g;
				LL f = 1LL << i;
				for (int k = 0; k != x.size(); ++k) {
					if (k != i) {
						int a = x[k] - x[i], b = y[k] - y[i], g = gcd(abs(a), abs(b));
						a /= g, b /= g;
						if ((a == dx && b == dy) || (-a == dx && -b == dy)) {
							f |= (1LL << k);
						}
					}
				}
				m[II(dx, dy)].insert(f);
				m[II(-dx, -dy)].insert(f);
			}
		}
		int ans = 1;
		for (auto e : m) {
			for (LL a : e.second) {
				ans = max(ans, popcount(a));
				if (a != mx) {
					ans = max(ans, popcount(a) + 1);
				}
				IILLSetMap::const_iterator p = m.find(II(-e.first.second, e.first.first));
				if (p != m.end()) {
					for (LL b : p->second) {
						ans = max(ans, popcount(a | b));
					}
				}
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
			int Arr0[] = {0, 5};
			int Arr1[] = {0, 5};
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, bestShot(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, -1, 1, 1, -1};
			int Arr1[] = {0, -1, -1, 1, 1};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, bestShot(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 1, -1};
			int Arr1[] = {0, 1, -1, 0, 0};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, bestShot(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, -3, 3, 3, -3, 0, 0, 3, -3};
			int Arr1[] = {0, -3, -3, 3, 3, 3, -3, 0, 0};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, bestShot(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {0};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, bestShot(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1000000, -1, 999998, 1, -1001, 1000000, -999999, 999999, 0, 0};
			int Arr1[] = {1000000, 1, 1000000, -1, -999, 1000000, 0, 0, -999999, 999999};
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, bestShot(Arg0, Arg1));
		}
		n++;
	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PlaneGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
