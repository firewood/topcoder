// BEGIN CUT HERE
/*
SRM 583 Div1 Easy (250)

PROBLEM STATEMENT
Bob recently went to Mars.

There are N cities on Mars. The cities all lie on a circular railroad and they are numbered 0 through N-1 along the railroad. More precisely, there is a railroad segment that connects cities N-1 and 0, and for each i (0 <= i <= N-2) there is a railroad segment that connects cities i and i+1. Trains travel along the railroad in both directions.

You are given a vector <int> range with N elements. For each i: the set of cities that are reachable from city i by a direct train is precisely the set of cities that are within the distance range[i] of city i. (The distance between two cities is the smallest number of railroad segments one needs to travel in order to get from one city to the other. For example, if N=17 and range[2]=3, the cities directly reachable from city 2 are the cities {17,0,1,2,3,4,5}.)

You are also given ints startCity and endCity. Bob starts his tour in the city startCity and wants to end it in the city endCity. Calculate and return the minimum number of succesive direct trains he needs to take.


DEFINITION
Class:TravelOnMars
Method:minTimes
Parameters:vector <int>, int, int
Returns:int
Method signature:int minTimes(vector <int> range, int startCity, int endCity)


CONSTRAINTS
-range will contain N elements, where N is between 2 and 50, inclusive.
-Each element of range will be between 1 and 50, inclusive.
-startCity will be between 0 and N-1, inclusive.
-endCity will be between 0 and N-1, inclusive.
-startCity and endCity will be different.


EXAMPLES

0)
{2,1,1,1,1,1}
1
4

Returns: 2

Bob wants to get from city 1 to city 4.
The optimal solution is to travel from city 1 to city 0, and then (as range[0]=2) from city 0 to city 4.


1)
{2,1,1,1,1,1}
4
1

Returns: 3

This is the same test case as Example 0, only startCity and endCity have been swapped. Note that the answer is now 3 instead of 2.


2)
{2,1,1,2,1,2,1,1}
2
6

Returns: 3

Bob starts in city 2. There are two optimal routes: (2->3->5->6) and (2->1->0->6).


3)
{3,2,1,1,3,1,2,2,1,1,2,2,2,2,3}
6
13

Returns: 4

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TravelOnMars {
public:
	int minTimes(vector <int> range, int startCity, int endCity) {
		int N = (int)range.size();
		int dist[50][50];
		memset(dist, 0x3f, sizeof(dist));
		int i, j, k;
		for (i = 0; i < N; ++i) {
			for (j = -range[i]; j <= range[i]; ++j) {
				dist[i][(((i+j)%N)+N)%N] = 1;
			}
//			for (j = 0; j < N; ++j) {
//				if (min(abs(i-j), abs(i+N-j)) <= range[i]) {
//					dist[i][j] = 1;
//				}
//			}
		}
		for (k = 0; k < N; ++k) {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		return dist[startCity][endCity];
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
			int Arr0[] = {2,1,1,1,1,1};
			int Arg1 = 1;
			int Arg2 = 4;
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1,1,1,1,1};
			int Arg1 = 4;
			int Arg2 = 1;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1,1,2,1,2,1,1};
			int Arg1 = 2;
			int Arg2 = 6;
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
			int Arg1 = 6;
			int Arg2 = 13;
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50,50};
			int Arg1 = 1;
			int Arg2 = 1;
			int Arg3 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, minTimes(Arg0, Arg1, Arg2));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TravelOnMars ___test;
	___test.run_test(-1);
}
// END CUT HERE
