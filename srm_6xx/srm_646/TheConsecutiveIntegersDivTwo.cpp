// BEGIN CUT HERE
/*
SRM 646 Div2 Easy (250)

問題
-いくつかの数が与えられる
-任意の数を+1または-1して、1または2個の連続した数を作る
-最小の操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheConsecutiveIntegersDivTwo {
public:
	int find(vector <int> numbers, int k) {
		int ans = 0;
		if (k > 1) {
			ans = 1 << 30;
			sort(numbers.begin(), numbers.end());
			int N = (int)numbers.size();
			for (int i = 0; i < N - 1; ++i) {
				ans = min(ans, abs(numbers[i + 1] - numbers[i]) - 1);
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
			int Arr0[] = {4, 47, 7};
			int Arg1 = 2;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 100};
			int Arg1 = 1;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-96, -53, 82, -24, 6, -75};
			int Arg1 = 2;
			int Arg2 = 20;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {64, -31, -56};
			int Arg1 = 2;
			int Arg2 = 24;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheConsecutiveIntegersDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
