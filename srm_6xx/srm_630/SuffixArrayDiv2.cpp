// BEGIN CUT HERE
/*
SRM 630 Div2 Hard (1000)

問題
-文字列Sの位置i以降の部分文字列を接尾辞iとする
-接尾辞を辞書順に並べ、その番号を配列にしたものを接尾辞配列とする
-文字列Sが与えられる
-接尾辞配列がSと等しく、かつ、Sより辞書順が小さい文字列が存在するかどうか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class SuffixArrayDiv2 {

	vector<int> calc(string &s) {
		vector<pair<string, int> >v;
		for (int i = 0; i < (int)s.length(); ++i) {
			v.push_back(make_pair(s.substr(i), i));
		}
		sort(v.begin(), v.end());
		vector<int> r;
		for (int i = 0; i < (int)v.size(); ++i) {
			r.push_back(v[i].second);
		}
		return r;
	}

public:
	string smallerOne(string s) {
		vector<int> a = calc(s);
		for (int i = 0; i < (int)s.length(); ++i) {
			string t = s;
			if (t[i] > 'a') {
				t[i] -= 1;
				vector<int> b = calc(t);
				if (a == b) {
					return "Exists";
				}
			}
		}
		return "Does not exist";
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
			string Arg0 = "abca";
			string Arg1 = "Exists";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbb";
			string Arg1 = "Exists";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "aaaa";
			string Arg1 = "Does not exist";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "examplesareveryweakthinktwicebeforesubmit";
			string Arg1 = "Exists";

			verify_case(n, Arg1, smallerOne(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SuffixArrayDiv2 ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
