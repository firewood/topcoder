// BEGIN CUT HERE
/*
SRM 686 Div1 Easy (250)

問題
-()と[]だけからなる文字列がある
-0文字以上削除して、1文字以上にする
-きちんと括弧が閉じるのは何通りか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef map<LL, LL> LLMap;

class BracketSequenceDiv1 {
	LLMap m[2];

	static string reversed(string s) {
		string r;
		for (int i = (int)s.length() - 1; i >= 0; --i) {
			switch (s[i]) {
			case '(': r += ')'; break;
			case ')': r += '('; break;
			case '[': r += ']'; break;
			case ']': r += '['; break;
			}
		}
		return r;
	}

	static void gen(LLMap &m, string s) {
		int len = (int)s.length();
		int mx = 1 << len;
		for (int b = 0; b < mx; ++b) {
			LL t = 0;
			for (int i = 0; i < len; ++i) {
				if ((1 << i) & b) {
					if (s[i] == ')') {
						if (t == 0 || (t & 3) != 2) {
							t = -1;
							break;
						}
						t >>= 2;
					} else if (s[i] == ']') {
						if (t == 0 || (t & 3) != 3) {
							t = -1;
							break;
						}
						t >>= 2;
					} else if (s[i] == '(') {
						t = (t << 2) | 2;
					} else {
						t = (t << 2) | 3;
					}
				}
			}
			if (t >= 0) {
				m[t] += 1;
			}
		}
	}

public:
	long long count(string s) {
		m[0].clear();
		m[1].clear();
		gen(m[0], s.substr(0, s.length() / 2));
		gen(m[1], reversed(s.substr(s.length() / 2)));

		LL ans = -1;
		LLMap::const_iterator p;
		for (p = m[0].begin(); p != m[0].end(); ++p) {
			ans += p->second * m[1][p->first];
		}
		return ans;
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
			string Arg0 = "()[]";
			long long Arg1 = 3LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "())";
			long long Arg1 = 2LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()";
			long long Arg1 = 4LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "([)]";
			long long Arg1 = 2LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "())[]][]([]()]]()]]]";
			long long Arg1 = 3854LL;

			verify_case(n, Arg1, count(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BracketSequenceDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
