// BEGIN CUT HERE
/*
// TCO12 Round 1A Easy (250)

問題
みかんジュースとりんごジュースが1ガロンずつある
n人で、1ターンにみかんとりんごを交互に飲む
一度に残量の半分飲む
一番飲んだ人が勝ち
ただし一番が複数いる場合は勝ちなし
勝つ可能性がある人の名前のリストを求める

*/
// END CUT HERE
#include <cmath>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef map<string, int> StrIntMap;

class EllysJuice {

public:
	vector <string> getWinners(vector <string> players) {
		vector <string> res;
		int n = players.size();
		StrIntMap m;
#if 1
		int i;
		for (i = 0; i < n; ++i) {
			m[players[i]] += 1;
		}
		if (m.size() == 1) {
			m.begin()->second += 1;
		}
		StrIntMap::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			if (it->second >= 2) {
				res.push_back(it->first);
			}
		}
#else
		int i, j, k;
		for (i = 0; i < n; ++i) {
			m[players[i]] += 1;
		}

		i = 0, k = 0;
		int seq[8] = {};
		StrIntMap::const_iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			for (j = 0; j < it->second; ++j) {
				seq[i++] = k;
			}
			++k;
		}

		int w[8] = {};
		do {
			int d[9] = {};
			int b[2] = {256,256};
			for (i = 0; i < n; ++i) {
				d[seq[i]] += b[i%2];
				b[i%2] /= 2;
			}
			if (d[seq[0]] > d[seq[1]] || seq[0] == seq[1]) {
				++w[seq[0]];
			}
		} while (next_permutation(seq, seq + n));

		if (m.size() == 1) {
			w[0] = 1;
		}

		k = 0;
		for (it = m.begin(); it != m.end(); ++it) {
			if (w[k]) {
				res.push_back(it->first);
			}
			++k;
		}
#endif
		return res;
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
			string Arr0[] = { "elly", "kriss", "stancho", "elly", "stancho" };
			string Arr1[] = {"elly", "stancho" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;


		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"torb", "elly", "stancho", "kriss"};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;


		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"elly", "elly", "elly", "elly", "elly"};
			string Arr1[] = {"elly" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" };
			string Arr1[] = {"ariadne", "elly", "stancho" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "ariadne", "ariadne", "ariadne", "ariadne", "ariadne", "ariadne", "elly", "elly" };
			string Arr1[] = {"ariadne", "elly" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinners(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	EllysJuice ___test;
//	___test.run_test(4);
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
