// BEGIN CUT HERE
/*
SRM 717 Div2 Easy (250)

問題
-0と1からなる行列Tがある
-ベクトルxとyが与えられる
-Tの要素(i,j)がx[i] XOR y[j]を満たすかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class NiceTable {
	bool nice(vector <string> t) {
		int h = (int)t.size(), w = (int)t[0].length();
		for (int x = 0; x != (1 << h); ++x) {
			for (int y = 0; y != (1 << w); ++y) {
				bool f = true;
				for (int i = 0; i < h; ++i) {
					for (int j = 0; j < w; ++j) {
						if ((((x >> i) ^ (y >> j)) & 1) != (t[i][j] - '0')) {
							f = false;
						}
					}
				}
				if (f) {
					return true;
				}
			}
		}
		return false;
	}

public:
	string isNice(vector <string> t) {
		return nice(t) ? "Nice" : "Not nice";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"01",
 "10"};
			string Arg1 = "Nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"01",
 "11"};
			string Arg1 = "Not nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"0100",
 "1011",
 "0100"};
			string Arg1 = "Nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"11",
 "10",
 "11",
 "11",
 "11"};
			string Arg1 = "Not nice";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, isNice(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NiceTable ___test;
	___test.run_test(-1);
}
// END CUT HERE
