// BEGIN CUT HERE
/*
// SRM 538 Div2 Easy (300)

問題
LかRからなるコマンド列が実行可能な機械がある。
Lは左に、Rは右に一歩進む。
コマンド列の一部が破損して?になっている。
破損したコマンドをLかRに補ったとき、初期位置から最遠点の距離を求める。

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

class LeftOrRight {

public:
	int maxDistance(string program) {
		int res = 0;
		int R[64] = {0};
		int L[64] = {0};
		int i;
		int rm = 0, lm = 0;
		for (i = 0; i < (int)program.length(); ++i) {
			switch (program[i]) {
			case 'R':
				R[i+1] = R[i] - 1;
				L[i+1] = L[i] - 1;
				break;
			case 'L':
				R[i+1] = R[i] + 1;
				L[i+1] = L[i] + 1;
				break;
			default:
				R[i+1] = R[i] - 1;
				L[i+1] = L[i] + 1;
				break;
			}
			rm = min(rm, R[i+1]);
			lm = max(lm, L[i+1]);
		}
		return max(-rm, lm);
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
			string Arg0 = "LLLRLRRR";
			int Arg1 = 3;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "R???L";
			int Arg1 = 4;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "??????";
			int Arg1 = 6;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LL???RRRRRRR???";
			int Arg1 = 11;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "L?L?";
			int Arg1 = 4;

			verify_case(n, Arg1, maxDistance(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftOrRight ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
