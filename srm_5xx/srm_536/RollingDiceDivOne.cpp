// BEGIN CUT HERE
/*
// SRM 536 Div1 Medium (500)

問題
N個のサイコロがある。
それぞれのサイコロの面は1からk=dice[i]までの番号が振られていて、出目の確率は等しい。
最も出やすい出目の合計値を求める。複数ある場合は最小値。

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class RollingDiceDivOne {

public:
	long long mostLikely(vector <int> dice) {
		size_t N = dice.size();
		sort(dice.begin(), dice.end());
		LL a = accumulate(dice.begin(), dice.begin() + N - 1, 0LL);
		LL b = a + dice.back() + N;
		return min(a + 1, b / 2);
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
			int Arr0[] = {6, 6, 8};
			long long Arg1 = 11LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			long long Arg1 = 1LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 3, 4, 5};
			long long Arg1 = 9LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 10, 1};
			long long Arg1 = 3LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {382828264, 942663792, 291832707, 887961277, 546603677, 545185615, 146267547, 6938117, 167567032, 84232402,
700781193, 452172304, 816532384, 951089120, 448136091, 280899512, 256093435, 39595226, 631504901, 154772240};
			long long Arg1 = 4366828428LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, mostLikely(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RollingDiceDivOne ___test;
//	___test.run_test(6);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
