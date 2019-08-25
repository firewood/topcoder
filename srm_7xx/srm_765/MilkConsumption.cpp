// BEGIN CUT HERE
/*
SRM 765 Div2 Easy (250)

PROBLEM STATEMENT

For a presentation you are comparing the amounts of milk drank by people in various countries.
The countries are numbered 0 through N-1, for some N.
The data you have are two vector <int>s: population[i] is the number of people in country number i and totalConsumption[i] is the number of litres of milk consumed by that country last year.

Among all non-empty subsets of these countries, you are looking for the one for which the consumption per capita (i.e., the average amount of milk consumed by one person) is maximal.

Find any one such subset of countries and return a vector <int> with their numbers.


DEFINITION
Class:MilkConsumption
Method:findMaxRegion
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> findMaxRegion(vector <int> population, vector <int> totalConsumption)


NOTES
-There may be more than one correct answer. Each optimal answer will be accepted.
-The country numbers in the vector <int> you return must be distinct, but they may be in any order.


CONSTRAINTS
-population will contain between 1 and 50 elements, inclusive.
-totalConsumption will contain the same number of elements as population.
-Each element of population will be between 1 and 20,000,000, inclusive.
-Each element of totalConsumption will be between 1 and 20,000,000, inclusive.


EXAMPLES

0)
{10, 10, 10, 10}
{47, 47, 47, 47}

Returns: {2, 3, 0 }

All countries have the same population and all countries drank the same amount of milk. In this situation any non-empty subset of countries is a valid answer.


1)
{1234567, 2345678, 3456789, 4567890}
{2345678, 3456789, 4567890, 5678901}

Returns: {0 }


2)
{98, 120, 40, 135, 40}
{4606, 5167, 1880, 1351, 1879}

Returns: {0, 2 }

Together, countries 0 and 2 have 98 + 40 = 138 people and they drank a total of 4606 + 1880 = 6486 litres of milk.
Thus, this subset of countries has consumed (6486 / 138) litres of milk per capita.
No other subset of countries has consumed more milk per person, so this is one of the optimal answers.


3)
{9227465, 14930352}
{5702887, 9227465}

Returns: {1 }

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class MilkConsumption {
public:
	vector <int> findMaxRegion(vector <int> population, vector <int> totalConsumption) {
		vector<pair<double, int>> v;
		for (int i = 0; i < (int)population.size(); ++i) {
			v.push_back({ (double)totalConsumption[i] / population[i], i });
		}
		sort(v.rbegin(), v.rend());
		return { v.front().second };
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10, 10, 10, 10};
			int Arr1[] = {47, 47, 47, 47};
			int Arr2[] = {2, 3, 0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxRegion(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1234567, 2345678, 3456789, 4567890};
			int Arr1[] = {2345678, 3456789, 4567890, 5678901};
			int Arr2[] = {0 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxRegion(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {98, 120, 40, 135, 40};
			int Arr1[] = {4606, 5167, 1880, 1351, 1879};
			int Arr2[] = {0, 2 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxRegion(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9227465, 14930352};
			int Arr1[] = {5702887, 9227465};
			int Arr2[] = {1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg2, findMaxRegion(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MilkConsumption ___test;
	___test.run_test(-1);
}
// END CUT HERE
