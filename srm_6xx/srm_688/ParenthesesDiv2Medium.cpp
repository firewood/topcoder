// BEGIN CUT HERE
/*
SRM 688 Div2 Medium (500)

問題
-括弧だけでできた、長さNの文字列が与えられる
-閉じ括弧の対応が正しくなるよう、任意の位置の文字を反転する
-最大(N/2)+1回反転できるとき、反転する位置を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ParenthesesDiv2Medium {
public:
	vector <int> correct(string s) {
		vector <int> ans;
		int cnt = 0;
		for (int i = 0; i != s.length(); ++i) {
			int r = (int)s.length() - i;
			if (s[i] == '(') {
				if (cnt >= r) {
					ans.push_back(i);
					--cnt;
				} else {
					++cnt;
				}
			} else if (cnt <= 0) {
				++cnt;
				ans.push_back(i);
			} else {
				--cnt;
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = ")(";
			int Arr1[] = {0, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = ")))))(((((";
			int Arr1[] = {0, 2, 4, 5, 7, 9 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((()";
			int Arr1[] = {1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = ")))(()(())))))";
			int Arr1[] = {0, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()()()()()()()()()()()()()";

			vector <int> Arg1;
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv2Medium ___test;
	___test.run_test(-1);
}
// END CUT HERE
