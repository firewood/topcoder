// BEGIN CUT HERE
/*
SRM 621 Div2 Easy (250)

問題
-文字列の配列がある
-辞書順と長さ順のそれぞれでソートしたものと一致するかどうかを求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TwoWaysSorting {
public:
	string sortingMethod(vector <string> stringList) {
		vector <string> a = stringList;
		sort(a.begin(), a.end());
		int lex = a == stringList;
		vector<pair<int, string> >v;
		for (int i = 0; i < (int)stringList.size(); ++i) {
			v.push_back(make_pair(stringList[i].length(), stringList[i]));
		}
		sort(v.begin(), v.end());
		a.clear();
		for (int i = 0; i < (int)stringList.size(); ++i) {
			a.push_back(v[i].second);
		}
		int len = a == stringList;
		if (lex && len) {
			return "both";
		}
		if (lex) {
			return "lexicographically";
		}
		if (len) {
			return "lengths";
		}
		return "none";
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
			string Arr0[] = {"a", "aa", "bbb"};
			string Arg1 = "both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"c", "bb", "aaa"};
			string Arg1 = "lengths";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"etdfgfh", "aio"};
			string Arg1 = "none";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"aaa", "z"};
			string Arg1 = "lexicographically";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"z"};
			string Arg1 = "both";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"};
			string Arg1 = "lexicographically";

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, sortingMethod(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TwoWaysSorting ___test;
	___test.run_test(-1);
}
// END CUT HERE
