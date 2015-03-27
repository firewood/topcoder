// BEGIN CUT HERE
/*
SRM 653 Div1 Easy (250)

問題
-人々が一列に座っている
-同郷の人が連続して座る
-同郷の人の人数を何人かに聞いた
-残りの人に質問しなくても一意かどうかを求める

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

class CountryGroupHard {

	int N;
	vector<int> x;
	int memo[256];

	int check(int pos) {
		int &r = memo[pos];
		if (r >= 0) {
			return r;
		}
		if (pos >= N) {
			return r = 1;
		}
		int i, j, k;
		for (i = pos; i < N; ++i) {
			if (x[i]) {
				break;
			}
		}
		if (i >= N) {
			return r = N - pos;
		}
		int cnt = 0;
		for (j = max(pos, i - x[i] + 1); j <= i; ++j) {
			int c = 0;
			for (k = j; k < (j + x[i]) && k < N; ++k) {
				c += (x[k] == 0 || x[k] == x[i]);
			}
			if (c == x[i]) {
				int t = check(j + x[i]);
				cnt += t;
				if (t > 0 && j >= (pos + 2)) {
					return 2;
				}
			}
		}
		return r = cnt;
	}

public:
	string solve(vector <int> a) {
		memset(memo, -1, sizeof(memo));
		N = (int)a.size();
		x = a;
		return check(0) == 1 ? "Sufficient" : "Insufficient";
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
			int Arr0[] = {0,2,3,0,0};
			string Arg1 = "Sufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,2,0};
			string Arg1 = "Insufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,3,0,0,3,0};
			string Arg1 = "Sufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,3,3,0,0};
			string Arg1 = "Insufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,0,2,2};
			string Arg1 = "Sufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 3, 3, 3, 5, 5, 5, 5, 5, 0, 2, 1, 0, 4, 4, 4, 1, 4, 0, 4, 4, 2, 0, 3, 3, 3, 4, 4, 4, 4, 2, 2, 0, 2, 3, 3, 3, 5, 5, 5, 0, 5, 2, 2, 5, 5, 5, 5, 5, 0, 4, 0, 0, 2, 2, 4, 4, 4, 4, 1, 5, 5, 5, 5, 5, 2, 2, 5, 5, 5, 0, 5, 0, 0, 0, 4, 4, 4, 0, 4, 4, 4, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 5, 5, 5 };
			string Arg1 = "Insufficient";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;



	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CountryGroupHard ___test;
	___test.run_test(-1);
}
// END CUT HERE
