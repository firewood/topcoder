// BEGIN CUT HERE
/*
SRM 522 Div2 Medium (550)

問題
-AliceとBobが交互にコインを置く。
-コインは1以上の連続するマスに置ける。
-全ての場所を埋める置き方はできない。
-残りのマスが1つになったとき、マスに書いてある文字で勝者が決まる。
-最適戦略で勝つほうを答える。

*/
// END CUT HERE
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;
typedef map<LL, int> LLIntMap;

class RowAndManyCoins {
	string _cells;
	int _n;
	LLIntMap _m;
	LLIntMap _g;
	int rec(int t, LL state) {
		LLIntMap::const_iterator it = _m.find(state);
		if (it != _m.end()) {
			return it->second;
		}
		int &result = _m[state];

		it = _g.find(state);
		if (it != _g.end()) {
			result = it->second;
			return result;
		}

		result = -1;
		int i, j;
		for (i = 0; i < _n; ++i) {
			LL b = (1LL << i);
			if ((state & b) != 0) {
				continue;
			}
			LL mask = 0;
			for (j = i; j < _n; ++j) {
				LL temp = (1LL << j);
				if ((state & j) != 0) {
					break;
				}
				mask |= temp;
				int r = rec(t ^ 1, mask);
				if (result < 0) {
					result = r;
				} else if (r == t) {
					result = r;
				}
			}
		}

		return result;
	}

public:
	string getWinner(string cells) {
		_cells = cells;
		_n = cells.length();
		_m.clear();
		_g.clear();

		int i;
		for (i = 0; i < _n; ++i) {
			LL mask = (1LL << _n) - 1;
			mask ^= (1LL << i);
			_g[mask] = cells[i] != 'A';
		}

		int r = rec(0, 0);
		return r ? "Bob" : "Alice";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABBB"; string Arg1 = "Alice"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { string Arg0 = "BBBB"; string Arg1 = "Bob"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { string Arg0 = "BA"; string Arg1 = "Alice"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { string Arg0 = "BABBABBB"; string Arg1 = "Bob"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { string Arg0 = "ABABBBABAABBAA"; string Arg1 = "Alice"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { string Arg0 = "BBBAAABBAAABBB"; string Arg1 = "Bob"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RowAndManyCoins ___test;
//	___test.run_test(1);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
