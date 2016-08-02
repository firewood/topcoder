// BEGIN CUT HERE
/*
SRM 695 Div1 Easy (300)

問題
-文字aまたはbだけからなるN文字のパスワードSを作る
-Sの同じ文字が連続する部分を取り出したものを部分文字列とする
-異なる位置からはじまる部分文字列は異なるものとする
-長さがi+1の部分文字列の個数が配列x[i]として与えられる
-条件を満たす文字列のうち辞書順最小のものを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef vector<int> IntVec;

class BearPasswordLexic {

public:
	string findPassword(vector <int> x) {
		int N = (int)x.size();
		int len = 0;
		for (int i = N - 1; i >= 0; --i) {
			for (int j = i + 1; j < N; ++j) {
				x[i] -= x[j] * (j - i + 1);
			}
			len += (i + 1) * x[i];
			if (x[i] < 0) {
				return "";
			}
		}
		if (len != N) {
			return "";
		}

		string ans;
		int high = N - 1, low = 0;
		bool f = true;
		while (ans.length() != N) {
			while (high > 0 && x[high] <= 0) {
				--high;
			}
			if (x[high]-- > 0) {
				ans += string(high + 1, f ? 'a' : 'b');
				f = !f;
			}
			while (low < (N - 1) && x[low] <= 0) {
				++low;
			}
			if (x[low]-- > 0) {
				ans += string(low + 1, f ? 'a' : 'b');
				f = !f;
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
			int Arr0[] = {5,0,0,0,0};
			string Arg1 = "ababa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,2,1,0};
			string Arg1 = "aaab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,1,1};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,3,2,1};
			string Arg1 = "aaaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4,0,3,2};
			string Arg1 = "";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 8,5,3,1,0,0,0,0 };
			string Arg1 = "aaaabaaa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 10,6,4,2,1,0,0,0,0,0 };
			string Arg1 = "aaaaabaaab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 7,5,3,1,0,0,0 };
			string Arg1 = "aaaabbb";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			string Arg1 = "ababababababababababababababababababababababababab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			string Arg1 = "aababababababababababababababababababababababababa";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 50,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			string Arg1 = "aabaababababababababababababababababababababababab";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, findPassword(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPasswordLexic ___test;
	___test.run_test(-1);
}
// END CUT HERE
