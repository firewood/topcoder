// BEGIN CUT HERE
/*
SRM 740 Div2 Medium (500)

問題
-N人でジャンプ競技を行う
-3ラウンドある
-各ラウンドにおいて、直前までのラウンドの成績が悪い順に競技を行う
-成績は最長の飛距離が長い順とし、同じ場合はベストの2番目、3番目で比較する
-それでも同じ成績の場合は、ゼッケンが若い方が良いとする
-飛距離の結果が与えられる
-各競技者の最終順位を求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<vector<int>, int> VII;

class LongJumpCompetition {
public:
	vector <int> recoverStandings(vector <int> jumpLengths) {
		int n = (int)jumpLengths.size() / 3;
		vector<VII> best(n);
		for (int i = 0; i < n; ++i) {
			best[i].second = -i;
		}
		for (int r = 0; r < 3; ++r) {
			for (int i = 0; i < n; ++i) {
				sort(best[i].first.rbegin(), best[i].first.rend());
			}
			sort(best.begin(), best.end());
			for (int i = 0; i < n; ++i) {
				best[i].first.push_back(jumpLengths[r * n + i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			sort(best[i].first.rbegin(), best[i].first.rend());
		}
		sort(best.rbegin(), best.rend());
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = -best[i].second;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {847, 833, 829};
			int Arr1[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 120, 110, 130, 120, 111, 147, 92, 0};
			int Arr1[] = {0, 2, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int Arr1[] = {0, 1, 2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {850, 840, 841, 850, 850, 837};
			int Arr1[] = {1, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, recoverStandings(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongJumpCompetition ___test;
	___test.run_test(-1);
}
// END CUT HERE
