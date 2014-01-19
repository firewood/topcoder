// BEGIN CUT HERE
/*
// SRM 536 Div1 Medium (500)

問題
N個のサイコロがある。
それぞれのサイコロの面は1からk=dice[i]までの番号が振られていて、出目の確率は等しい。
最も出やすい出目の合計値を求める。複数ある場合は最小値。

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

typedef long long LL;

class RollingDiceDivOne {

public:
	long long mostLikely(vector <int> dice) {
		int dices = dice.size();
		int i;
#if 1
		sort(dice.begin(), dice.end());
		LL sum = 0;
		for (i = 0; i < (dices-1); ++i) {
			sum += dice[i];
		}
		double p = 0;
		for (i = 0; i < dices; ++i) {
			p += (dice[i]+1.0);
		}
		LL res = min(sum + 1, (LL)(p/2.0));
#else
		int nop = 0;
		double p = 0;
		for (i = 0; i < (int)dice.size(); ++i) {
			if (dice[i] == 1) {
				++nop;
				--dices;
			} else {
				p += (dice[i] + 1.0) / 2.0;
			}
		}
		if (dices <= 1) {
			p = 1;
		}
		p += nop;

		LL res = (LL)p;
#endif
		return res;
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
			int Arr0[] = {6, 6, 8};
			long long Arg1 = 11LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			long long Arg1 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 4, 5};
			long long Arg1 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 10, 1};
			long long Arg1 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240};
			long long Arg1 = 4366828428LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RollingDiceDivOne ___test;
//	___test.run_test(6);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
