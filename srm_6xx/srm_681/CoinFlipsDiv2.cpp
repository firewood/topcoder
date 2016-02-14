// BEGIN CUT HERE
/*
SRM 681 Div2 Easy (250)

問題
-N枚のコインが左右に並んでいて、裏か表の状態が与えられる
-左か右の隣のコインの状態と異なるコインの枚数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CoinFlipsDiv2 {
public:
	int countCoins(string state) {
		string s = state.front() + state + state.back();
		int ans = 0;
		for (int i = 1; i != s.length() - 1; ++i) {
			ans += s[i - 1] != s[i] || s[i] != s[i + 1];
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
			string Arg0 = "HT";
			int Arg1 = 2;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "T";
			int Arg1 = 0;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HHH";
			int Arg1 = 0;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HHTHHH";
			int Arg1 = 3;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "HHHTTTHHHTTTHTHTH";
			int Arg1 = 12;

			verify_case(n, Arg1, countCoins(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CoinFlipsDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
