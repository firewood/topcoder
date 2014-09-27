// BEGIN CUT HERE
/*
SRM 634 Div1 Easy (250)

問題
-M種類の商品があり、購入総数が配列で与えられる
-N人の顧客がいて、それぞれの種類の商品を最大1個買う
-K種類以上購入した顧客の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class ShoppingSurveyDiv1 {
public:

	int minValue(int N, int K, vector <int> s) {
		int ans;
		for (ans = 0; ans < N; ++ans) {
			int sum = 0;
			for (int x : s) {
				sum += max(0, x - ans);
			}
			if (sum <= (K - 1) * (N - ans)) {
				break;
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
			int Arg0 = 10;
			int Arg1 = 2;
			int Arr2[] = {1, 2, 3};
			int Arg3 = 0;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arg1 = 2;
			int Arr2[] = {1, 2, 3};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 4;
			int Arr2[] = {4, 4, 4, 2};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 20;
			int Arg1 = 3;
			int Arr2[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
			int Arg3 = 10;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			int Arg1 = 2;
			int Arr2[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = {1, 1, 1, 2};
			int Arg3 = 1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 3;
			int Arr2[] = { 3, 3, 3 };
			int Arg3 = 3;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 2;
			int Arr2[] = { 1, 2, 3 };
			int Arg3 = 2;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, minValue(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShoppingSurveyDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
