// BEGIN CUT HERE
/*
SRM 650 Div2 Easy (250)

問題
-紙に数字を書く
-奇数なら終了、偶数なら数値を書き、半分にして続行
-数AとBからはじめて、共通して書かれる数の個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TaroJiroDividing {
public:
	int getNumber(int A, int B) {
		set<int> a, b;
		while (true) {
			a.insert(A);
			if (A % 2) {
				break;
			}
			A /= 2;
		}
		while (true) {
			if (a.find(B) != a.end()) {
				b.insert(B);
			}
			if (B % 2) {
				break;
			}
			B /= 2;
		}
		return b.size();
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
			int Arg0 = 8;
			int Arg1 = 4;
			int Arg2 = 3;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 7;
			int Arg2 = 0;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 12;
			int Arg1 = 12;
			int Arg2 = 3;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 24;
			int Arg1 = 96;
			int Arg2 = 4;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1000000000;
			int Arg1 = 999999999;
			int Arg2 = 0;

			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TaroJiroDividing ___test;
	___test.run_test(-1);
}
// END CUT HERE
