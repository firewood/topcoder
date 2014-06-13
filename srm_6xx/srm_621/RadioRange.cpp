// BEGIN CUT HERE
/*
SRM 621 Div1 Easy (250)

問題
-座標(0,0)に放送局がある
-いくつかの街の中心座標と半径が与えられる
-それぞれの街について、放送局の電波が完全に届かないか、または、街の中全てがカバーされていればgood
-放送局の半径を0以上Z以下の乱数で選ぶとき、全ての街がgoodとなる確率を求める

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class RadioRange {
public:
	double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
		int N = (int)X.size();
		double z = Z;
		vector< pair<double, double> > bad_range;
		for (int i = 0; i < N; ++i) {
			double x = X[i], y = Y[i], r = R[i];
			double d = sqrt(x*x + y*y);
			double s = max(0.0, min(z, d - r));
			double e = min(z, d + r);
			bad_range.push_back(make_pair(s, e));
		}
		sort(bad_range.begin(), bad_range.end());
		double good = 0.0;
		double edge = 0.0;
		for (auto &r : bad_range) {
			good += max(edge, r.first) - edge;
			edge = max(edge, r.second);
		}
		good += z - edge;
		return good / z;
	}


#if 0
	double RadiusProbability2(vector <int> X, vector <int> Y, vector <int> R, int Z) {
		double z = Z;
		int N = (int)X.size();
		vector< pair<double, double> > bad_range;
		for (int i = 0; i < N; ++i) {
			double x = X[i], y = Y[i], r = R[i];
			double d = sqrt(x*x + y*y);
			double s = max(0.0, d - r), e = d + r;
			bad_range.push_back(make_pair(s, e));
		}
		sort(bad_range.begin(), bad_range.end());
		double bs = bad_range[0].first;
		double be = min(z, bad_range[0].second);
		if (z <= bs) {
			return 1.0;
		}
		double g = min(z, bs), b = min(z, be) - bs;
		for (int i = 1; i < (int)bad_range.size(); ++i) {
			double s = bad_range[i].first, e = bad_range[i].second;
			s = min(z, max(s, be));
			e = min(z, max(e, be));
			g += s - be;
			b += e - s;
			be = e;
		}
		g += z - be;
		double ans = g / (g + b);
		return ans;
	}
#endif


// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (fabs(Expected - Received) <= 1.0e-6) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {0};
			int Arr2[] = {5};
			int Arg3 = 10;
			double Arg4 = 0.5;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {0};
			int Arr2[] = {10};
			int Arg3 = 10;
			double Arg4 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10};
			int Arr1[] = {10};
			int Arr2[] = {10};
			int Arg3 = 10;
			double Arg4 = 0.4142135623730951;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {11, -11, 0, 0};
			int Arr1[] = {0, 0, 11, -11};
			int Arr2[] = {10, 10, 10, 10};
			int Arg3 = 31;
			double Arg4 = 0.3548387096774194;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arr1[] = {100};
			int Arr2[] = {1};
			int Arg3 = 10;
			double Arg4 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000000000};
			int Arr1[] = {1000000000};
			int Arr2[] = {1000000000};
			int Arg3 = 1000000000;
			double Arg4 = 0.41421356237309503;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {20, -20, 0, 0};
			int Arr1[] = {0, 0, 20, -20};
			int Arr2[] = {50, 50, 50, 50};
			int Arg3 = 100;
			double Arg4 = 0.3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_7
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0, -60, -62, -60, 63, -97};
			int Arr1[] = {-72, 67, 61, -8, -32, 89};
			int Arr2[] = {6, 7, 8, 7, 5, 6};
			int Arg3 = 918;
			double Arg4 = 0.9407071068962471;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {0};
			int Arr2[] = {20};
			int Arg3 = 10;
			double Arg4 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 0,0 };
			int Arr1[] = { 0,0 };
			int Arr2[] = { 5,9 };
			int Arg3 = 10;
			double Arg4 = 0.1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 0, 0 };
			int Arr1[] = { 0, 0 };
			int Arr2[] = { 1, 10 };
			int Arg3 = 10;
			double Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 20 };
			int Arr1[] = { 1, 20 };
			int Arr2[] = { 1, 1 };
			int Arg3 = 1;
			double Arg4 = sqrt(2.0)-1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1000000000 };
			int Arr1[] = { 0 };
			int Arr2[] = {  999999999 };
			int Arg3 = 1;
			double Arg4 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { -2,-10,1 };
			int Arr1[] = { -8,-3,2 };
			int Arr2[] = { 1,6,7 };
			int Arg3 = 10;
			double Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RadioRange ___test;
	___test.run_test(-1);

#if 0
	for (int t = 0; t < 10000; ++t) {
		int N = 3;
		vector<int> x(N), y(N), r(N);
		int z = (rand() * 10) / (RAND_MAX + 1) + 1;
		for (int i = 0; i < N; ++i) {
			x[i] = (rand() * 20) / (RAND_MAX + 1) - 10;
			y[i] = (rand() * 20) / (RAND_MAX + 1) - 10;
			r[i] = (rand() * 10) / (RAND_MAX + 1) + 1;
		}
		double a = ___test.RadiusProbability2(x, y, r, z);
		double b = ___test.RadiusProbability(x, y, r, z);
		if (fabs(b - a) > 1.0e-5) {
			cout << "Z=" << z << ", mine=" << a << ", target=" << b << endl;
			cout << "X:";
			for (int a : x) {
				cout << " " << a;
			}
			cout << endl;
			cout << "Y:";
			for (int a : y) {
				cout << " " << a;
			}
			cout << endl;
			cout << "R:";
			for (int a : r) {
				cout << " " << a;
			}
			cout << endl;
			break;
		}
	}
#endif

}
// END CUT HERE
