// BEGIN CUT HERE
/*
// SRM 532 Div2 Medium (600)

問題

布切れの状態を表す3文字が与えられる。
文字はドットか数字である。
数字の部分だけをつなげることができる。
連続する数字の和の最大値を求める。

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
typedef pair<int, int> II;
typedef vector<II> IIVec;

class DengklekMakingChains {

	static int a(const StrVec &chains) {
		int res = 0;
		IIVec v;
		int i, j;
		for (i = 0; i < (int)chains.size(); ++i) {
			const char *s = chains[i].c_str();
			int len = chains[i].length();
			if (strchr(s, '.') == 0) {
				for (j = 0; j < len; ++j) {
					res += (s[j] - '0');
				}
			} else {
				int _f = 0;
				int _b = 0;
				for (j = 0; j < len; ++j) {
					if (s[j] == '.') {
						break;
					}
					_f += (s[j] - '0');
				}
				for (j = len-1; j >= 0; --j) {
					if (s[j] == '.') {
						break;
					}
					_b += (s[j] - '0');
				}
				v.push_back(II(_f, _b));
			}
		}
		v.push_back(II(0, 0));
		int m = 0;
		for (i = 0; i < (int)v.size(); ++i) {
			for (j = 0; j < (int)v.size(); ++j) {
				if (i == j) {
					continue;
				}
				m = max(m, v[i].first + v[j].second);
			}
		}
		res += m;
		return res;
	}

	static int b(const StrVec &chains) {
		int res = 0;
		int i, j;
		for (i = 0; i < (int)chains.size(); ++i) {
			const char *s = chains[i].c_str();
			int len = chains[i].length();
			int sum = 0;
			for (j = 0; j < len; ++j) {
				if (s[j] == '.') {
					res = max(res, sum);
					sum = 0;
				} else {
					sum += (s[j] - '0');
				}
			}
			res = max(res, sum);
		}
		return res;
	}

public:
	int maxBeauty(vector <string> chains) {
		int res = a(chains);
		res = max(res, b(chains));
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
			string Arr0[] = {".15", "7..", "402", "..3"};
			int Arg1 = 19;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"};
			int Arg1 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"...", "..."};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
			int Arg1 = 28;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..1", "3..", "2..", ".7."};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
			int Arg1 = 58;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"99....", "....99", "..999...", ".7."};
			int Arg1 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"99....", "....89", "..9999...", ".2."};
			int Arg1 = 36;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"..1", "123"};
			int Arg1 = 7;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"6.9"};
			int Arg1 = 9;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxBeauty(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DengklekMakingChains ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
