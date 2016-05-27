// BEGIN CUT HERE
/*
SRM 690 Div2 Medium (500)

問題
-各都市に有権者がA[i]人、支持者がB[i]人いる
-連続するK個以上の都市を選んだときの支持率B÷Aの最大値を求める

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GerrymanderEasy {
public:
	double getmax(vector <int> A, vector <int> B, int K) {
		double ans = 0;
		for (int i = 0; (i + K) <= (int)A.size(); ++i) {
			for (int k = K; (i + k) <= (int)A.size(); ++k) {
				int a = accumulate(A.begin() + i, A.begin() + i + k, 0);
				int b = accumulate(B.begin() + i, B.begin() + i + k, 0);
				ans = max(ans, (double)b / a);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,1,2,7};
			int Arr1[] = {4,0,2,2};
			int Arg2 = 2;
			double Arg3 = 0.75;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,34,56,78,90};
			int Arr1[] = {1,1,1,1,1};
			int Arg2 = 1;
			double Arg3 = 0.08333333333333333;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
			int Arr1[] = {3,1,4,1,5,9,2,6,5,3};
			int Arg2 = 5;
			double Arg3 = 5.4E-4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123,4,46,88,22,34,564,87,56,311,886};
			int Arr1[] = {0,0,0,0,0,0,0,0,0,0,0};
			int Arg2 = 1;
			double Arg3 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GerrymanderEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
