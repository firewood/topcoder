// BEGIN CUT HERE
/*
SRM 704 Div1 Easy (300)

問題
-木において、距離d(u,v)は、uからvへ到達するために経由する辺の数の最小値である
-頂点uのd(u,v)の最大値を、頂点uの偏心とする
-各頂点iについて、偏心がd[i]となる木を構築せよ

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TreeDistanceConstruction {

public:
	vector <int> construct(vector <int> d) {
		vector <int> ans;
		int N = (int)d.size();
		if (N == 2) {
			if (d[0] == 1 && d[1] == 1) {
				ans.push_back(0);
				ans.push_back(1);
			}
			return ans;
		}
		vector <int> dd[64];
		for (int i = 0; i < N; ++i) {
			dd[d[i]].push_back(i);
		}
		int m = *max_element(d.begin(), d.end());
		int center = (m + 1) / 2;
		for (int i = m; i > center; --i) {
			bool is_next_one_node = (i == (center + 1) && ((m % 2) == 0));
			if (dd[i].size() < 2 || dd[i - 1].size() < (2 - is_next_one_node)) {
				return vector<int>();
			}
			ans.push_back(dd[i - 1][0]);
			ans.push_back(dd[i][0]);
			for (int j = 1; j < (int)dd[i].size(); ++j) {
				ans.push_back(dd[i - 1][1 - is_next_one_node]);
				ans.push_back(dd[i][j]);
			}
		}
		if (m % 2) {
			ans.push_back(dd[center][0]);
			ans.push_back(dd[center][1]);
		}
		if (ans.size() != 2 * (N - 1)) {
			return vector<int>();
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
			int Arr0[] = {3,2,2,3};
			int Arr1[] = {1, 2, 1, 0, 2, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,2,2};
			int Arr1[] = {0, 1, 0, 2, 0, 3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,1};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1};

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1};
			int Arr1[] = {0, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 4,3,2,3,4 };
			int Arr1[] = { 1,0,3,4,2,1,2,3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 5,4,3,3,4,5 };
			int Arr1[] = { 1,0,4,5,2,1,3,4,2,3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 3,3,4,4,5,5,5 };
			int Arr1[] = { 2,4,3,5,3,6,0,2,1,3,0,1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 5,4,3,2,4,5 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = {2,2,2,2,3,3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 4,4,3,3,2,2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1;
			verify_case(n, Arg1, construct(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TreeDistanceConstruction ___test;
	___test.run_test(-1);
}
// END CUT HERE
