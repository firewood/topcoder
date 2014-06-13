// BEGIN CUT HERE
/*
SRM 621 Div1 Easy (250)

PROBLEM STATEMENT
Note that the return value is a floating-point number and that in this problem the allowed absolute or relative error has been increased to 1e-6.

This problem takes place in a plane.
Nikola works at a radio station that is located in the point (0, 0).
You can hear the station if and only if you are within a circle with center at (0, 0) and some unknown radius.

There are some cities near the station.
Each city has the shape of a circle with some positive integer radius.
Cities may partially or even completely overlap each other, and some of them may contain the radio station.
You are given the description of all cities as vector <int>s X, Y, and R.
For each valid i, there is a city with center at (X[i], Y[i]) and radius R[i].

The radius of our radio station is bad if there is a city that is only partially covered by the radio signal.
Otherwise, the radius is good.
In other words, if there is a point in a city where you can listen to our radio and another point in the same city where you cannot do so, the radius is bad.
A radius is good if and only if each city is either covered completely by radio signal, or not covered at all.

You are given a int Z.
The radius of our radio station is a real number chosen uniformly at random from the range [0, Z].
Return the probability that the radius is good.


DEFINITION
Class:RadioRange
Method:RadiusProbability
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:double
Method signature:double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z)


NOTES
-Your return value must have an absolute or relative error less than 1e-6.


CONSTRAINTS
-X will contain between 1 and 100 elements, inclusive.
-X, Y, and R will each contain the same number of elements.
-Each element of X will be between -10^9 and 10^9, inclusive.
-Each element of Y will be between -10^9 and 10^9, inclusive.
-Each element of R will be between 1 and 10^9, inclusive.
-Z will be between 1 and 10^9, inclusive.


EXAMPLES

0)
{0}
{0}
{5}
10

Returns: 0.5

Our radio station is in the center of a city with radius 5, and we are choosing the radius for the station uniformly at random from [0,10].
Radii in [0,5) are all bad, because people in the center of the city can hear our radio but people on its boundary cannot.
Radii in [5,10] are all good, as the entire city is covered.
Hence, the probability of having a good radius is 5/10 = 0.5.


1)
{0}
{0}
{10}
10

Returns: 0.0

Our radio station is in the center of a city with radius 10, and we are choosing the radius for the station uniformly at random from [0,10].
In this case, the only good radius is 10, but the probability that it will be chosen is zero.


2)
{10}
{10}
{10}
10

Returns: 0.4142135623730951

The center of the city is at (10, 10) and its radius is 10.
The good radii for our station are those where the city is not covered at all.
These are the radii from 0 to approximately 4.14.


3)
{11, -11, 0, 0}
{0, 0, 11, -11}
{10, 10, 10, 10}
31

Returns: 0.3548387096774194

Here we have four cities.
They are located to the north, south, east, and west of the station.
A radius is good if it lies in [0,1) or in [21,31].


4)
{100}
{100}
{1}
10

Returns: 1.0

It is possible that some cities will not be covered even if the radius of our radio station is Z.


5)
{1000000000}
{1000000000}
{1000000000}
1000000000

Returns: 0.41421356237309503


6)
{20, -20, 0, 0}
{0, 0, 20, -20}
{50, 50, 50, 50}
100

Returns: 0.3


7)
{0, -60, -62, -60, 63, -97}
{-72, 67, 61, -8, -32, 89}
{6, 7, 8, 7, 5, 6}
918

Returns: 0.9407071068962471

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
