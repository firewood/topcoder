// BEGIN CUT HERE
/*
// SRM 534 Div2 Medium (500)

問題

N個のマスからなる盤面がある。
マスは空または駒が置かれている。
駒の右が空いていれば駒を一つ右に移動できる。
駒の右とその右が駒でその右が空いていれば、駒を三つ移動できる。
最も右の駒は直ちに取り除かれる。
二人のプレーヤーで交互に移動操作をするとき、動かせなかったら負けとするとき
最初のプレーヤーが勝つかどうかを求める。

*/
// END CUT HERE
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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

typedef map<int, int> IntMap;

class EllysCheckers {
	int N;
	IntMap m;

	int rec(int B) {
		B &= ~1;
		if (B == 0) {
			return 0;
		}
		if (m.find(B) != m.end()) {
			return m[B];
		}
		int &res = m[B];
		res = 0;

		int i, t;
		for (i = N-1; i >= 1; --i) {
			int current = (1 << i);
			int next = (1 << (i-1));
			if ((B & current) != 0 && (B & next) == 0) {
				t = rec((B & ~current) | next);
				if (!t) {
					res = 1;
					return res;
				}
			}
		}
		for (i = N-1; i >= 3; --i) {
			int current = (1 << i);
			int a = (1 << (i-1));
			int b = (1 << (i-2));
			int c = (1 << (i-3));
			if ((B & current) == 0) {
				continue;
			}
			if ((B&a)!=0 && (B&b)!=0 && (B&c)==0) {
				t = rec((B & ~current) | c);
				if (!t) {
					res = 1;
					return res;
				}
			}
		}

		return res;
	}

public:
	string getWinner(string board) {
		N = board.length();
		m.clear();
		int B = 0;
		int i;
		for (i = 0; i < N; ++i) {
			if (board[i] != '.') {
				B |= (1 << (N-i-1));
			}
		}
		return rec(B) ? "YES" : "NO";
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
			string Arg0 = ".o...";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "..o..o";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".o...ooo..oo..";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "......o.ooo.o......";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".o..o...o....o.....o";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;


		//@@
		if ((Case == -1) || (Case == n)){
			string Arg0 = "....o";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;
		//@@
		if ((Case == -1) || (Case == n)){
			string Arg0 = "...o.";
			string Arg1 = "YES";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;
		//@@
		if ((Case == -1) || (Case == n)){
			string Arg0 = "oooo";
			string Arg1 = "NO";

			verify_case(n, Arg1, getWinner(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysCheckers ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
