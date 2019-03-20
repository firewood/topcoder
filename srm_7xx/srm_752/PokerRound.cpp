// BEGIN CUT HERE
/*
SRM 752 Div2 Easy (250)

問題
- 二人でポーカーをする
- 先手はXドル、後手はYドル持っている
- XとYの合計は1万ドルである
- 先手が常に全額賭け、後手がコールし、先手が勝つことを3回繰り返す
- 最終的に後手がTドルのとき、Yを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PokerRound {
public:
	int amount(int T) {
		int x = (10000 - T) / 8;
		int y = T + x * 7;
		return x >= 0 && (x + y == 10000) ? y : -1;
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
			int Arg0 = 2000;
			int Arg1 = 9000;

			verify_case(n, Arg1, amount(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10000;
			int Arg1 = 10000;

			verify_case(n, Arg1, amount(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1722;
			int Arg1 = -1;

			verify_case(n, Arg1, amount(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PokerRound ___test;
	___test.run_test(-1);
}
// END CUT HERE
