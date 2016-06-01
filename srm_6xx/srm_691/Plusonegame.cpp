// BEGIN CUT HERE
/*
SRM 691 Div2 Easy (300)

問題
-数字または+のカードが何枚かある
-カードを1枚ずつ場に出していく
-場にはカウンターが設置されていて初期値はゼロである
-+のカードを出すとカウンターの値が1加算される
-数値のカードを出すと、ペナルティとしてカウンターとの差の絶対値が加算される
-ペナルティを最小化する手の出し方のうち辞書順最小のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Plusonegame {
public:
	string getorder(string s) {
		int cnt[256] = {};
		for (char c : s) {
			cnt[(int)c] += 1;
		}
		string ans;
		for (char i = '0'; i <= '9'; ++i) {
			ans += string(cnt[(int)i], i);
			if (cnt['+']) {
				ans += "+";
				cnt['+'] -= 1;
			}
		}
		ans += string(cnt[(int)'+'], '+');
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
			string Arg0 = "1++";
			string Arg1 = "+1+";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "549";
			string Arg1 = "459";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++++++";
			string Arg1 = "++++++";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "+++++2+";
			string Arg1 = "++2++++";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++++4++++200++2++1+6++++++";
			string Arg1 = "00+1+22++4++6+++++++++++++";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "++11199999";
			string Arg1 = "+111+99999";

			verify_case(n, Arg1, getorder(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Plusonegame ___test;
	___test.run_test(-1);
}
// END CUT HERE
