// BEGIN CUT HERE
/*
SRM 598 Div2 Medium (500)

問題
-制限重量が300の容器がいくつかある
-重さ101以上300以下の品物がいくつか与えられる
-必要な容器の最小の個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class BinPackingEasy {
public:
	int minBins(vector <int> item) {
		int ans = 0;
		sort(item.begin(), item.end());
		int used[64] = {};
		for (int i = 0; i < (int)item.size(); ++i) {
			if (!used[i]) {
				++ans;
				for (int j = (int)item.size() - 1; j > i; --j) {
					if (!used[j] && (item[i] + item[j]) <= 300) {
						used[j] = 1;
						break;
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
			int Arr0[] = {150, 150, 150, 150, 150};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {130, 140, 150, 160};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {101, 101, 101, 101, 101, 101, 101, 101, 101};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {101, 200, 101, 101, 101, 101, 200, 101, 200};
			int Arg1 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
			int Arg1 = 8;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minBins(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BinPackingEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
