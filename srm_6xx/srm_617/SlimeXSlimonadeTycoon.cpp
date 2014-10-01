// BEGIN CUT HERE
/*
SRM 617 Div2 Medium (500)

問題
-毎朝morning[i]の飲み物が生産でき、最大customers[i]まで販売できる
-stale_limit前に生産した飲み物は腐る
-販売可能な最大量を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SlimeXSlimonadeTycoon {
public:
	int sell(vector <int> morning, vector <int> customers, int stale_limit) {
		int ans = 0;
		int N = (int)morning.size();
		for (int i = 0; i < N; ++i) {
			if (i >= stale_limit) {
				morning[i - stale_limit] = 0;
			}
			for (int j = 0; j <= i; ++j) {
				int x = min(customers[i], morning[j]);
				ans += x;
				morning[j] -= x;
				customers[i] -= x;
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
			int Arr0[] = {5, 1, 1};
			int Arr1[] = {1, 2, 3};
			int Arg2 = 2;
			int Arg3 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 20, 30};
			int Arr1[] = {30, 20, 10};
			int Arg2 = 1;
			int Arg3 = 40;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 2, 3, 4, 5};
			int Arr1[] = {5, 5, 5, 5, 5};
			int Arg2 = 5;
			int Arg3 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000, 0, 0, 0, 0, 0, 0};
			int Arr1[] = {1, 2, 4, 8, 16, 32, 64};
			int Arg2 = 4;
			int Arg3 = 15;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 6698, 5233, 7329, 6261, 7772, 783, 9346, 4110, 5752, 628, 2011, 9620, 9873 };
			int Arr1[] = { 7551, 2566, 8205, 211, 5336, 1247, 5179, 1726, 7114, 8888, 5603, 2993, 9004 };
			int Arg2 = 10;
			int Arg3 = 64770;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, sell(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SlimeXSlimonadeTycoon ___test;
	___test.run_test(-1);
}
// END CUT HERE
