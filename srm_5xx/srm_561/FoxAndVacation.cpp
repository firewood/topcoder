// BEGIN CUT HERE
/*
// SRM 561 Div2 Easy (250)

// PROBLEM STATEMENT
// Fox Ciel is planning to visit the Tourist Kingdom for total days.
This kingdom is full of lovely cities.
During her stay Ciel would like to visit as many different cities as possible.
She cannot visit more than one city on the same day.


Additionally, different cities may require her to stay for a different number of days.
For each i, city i only counts as visited if Ciel spends at least d[i] days in the city.


You are given the int total and the vector <int> d.
Return the maximal number of cities she can visit during her vacation.


DEFINITION
Class:FoxAndVacation
Method:maxCities
Parameters:int, vector <int>
Returns:int
Method signature:int maxCities(int total, vector <int> d)


NOTES
-When solving the task, ignore travel times. (Fox Ciel always travels at night, and she can travel between any two cities very quickly.)


CONSTRAINTS
-total will be between 1 and 50, inclusive.
-d will contain between 1 and 50 elements, inclusive.
-Each element of d will be between 1 and 50, inclusive.


EXAMPLES

0)
5
{2,2,2}

Returns: 2

Fox Ciel's vacation lasts for 5 days. She needs at least 2 days to visit each of the cities, so she can visit at most 2 of them.


1)
5
{5,6,1}

Returns: 1

She can only visit one city: either city 0, or city 2.


2)
5
{6,6,6}

Returns: 0

This time the poor Fox Ciel cannot visit any city during her summer vacation.


3)
6
{1,1,1,1,1}

Returns: 5

In this test case Ciel can visit all five cities.
Note that at the end of her trip each city either does count as visited, or it does not -- there is no way to "visit" the same city twice.


4)
10
{7,1,5,6,1,3,4}

Returns: 4


5)
50
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}

Returns: 9


6)
21
{14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14}

Returns: 6

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class FoxAndVacation {

public:
	int maxCities(int total, vector <int> d) {
		sort(d.begin(), d.end());
		int res = 0;
		int t = 0;
		int i;
		for (i = 0; i < (int)d.size(); ++i) {
			if ((t+d[i]) <= total) {
				t += d[i];
				++res;
			}
		}
		return res;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {2,2,2};
			int Arg2 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {5,6,1};
			int Arg2 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 5;
			int Arr1[] = {6,6,6};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {1,1,1,1,1};
			int Arg2 = 5;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {7,1,5,6,1,3,4};
			int Arg2 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arg0 = 50;
			int Arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
			int Arg2 = 9;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

		// test_case_6
		if ((Case == -1) || (Case == n)){
			int Arg0 = 21;
			int Arr1[] = {14,2,16,9,9,5,5,23,25,20,8,25,6,12,3,2,4,5,10,14,19,12,25,15,14};
			int Arg2 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, maxCities(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndVacation ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
