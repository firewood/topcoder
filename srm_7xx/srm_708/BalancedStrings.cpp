// BEGIN CUT HERE
/*
SRM 708 Div1 Easy (250)

問題
-文字列中の隣り合う2文字が異なる個数を、文字列のinstabilityとする
-文字列の配列のinstabilityは、それぞれの文字列のinstabilityの合計値とする
-二つの文字列s1,s2について、s1の各文字s1[i]とs2の各文字s2[j]が同じである個数を文字列のsimilarityとする
-文字列の配列のsimilarityは、配列の全ての2要素の組み合わせのsimilarityの合計値とする
-数Nが与えられる
-instabilityとsimilarityが等しくなるよう、要素数がNの文字列の配列を構築せよ
-ただし各文字列は100文字までとする

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<string> StrVec;
typedef map<int, int> IntMap;

static int instability(StrVec &v) {
	int cnt = 0;
	for (string &s : v) {
		for (int i = 1; i < (int)s.length(); ++i) {
			cnt += s[i - 1] != s[i];
		}
	}
	return cnt;
}

int similarity(StrVec &v) {
	int r = 0;
	IntMap cnt[100];
	for (int i = 0; i != v.size(); ++i) {
		for (char c : v[i]) {
			++cnt[i][c - 'a'];
		}
	}
	for (int i = 0; i != v.size(); ++i) {
		for (auto &kv : cnt[i]) {
			for (int j = i + 1; j != v.size(); ++j) {
				r += kv.second * cnt[j][kv.first];
			}
		}
	}
	return r;
}

class BalancedStrings {
	public:
	vector <string> findAny(int N) {
		StrVec ans(N);
		if (N <= 26) {
			for (int i = 0; i < N; ++i) {
				ans[i] = string(1, 'a' + i);
			}
		} else {
			ans[0] = "abababababababababababababababababababababababababababababababababababababababababababababababababab";
			ans[1] = "cdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcdcd";
			for (int i = 2; i < N; ++i) {
				ans[i] = "e";
			}
			int p = instability(ans);
			int q = similarity(ans);
			for (int i = N - 1; q > p && i >= 2; --i) {
				ans[i] = string(1, 'e' + (i % 22));
				q = similarity(ans);
			}
			while (p > q) {
				for (int i = 1; i >= 0; --i) {
					if (ans[i].length() > 1) {
						ans[i] = ans[i].substr(0, ans[i].length() - 1);
						break;
					}
				}
				p = instability(ans);
			}
		}
		return ans;
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
			int Arg0 = 3;
			string Arr1[] = {"eertree", "topcoder", "arena" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			string Arr1[] = {"hello", "little", "polar", "bear" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			string Arr1[] = {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			string Arr1[] = {"kkkkkkkkkkkkkkkkkkk" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			string Arr1[] = {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, findAny(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BalancedStrings ___test;
	___test.run_test(-1);

	for (int t = 1; t <= 100; ++t) {
		StrVec ans = ___test.findAny(t);
		int p = instability(ans);
		int q = similarity(ans);
		if (ans.empty() || ans[0].empty() || p != q) {
			printf("ERROR: %d\n", t);
		}
	}
}
// END CUT HERE
