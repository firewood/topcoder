// BEGIN CUT HERE
/*
SRM 688 Div1 Easy (250)

問題
-括弧だけの文字列が与えられる
-閉じ括弧の対応が正しくなるよう、任意の範囲を反転する
-最大10回反転できるとき、反転する範囲を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ParenthesesDiv1Easy {
public:
	vector <int> correct(string s) {
		vector <int> ans;
		int len = (int)s.length();
		if (len % 2) {
			ans.push_back(-1);	
		} else {
			vector<int> deleted(len);
			int closed_cnt = 0, closed_pos = -1, opened_cnt = 0;
			for (int i = 0; i < len; ++i) {
				if (s[i] == '(') {
					++opened_cnt;
				} else if (opened_cnt) {
					--opened_cnt;
					deleted[i] = 1;
					for (int j = i - 1; j >= 0; --j) {
						if (!deleted[j]) {
							deleted[j] = 1;
							break;
						}
					}
				} else {
					++closed_cnt;
					closed_pos = i;
				}
			}

			if (closed_pos >= 0) {
				ans.push_back(0);
				ans.push_back(closed_pos);
				for (int i = 0; i <= (closed_pos / 2); ++i) {
					swap(deleted[i], deleted[closed_pos - i]);
					char a = s[i] == '(' ? ')' : '(';
					char b = s[closed_pos - i] == '(' ? ')' : '(';
					s[i] = b, s[closed_pos - i] = a;
				}
			}

			int total_cnt = closed_cnt + opened_cnt;
			opened_cnt = 0;
			for (int i = 0; i < len; ++i) {
				if (!deleted[i] && s[i] == '(') {
					++opened_cnt;
					if (opened_cnt > (total_cnt / 2)) {
						ans.push_back(i);
						ans.push_back(len - 1);
						break;
					}
				}
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
		if ((Case == -1) || (Case == n)) {
			string Arg0 = ")(";
			int Arr1[] = { 0, 0, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "))))))((((((";
			int Arr1[] = { 0, 5, 6, 11 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "))()())()";
			int Arr1[] = { -1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)) {
			string Arg0 = ")()(((";
			//			int Arr1[] = {0, 0, 3, 3, 5, 5 };
			int Arr1[] = { 0, 0, 4, 5 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)) {
			string Arg0 = "()";

			vector <int> Arg1;
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arg0 = "))()()()())())))))))))((((((((()()()()()()))(()()())";
			//             ))()()()())()))))))))) ((((((((()()()()()()))(()()())";
			int Arr1[] = { 0, 21, 11, 51 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			string Arg0 = "(()))()))(((((()()))((())(()))((((((((()))))((((((()))))))()(((()(((()(()())())(())())))((((((()))((())))))()(()((()((()))()(()(()(()()))))))(((())()())(())()(((()(((()()()()()())((()(((())((()()))((((()(()()(())))())))))())((()()((((())())(()()())(((()(((((((()()))()()((((())()(((()(()))(()((())))(())))(()))))()((()(()(()()())))))())))))())()))(((()((()()()(((((())))))))(((())((()(()()))((()))))())))))))(()))(()(()(()((()())((()())()())()())((((()((())))))(()((())(()()()))((()()(()))(()((((())()()()()())(()()()))(()())(((()()()))(((()))())()((())(())()(())()()))((((()))()(()))((()()(()(()()()((((())(()())))())))(((()(((((((())((()(((()((((((()(())(((()(())))()((()(((((((())()()()()()())))())))())()))((()()()()((()((()((()()()(()()))()((())(()))()()(((()))((()))((()()()(()()))(((())()((())()()(((())))(()()()())(((())))())((()(()(()))(((((()())))))()(()(()(()((())((()(()()))()()))()(()))(())()))(()(()(())()()()((()(()((())))))())(((()))()))))))()()((())(()())()(((((())(())(()()(()()(())";
			int Arr1[] = { 0, 8, 625, 999 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, correct(Arg0));
		}
		n++;

	}

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ParenthesesDiv1Easy ___test;
	___test.run_test(-1);
}
// END CUT HERE
