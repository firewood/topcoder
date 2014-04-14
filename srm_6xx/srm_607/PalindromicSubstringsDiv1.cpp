// BEGIN CUT HERE
/*
SRM 607 Div1 Easy (250)

問題
-a-zと?からなる文字列が与えられる
-?はa-zのどれかに置換される
-左右対称な部分文字列の個数の期待値を求める

*/
// END CUT HERE
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class PalindromicSubstringsDiv1 {
public:
	double expectedPalindromes(vector <string> S1, vector <string> S2) {
		string S = accumulate(S2.begin(), S2.end(), accumulate(S1.begin(), S1.end(), string()));
		int len = (int)S.length();
		double ans = 0;
		for (int i = 0; i < len; ++i) {
			double p = 1.0;
			for (int j = 0; (i - j) >= 0 && (i + j) < len; ++j) {
				if (j > 0 && (S[i - j] == '?' || S[i + j] == '?')) {
					p *= (1.0 / 26.0);
				}
				else if (S[i - j] != S[i + j]) {
					p = 0;
				}
				ans += p;
			}
			p = 1.0;
			for (int j = 0; (i - j) >= 0 && (i + j + 1) < len; ++j) {
				if (S[i - j] == '?' || S[i + j + 1] == '?') {
					p *= (1.0 / 26.0);
				}
				else if (S[i - j] != S[i + j + 1]) {
					p = 0;
				}
				ans += p;
			}
		}
		return ans;
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
			string Arr0[] = {"a","a",""};
			string Arr1[] = {"a"};
			double Arg2 = 6.0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"z??"};
			// string Arr1[] = {};
			double Arg2 = 3.115384615384615;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab","c"};
			string Arr1[] = {"??","a?"};
			double Arg2 = 7.315088757396449;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			// string Arr0[] = {};
			string Arr1[] = {"?"};
			double Arg2 = 1.0;

			vector <string> Arg0;
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab?def","?"};
			string Arr1[] = {"f??a"};
			double Arg2 = 12.545971779699588;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, expectedPalindromes(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromicSubstringsDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
