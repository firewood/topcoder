// BEGIN CUT HERE
/*
// SRM 530 Div2 Easy (250)

問題

N本のビンがあり、それぞれT[x]個のボールが入っている。
Tは昇順にソートされている。
T[x]の順番をシャッフルしたものをS[x]として、
ビンからビンへコスト1でボールを1個移動できる。
状態Sから状態Tへの移動量が最大となるSを求める。

*/
// END CUT HERE
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef vector<string> StrVec;

class GogoXBallsAndBinsEasy {

public:
	int solve(vector <int> T) {
		sort(T.begin(), T.end());
		int res = 0;
		int i, j = T.size() - 1;
		for (i = 0; i < j; ++i, --j) {
			res += T[j] - T[i];
		}
		return res;
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
			int Arr0[] = {0, 2, 5};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 6, 7, 8};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 1, 2, 10};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8};
			int Arg1 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, solve(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GogoXBallsAndBinsEasy ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
