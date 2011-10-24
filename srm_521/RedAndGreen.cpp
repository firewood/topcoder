// BEGIN CUT HERE
/*
// SRM 521 Div2 Easy (250)

問題

RとGのどちらかで塗られたパネルが1列に並んでいる。
RをGに、または、GをRに塗る操作により、Gの右側にRがない状態にしたい。
RをGに、またはGをRにする操作の最小回数を求める。

#line 67 "RedAndGreen.cpp"
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
typedef vector<string> StrVec;
typedef map<string, int> StringIntMap;

class RedAndGreen {
	StringIntMap M;

	int rec(const string &s) {
		StringIntMap::const_iterator it = M.find(s);
		if (it != M.end()) {
			return it->second;
		}

		char temp[64];
		strcpy(temp, s.c_str());
		char *fg = strchr(temp, 'G');
		char *rr = strrchr(temp, 'R');

		int f = 0;
		int r = 0;
		if (rr > fg) {
			if (fg != NULL) {
				*fg = 'R';
				f = rec(temp) + 1;
				*fg = 'G';
			}
			if (rr != NULL) {
				*rr = 'G';
				r = rec(temp) + 1;
			}
		}
		int result = min(f, r);
		M[s] = result;
		return result;
	}

public:
	int minPaints(string row) {
		char temp[64] = {0};
		strcpy(temp, row.c_str());
		char *fg = strchr(temp, 'G');
		char *fr = strchr(temp, 'R');
		char *rr = strrchr(temp, 'R');
		if (fg == NULL) {
			return 0;
		}
		if (fr == NULL) {
			return 0;
		}
		if (rr < fg) {
			return 0;
		}

		M.clear();
		return rec(row);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGRGR"; int Arg1 = 2; verify_case(0, Arg1, minPaints(Arg0)); }
	void test_case_1() { string Arg0 = "RRRGGGGG"; int Arg1 = 0; verify_case(1, Arg1, minPaints(Arg0)); }
	void test_case_2() { string Arg0 = "GGGGRRR"; int Arg1 = 3; verify_case(2, Arg1, minPaints(Arg0)); }
	void test_case_3() { string Arg0 = "RGRGRGRGRGRGRGRGR"; int Arg1 = 8; verify_case(3, Arg1, minPaints(Arg0)); }
	void test_case_4() { string Arg0 = "RRRGGGRGGGRGGRRRGGRRRGR"; int Arg1 = 9; verify_case(4, Arg1, minPaints(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RedAndGreen ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
