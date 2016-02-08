// BEGIN CUT HERE
/*
SRM 681 Div1 Easy (300)

PROBLEM STATEMENT
George is in charge of building a fleet of spaceships.
Each spaceship consists of m different parts, labeled from 1 to m.

George has no parts at the moment but he has an unlimited supply of money.
There are n workshops that can produce the parts he needs.
The workshops can be described by the vector <int>s k, a, and b.
For each valid i, there is a workshop that has the following limits:

The workshop has a limited amount of resources and therefore it can produce at most k[i] parts in total.
The workshop can only produce parts with numbers between a[i] and b[i], inclusive.

Note that each workshop can create multiple copies of the same part, as long as the total number of parts produced by that workshop doesn't exceed k[i].

Given these constraints, determine the maximum number of spaceships George can build.


DEFINITION
Class:FleetFunding
Method:maxShips
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxShips(int m, vector <int> k, vector <int> a, vector <int> b)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-m will be between 1 and 10^5, inclusive.
-k,a,b will have exactly n elements each.
-Each element of k will be between 1 and 10^6, inclusive.
-Each element of a,b will be between 1 and m, inclusive.
-For each integer i from 0 to n-1, inclusive, a[i] will be less than or equal to b[i].


EXAMPLES

0)
3
{2,2,2}
{1,2,1}
{3,3,2}

Returns: 2

In this test case, each spaceship requires parts 1, 2, and 3.
We have the following workshops:

Workshop 0 can produce at most 2 parts, each with a label between 1 and 3, inclusive.
Workshop 1 can produce at most 2 parts, each with a label between 2 and 3, inclusive.
Workshop 2 can produce at most 2 parts, each with a label between 1 and 2, inclusive.

We can build two complete spaceships.
One possible solution:

Workshop 0 will produce a part with label 1 and a part with label 3.
Workshop 1 will produce a part with label 2 and a part with label 3.
Workshop 2 will produce a part with label 1 and a part with label 2.

Another possible solution:

Workshop 0 will produce two parts with label 2.
Workshop 1 will produce two parts with label 3.
Workshop 2 will produce two parts with label 1.


1)
1
{10,9,8,7,6,5,4,3,2,1}
{1,1,1,1,1,1,1,1,1,1}
{1,1,1,1,1,1,1,1,1,1}

Returns: 55


2)
10
{2,4,6,8,10,1,3,5,7,9}
{1,2,3,4,5,6,7,8,9,10}
{1,2,3,4,5,6,7,8,9,10}

Returns: 1

Here we can buy a lot of different parts.
The bottleneck is part number 6.
This can only be produced by workshop 5, and this workshop can only build us a single copy of this part.
Thus, we can only build a single spaceship.


3)
84457
{374778,169109,529984,498638,29462,465769,29285,394948,307944,459189,
349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370,
574862,337134,965567,32223,935678,389898,973497,990575,483190,122899,
857994,991217,149619,415870}
{92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851,
3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998}
{81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457,
81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445,
84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456}

Returns: 186


4)
2
{1000000,1000000,1000000,1000000,1000000}
{1,1,1,2,2}
{1,1,2,2,2}

Returns: 2500000

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, int> III;

class FleetFunding {

	int M;
	vector<III> V;

	bool possible(int x) {
		vector<III> v = V;
		for (int a = 1; a <= M; ++a) {
			int r = x;
			for (int i = 0; r > 0 && i != v.size(); ++i) {
				if (v[i].first.second <= a && a <= v[i].first.first && v[i].second > 0) {
					int c = min(r, v[i].second);
					r -= c;
					v[i].second -= c;
				}
			}
			if (r > 0) {
				return false;
			}
		}
		return true;
	}

public:
	int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
		M = m;
		V.clear();
		for (int i = 0; i != k.size(); ++i) {
			V.push_back(III(II(b[i], a[i]), k[i]));
		}
		sort(V.begin(), V.end());

		int low = 0, high = 1 << 30;
		while ((high - low) > 1) {
			int mid = (low + high) / 2;
			if (!possible(mid)) {
				high = mid;
			} else {
				low = mid;
			}
		}
		return low;
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
			int Arg0 = 3;
			int Arr1[] = {2,2,2};
			int Arr2[] = {1,2,1};
			int Arr3[] = {3,3,2};
			int Arg4 = 2;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {10,9,8,7,6,5,4,3,2,1};
			int Arr2[] = {1,1,1,1,1,1,1,1,1,1};
			int Arr3[] = {1,1,1,1,1,1,1,1,1,1};
			int Arg4 = 55;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 10;
			int Arr1[] = {2,4,6,8,10,1,3,5,7,9};
			int Arr2[] = {1,2,3,4,5,6,7,8,9,10};
			int Arr3[] = {1,2,3,4,5,6,7,8,9,10};
			int Arg4 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 84457;
			int Arr1[] = {374778,169109,529984,498638,29462,465769,29285,394948,307944,459189,
349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370,
574862,337134,965567,32223,935678,389898,973497,990575,483190,122899,
857994,991217,149619,415870};
			int Arr2[] = {92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851,
3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998};
			int Arr3[] = {81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457,
81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445,
84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456};
			int Arg4 = 186;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arr1[] = {1000000,1000000,1000000,1000000,1000000};
			int Arr2[] = {1,1,1,2,2};
			int Arr3[] = {1,1,2,2,2};
			int Arg4 = 2500000;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FleetFunding ___test;
	___test.run_test(-1);
}
// END CUT HERE
