// BEGIN CUT HERE
/*
SRM 646 Div1 Easy (250)

問題
-いくつかの数が与えられる
-任意の数を+1または-1して、k個の連続した数を作る
-最小の操作回数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheConsecutiveIntegersDivOne {
public:
	int find(vector <int> numbers, int k) {
		int ans = 1 << 30;
		int N = (int)numbers.size();
		int m = k / 2;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i <= N - k; ++i) {
			int sum = 0;
			for (int j = 0; j < k; ++j) {
				sum += abs(numbers[i + m] + j - m - numbers[i + j]);
			}
			ans = min(ans, sum);
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
			int Arr0[] = {4, 7, 47};
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

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-96, -53, 82, -24, 6, -75};
			int Arg1 = 4;
			int Arg2 = 90;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { -4845232, -5077278, -1696332, 9685053, -8008906, -2041580, -2825611, 7330935, -1994531, -5206896, -202206, -1506777, 8005773 };
			int Arg1 = 9;
			int Arg2 = 12555151;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheConsecutiveIntegersDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
