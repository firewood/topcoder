// BEGIN CUT HERE
/*
SRM 579 Div1 Easy (250)

問題
-historyバッファを持つエディタがある
-現在行の状態は常にhistoryバッファに履歴として残る
-任意のhistoryバッファから2クリックで現在行にコピーすることができる
-入力すべき行が与えられる
-キーストロークまたはクリックの合計の最小値を求める

*/
// END CUT HERE
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef set<string> StrSet;

class UndoHistory {
public:
	int minPresses(vector <string> lines) {
		StrSet h;
		h.insert("");
		int sz = (int)lines.size();

		string cur;
		int ans = 0;
		int i, j, k, l;
		for (i = 0; i < sz; ++i) {
			string &s = lines[i];
			l = (int)s.length();

			size_t types = 1000000000;
			if (cur.compare(s.substr(0, cur.length())) == 0) {
				// prefix matched with current string
				types = l - cur.length();
			}

			// search from history
			for (j = l; j >= 0; --j) {
				string r = s.substr(0, j);
				if (h.find(r) != h.end()) {
					// found from history
					size_t t = l - r.length();
					if (types >= (t+2)) {
						// paste from history
						ans += 2;
						cur = r;
					}
					break;
				}
			}

			// type remain characters
			for (k = (int)cur.length(); k < l; ++k) {
				cur += s[k];
				h.insert(cur);
				++ans;
			}
			// enter
			++ans;
		}
		return ans;
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
			string Arr0[] = {"tomorrow", "topcoder"};
			int Arg1 = 18;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a","b"};
			int Arg1 = 6;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a", "ab", "abac", "abacus" };
			int Arg1 = 10;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
			int Arg1 = 39;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ba","a","a","b","ba"}
;
			int Arg1 = 13;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaaabbbb","aaaa","aaaabbbb"}
;
			int Arg1 = 15;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcde","a","abdef"}
;
			int Arg1 = 14;

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, minPresses(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	UndoHistory ___test;
	___test.run_test(-1);
}
// END CUT HERE
