// BEGIN CUT HERE
/*
SRM 749 Div2 Easy (250)

問題
- モンスターと戦っている
- 基本攻撃力はattackである
- 1回攻撃するたびに、攻撃力が基本攻撃力のlevelパーセント上がる
- duration回攻撃するとき、合計の攻撃力を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FightMonsterDiv2 {
public:
	long long damageDealt(long long attack, long long level, long long duration) {
		return attack * duration + ((duration - 1) * duration) / 2 * (attack * level / 100);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 10LL;
			long long Arg2 = 3LL;
			long long Arg3 = 330LL;

			verify_case(n, Arg3, damageDealt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100LL;
			long long Arg1 = 0LL;
			long long Arg2 = 5LL;
			long long Arg3 = 500LL;

			verify_case(n, Arg3, damageDealt(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 100000LL;
			long long Arg1 = 100LL;
			long long Arg2 = 100000LL;
			long long Arg3 = 500005000000000LL;

			verify_case(n, Arg3, damageDealt(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FightMonsterDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
