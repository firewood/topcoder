// BEGIN CUT HERE
/*
SRM 645 Div2 Medium (500)

PROBLEM STATEMENT
Janusz works in roller coaster maintenance.
The station of the roller coaster is a long straight segment of railroad tracks.
There are some cars on those tracks.
The cars are currently not attached to each other, and there may be gaps between some of them.
Janusz has to push them all together and connect them into a train.

You are given the vector <int>s positions and lengths.
For each valid i, there is a car that is lengths[i] meters long and starts positions[i] meters from the beginning of the station.
(In other words, the coordinates currently occupied by this car are in the interval from positions[i] to positions[i]+lengths[i].)

Moving a single car one meter in either direction costs Janusz one unit of energy.
Compute the smallest total amount of energy sufficient to push all cars together.
In the final configuration the cars must be located one after another with no gaps between them.

(Note that there is no restriction on the movement of cars or on the final position of the train. 
Janusz may push the cars in any order, and he may even push some cars by a non-integer number of meters if he wants to.)

DEFINITION
Class:ConnectingCars
Method:minimizeCost
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long minimizeCost(vector <int> positions, vector <int> lengths)


NOTES
-You may assume that the optimal answer is always an integer that fits into a signed 64-bit integer data type.


CONSTRAINTS
-lengths and positions will have the same number of elements.
-lengths will have between 2 and 50 elements, inclusive.
-Each element of lengths and positions will be between 1 and 10^9, inclusive.
-The segments occupied by the cars may touch but they will not overlap.


EXAMPLES

0)
{1, 3, 10, 20}
{2, 2, 5, 3}

Returns: 15

There are four cars.
The intervals currently occupied by the cars are (1,3), (3,5), (10,15), and (20,23).
In one optimal solution Janusz would move each of the first two cars three meters to the right, the third car two meters to the left, and the fourth car seven meters to the left.
At the end, the cars occupy the intervals (4,6), (6,8), (8,13), and (13,16).
Total energy spent: 3+3+2+7 = 15.


1)
{100, 50, 1}

{10, 2, 1}

Returns: 96

There are three cars.
The gaps between consecutive cars have 48 meters each.
The best solution is to keep the middle car in place and to push the other two towards it.
This requires 48+48 = 96 units of energy.


2)
{4, 10, 100, 13, 80}
{5, 3, 42, 40, 9}

Returns: 66


3)
{5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427}
{42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540}

Returns: 1009957100

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;
typedef vector<LLLL> LLLLVec;

class ConnectingCars {

public:
	long long minimizeCost(vector <int> positions, vector <int> lengths) {
		LL N = positions.size();
		LLLLVec v;
		for (LL i = 0; i < N; ++i) {
			v.push_back(LLLL(positions[i], lengths[i]));
		}
		sort(v.begin(), v.end());
		LL offset[60] = {};
		for (LL i = 1; i < N; ++i) {
			offset[i] = offset[i-1] + v[i-1].second;
		}
		LL ans = 0;
		for (LL i = 0; i < N; ++i) {
			LL pos = v[N / 2].first - offset[N / 2] + offset[i];
			ans += abs(v[i].first - pos);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 3, 10, 20};
			int Arr1[] = {2, 2, 5, 3};
			long long Arg2 = 15LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 50, 1}
;
			int Arr1[] = {10, 2, 1};
			long long Arg2 = 96LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {4, 10, 100, 13, 80};
			int Arr1[] = {5, 3, 42, 40, 9};
			long long Arg2 = 66LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427};
			int Arr1[] = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540};
			long long Arg2 = 1009957100LL;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, minimizeCost(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ConnectingCars ___test;
	___test.run_test(-1);
}
// END CUT HERE
