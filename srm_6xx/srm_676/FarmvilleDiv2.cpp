// BEGIN CUT HERE
/*
SRM 676 Div2 Easy (250)

PROBLEM STATEMENT

Farmer John recently found out about a popular online farming game.

There are n types of plants in the game.
The types are numbered 0 through n-1.
At the beginning of the game, Farmer John is given one seed of each plant type.

There is a single plot of land.
At any time the plot can only contain at most one plant.
Whenever the plot is empty, Farmer John can plant one of the seeds.
Once a seed of type i is planted, it takes time[i] seconds until it grows into a fully developed plant.
When that happens, Farmer John will harvest the plant and the plot will become empty again.
Planting a seed and harvesting a plant happens instanteously.

Farmer John also has budget coins.
He can spend these coins to make his plants grow faster.
For each i, Farmer John may pay cost[i] coins to reduce time[i] by 1.
Farmer John may pay for the same plant multiple times, each time decreasing its growing time by 1.
Obviously, the growing time cannot be reduced below 0.

You are given the vector <int>s time and cost with n elements each, and the int budget.
Determine and return the minimum amount of time in which Farmer John can grow a single plant of each type.


DEFINITION
Class:FarmvilleDiv2
Method:minTime
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int minTime(vector <int> time, vector <int> cost, int budget)


NOTES
-The value of n is not given as a separate argument. Instead, you can determine it as the number of elements in time.


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-time,cost will have exactly n elements.
-Each element of time,cost will be between 1 and 100, inclusive.
-budget will be between 1 and 5,000, inclusive.


EXAMPLES

0)
{100}
{1}
26

Returns: 74

In this case, we have a single plant that takes 100 seconds to grow. We can reduce the time it takes to grow by 1 second at a cost of 1 coin. Since we have 26 coins, we can use all our coins to reduce the time it takes the plant to grow to only 74 seconds.


1)
{100}
{1}
101

Returns: 0


2)
{2,1}
{1,1}
3

Returns: 0

Here we have two plants.
Without payments, plant 0 will grow in 2 seconds and plant 1 will grow in 1 second.
We have a budget of 3 coins.
We can pay 1+1 to decrease the growing time of plant 0 from 2 to 0.
We can then pay 1 to decrease the growing time of plant 1 from 1 to 0.


3)
{1,2,3,4,5}
{5,4,3,2,1}
15

Returns: 6


4)
{100,100,100,100,100,100,100,100,100,100}
{2,4,6,8,10,1,3,5,7,9}
5000

Returns: 50


5)
{30,40,20,10}
{10,20,30,40}
5

Returns: 100

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FarmvilleDiv2 {
public:
	int minTime(vector <int> time, vector <int> cost, int budget) {
		vector<pair<int, int> > v;
		for (int i = 0; i != time.size(); ++i) {
			v.push_back(make_pair(cost[i], time[i]));
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for (int i = 0; i != v.size(); ++i) {
			int x = min(v[i].second, budget / v[i].first);
			ans += v[i].second - x;
			budget -= x * v[i].first;
		}
		return ans;
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
			int Arr0[] = {100};
			int Arr1[] = {1};
			int Arg2 = 26;
			int Arg3 = 74;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minTime(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100};
			int Arr1[] = {1};
			int Arg2 = 101;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minTime(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,1};
			int Arr1[] = {1,1};
			int Arg2 = 3;
			int Arg3 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minTime(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5};
			int Arr1[] = {5,4,3,2,1};
			int Arg2 = 15;
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minTime(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100,100,100,100,100,100,100,100,100,100};
			int Arr1[] = {2,4,6,8,10,1,3,5,7,9};
			int Arg2 = 5000;
			int Arg3 = 50;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minTime(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {30,40,20,10};
			int Arr1[] = {10,20,30,40};
			int Arg2 = 5;
			int Arg3 = 100;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, minTime(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FarmvilleDiv2 ___test;
	___test.run_test(-1);
}
// END CUT HERE
