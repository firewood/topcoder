// BEGIN CUT HERE
/*
SRM 728 Div1 Easy (250)

問題
-N本かの棒がある
-それぞれの棒について、長さが2以上のときは分割操作ができる
-長さがLのとき、Lが偶数ならL/2に、Lが奇数なら(L-1)/2と(L+1)/2に分割できる
-分割したあと、片方だけを残す
-全ての棒を同じ長さにするのに必要なステップ数の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Halving {
	map<int, int> memo[50];
	void gen(int i, int x, int y) {
		if (memo[i].find(x) == memo[i].end() || memo[i][x] > y) {
			memo[i][x] = y;
			if (x >= 2) {
				gen(i, (x + 1) / 2, y + 1);
				gen(i, x / 2, y + 1);
			}
		}
	}
public:
	int minSteps(vector <int> a) {
		int n = (int)a.size();
		for (int i = 0; i < n; ++i) {
			memo[i].clear();
			gen(i, a[i], 0);
		}
		int ans = 1 << 30;
		for (auto kv : memo[0]) {
			int cnt = kv.second;
			for (int i = 1; i < n; ++i) {
				if (memo[i].find(kv.first) == memo[i].end()) {
					cnt = 1 << 30;
					break;
				}
				cnt += memo[i][kv.first];
			}
			ans = min(ans, cnt);
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
			int Arr0[] = {11, 4};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000, 1000000000, 1000000000, 1000000000};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5, 6, 7};
			int Arg1 = 10;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {13, 13, 7, 11, 13, 11};
			int Arg1 = 11;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 4, 7 };
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minSteps(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Halving ___test;
	___test.run_test(-1);
}
// END CUT HERE
