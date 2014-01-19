// BEGIN CUT HERE
/*
SRM 586 Div2 Hard (1000)

問題
-26文字のどれかからなる文字列Sがある
-ある文字についてのスコアは、最も右のものと最も左のものの出現位置の差の絶対値である
-文字列Sのスコアは、文字のスコアの合計である
-文字列Sの長さLが与えられる
-その長さにおいて最小のスコアの文字列が何通りあるかを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

#define MOD 1000000009
#define COMBSZ 1024

class StringWeightDiv2 {
public:
	int countMinimums(int L) {
		static int C[COMBSZ][COMBSZ];
		memset(C, 0, sizeof(C));
		int i, j;
		for (i = 0; i < COMBSZ; ++i) {
			C[i][0] = 1;
		}
		for (i = 1; i < COMBSZ; ++i) {
			for (j = 1; j < COMBSZ; ++j) {
				LL x = C[i-1][j-1];
				x += C[i-1][j];
				C[i][j] = (int)(x % MOD);
			}
		}

		LL ans = 1;
		if (L > 26) {
			for (i = 1; i <= 26; ++i) {
				ans *= i;
				ans %= MOD;
			}
			ans *= C[L - 1][25];
			ans = ans % MOD;
		} else {
			j = 26;
			for (i = 0; i < L; ++i) {
				ans *= j;
				ans %= MOD;
				--j;
			}
		}
		return (int)(ans % MOD);
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
			int Arg0 = 1;
			int Arg1 = 26;

			verify_case(n, Arg1, countMinimums(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 650;

			verify_case(n, Arg1, countMinimums(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arg1 = 488801539;

			verify_case(n, Arg1, countMinimums(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringWeightDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
