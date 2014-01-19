// BEGIN CUT HERE
/*
// SRM 515 Div2 Hard (1000)

問題
アイテムショップに商品が1つだけある。
客が2人いて、それぞれの客は一日に一回だけ来る。
それぞれの客が来る時刻、購入価格、確率が与えられる。
アイテムショップの最大の利益を求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NewItemShopTwo {

public:
	double getMaximum(vector <string> customers) {
		int index[25];
		double price[25] = {};
		double probability[25] = {};
		memset(index, -1, sizeof(index));
		int i, h;
		for (i = 0; i < 2; ++i) {
			double r = 100.0;
			stringstream ss(customers[i]);
			while (true) {
				h = -1;
				int a, b;
				char c;
				ss >> h >> c >> a >> c >> b;
				if (h < 0 || h >= 24) break;
				index[h] = i;
				price[h] = a;
				probability[h] = b / r;
				r -= b;
			}
		}

		double earn[25][2] = {};
		for (h = 24-1; h >= 0; --h) {
			for (i = 0; i < 2; ++i) {
				earn[h][i] = earn[h+1][i];
				if (index[h] == i) {
					earn[h][i] = price[h] * probability[h] + (1.0 - probability[h]) * earn[h+1][i];
				}
			}
		}
		double dp[25] = {};
		for (h = 24-1; h >= 0; --h) {
			dp[h] = dp[h+1];
			for (i = 0; i < 2; ++i) {
				if (index[h] == i) {
					dp[h] = probability[h] * max(price[h], earn[h][i^1]) + (1.0 - probability[h]) * dp[h+1];
				}
			}
		}
		return dp[0];
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "8,1,80 16,100,11", "12,10,100" };
			double Arg1 = 19.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "8,1,80 16,100,11", "12,10,90 13,30,5" };
			double Arg1 = 19.4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" };
			double Arg1 = 90.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" };
			double Arg1 = 95.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }
;
			double Arg1 = 3.0692999999999997;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMaximum(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NewItemShopTwo ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
