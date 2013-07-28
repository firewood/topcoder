// BEGIN CUT HERE
/*
SRM 585 Div2 Medium (500)

PROBLEM STATEMENT
There are some cities and some roads connecting them together.
The road network has the topology of a perfect binary tree (see below for a picture), in which the cities are nodes and the roads are edges.

You are given the int treeHeight giving the height of the tree.
(The height of a perfect binary tree is the number of edges on the path between the root node and any leaf node.)
Thus, there are 2^(treeHeight+1)-1 cities and 2^(treeHeight+1)-2 roads in total.

The picture below shows how the road network looks like when treeHeight = 2.

We want to send some cars into the road network.
Each car will be traveling from its starting city to its destination city without visiting the same city twice.
(Note that the route of each car is uniquely determined by its starting and its destination city.)
It is possible for the starting city to be equal to the destination city, in that case the car only visits that single city.

Our goal is to send out the cars in such a way that each city will be visited by exactly one car. Compute and return the smallest number of cars we need in order to do so.


DEFINITION
Class:TrafficCongestionDivTwo
Method:theMinCars
Parameters:int
Returns:long long
Method signature:long long theMinCars(int treeHeight)


NOTES
-The answer will always fit into a 64-bit signed integer data type.


CONSTRAINTS
-treeHeight will be between 0 and 60, inclusive.


EXAMPLES

0)
1

Returns: 1

In this case, one car can visit all the cities.


1)
2

Returns: 3

Here is one way to visit all cities exactly once by three cars:


2)
3

Returns: 5


3)
10

Returns: 683


4)
60

Returns: 768614336404564651

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

class TrafficCongestionDivTwo {
public:
	long long theMinCars(int treeHeight) {
		LL ans = 1;
		LL x = 1LL << treeHeight;
		while (x > 3) {
			ans += (x >> 1);
			x >>= 2;
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
			int Arg0 = 1;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			long long Arg1 = 3LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			long long Arg1 = 5LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			long long Arg1 = 683LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 60;
			long long Arg1 = 768614336404564651LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arg0 = 4;
			long long Arg1 = 11LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;



		if ((Case == -1) || (Case == n)){
			int Arg0 = 0;
			long long Arg1 = 1LL;

			verify_case(n, Arg1, theMinCars(Arg0));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TrafficCongestionDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
