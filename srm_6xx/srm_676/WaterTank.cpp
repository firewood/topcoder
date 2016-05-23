// BEGIN CUT HERE
/*
SRM 676 Div1 Easy (250)

問題
-Cリットル入るタンクがある
-N個の連続する区間があり、区間ごとに水量が変わる
-区間iの長さはt[i]秒で、毎秒x[i]リットルの水がタンクに入る
-タンクがあふれないようにするための出力Rリットル/秒の最小値を求める

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class WaterTank {

public:
	double minOutputRate(vector <int> t, vector <int> x, int C) {
		long double low = 0;
		long double high = 1.0e+10;
		for (int i = 0; i < 1000; ++i) {
			long double mid = (low + high) / 2;
			bool f = [&]() -> bool {
				long double tot = 0;
				for (int j = 0; j != t.size(); ++j) {
					tot += 1.0 * t[j] * x[j];
					tot = max((long double)0.0, tot - mid * t[j]);
					if (tot > C) {
						return false;
					}
				}
				return true;
			} ();

			if (f) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return low;
	}


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) < 1e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,3};
			int Arr1[] = {1,2};
			int Arg2 = 3;
			double Arg3 = 0.9999999999999999;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5};
			int Arr1[] = {5,4,3,2,1};
			int Arg2 = 10;
			double Arg3 = 1.9999999999999996;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5949,3198,376,3592,4019,3481,5609,3840,6092,4059};
			int Arr1[] = {29,38,96,84,10,2,39,27,76,94};
			int Arg2 = 1000000000;
			double Arg3 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9,3,4,8,1,2,5,7,6};
			int Arr1[] = {123,456,789,1011,1213,1415,1617,1819,2021};
			int Arg2 = 11;
			double Arg3 = 2019.1666666666665;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arr1[] = {1000};
			int Arg2 = 12345;
			double Arg3 = 876.55;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 2, 2 };
			int Arr1[] = { 2, 2 };
			int Arg2 = 3;
			double Arg3 = 1.25;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minOutputRate(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WaterTank ___test;
	___test.run_test(-1);
}
// END CUT HERE
