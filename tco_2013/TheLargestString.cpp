// BEGIN CUT HERE

/*
TCO 2013 Round 2A Easy (300)

問題
-2つの文字列sとtが与えられる
-sとt両方の同じ位置の文字を消去できる
-sとtを連結したもののうち辞書順最大のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheLargestString {

public:
	string find(string s, string t) {
		string ans;
		int sz = (int)s.length();
		pair<string, string> dp[51][51];
		int i, j, k;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j <= i; ++j) {
				string c = dp[j+1][i+1].first + dp[j+1][i+1].second;
				for (k = 0; k <= i; ++k) {
					string a = dp[j][k].first + s[i];
					string b = dp[j][k].second + t[i];
					if ((a + b) > c) {
						c = a + b;
						dp[j+1][i+1].first = a;
						dp[j+1][i+1].second = b;
					}
				}
				ans = max(ans, c);
			}
		}
		return ans;
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
			string Arg0 = "ab";
			string Arg1 = "zy";
			string Arg2 = "by";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			string Arg1 = "zzzaaaa";
			string Arg2 = "cbaaaa";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "x";
			string Arg1 = "x";
			string Arg2 = "xx";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abbabbabbababaaaabbababab";
			string Arg1 = "bababbaabbbababbbbababaab";
			string Arg2 = "bbbbbbbbbbbbbbbbbbaaab";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;


		// test_case 20
		if ((Case == -1) || (Case == n)){
			string Arg0 = "yxyxyxxyxxyxxyyxyxyxyyyxyyxyyxyyyxyxxyyyyyyxxyx";
			string Arg1 = "xxxxxxxxyxyxxxyyxyyxxxxxxyxxyxyyxxxyyyyyxxxyxyx";
			string Arg2 = "yyyyyyyyyyyyyyyyyyyyyyyyyyyxxxxyxyxyxxxxyxyyyxxyyyxxxy";

			verify_case(n, Arg2, find(Arg0, Arg1));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheLargestString ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
