// BEGIN CUT HERE
/*
SRM 643 Div2 Easy (250)

問題
-R×C人の戦士がいる
-戦士の状態はhappyまたはsadである
-隣り合う戦士の状態がhappyのとき、その2人に隣り合う戦士もhappyとなる
-戦士の状態が与えられる
-王が褒美を与えるとsadの戦士もhappyにできる
-全員がhappyとなるために必要な褒美の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheKingsArmyDiv2 {
public:
	int getNumber(vector <string> state) {
		int H = (int)state.size(), W = (int)state[0].length();
		int ans = 2;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (state[i][j] == 'H') {
					ans = 1;
					if (j > 0 && state[i][j - 1] == 'H') {
						return 0;
					}
					if (i > 0 && state[i - 1][j] == 'H') {
						return 0;
					}
				}
			}
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
			string Arr0[] = {"SSSSS",
 "SSHHS",
 "SSSSS"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"SSSSS",
 "SSHSH",
 "HSSSS"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"SSS",
 "SSS",
 "SSS"};
			int Arg1 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HSHSHSH", "SSSHSSS", "SSHSHSS", "SHSHSHS"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"HHSH", "HHHS", "HSSS", "SHSH", "HHHS", "HSHH", "SSSH"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getNumber(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheKingsArmyDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
