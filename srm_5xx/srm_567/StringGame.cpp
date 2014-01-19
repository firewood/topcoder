// BEGIN CUT HERE
/*
SRM 567 Div1 Medium (500)

問題
-文字列の集合Sが与えられる
-最初のプレイヤーがSから文字列をひとつ選び、並び替えてXとする
-最初のプレイヤーがアルファベットの並び順を選ぶ
-XとS内の全ての文字列を並べ替えた文字列のうち、Xが単独の辞書順最小にできるかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class StringGame {
public:
	vector <int> getWinningStrings(vector <string> S) {
		vector <int> ans;
		int sz = (int)S.size();
		int cnt[50][26] = {};
		int i, j, k, l;
		for (i = 0; i < sz; ++i) {
			for (j = 0; j < (int)S[i].length(); ++j) {
				cnt[i][S[i][j]-'a'] += 1;
			}
		}

#if 1
		for (i = 0; i < sz; ++i) {
			int lc = 1;
			int lesser[50] = {};
			bool yes = false;
			for (l = 0; l < 26; ++l) {
				for (j = 0; j < 26; ++j) {
					for (k = 0; k < sz; ++k) {
						if (!lesser[k] && cnt[k][j] > cnt[i][j]) {
							break;
						}
					}
					if (k < sz) {
						continue;
					}
					for (k = 0; k < sz; ++k) {
						if (cnt[k][j] < cnt[i][j]) {
							if (!lesser[k]) {
								lesser[k] = 1;
								if (++lc >= sz) {
									yes = true;
								}
							}
						}
					}
				}
			}
			if (yes) {
				ans.push_back(i);
			}
		}
#else
		typedef long long LL;
		LL full = (1LL << sz) - 1;
		for (i = 0; i < sz; ++i) {
			LL lesser = 1LL << i;
			for (l = 0; l < 26; ++l) {
				for (j = 0; j < 26; ++j) {
					LL b = 0;
					for (k = 0; k < sz; ++k) {
						if (lesser & (1LL << k)) continue;
						if (cnt[k][j] > cnt[i][j]) {
							break;
						}
						if (cnt[k][j] < cnt[i][j]) {
							b |= 1LL << k;
						}
					}
					if (k < sz) continue;
					lesser |= b;
				}
			}
			if (lesser == full) {
				ans.push_back(i);
			}
		}
#endif

		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"a", "b", "c", "d"};
			int Arr1[] = {0, 1, 2, 3 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aabbcc", "aaabbb", "aaaccc"};
			int Arr1[] = {1, 2 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"ab", "ba"};
			int Arr1[] = { 0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
//			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
			int Arr1[] = {1, 3, 4 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;





		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaabbbcde", "aaabbbcdf", "eeeeeeeee"};
			int Arr1[] = {0 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getWinningStrings(Arg0));
		}
		n++;







	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	StringGame ___test;
//	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
