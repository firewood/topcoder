// BEGIN CUT HERE
/*
SRM 586 Div2 Easy (250)

問題
-メンバーを2チームにふりわける
-それぞれのキャプテンがメンバーの番号の優先順位を持っている
-1人ずつ割り当てたときのチーム割りを求める

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TeamsSelection {
public:
	string simulate(vector <int> preference1, vector <int> preference2) {
		char ans[64] = {};
		int N = (int)preference1.size();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int k = ((i & 1) ? preference2[j] : preference1[j]) - 1;
				if (!ans[k]) {
					ans[k] = '1' + (i & 1);
					break;
				}
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
			int Arr0[] = {1, 2, 3, 4};
			int Arr1[] = {1, 2, 3, 4};
			string Arg2 = "1212";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3, 2, 1};
			int Arr1[] = {1, 3, 2};
			string Arg2 = "211";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {6, 1, 5, 2, 3, 4};
			int Arr1[] = {1, 6, 3, 4, 5, 2};
			string Arg2 = "212211";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8, 7, 1, 2, 4, 5, 6, 3, 9};
			int Arr1[] = {7, 2, 4, 8, 1, 5, 9, 6, 3};
			string Arg2 = "121121212";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, simulate(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TeamsSelection ___test;
	___test.run_test(-1);
}
// END CUT HERE
