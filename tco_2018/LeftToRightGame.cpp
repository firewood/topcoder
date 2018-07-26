// BEGIN CUT HERE
/*
TCO18 R3A Easy (250)

問題
-2人で数を左から1桁ずつlength桁まで書いていくゲームを行う
-length桁になったとき、divisorで割り切れれば後手の勝ち、そうでなければ先手の勝ち
-両者が最適な戦略を取ったときにどちらが勝つか求めよ

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

class LeftToRightGame {
public:
	bool win(int length, int divisor) {
		int st = 1;
		while (length > 4) {
			st = 0;
			length -= 2;
		}
		bool ok = false;
		switch (length) {
		case 1:
		{
			for (int i = st; i <= 9; ++i) {
				if (i % divisor) {
					ok = true;
				}
			}
		}
		break;
		case 2:
		{
			for (int i = st; i < 10; ++i) {
				bool f = false;
				for (int j = 0; j < 10; ++j) {
					int m = i * 10 + j;
					if ((m % divisor) == 0) {
						f = true;
						break;
					}
				}
				if (!f) {
					ok = true;
					break;
				}
			}
		}
		break;
		case 3:
		{
			for (int i = st; i < 10; ++i) {
				int a = 0;
				for (int j = 0; j < 10; ++j) {
					for (int k = 0; k < 10; ++k) {
						int m = i * 100 + j * 10 + k;
						if (m % divisor) {
							++a;
							break;
						}
					}
				}
				if (a >= 10) {
					ok = true;
					break;
				}
			}
		}
		break;
		case 4:
		{
			for (int i = st; i < 10; ++i) {
				int a = 0;
				for (int j = 0; j < 10; ++j) {
					for (int k = 0; k < 10; ++k) {
						int b = 1;
						for (int l = 0; l < 10; ++l) {
							int m = i * 1000 + j * 100 + k * 10 + l;
							if ((m % divisor) == 0) {
								b = 0;
								break;
							}
						}
						if (b) {
							++a;
							break;
						}
					}
				}
				if (a >= 10) {
					ok = true;
					break;
				}
			}
		}
		break;
		}
		return ok;
	}

	string whoWins(int length, int divisor) {
		return win(length, divisor) ? "Alice" : "Bob";
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
			int Arg0 = 4;
			int Arg1 = 10;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 1000;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 147;
			int Arg1 = 47;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;




		if ((Case == -1) || (Case == n)) {
			int Arg0 = 1;
			int Arg1 = 1000;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 12;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 11;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 3;
			int Arg1 = 1;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 2;
			int Arg1 = 11;
			string Arg2 = "Bob";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 4;
			int Arg1 = 12;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 6;
			int Arg1 = 12;
			string Arg2 = "Alice";

			verify_case(n, Arg2, whoWins(Arg0, Arg1));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LeftToRightGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
