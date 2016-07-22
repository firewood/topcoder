// BEGIN CUT HERE
/*
SRM 695 Div2 Easy (250)

問題
-四方向いずれかの移動方向と、移動距離の配列が与えられる
-与えられた方向に移動したのち、まっすぐ最初の位置に戻る
-総移動距離を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class BearNSWE {
public:
	double totalDistance(vector <int> a, string dir) {
		double ans = 0;
		int x = 0, y = 0;
		for (int i = 0; i != a.size(); ++i) {
			ans += a[i];
			switch (dir[i]) {
			case 'N': y -= a[i]; break;
			case 'E': x += a[i]; break;
			case 'W': x -= a[i]; break;
			case 'S': y += a[i]; break;
			}
		}
		ans += sqrt(x * x + y * y);
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
			int Arr0[] = {1,3,3};
			string Arg1 = "NES";
			double Arg2 = 10.60555127546399;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,10,10};
			string Arg1 = "NWSE";
			double Arg2 = 40.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,10,10,15,8,20,5};
			string Arg1 = "NEWEWWE";
			double Arg2 = 90.8062484748657;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42};
			string Arg1 = "E";
			double Arg2 = 84.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10,40,40};
			string Arg1 = "NSE";
			double Arg2 = 140.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, totalDistance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearNSWE ___test;
	___test.run_test(-1);
}
// END CUT HERE
