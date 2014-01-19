// BEGIN CUT HERE
/*
SRM 591 Div1 Easy (275)

問題
-ある頂点Xを始点とする木がある
-Xからの距離ごとの頂点の数が与えられる
-制約条件を満たす木のうち、任意の頂点の距離の最大値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheTree {
public:
	int maximumDiameter(vector <int> cnt) {
		int h = (int)cnt.size();
		int ans = 0;
		int i, j;
		for (i = 0; i < h; ++i) {
			int sum = h-i;
			for (j = i; j < h; ++j) {
				if (cnt[j] <= 1) {
					break;
				}
				++sum;
			}
			ans = max(ans, sum);
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
			int Arr0[] = {3};
			int Arg1 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 1, 2, 4};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
			int Arg1 = 21;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximumDiameter(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTree ___test;
	___test.run_test(-1);
}
// END CUT HERE
