// BEGIN CUT HERE
/*
SRM 592 Div1 Easy (250)

問題
-RGB三種類のボールがある
-テーブルに1つずつ置いていく
-ボールを置いたとき、置いたボールの左側の色の数と、右側の色の数が得点になる
-得点の最大値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LittleElephantAndBalls {
public:
	int getNumber(string S) {
		int ans = 0;
		int cnt[256] = {};
		for (int i = 0; i < (int)S.length(); ++i) {
			ans += min(2, cnt['R']) + min(2, cnt['G']) + min(2, cnt['B']);
			cnt[S[i]] += 1;
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
			string Arg0 = "RGB";
			int Arg1 = 3;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RGGRBBB";
			int Arg1 = 21;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRGBRR";
			int Arg1 = 16;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "RRRR";
			int Arg1 = 5;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "GGRRRGR";
			int Arg1 = 18;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "G";
			int Arg1 = 0;

			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndBalls ___test;
	___test.run_test(-1);
}
// END CUT HERE
