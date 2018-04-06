// BEGIN CUT HERE
/*
SRM 731 Div1 Easy (250)

問題
-木の親子関係を括弧で表す
-各頂点は'('ではじまり、子の全ての頂点を記述し、')'で閉じる
-1回の操作で葉だけを取り除くことができるとき、木表現t1をt2にできるかどうかを求めよ。

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TreesAndBrackets {

	vector<string> split(string s) {
		vector<string> r;
		string x;
		int level = 0;
		for (char c : s) {
			x += c;
			level += c == '(' ? 1 : -1;
			if (level == 0) {
				r.push_back(x.substr(1, x.length() - 2));
				x.clear();
			}
		}
		return r;
	}

	bool dfs(string t1, string t2) {
		if (t2.empty()) {
			return true;
		}
		if (t1.empty()) {
			return false;
		}
		vector<string> al = split(t1);
		vector<string> ar = split(t2);
		int left = -1;
		for (int right = 0; right < (int)ar.size(); ++right) {
			while (++left < (int)al.size() && !dfs(al[left], ar[right])) {
				;
			}
			if (left >= (int)al.size()) {
				return false;
			}
		}
		return true;
	}

public:
	string check(string t1, string t2) {
		return dfs(t1, t2) ? "Possible" : "Impossible";
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
			string Arg0 = "(())";
			string Arg1 = "()";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "()";
			string Arg1 = "()";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "(()()())";
			string Arg1 = "((()))";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())((())())())";
			string Arg1 = "(()(())())";
			string Arg2 = "Possible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "((())((())())())";
			string Arg1 = "((()()()()()))";
			string Arg2 = "Impossible";

			verify_case(n, Arg2, check(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreesAndBrackets ___test;
	___test.run_test(-1);
}
// END CUT HERE
