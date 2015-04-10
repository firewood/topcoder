// BEGIN CUT HERE
/*
SRM 653 Div2 Medium (500)

問題
-N回じゃんけんする
-勝つと1ポイントもらえる
-ちょうどscoreポイント稼ぐ場合の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

#define COMBSZ 2048
#define MOD 1000000007LL

class RockPaperScissorsMagicEasy {
public:
	int count(vector <int> card, int score) {
		LL N = card.size();
		if (score > N) {
			return 0;
		}
		static LL C[COMBSZ][COMBSZ];
		for (LL i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
			for (LL j = 1; j <= i; ++j) {
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
			}
		}
		LL ans = C[N][score];
		LL R = N - score;
		for (LL i = 0; i < R; ++i) {
			ans = (ans * 2) % MOD;
		}
		return (int)ans;
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
			int Arr0[] = {0,1,2};
			int Arg1 = 2;
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2};
			int Arg1 = 0;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,1,0,0};
			int Arg1 = 10;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
			int Arg1 = 7;
			int Arg2 = 286226628;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,0,1,2,2,1,0};
			int Arg1 = 8;
			int Arg2 = 18;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RockPaperScissorsMagicEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
