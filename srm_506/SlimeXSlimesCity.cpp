// BEGIN CUT HERE
/*
// SRM 506 Div2 Middle (500)
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


You are playing a game titled Slimes City. You are managing several towns in this game.


You have N towns in a region. For simplicity, they are named 0 through N-1. The population of town i is population[i].


You are going to merge these towns to form one big city. The procedure is as follows. While the number of towns is more than one, pick two different towns, i and j. Delete these two towns and form a new one, with a population equal to the sum of the populations of towns i and j. The name of the newly formed town will be i if i had a larger population than j, or j if j had a larger population than i. If both of the original towns had the same population, either name can be chosen.


When this process ends, one town remains. That town's name becomes the city's name. Return the number of different possible names for the resulting city.

DEFINITION
Class:SlimeXSlimesCity
Method:merge
Parameters:vector <int>
Returns:int
Method signature:int merge(vector <int> population)


CONSTRAINTS
-population will contain between 2 and 50 elements, inclusive.
-Each element of population will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2, 3, 4}

Returns: 2



If towns 0 and 1 are merged first, the city's name will be 1. Otherwise the city's name will be 2. It is illustrated by the following image that shows the only three possible ways to merge the cities.




1)
{1, 2, 3}

Returns: 2



If town 2 is merged first (with town 0 or 1), the city's name will be 2. Otherwise, if towns 0 and 1 are merged first (to form a new town named 1, with a population of 3) and then the resulting town is merged with town 2, the city can be named either 1 or 2.  It's not possible for the city to be named 0.



2)
{8,2,3,8}

Returns: 2

There may be multiple towns with the same population.

3)
{1000000000, 999999999, 999999998, 999999997}

Returns: 3



4)
{1,1,1}

Returns: 3



5)
{1, 2, 4, 6, 14, 16, 20}

Returns: 3



*/
#line 86 "SlimeXSlimesCity.cpp"
// END CUT HERE
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long __ll;

class SlimeXSlimesCity {
	public:
	int merge(vector <int> population) {
		sort(population.begin(), population.end());
		int result = population.size();

		int max_index = (int)population.size() - 1;
		int i;
		for (i = 1; i <= max_index; ++i) {
			__ll sum = 0;

			int j;
			for (j = 0; j < i; ++j) {
				sum += population[j];
			}
			if (sum < (__ll)population[i]) {
				result = population.size() - i;
			}
		}

		return result;
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

static void Test(const char *seq, int expected)
{
	vector <int> v = getVector<int>(seq);
	SlimeXSlimesCity ___test;
	int result = ___test.merge(v);
	printf("result: %s, %d\n", result == expected ? "OK" : "FAILED", result);
}

int main() {
	Test("2,3,4", 2);
	Test("1,2,3", 2);
	Test("8,2,3,8", 2);
	Test("1000000000,999999999,999999998,999999997", 3);
	Test("1,1,1", 3);
	Test("1,2,4,6,14,16,20", 3);


	Test("1,2", 1);
	Test("1,1", 2);


	return 0;
}
// END CUT HERE
