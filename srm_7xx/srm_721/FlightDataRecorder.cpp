// BEGIN CUT HERE
/*
SRM 721 Div2 Easy (250)

PROBLEM STATEMENT
A Flight Data Recorder is a device that records lots of parameters during a flight.
In this task you are going to use some of those parameters to calculate the distance between the start point and the end point of the flight.

The whole flight consists of one or more segments.
During each segment the plane was heading in a fixed direction.
For each segment, you are given the direction and the distance traveled.
More precisely, you are given two vector <int>s: heading and distance.
For each valid i: during segment i of the flight the plane traveled in the direction heading[i] and the distance it traveled was distance[i].
The heading is an angle in degrees between North and the direction of flight, measured in clockwise direction.
For example, 0 means North, 90 means East, 180 means South, and 270 means West.

Assume that the airplane is a point moving in a two-dimensional plane.
Also, assume that between the segments the airplane can change its heading in an instant.

Calculate and return the distance between the start and the end of the flight.


DEFINITION
Class:FlightDataRecorder
Method:getDistance
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double getDistance(vector <int> heading, vector <int> distance)


NOTES
-Your answer will be considered correct if its absolute or relative error does not exceed 10^(-9).


CONSTRAINTS
-heading will contain between 1 and 50 elements, inclusive.
-heading and distance will contain the same number of elements.
-Each element in heading will be between 0 and 359, inclusive.
-Each element in distance will be between 1 and 1,000, inclusive.


EXAMPLES

0)
{90,0}
{3,4}

Returns: 5.0

The airplane flew 3 units of distance towards the East and then 4 units of distance towards the North.
From the Pythagorean theorem we know that the distance between the start and the end of the flight is sqrt(3*3 + 4*4) = 5.


1)
{37,37,37,37}
{1,10,100,1000}

Returns: 1111.0

The heading never changed, so the answer is 1+10+100+1000.


2)
{0,120,240,0,120,240}
{999,999,999,999,999,999}

Returns: 6.431098710768743E-13

The airplane returned back to the start point.


3)
{76,321,214,132,0,359,74,65,213}
{621,235,698,1,35,658,154,426,965}

Returns: 153.54881555325184


4)
{0}
{1}

Returns: 1.0

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FlightDataRecorder {
public:
	double getDistance(vector <int> heading, vector <int> distance) {
		double x = 0, y = 0;
		for (int i = 0; i < (int)heading.size(); ++i) {
			double r = (2.0 * M_PI * heading[i]) / 360.0;
			x += distance[i] * cos(r);
			y += distance[i] * sin(r);
		}
		return sqrt(x * x + y * y);
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (abs(Expected - Received) <= 1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {90,0};
			int Arr1[] = {3,4};
			double Arg2 = 5.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getDistance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {37,37,37,37};
			int Arr1[] = {1,10,100,1000};
			double Arg2 = 1111.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getDistance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,120,240,0,120,240};
			int Arr1[] = {999,999,999,999,999,999};
			double Arg2 = 6.431098710768743E-13;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getDistance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {76,321,214,132,0,359,74,65,213};
			int Arr1[] = {621,235,698,1,35,658,154,426,965};
			double Arg2 = 153.54881555325184;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getDistance(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arr1[] = {1};
			double Arg2 = 1.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, getDistance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FlightDataRecorder ___test;
	___test.run_test(-1);
}
// END CUT HERE
