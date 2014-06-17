// BEGIN CUT HERE
/*
SRM 562 Div2 Easy (250)

問題
-きゅうりが大好き
-ランダムでK本買う
-どういう選び方でも買えるかどうか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class CucumberMarket {

public:
	string check(vector <int> price, int budget, int k) {
		sort(price.rbegin(), price.rend());
		int i;
		for (i = 0; i < k; ++i) {
			budget -= price[i];
			if (budget < 0) {
				return "NO";
			}
		}
		return "YES";
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,1,10,100};
			int Arg1 = 1110;
			int Arg2 = 3;
			string Arg3 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,1,10,100};
			int Arg1 = 1109;
			int Arg2 = 3;
			string Arg3 = "NO";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {33,4};
			int Arg1 = 33;
			int Arg2 = 1;
			string Arg3 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arg1 = 2;
			int Arg2 = 4;
			string Arg3 = "NO";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
			int Arg1 = 10000;
			int Arg2 = 9;
			string Arg3 = "YES";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, check(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CucumberMarket ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
