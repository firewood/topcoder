// BEGIN CUT HERE
/*
SRM 590 Div1 Easy (250)

問題
-横一列に右向きまたは左向きのポーンが配置されている
-beginからtargetの状態に遷移可能かどうかを求める

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

using namespace std;

typedef long long LL;

class FoxAndChess {

	bool solve(string begin, string target) {
		int N = (int)begin.length();
		int i, j = 0;
		for (i = 0; i < N; ++i) {
			if (begin[i] == '.') {
				continue;
			}
			while (target[j] == '.') {
				++j;
				if (j >= N) {
					return false;
				}
			}
			if (begin[i] != target[j]) {
				return false;
			}
			if (begin[i] == 'R') {
				if (j < i) {
					return false;
				}
			} else {
				if (j > i) {
					return false;
				}
			}
			++j;
		}
		while (j < N) {
			if (target[j] != '.') {
				return false;
			}
			++j;
		}
		return true;
	}

public:
	string ableToMove(string begin, string target) {
		return solve(begin, target) ? "Possible" : "Impossible";
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
			string Arg0 = "R...";
			string Arg1 = "..R.";
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "..R.";
			string Arg1 = "R...";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".L.R.R.";
			string Arg1 = "L...R.R";
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ".L.R.";
			string Arg1 = ".R.L.";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "LRLLRLRLLRLLRLRLRL";
			string Arg1 = "LRLLRLRLLRLLRLRLRL";
			string Arg2 = "Possible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "L";
			string Arg1 = ".";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, ableToMove(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndChess ___test;
	___test.run_test(-1);
}
// END CUT HERE
