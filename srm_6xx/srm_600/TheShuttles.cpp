// BEGIN CUT HERE
/*
SRM 600 Div2 Easy (250)

問題
-N箇所の拠点と、それぞれの社員数が与えられる
-それぞれの拠点について、全員を運べる台数を用意する
-全てのシャトルの座席数は同じである
-シャトル1台のコストはbaseCost＋seatCost×座席数である
-コストの最小値を求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheShuttles {
public:
	int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
		int ans = 99999999;
		for (int s = 1; s <= 100; ++s) {
			int t = 0;
			for (int i = 0; i < (int)cnt.size(); ++i) {
				t += ((cnt[i] + s-1)/s) * (baseCost + seatCost * s);
			}
			ans = min(ans, t);
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
			int Arr0[] = {9};
			int Arg1 = 30;
			int Arg2 = 5;
			int Arg3 = 75;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9, 4};
			int Arg1 = 30;
			int Arg2 = 5;
			int Arg3 = 150;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9, 4};
			int Arg1 = 10;
			int Arg2 = 5;
			int Arg3 = 105;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {51, 1, 77, 14, 17, 10, 80};
			int Arg1 = 32;
			int Arg2 = 40;
			int Arg3 = 12096;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheShuttles ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
