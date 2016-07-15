// BEGIN CUT HERE

/*
TCO 2016 Round 1C Medium (500)

問題
-A,B,Cの三人がいる
-Aは毎日働くことができる
-Bは働いたら少なくとも1日の休みが必要
-Cは働いたら少なくとも2日の休みが必要
-A,B,Cからなる働き方の文字列が与えられる
-条件を満たすように働き方を並べ替える

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class ThreeProgrammers {

	int end_pos;
	char w[64];

	bool possible(int pos, int a, int b, int c) {
		int r = end_pos - pos;
		if (b > (r + 1) / 2) {
			return false;
		}
		if (c > (r + 2) / 3) {
			return false;
		}
		if (a > 0) {
			w[pos] = 'A';
			if (possible(pos + 1, a - 1, b, c)) {
				return true;
			}
		}
		if (b > 0 && w[pos - 1] != 'B') {
			w[pos] = 'B';
			if (possible(pos + 1, a, b - 1, c)) {
				return true;
			}
		}
		if (c > 0 && w[pos - 1] != 'C' && w[pos - 2] != 'C') {
			w[pos] = 'C';
			if (possible(pos + 1, a, b, c - 1)) {
				return true;
			}
		}
		return pos == end_pos;
	}

public:
	string validCodeHistory(string code) {
		end_pos = 2 + (int)code.length();
		memset(w, 0, sizeof(w));
		int cnt[256] = {};
		for (char c : code) {
			cnt[(int)c] += 1;
		}
		return possible(2, cnt['A'], cnt['B'], cnt['C']) ? (w + 2) : "impossible";
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
			string Arg0 = "CAB";
			string Arg1 = "BCA";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CBB";
			string Arg1 = "BCB";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BB";
			string Arg1 = "impossible";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BBA";
			string Arg1 = "BAB";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arg0 = "CAC";
			string Arg1 = "impossible";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACAC";
			string Arg1 = "CAAC";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ACABC";
			string Arg1 = "ACABC";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			string Arg0 = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB";
			string Arg1 = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA";

			verify_case(n, Arg1, validCodeHistory(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ThreeProgrammers ___test;
	___test.run_test(-1);
}
// END CUT HERE
