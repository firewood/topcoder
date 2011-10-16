// BEGIN CUT HERE 
/*
// SRM 503 Div2 Hard (900)

問題
  N個の街とM個の村がある。
  街および村が座標で与えられる。
  街からは王宮に行く道があり、村はどの街へも接続していない(道がない)。
  どの村からも直接または間接的に王宮に行けるように道を整備する。
  整備すべき最小限の長さを求める。

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
	printf("result: %s, returned %f, expected %f\n", fabs(result - expected) < 0.000000001 ? "OK" : "FAILED", result, expected);
}

int main() {
	// example 0
	Test("1", "1", "2,3", "1,1", 2.0);

	// example 1
	Test("1,2", "1,1", "1,2", "2,2", 2.0);

	// example 2
	Test("0", "0", "2", "2", 2.8284271247461903);

	Test("920978", "375185", "228692", "991009", 926552.2676956762);

	return 0;
}
// END CUT HERE
