// BEGIN CUT HERE
/*
SRM 672 Div2 Medium (500)

問題
-アルファベットだけからなる文字列を置換して暗号化する
-置換は1文字が1文字に対応する
-元の文字列aとそれを置換した文字列b、ある文字列を置換したyが与えられる
-yから置換元のxを求める

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

typedef set<int> IntSet;

class SubstitutionCipher {
public:
	string decode(string a, string b, string y) {
		IntSet p, q;
		for (int i = 'A'; i <= 'Z'; ++i) {
			p.insert(i);
			q.insert(i);
		}
		char table[256] = {};
		for (int i = 0; i != a.length(); ++i) {
			table[b[i]] = a[i];
			p.erase(a[i]);
			q.erase(b[i]);
		}
		if (p.size() == 1) {
			table[*q.begin()] = *p.begin();
		}
		string x;
		for (char c : y) {
			c = table[c];
			if (!c) {
				return "";
			}
			x += c;
		}
		return x;
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
			string Arg0 = "CAT";
			string Arg1 = "DOG";
			string Arg2 = "GOD";
			string Arg3 = "TAC";

			verify_case(n, Arg3, decode(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BANANA";
			string Arg1 = "METETE";
			string Arg2 = "TEMP";
			string Arg3 = "";

			verify_case(n, Arg3, decode(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG";
			string Arg1 = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH";
			string Arg2 = "DIDYOUNOTICESKIPPEDLETTER";
			string Arg3 = "CHCXNTMNSHBDRJHOODCKDSSDQ";

			verify_case(n, Arg3, decode(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubstitutionCipher ___test;
	___test.run_test(-1);
}
// END CUT HERE
