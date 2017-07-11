// BEGIN CUT HERE
/*
TCO 2017 R2B Easy (300)

問題
-K個のパーツからなる円環上の鎖がN個ある
-各パーツには文字が1つ書かれている
-M個の数値からなる配列Lが与えられる
-各数値について、未使用の鎖をひとつ取り出し、その長さだけ切り出す
-それらを連結した文字列のうち、辞書順最大のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class DengklekGaneshAndChains {
public:
	string getBestChains(vector <string> chains, vector <int> lengths) {
		string ans;
		int n = (int)chains.size(), k = (int)chains[0].length();
		for (int i = 0; i < n; ++i) {
			string m = chains[i];
			for (int j = 1; j < k; ++j) {
				m = max(m, chains[i].substr(j) + chains[i].substr(0, j));
			}
			chains[i] = m;
		}
		sort(chains.begin(), chains.end());
		int used[64] = {};
		for (int len : lengths) {
			int j = -1;
			string s;
			for (int i = 0; i < n; ++i) {
				if (!used[i]) {
					if (j < 0 || s < chains[i].substr(0, len)) {
						j = i;
						s = chains[i].substr(0, len);
					}
				}
			}
			used[j] = 1;
			ans += s;
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
			string Arr0[] = {"topc", "oder", "open", "twob"};
			int Arr1[] = {2, 1, 3};
			string Arg2 = "wotrod";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ssh", "she", "see", "sea"};
			int Arr1[] = {2, 3, 2, 3};
			string Arg2 = "ssshesesee";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"wri", "ter", "who", "are", "you"};
			int Arr1[] = {3};
			string Arg2 = "you";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"harus", "imfyo"};
			int Arr1[] = {5, 5};
			string Arg2 = "yoimfushar";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getBestChains(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DengklekGaneshAndChains ___test;
	___test.run_test(-1);
}
// END CUT HERE
