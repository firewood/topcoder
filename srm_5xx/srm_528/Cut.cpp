// BEGIN CUT HERE
/*
// SRM 528 Div1 Easy (250)

問題

Fox Cielは年末の記念に蒲焼を食べることにした。
長さ10にカットされたうなぎだけを蒲焼にすることができる。
maxCuts回だけカットできるとき、蒲焼の最大数を求める。

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Cut {

public:
	int getMaximum(vector <int> eelLengths, int maxCuts) {
		int res = 0;
		sort(eelLengths.begin(), eelLengths.end());
		int i, j, k, l;
		for (i = 0; i < (int)eelLengths.size(); ++i) {
			j = eelLengths[i];
			if (j % 10) {
				continue;
			}
			k = j/10 -1;	// カットが必要な回数
			l = min(k, maxCuts);
			res += l;
			maxCuts -= l;
			res += (k == l);		// 残りの長さが10のとき
		}
		for (i = 0; i < (int)eelLengths.size(); ++i) {
			j = eelLengths[i];
			if ((j % 10) == 0) {
				continue;
			}
			l = min(j/10, maxCuts);
			res += l;
			maxCuts -= l;
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
			int Arr0[] = {13, 20, 13};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 5, 5, 5};
			int Arg1 = 2;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {34, 10, 48};
			int Arg1 = 4;
			int Arg2 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMaximum(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30, 50, 30, 50};
			int Arg1 = 350;
			int Arg2 = 16;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getMaximum(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Cut ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
