// BEGIN CUT HERE
/*
SRM 470 Div1 Easy (250)

問題
-N+1個のドアがある
-2人のプレーヤーが1ターンずつ交互にドアを開ける
-ひとつだけゴールの部屋が与えられる
-最初のプレーヤーは左端、もう片方のプレーヤーは右端から、ゴールの部屋まで全てのドアが開いていれば勝利
-各ドアには色がついている
-各ターンで色を指定すると、その色のドアが全て開く
-各プレーヤーは次のような戦略をとる
  - 相手が何をしても自分が勝つような色がある場合、それを指定する
  - そのような色が複数ある場合、総選択回数が最小になるように選択する
  - そのような色がなく、ドローになる色が存在する場合、その色を選択する
  - それ以外の場合、総選択回数が最大となるように選択する
-両者が最適な行動を取るとき、総選択回数Xを求める
-0ならドロー
-Xターンで先手が勝つならX
-Xターンで後手が勝つなら-X

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class DoorsGame {
public:
	int determineOutcome(string doors, int trophy) {
		int a = 0, b = 0;
		for (int i = 0; i < trophy; ++i) {
			a |= (1 << (doors[i] - 'A'));
		}
		for (int i = trophy; i < (int)doors.size(); ++i) {
			b |= (1 << (doors[i] - 'A'));
		}
		int c = popcount(a), d = popcount(b), e = popcount(a&b);
		if (c + e > d && d + e >= c) {
			return 0;
		}
		if (d < c) {
			return -2 * d;
		}
		return 2 * c - 1;
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
			string Arg0 = "ABCD";
			int Arg1 = 2;
			int Arg2 = 3;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCC";
			int Arg1 = 2;
			int Arg2 = -2;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABABAB";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABAPDCAA";
			int Arg1 = 5;
			int Arg2 = -4;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "MOCFDCE";
			int Arg1 = 3;
			int Arg2 = 5;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCCDE";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCCD";
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCB";
			int Arg1 = 2;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "BCABA";  //c-b-a
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arg0 = "ABCBA";  //c-b-a
			int Arg1 = 3;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "EBFDCAE";
			int Arg1 = 4;
			int Arg2 = 0;

			verify_case(n, Arg2, determineOutcome(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoorsGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
