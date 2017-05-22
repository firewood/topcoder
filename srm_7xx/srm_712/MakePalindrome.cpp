// BEGIN CUT HERE
/*
SRM 712 Div2 Medium (500)

問題
-英小文字が1つだけ書かれたカードが何枚かある
-反転しても同じ文字列になるようにカードをつなげる
-カードの組が最小になるように構築する

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MakePalindrome {
public:
	vector <string> constructMinimal(string card) {
		int cnt[256] = {};
		for (char c : card) {
			cnt[c] += 1;
		}
		vector <string> ans;
		int used = 0;
		while (used != card.length()) {
			string s;
			for (char c = 'a'; c <= 'z'; ++c) {
				if (cnt[c] % 2) {
					s = string(cnt[c], c);
					used += cnt[c];
					cnt[c] = 0;
					break;
				}
			}
			for (char c = 'a'; c <= 'z'; ++c) {
				if (cnt[c] && (cnt[c] % 2) == 0) {
					s = string(cnt[c] / 2, c) + s + string(cnt[c] / 2, c);
					used += cnt[c];
					cnt[c] = 0;
				}
			}
			ans.push_back(s);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abbaa";
			string Arr1[] = {"ababa" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, constructMinimal(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abc";
			string Arr1[] = {"a", "b", "c" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, constructMinimal(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaabbbccc";
			string Arr1[] = {"aba", "bcb", "cac" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, constructMinimal(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "topcoder";
			string Arr1[] = {"oco", "d", "e", "p", "r", "t" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, constructMinimal(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "z";
			string Arr1[] = {"z" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, constructMinimal(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MakePalindrome ___test;
	___test.run_test(-1);
}
// END CUT HERE
