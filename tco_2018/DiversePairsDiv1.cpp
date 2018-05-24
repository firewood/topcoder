// BEGIN CUT HERE
/*
TCO18 Fun Round Poland Medium (500)

問題
-a以上b以下の数値の配列がある
-その中から2つの数を取り出してペアを作る
-各ペアは以下の条件を満たすこと
  -使用する全ての数値が異なっていること
  -ペアの合計値がa+b未満であること
  -ペアの合計値がユニークであること
-ペアが最大何個作れるかを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DiversePairsDiv1 {
	vector <int> t(int a, int b, int s) {
		vector <int> ans;
		set<int> up;
		set<int> us;
		for (int i = s; i < b; ++i) {
			if (up.find(i) != up.end()) {
				continue;
			}
			for (int j = b; j >= a; --j) {
				if (i == j || i + j >= a + b || up.find(j) != up.end()) {
					continue;
				}
				int y = i + j;
				if (us.find(y) == us.end()) {
					ans.push_back(i);
					ans.push_back(j);
					up.insert(i);
					up.insert(j);
					us.insert(y);
					break;
				}
			}
		}
		return ans;
	}

public:
	vector <int> findMaxDiversePairs(int a, int b) {
		vector <int> ans;
		int n = a + max(0, (b - a) / 5 - 1);
		int m = min(b, a + (b - a) / 5 + 1);
		for (int s = n; s <= m; s += 1) {
			vector <int> r = t(a, b, s);
			if (r.size() > ans.size()) {
				ans = r;
			}
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
			int Arg0 = 1;
			int Arg1 = 1;
//			int Arr2[] = { };

			vector <int> Arg2;
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 2;
//			int Arr2[] = { };

			vector <int> Arg2;
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 4;
			int Arr2[] = {2, 3 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 9;
			int Arr2[] = {5, 6 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			int Arg1 = 21;
			int Arr2[] = {15, 20, 16, 18 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 27;
			int Arr2[] = {21, 25, 22, 23, 20, 24 };

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxDiversePairs(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DiversePairsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
