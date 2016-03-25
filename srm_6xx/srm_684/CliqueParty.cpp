// BEGIN CUT HERE
/*
SRM 684 Div1 Easy (250)

問題
-数値の集合Sが与えられる
-任意の要素A,Bが常にA <= k×Bを満たすとき、良い集合とする
-Sの部分集合Xの任意の要素A,Bの差|A-B|からなる集合をDとする
-Dが良い集合となるXの要素数の最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class CliqueParty {
public:
	int maxsize(vector <int> a, int K) {
		int ans = 0;
		sort(a.begin(), a.end());
		int N = (int)a.size();
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				int mx = a[j] - a[i];
				int mn = (mx + K - 1) / K;
				set<int> s;
				s.insert(a[i]);
				s.insert(a[j]);
				for (int k = i + 1; k < j; ++k) {
					int nk = mx;
					for (int x : s) {
						nk = min(nk, abs(x - a[k]));
					}
					if (nk >= mn) {
						s.insert(a[k]);
					}
				}
				ans = max(ans, (int)s.size());
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
			int Arr0[] = {1,2,3};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,10,5,6};
			int Arg1 = 2;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6};
			int Arg1 = 3;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,9,25,24,23,30};
			int Arg1 = 7;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 };
			int Arg1 = 25;
			int Arg2 = 26;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxsize(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CliqueParty ___test;
	___test.run_test(-1);
}
// END CUT HERE
