// BEGIN CUT HERE
/*
// TCO12 Round 1B Easy (250)

問題
何本かの鉛筆がある。
1本が長さk、または、2本でk-1の長さとなる鉛筆をk段並べたものをk-gramと呼ぶ。
与えられた鉛筆の組み合わせで可能な最大のk-gramを求める。

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndKgram {

public:
	int maxK(vector <int> len) {
		int sz = len.size();
		int k;
		for (k = 50; k > 0; --k) {
			int cnt = 0;
			int f[50] = {};
			int i, j;
			for (i = 0; i < sz; ++i) {
				if (len[i] == k) {
					++cnt;
					if (cnt >= k) {
						return k;
					}
				}
			}
			for (i = 1; i < sz; ++i) {
				for (j = 0; j < i; ++j) {
					if (!f[i] && !f[j] && len[i] + len[j] == (k-1)) {
						f[i] = 1, f[j] = 1;
						++cnt;
						if (cnt >= k) {
							return k;
						}
					}
				}
			}
		}
		return 0;
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
			int Arr0[] = {1,1,1,1,3};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,1,3,5,5,5};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arg1 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2,2,2,2,2,2,2,2};
			int Arg1 = 5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,1,2,4,2,3,1};
			int Arg1 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11,13,17,19,23,29};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;




		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1,1,1};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maxK(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndKgram ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
