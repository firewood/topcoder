// BEGIN CUT HERE
/*
TCO13 Round 1B Hard (1000)

問題
-いくつかの英数字からなる単語のリストがある
-任意の単語Sと、Sの長さを超えない偶数kを選ぶ
-Sの1番目からk番目までの文字列を反転する
-その結果ほかの単語と一致した場合は、その単語をリストから取り除く
-最終的に残る単語の数を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;
typedef set<string> StrSet;

class EllysReversals {
public:
	int getMin(vector <string> words) {
		StrSet m;
		int i, j, k, l;
		for (i = 0; i < (int)words.size(); ++i) {
			StrVec v;
			l = (int)words[i].length();
			k = l & ~1;
			for (j = 0; j < k; j += 2) {
				char a = min(words[i][j], words[i][j+1]);
				char b = max(words[i][j], words[i][j+1]);
				string x;
				x += a;
				x += b;
				v.push_back(x);
			}
			string s;
			sort(v.begin(), v.end());
			for (j = 0; j < (int)v.size(); ++j) {
				s += v[j];
			}
			if (l & 1) {
				s += words[i][k];
			}
			if (m.find(s) != m.end()) {
				m.erase(s);
			} else {
				m.insert(s);
			}
		}
		return (int)m.size();
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
			int Arg1 = 3;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"no", "zaphod", "just", "very", "improbable"};
			int Arg1 = 5;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
			int Arg1 = 0;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
			int Arg1 = 1;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
 "nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
 "xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
 "zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
 "yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
			int Arg1 = 16;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "reodtopc"};
			int Arg1 = 1;
			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, getMin(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysReversals ___test;
	___test.run_test(-1);
}
// END CUT HERE
