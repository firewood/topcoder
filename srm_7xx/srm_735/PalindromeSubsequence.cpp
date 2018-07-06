// BEGIN CUT HERE
/*
SRM 735 Div1 Easy (250)

問題
-文字列Sが与えられる
-文字列Sの各文字を、1個1回ずつ使い、いくつかの部分文字列に分割する
-全ての部分文字列が左右対称になるようにする
-部分文字列の個数を最小化するとき、各文字を何番目の文字列に割り当てるかを求めよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PalindromeSubsequence {
public:
	vector <int> optimalPartition(string s) {
		int n = (int)s.length();
		vector <int> ans(n, 1);
		string r = s;
		reverse(r.begin(), r.end());
		if (r != s) {
			for (int i = 0; i < n; ++i) {
				ans[i] = s[i] - 'a' + 1;
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
			string Arg0 = "bababba";
			int Arr1[] = {1, 2, 2, 1, 2, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abba";
			int Arr1[] = {1, 1, 1, 1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "b";
			int Arr1[] = {1 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "babb";
			int Arr1[] = {1, 1, 1, 2 };

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, optimalPartition(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PalindromeSubsequence ___test;
	___test.run_test(-1);
}
// END CUT HERE
