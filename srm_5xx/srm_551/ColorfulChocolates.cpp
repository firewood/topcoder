// BEGIN CUT HERE
/*
// SRM 551 Div1 Easy (250)

問題
何色かのチョコレートが横一列に並んでいる。
交換して同じ色ができるだけ連続で並べたい。
交換回数が与えられる。最大の連続数を求める。

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

class ColorfulChocolates {

public:
	int maximumSpread(string chocolates, int maxSwaps) {
		int sz = (int)chocolates.length();
		int res = 0;
		int C, i, j, k, p, q, r, s, a, b;
		for (C = 'A'; C <= 'Z'; ++C) {
			int cnt = 0;
			int pos[50];
			for (i = 0; i < sz; ++i) {
				if (chocolates[i] == C) {
					pos[cnt++] = i;
				}
			}
			for (i = 0; i < cnt; ++i) {
				a = pos[i] - 1;
				b = pos[i] + 1;
				r = maxSwaps;
				j = i-1;
				k = i+1;
				s = 1;
				while (true) {
					p = 9999, q = 9999;
					if (j >= 0) {
						p = a - pos[j];
					}
					if (k < cnt) {
						q = pos[k] - b;
					}
					if (p < q) {
						if (r < p) {
							break;
						}
						r -= p;
						++s;
						--a;
						--j;
					} else if (q < 9999) {
						if (r < q) {
							break;
						}
						r -= q;
						++s;
						++b;
						++k;
					} else {
						break;
					}
				}
				res = max(res, s);
			}
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
			string Arg0 = "ABCDCBC";
			int Arg1 = 1;
			int Arg2 = 2;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCDCBC";
			int Arg1 = 2;
			int Arg2 = 3;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBABABBA";
			int Arg1 = 3;
			int Arg2 = 4;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABBABABBA";
			int Arg1 = 4;
			int Arg2 = 5;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
			int Arg1 = 77;
			int Arg2 = 5;

			verify_case(n, Arg2, maximumSpread(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulChocolates ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
