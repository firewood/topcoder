// BEGIN CUT HERE
/*
SRM 658 Div1 Easy (300)

問題
-N個の頂点からなる木がある
-それぞれの頂点の距離の偶奇が与えられる
-構成が可能なら辺を求める

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

class OddEvenTree {

	vector <int> gt(const vector <string> &x) {
		int N = (int)x.size();
		int oa = -1, ob = -1, ec = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) {
					if (x[i][j] != 'E') {
						return IntVec();
					}
				} else {
					if (x[i][j] == 'O') {
						if (oa < 0) {
							oa = i, ob = j;
						}
					} else {
						++ec;
					}
					if ((x[0][i] == x[i][i]) != (x[0][j] == x[i][j])) {
						return IntVec();
					}
				}
			}
		}
		IntVec ans;
		ans.push_back(oa);
		ans.push_back(ob);
		if (oa < 0 || (N > 2 && ec <= 0)) {
			return IntVec();
		}
		int used[64] = {};
		used[oa] = 1, used[ob] = 1;
		for (int i = 0; i < N; ++i) {
			if (!used[i]) {
				if (x[0][oa] == x[0][i]) {
					ans.push_back(ob);
					ans.push_back(i);
				} else {
					ans.push_back(oa);
					ans.push_back(i);
				}
			}
		}
		return ans;
	}

public:
	vector <int> getTree(vector <string> x) {
		IntVec ans = gt(x);
		if (ans.empty()) {
			ans.push_back(-1);
		}
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
			string Arr0[] = {"EOE",
 "OEO",
 "EOE"};
			int Arr1[] = {0, 1, 2, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"EO",
 "OE"};
			int Arr1[] = {0, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"OO",
 "OE"};
			int Arr1[] = {-1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"EO",
 "EE"};
			int Arr1[] = {-1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			string Arr0[] = {"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"};
			int Arr1[] = {0, 1, 0, 3, 2, 1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "EE",
				"EE" };
			int Arr1[] = { -1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			string Arr0[] = { "EOO",
				"OEO",
				"OOE" };
			int Arr1[] = { -1 };

			vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, getTree(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OddEvenTree ___test;
	___test.run_test(-1);
}
// END CUT HERE
