// BEGIN CUT HERE
/*
TCO18 R1B Easy (250)

問題
-直線上に、彩色された点がいくつかある
-同じ色の隣接する2つの点を消すと1点入る
-各文字が色を表した文字列pointsが与えられる
-最大の点数を求めよ

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

class LineOff {
public:
	int movesToDo(string points) {
		vector<string> v(26);
		for (int i = 0; i < 26; ++i) {
			v[i] = string(2, (char)(i + 'a'));
		}
		int ans = 0;
		bool f = true;
		while (f) {
			f = false;
			for (int i = 0; i < 26; ++i) {
				int pos = points.find(v[i]);
				if (pos >= 0) {
					points = points.substr(0, pos) + points.substr(pos + 2);
					++ans;
					f = true;
				}
			}
		}
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
			string Arg0 = "abba";
			int Arg1 = 2;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "zwwwzffw";
			int Arg1 = 2;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "rrrrrrr";
			int Arg1 = 3;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "dfghj";
			int Arg1 = 0;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "wasitacarooracatisaw";
			int Arg1 = 10;

			verify_case(n, Arg1, movesToDo(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LineOff ___test;
	___test.run_test(-1);
}
// END CUT HERE
