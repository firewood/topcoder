// BEGIN CUT HERE
/*
SRM 633 Div2 Easy (250)

ñ‚ëË
-ëÂÇ´Ç≥nÇÃè°ñ⁄Ç…ìIÇÃäGÇï`Ç≠

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Target {
public:
	vector <string> draw(int n) {
		vector <string> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = string(n, ' ');
		}
		for (int i = 0; i <= n / 2; i += 2) {
			for (int j = -i; j <= i; ++j) {
				ans[n / 2 - i][n / 2 + j] = '#';
				ans[n / 2 + i][n / 2 + j] = '#';
				ans[n / 2 + j][n / 2 - i] = '#';
				ans[n / 2 + j][n / 2 + i] = '#';
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
			int Arg0 = 5;
			string Arr1[] = {"#####", "#   #", "# # #", "#   #", "#####" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 9;
			string Arr1[] = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 13;
			string Arr1[] = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 17;
			string Arr1[] = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" };

			vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, draw(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Target ___test;
	___test.run_test(-1);
}
// END CUT HERE
