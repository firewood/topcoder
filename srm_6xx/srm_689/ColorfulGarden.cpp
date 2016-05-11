// BEGIN CUT HERE
/*
SRM 689 Div1 Easy (250)

ñ‚ëË
-â°Ç…nóÒÅAècÇ…2íiÇÃè°ñ⁄èÛÇÃâ‘ídÇ™Ç†ÇÈ
-äeè°ñ⁄ÇÃâ‘ÇÃêFÇ™ó^Ç¶ÇÁÇÍÇÈ
-ècÇ‹ÇΩÇÕâ°Ç…ìØÇ∂êFÇ™ó◊ÇËçáÇÌÇ»Ç¢ÇÊÇ§Ç…ï¿Ç◊ë÷Ç¶ÇÈ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class ColorfulGarden {
public:
	vector <string> rearrange(vector <string> garden) {
		vector <string> ans;
		int W = (int)garden[0].length();
		int cnt[256] = {};
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < W; ++j) {
				cnt[garden[i][j]] += 1;
			}
		}
		IIVec v;
		for (int i = 0; i < 256; ++i) {
			if (cnt[i] > W) {
				return ans;
			}
			if (cnt[i]) {
				v.push_back(II(-cnt[i], i));
			}
		}
		sort(v.begin(), v.end());
		ans = garden;
		int pos = 0;
		for (int i = 0; i < W * 2; ++i) {
			if (v[pos].first >= 0) {
				++pos;
			}
			int col = i % W, row = (col & 1) ^ (i >= W);
			ans[row][col] = (char)v[pos].second;
			v[pos].first += 1;
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <string> &Source, const vector <string> &Expected, const vector <string> &Received) {
		cerr << "Test Case #" << Case << "...";
		bool valid = true;
		if (Expected.size() != Received.size()) {
			valid = false;
		}
		else if (Expected.size() > 0) {
			int W = (int)Source[0].length();
			int cnt[256] = {};
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < W; ++j) {
					cnt[Source[i][j]] += 1;
				}
			}
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < W; ++j) {
					cnt[Received[i][j]] -= 1;
					if (cnt[Received[i][j]] < 0) {
						valid = false;
					}
					if (Received[0][j] == Received[1][j]) {
						valid = false;
					}
					if (j > 0 && Received[i][j - 1] == Received[i][j]) {
						valid = false;
					}
				}
			}
			++W;
		}
		if (valid) {
			cerr << "PASSED" << endl;
		}
		else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: " << print_array(Expected) << endl;
			cerr << "\tReceived: " << print_array(Received) << endl;
		}
	}

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aa",
 "bb"};
			string Arr1[] = {"ab", "ba" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"xxxx",
 "xxxx"};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcd",
 "abcd"};
			string Arr1[] = {"abcd", "dcba" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcdefghijklm",
 "nopqrstuvwxyz"};
			string Arr1[] = {"abcdefghijklm", "nopqrstuvwxyz" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaa",
 "aab"};

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1;
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			string Arr0[] = { "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac",
				"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbc" };
			string Arr1[] = { "abababababababababababababababababababababababacb", "babababababababababababababababababababababababac" };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg0, Arg1, rearrange(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulGarden ___test;
	___test.run_test(-1);
}
// END CUT HERE
