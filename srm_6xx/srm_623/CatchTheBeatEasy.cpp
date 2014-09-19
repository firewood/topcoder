// BEGIN CUT HERE
/*
SRM 623 Div2 Easy (250)

問題
-(x[i],y[i])からフルーツが速度毎秒1で垂直に落ちてくる
-主人公は(0,0)から毎秒1で水平に移動できる
-全てのフルーツをキャッチできるかどうか求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

class CatchTheBeatEasy {

	bool can(vector <int> x, vector <int> y) {
		int N = (int)x.size();
		IIVec v;
		for (int i = 0; i < N; ++i) {
			v.push_back(II(y[i], x[i]));
		}
		sort(v.begin(), v.end());
		int cx = 0, cy = 0;
		for (int i = 0; i < N; ++i) {
			int t = v[i].first - cy;
			int d = abs(v[i].second - cx);
			if (d > t) {
				return false;
			}
			cx = v[i].second;
			cy = v[i].first;
		}
		return true;
	}

public:
	string ableToCatchAll(vector <int> x, vector <int> y) {
		return can(x, y) ? "Able to catch" : "Not able to catch";
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
			int Arr0[] = {-1, 1, 0};
			int Arr1[] = {1, 3, 4};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-3};
			int Arr1[] = {2};
			string Arg2 = "Not able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-1, 1, 0};
			int Arr1[] = {1, 2, 4};
			string Arg2 = "Not able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, -1, 1};
			int Arr1[] = {9, 1, 3};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {70,-108,52,-70,84,-29,66,-33};
			int Arr1[] = {141,299,402,280,28,363,427,232};
			string Arg2 = "Not able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
			int Arr1[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,0,0};
			int Arr1[] = {0,0,0,0};
			string Arg2 = "Able to catch";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, ableToCatchAll(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CatchTheBeatEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
