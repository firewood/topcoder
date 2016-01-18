// BEGIN CUT HERE
/*
SRM 677 Div2 Medium (550)

問題
-文字列a,b,c,dが与えられる
-a,b,c,d全てを部分文字列として含む文字列Sの最小の長さを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FourStrings {
public:
	int shortestLength(string a, string b, string c, string d) {
		int seq[] = { 0, 1, 2, 3 };
		string S[4] = { a, b, c, d };
		int ans = 1 << 30;
		do {
			string sa = S[seq[0]], sb = S[seq[1]], sc = S[seq[2]], sd = S[seq[3]];
			int la = sa.length(), lb = sb.length(), lc = sc.length(), ld = sd.length();
			for (int i = 0; i <= la; ++i) {
				int m1 = min(la - i, lb);
				if (sa.substr(i, m1) == sb.substr(0, m1)) {
					string sab = sa + sb.substr(m1);
					int lab = sab.length();
					for (int j = 0; j <= lab; ++j) {
						int m2 = min(lab - j, lc);
						if (sab.substr(j, m2) == sc.substr(0, m2)) {
							string sabc = sab + sc.substr(m2);
							int labc = sabc.length();
							for (int k = 0; k <= labc; ++k) {
								int m3 = min(labc - k, ld);
								if (sabc.substr(k, m3) == sd.substr(0, m3)) {
									ans = min(ans, labc + ld - m3);
								}
							}
						}
					}
				}
			}
		} while (next_permutation(seq, seq + 4));
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
			string Arg0 = "abc";
			string Arg1 = "ab";
			string Arg2 = "bc";
			string Arg3 = "b";
			int Arg4 = 3;

			verify_case(n, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "a";
			string Arg1 = "bc";
			string Arg2 = "def";
			string Arg3 = "ghij";
			int Arg4 = 10;

			verify_case(n, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "top";
			string Arg1 = "coder";
			string Arg2 = "opco";
			string Arg3 = "pcode";
			int Arg4 = 8;

			verify_case(n, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "thereare";
			string Arg1 = "arelots";
			string Arg2 = "lotsof";
			string Arg3 = "ofcases";
			int Arg4 = 19;

			verify_case(n, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aba";
			string Arg1 = "b";
			string Arg2 = "b";
			string Arg3 = "b";
			int Arg4 = 3;

			verify_case(n, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "x";
			string Arg1 = "x";
			string Arg2 = "x";
			string Arg3 = "x";
			int Arg4 = 1;

			verify_case(n, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FourStrings ___test;
	___test.run_test(-1);
}
// END CUT HERE
