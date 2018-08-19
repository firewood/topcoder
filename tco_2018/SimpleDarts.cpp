// BEGIN CUT HERE
/*
TCC India 2018 Qualification Round Easy (250)

問題
-ダーツの区間がF個ある
-通常のマトは1,2,3,...F点である
-2倍のマトは2,4,6,...2×F点である
-3倍のマトは3,6,9,...3×F点である
-中心部には25点と50点のエリアがある
-3回投げて全て違う場所に当たった時の合計の最大値を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class SimpleDarts {
public:
	int highestScore(int F) {
		int a[] = { 25, 50, F * 3, (F - 1) * 3, (F - 2) * 3 };
		sort(a, a + 5);
		return a[2] + a[3] + a[4];
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
			int Arg0 = 20;
			int Arg1 = 171;

			verify_case(n, Arg1, highestScore(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 78;

			verify_case(n, Arg1, highestScore(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			int Arg1 = 102;

			verify_case(n, Arg1, highestScore(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SimpleDarts ___test;
	___test.run_test(-1);
}
// END CUT HERE
