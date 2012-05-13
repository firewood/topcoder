// BEGIN CUT HERE
/*
// TCO 2012 R2B Easy (300)

問題
N分割されていて、それぞれ1～N点のダーツ盤がある。
一部の文字盤は汚れていて数値が読めない。
正確にどれでも当てられるとして、最低P点以上にできる回数を求める。

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

typedef vector<int> IntVec;

class BlurredDartboard {

public:
	int minThrows(vector <int> points, int P) {
		sort(points.begin(), points.end());
		int sz = points.size();
		int Max = points[sz-1];
		IntVec cnt(sz+1);
		int i, sum = 0;
		for (i = 0; i < sz; ++i) {
			++cnt[points[i]];
			sum += points[i];
		}
		int zsum = (sz+1)*sz/2 - sum;
		double zavg = cnt[0] > 0 ? (double)zsum / (double)cnt[0] : 0;
		if ((double)Max > zavg) {
			return (P + Max-1) / Max;
		}
		int zcnt = P / zsum;
		int res = cnt[0] * zcnt;
		P -= zsum * zcnt;
		zcnt = 0, zsum = 0;
		if (P > 0) {
			for (i = 1; i <= sz; ++i) {
				if (cnt[i] == 0) {
					++zcnt;
					zsum += i;
					if (zsum >= P) {
						break;
					}
				}
			}
			if (Max > 0) {
				zcnt = min(zcnt, (P+Max-1)/Max);
			}
		}
		return res + zcnt;
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
			int Arr0[] = {0, 3, 4, 0, 0};
			int Arg1 = 8;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0};
			int Arg1 = 15;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 7, 8, 1, 3, 2, 6, 5};
			int Arg1 = 2012;
			int Arg2 = 252;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
			int Arg1 = 2012;
			int Arg2 = 307;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
			int Arg1 = 1000000000;
			int Arg2 = 84656087;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minThrows(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BlurredDartboard ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
