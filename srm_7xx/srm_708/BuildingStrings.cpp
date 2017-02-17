// BEGIN CUT HERE
/*
SRM 708 Div2 Medium (500)

問題
-文字列に存在する文字の種類の数と、文字列の長さの積を文字列のスコアとする
-スコアの合計がKとなるように、文字列の配列を作成せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<string> StrVec;

int score(StrVec &v) {
	int r = 0;
	for (string &s : v) {
		set<char> m;
		for (char c : s) {
			m.insert(c);
		}
		r += s.length() * m.size();
	}
	return r;
}

class BuildingStrings {
public:
	vector <string> findAny(int K) {
		vector <string> ans;
		while (K >= 25 * 25) {
			string s = "abcdefghijklmnopqrstuvwxy";
			for (int i = 25; i < K / 25 && s.length() < 50; ++i) {
				s += "a";
			}
			ans.push_back(s);
			K -= s.length() * 25;
		}
		while (K >= 5 * 5) {
			string s = "abcde";
			for (int i = 5; i < K / 5 && s.length() < 50; ++i) {
				s += "a";
			}
			ans.push_back(s);
			K -= s.length() * 5;
		}
		while (K >= 1) {
			string s(min(50, K), 'a');
			ans.push_back(s);
			K -= s.length();
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
			int Arg0 = 49;
			string Arr1[] = {"little", "limak" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 15;
			string Arr1[] = {"azz", "xyz" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 704;
			string Arr1[] = {"aaaaaaaaaa", "abcdefghijklmnopqrstuvwxyz", "aabbcc" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 37521;
			string Arr1[] = {"aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyy", "abcd", "aa", "a", "a", "a" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arr1[] = {"a" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50000;
			string Arr1[] = { "a" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BuildingStrings ___test;
	___test.run_test(-1);

	for (int t = 1; t <= 50000; ++t) {
		StrVec r = ___test.findAny(t);
		int s = score(r);
		if (r.size() > 50 || s != t) {
			cout << "ERROR: " << t << endl;
		}
	}
}
// END CUT HERE
