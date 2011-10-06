// BEGIN CUT HERE 
/*
// SRM 503 Div2 Hard (900)
// PROBLEM STATEMENT
// The Grid Kingdom lies on a plane. There are N cities and M villages in the Grid Kingdom, each is a point on the plane. The i-th city is located at coordinates (cityX[i], cityY[i]) and the i-th village is located at coordinates (villageX[i], villageY[i]). Initially, there are no roads in the kingdom, so no village is initially connected to any city.


To improve this, the king has ordered that each village shall be connected to a city by a system of roads. The scheme for building the roads is as follows: 

While there exists a village that is not connected to any city:

Pick one unconnected village, call it V.
Select a point, X, which is either a city or a village-that-is-already-connected-to-a-city.
Construct a road from V to X. The length of this road is equal to the Euclidean Distance between points V and X. V is now connected to a city.

You are the king's advisor (for the day) and are in charge of applying the scheme above such that the total length of the constructed roads is minimum. Return this total length.

DEFINITION
Class:KingdomXCitiesandVillagesAnother
Method:determineLength
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY)


NOTES
-The Euclidean distance between two points (X1, Y1) and (X2, Y2) is defined as the square root of ((X1-X2)^2 + (Y1-Y2)^2).
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-cityX will contain between 1 and 50 elements, inclusive.
-cityY will contain the same number of elements as cityX.
-Each element in cityX and cityY will be between 0 and 1,000,000, inclusive.
-villageX will contain between 1 and 50 elements, inclusive.
-villageY will contain the same number of elements as villageX.
-Each element in villageX and villageY will be between 0 and 1,000,000, inclusive.
-The location of all cities will be distinct.
-The location of all villages will be distinct.
-There will be no pair of city and village that is located at the same location.


EXAMPLES

0)
{1}
{1}
{2,3}
{1,1}

Returns: 2.0

If you pick village 0 first, the total length is 2.0. Otherwise, it's 3.0. So, the minimum possible total length is 2.0

1)
{1,2}
{1,1}
{1,2}
{2,2}

Returns: 2.0



2)
{0}
{0}
{2}
{2}

Returns: 2.8284271247461903



*/
#include <string>
// END CUT HERE
#line 77 "KingdomXCitiesandVillagesAnother.cpp"
#include <math.h>
#include <list>
#include <vector>

using namespace std;

struct XY {
	int x;
	int y;
};

typedef vector<int> VI;
typedef list<XY> LXY;


class KingdomXCitiesandVillagesAnother {
	public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
		LXY cities, villages;
		VI::const_iterator x, y;
		for (x = cityX.begin(), y = cityY.begin(); x != cityX.end(); ++x, ++y) {
			XY city = {*x, *y};
			cities.push_back(city);
		}
		for (x = villageX.begin(), y = villageY.begin(); x != villageX.end(); ++x, ++y) {
			XY village = {*x, *y};
			villages.push_back(village);
		}
		double total = 0.0;
		while (villages.size() > 0) {
			double distance = 0.0;
			LXY::iterator it = findNearestVillage(cities, villages, distance);
			cities.push_back(*it);
			villages.erase(it);
			total += distance;
		}
		return total;
	}
	static LXY::iterator findNearestVillage(const LXY &cities, LXY &villages, double &distance) {
		LXY::iterator nearest = villages.end();
		LXY::iterator village;
		for (village = villages.begin(); village != villages.end(); ++village) {
			LXY::const_iterator city;
			for (city = cities.begin(); city != cities.end(); ++city) {
				double d = getDistance(*city, *village);
				if (nearest == villages.end() || d < distance) {
					nearest = village;
					distance = d;
				}
			}
		}
		return nearest;
	}
	static double getDistance(const XY &a, const XY &b) {
		double x = a.x - b.x;
		double y = a.y - b.y;
		return sqrt(x * x + y * y);
	}
};

// BEGIN CUT HERE
template <typename T> static T __str_to_val(const char *p)
{
	return p;
}
template <> static int __str_to_val(const char *p)
{
	return atoi(p);
}
template <typename T> vector<T> getVector(const char *s)
{
	static const int buffer_size = 1024000;
	static char buffer[buffer_size];
	strcpy(buffer, s);
	vector <T> v;
	char *p = strtok(buffer, " ,");
	while (p) {
		v.push_back(__str_to_val<T>(p));
		p = strtok(NULL, " ,");
	}
	return v;
}

static void Test(const char *cx, const char *cy, const char *vx, const char *vy, double expected)
{
	VI CX = getVector<int>(cx);
	VI CY = getVector<int>(cy);
	VI VX = getVector<int>(vx);
	VI VY = getVector<int>(vy);
	KingdomXCitiesandVillagesAnother ___test;
	double result = ___test.determineLength(CX, CY, VX, VY);
	printf("result: %s, %f\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("1", "1", "2,3", "1,1", 2.0);
	Test("920978", "375185", "228692", "991009", 926552.2676956762);
	return 0;
}
// END CUT HERE
