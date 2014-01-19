// BEGIN CUT HERE
/*
// SRM 512 Div2 Hard (1024)

問題
AshとElshがダブルじゃんけんをする。
ダブルじゃんけんでは右手と左手の両方でじゃんけんをする。
右手も左手も勝った場合は2点、右手が勝って左手があいこなら1点、その他は0点である。
順不同でAshとElshの手が与えられるとき、手を並べ替えて、Ashの最高得点を求める。

*/
// END CUT HERE
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class DoubleRoshambo {

public:
	int maxScore(vector <string> A, vector <string> E) {
		int result = 0;

		char win[128];
		win['R'] = 'S', win['P'] = 'R', win['S'] = 'P';

		int x[64] = {}, y[64] = {};

		int i, j;
		for (i = 0; i < (int)A.size(); ++i) {
			for (j = 0; j < (int)E.size(); ++j) {
				if (!y[j] && win[A[i][1]] == E[j][1] && win[A[i][0]] == E[j][0]) {
					x[i] = 1;
					y[j] = 1;
					result += 2;
					break;
				}
			}
		}

		for (i = 0; i < (int)A.size(); ++i) {
			if (!x[i]) {
				for (j = 0; j < (int)E.size(); ++j) {
					if (!y[j] && win[A[i][1]] == E[j][1] && A[i][0] == E[j][0]) {
						y[j] = 1;
						result += 1;
						break;
					}
				}
			}
		}

		return result;
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
			string Arr0[] = {"RR"};
			string Arr1[] = {"SS"};
			int Arg2 = 2;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"SR", "PP"};
			string Arr1[] = {"PR", "RS"};
			int Arg2 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PP", "PP", "PP", "PP"};
			string Arr1[] = {"RR", "PR", "SS", "SP"};
			int Arg2 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"PS", "RS", "PP", "SP", "RR", "SS", "SP"};
			string Arr1[] = {"RP", "SP", "RR", "SR", "RS", "SP", "SS"};
			int Arg2 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxScore(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DoubleRoshambo ___test;
	___test.run_test(0);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
