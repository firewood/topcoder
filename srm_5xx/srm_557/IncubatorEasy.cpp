// BEGIN CUT HERE
/*
// SRM 557 Div2 Medium (550)

問題
インキュベーターが少女と契約する。
少女は契約すると魔法少女となり、自分が守りたい少女を守る。
誰かに守られた少女もまた、自分が守りたい少女を守る。
守られていない魔法少女の最大人数を求める。

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
typedef vector<int> IntVec;
typedef vector<LL> LLVec;
typedef vector<string> StrVec;
typedef set<int> IntSet;
typedef set<LL> LLSet;

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555LL) + (bits >>  1 & 0x5555555555555555LL);
	bits = (bits & 0x3333333333333333LL) + (bits >>  2 & 0x3333333333333333LL);
	bits = (bits & 0x0f0f0f0f0f0f0f0fLL) + (bits >>  4 & 0x0f0f0f0f0f0f0f0fLL);
	bits = (bits & 0x00ff00ff00ff00ffLL) + (bits >>  8 & 0x00ff00ff00ff00ffLL);
	bits = (bits & 0x0000ffff0000ffffLL) + (bits >> 16 & 0x0000ffff0000ffffLL);
	bits = (bits & 0x00000000ffffffffLL) + (bits >> 32 & 0x00000000ffffffffLL);
	return (int)bits;
}

class IncubatorEasy {

public:
	int maxMagicalGirls(vector <string> love) {
		int res = 0;
		int sz = (int)love.size();
		int Max = 1 << sz;
		int pm[10] = {};
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			int b = 0;
			for (j = 0; j < sz; ++j) {
				if (love[i][j] == 'Y') {
					b |= 1<<j;
				}
			}
			pm[i] = b;
		}
		for (i = 0; i < sz; ++i) {
			int b = pm[i];
			for (j = 0; j < sz; ++j) {
				for (k = 0; k < sz; ++k) {
					if (b & (1<<k)) {
						b |= pm[k];
					}
				}
			}
			pm[i] = b;
		}
		for (i = 1; i < Max; ++i) {
			int p = 0;
			for (j = 0; j < sz; ++j) {
				if (i & (1<<j)) {
					p |= pm[j];
				}
			}
			int m = i & ~p;
			res = max(res, (int)popcount(m));
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
			string Arr0[] = {"NY","NN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NYN", "NNY", "NNN"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"Y"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxMagicalGirls(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	IncubatorEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
