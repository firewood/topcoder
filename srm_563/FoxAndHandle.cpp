// BEGIN CUT HERE
/*
// SRM 563 Div1 Easy (300)

問題
二つの文字列を、どちらかの先頭から一文字ずつ結合していく操作をシャッフルとする
シャッフル後の文字列が与えられる
元の文字列の候補のうち辞書順最小のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef map<int, int> IntMap;

class FoxAndHandle {

	bool check(IntMap &s, IntMap &m) {
		IntMap::const_iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			if (it->second > m[it->first]) {
				return false;
			}
		}
		return true;
	}

public:
	string lexSmallestName(string S) {
		IntMap m[51];
		int len = (int)S.length();
		int i, j;
		for (i = len-1; i >= 0; --i) {
			m[i] = m[i+1];
			m[i][S[i]] += 1;
		}
		IntMap s = m[0];
		IntMap::iterator it;
		for (it = s.begin(); it != s.end(); ++it) {
			it->second /= 2;
		}
		string ans;
		i = 0;
		while ((int)ans.length() < len/2) {
			char c;
			for (c = 'a'; c <= 'z'; ++c) {
				if (s[c] <= 0) continue;
				j = (int)S.find(c, i);		// j >= 0
				if (check(s, m[j])) {
					ans += c;
					s[c] -= 1;
					i = j+1;
					break;
				}
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
			string Arg0 = "foxfox";
			string Arg1 = "fox";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ccieliel";
			string Arg1 = "ceil";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "abaabbab";
			string Arg1 = "aabb";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbbbaaaa";
			string Arg1 = "bbaa";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "fedcbafedcba";
			string Arg1 = "afedcb";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "nodevillivedon";
			string Arg1 = "deilvon";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arg0 = "bkbkaajaajkkmfmfliffajaelhihlihajaeohggholihoggo";
			string Arg1 = "baaaajkkfmfehhlihjgglioo";

			verify_case(n, Arg1, lexSmallestName(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndHandle ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
