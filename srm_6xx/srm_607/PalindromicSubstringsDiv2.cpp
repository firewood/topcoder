// BEGIN CUT HERE
/*
SRM 607 Div2 Medium (500)

問題
-a-zからなる文字列が与えられる
-部分文字列が左右対称になる個数を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PalindromicSubstringsDiv2 {
public:
	int count(vector <string> S1, vector <string> S2) {
		string S = accumulate(S2.begin(), S2.end(), accumulate(S1.begin(), S1.end(), string()));
		int len = (int)S.length();
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			for (int j = 0; (i - j) >= 0 && (i + j) < len; ++j) {
				if (S[i - j] != S[i + j]) {
					break;
				}
				++ans;
			}
			for (int j = 0; (i - j) >= 0 && (i + j + 1) < len; ++j) {
				if (S[i - j] != S[i + j + 1]) {
					break;
				}
				++ans;
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
			string Arr0[] = {"a","a",""};
			string Arr1[] = {"a"};
			int Arg2 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"zaz"};
			// string Arr1[] = {};
			int Arg2 = 4;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"top"};
			string Arr1[] = {"coder"};
			int Arg2 = 8;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			// string Arr0[] = {};
			string Arr1[] = {"daata"};
			int Arg2 = 7;

			vector <string> Arg0;
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromicSubstringsDiv2 ___test;
	___test.run_test(-1);

}
// END CUT HERE
