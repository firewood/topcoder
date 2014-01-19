// BEGIN CUT HERE
/*
SRM 592 Div2 Easy (250)

問題
-何冊かの本があり、ページ数が配列で与えられる
-N冊選んで読む
-読んだページ数の合計が2番目に少ないようにしたい
-何ページ読むことになるか求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class LittleElephantAndBooks {
public:
	int getNumber(vector <int> pages, int number) {
		sort(pages.begin(), pages.end());
		int sum = accumulate(pages.begin(), pages.begin() + number + 1, 0);
		return min(sum - pages[0], sum - pages[number-1]);
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
			int Arr0[] = {1, 2};
			int Arg1 = 1;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {74, 7, 4, 47, 44};
			int Arg1 = 3;
			int Arg2 = 58;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 1, 9, 7, 2, 8, 6, 4, 5};
			int Arg1 = 7;
			int Arg2 = 29;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {74, 86, 32, 13, 100, 67, 77};
			int Arg1 = 2;
			int Arg2 = 80;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, getNumber(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LittleElephantAndBooks ___test;
	___test.run_test(-1);
}
// END CUT HERE
