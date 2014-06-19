// BEGIN CUT HERE
/*
SRM 603 Div2 Easy (250)

問題
-文字列sが与えられる
-文字列tの初期値は空
-sの長さが奇数のとき、tの末尾にsの中央の文字を追加して、sからは削除する
-sの長さが偶数のとき、tの末尾にsの中央の2文字のうち小さいほうを追加して、sから削除する
-sが空になったときのtを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class MiddleCode {
public:
	string encode(string s) {
		string t;
		while (!s.empty()) {
			int len = (int)s.length();
			char a = s[(len-1)/2], b = s[len/2];
			if (a < b) {
				t += a;
				s = s.substr(0, len/2-1) + s.substr(len/2);
			} else {
				t += b;
				s = s.substr(0, len/2) + s.substr(len/2+1);
			}
		}
		return t;
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
			string Arg0 = "word";
			string Arg1 = "ordw";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaaa";
			string Arg1 = "aaaaa";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abacaba";
			string Arg1 = "caabbaa";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "shjegr";
			string Arg1 = "ejghrs";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "adafaaaadafawafwfasdaa";
			string Arg1 = "afawadafawafaafsadadaa";

			verify_case(n, Arg1, encode(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MiddleCode ___test;
	___test.run_test(-1);
}
// END CUT HERE
