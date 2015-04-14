// BEGIN CUT HERE
/*
SRM 647 Div2 Medium (500)

PROBLEM STATEMENT

You are a traveling salesman.
You have already heard a lot about how hard the problems of a traveling salesman can be.
Luckily, the one you currently have seems easier.

There are M cities where you can sell products.
The cities are conveniently numbered 1 through M.

You have a case that contains multiple items.
Each of those items can only be sold in one of the cities.
You are given information about those items in vector <int>s profit and city.
For each valid i, you have an item that can be sold in city[i], and doing so would bring you profit[i] dollars of profit.
Obviously, you can only sell each item at most once.

You have already planned your business trip: a sequence of cities you are going to visit.
These are given in the vector <int> visit.
Each time you visit a city you may sell at most one item.

Compute and return the maximum total profit you can obtain.


DEFINITION
Class:TravellingSalesmanEasy
Method:getMaxProfit
Parameters:int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit)


CONSTRAINTS
-M will be between 1 and 100, inclusive.
-profit will have between 1 and 2500 elements, inclusive.
-city will have exactly the same number of elements as profit.
-Each element of profit will between 1 and 100, inclusive.
-Each element of city will be between 1 and M, inclusive.
-visit will have between 1 and 2500 elements, inclusive.
-Each element of visit will be between 1 and M, inclusive. 


EXAMPLES

0)
2
{3,10}
{1,1}
{2,1}

Returns: 10


There are 2 cities, and you have 2 items. Both of these two items can only be sold to city 1, with one giving you profit 10, and the other giving profit 3.

Your trip consists of a visit to city 2 and then a visit to city 1. At city 2, you cannot sell any item, so your profit in this case is zero. At city 1, you can sell the item with profit 10. Thus, the total answer is 0+10=10, which is the maximum profit you can achieve. 


1)
1
{3,5,2,6,4}
{1,1,1,1,1}
{1,1,1}

Returns: 15

It is possible for you to visit a city multiple times. Each time you visit the city, you may sell another item.


2)
6
{77,33,10,68,71,50,89}
{4,1,5,6,2,2,1}
{6,5,5,6,4}

Returns: 155


3)
7
{22,91,53,7,80,100,36,65,92,93,19,92,95,3,60,50,39,36,2,30,63,84,2}
{5,3,4,3,6,5,6,6,5,2,7,6,3,2,6,1,7,4,6,3,7,2,5}
{5,7,1,3,6,2,5,7,3,6,3,2,7,3,1,3,1,7,2,3,1,1,3,1,6,1}

Returns: 1003


4)
85
{94,21,99,27,91,1,64,96,32,39,84,71,97,53,73,20,7,13,33,45,5,85,7,87,
94,37,48,30,5,85,47,62,91,18,71,37,7,25,75,17,40,19,89,85,86,87,45,
12,61,71,32,73,63,89,25,51,60,76,32,2,69,78,28,32,74,44,47,11,82,5,
2,28,54,35,67,44,35,6,70,66,77,7,60,67,33,66,21,91,76,75,16,79,20,24,
91,31,2,50,11,19,93,49,4,7,55,9,95,39,54,12,48,38,73,100,57,97,44,2,
2,51,40,4,51,3,95,93,56,88,60,98,67,7,99,46,71,75,24,82,87,29,92,92,
81,87,34,83,58,46,79,53,38,32,97,41,65,10,54,81,42,37,76,28,11,50,
13,29,15,99,73,72,2,81,39,75,1,54}
{72,69,19,25,3,65,10,42,37,76,29,34,41,14,46,46,37,55,30,32,84,57,74,
16,10,48,67,31,44,84,11,59,67,63,5,31,28,71,3,21,42,21,61,50,5,79,79,
27,69,33,47,70,76,70,17,73,28,64,77,84,9,6,63,71,17,71,40,9,8,16,76,
76,6,53,47,10,45,31,78,55,13,35,50,43,32,78,78,44,20,56,24,43,80,62,
72,16,5,72,67,29,11,51,64,27,7,44,59,1,40,71,64,63,67,81,72,22,73,59,
21,44,3,18,9,75,72,43,13,44,79,42,58,49,81,44,42,41,35,81,63,74,42,79,
42,39,45,49,18,73,53,36,80,34,75,57,10,79,79,33,48,18,81,3,69,36,37,
49,54,29,17,81,83,13,8,69,5,84}
{39,29,15,5,3,65,29,64,60,21,13,10,73,75,44,84,15,61,26,49,31,27,83,24,
16,55,60,74,71,53,68,15,75,15,36,4,47,9,77,45,63,32,77,84,8,68,11,5,18,
80,36,52,42,59,79,83,81,29,43,70,29,19,68,5,83,60,71,66,62,81,85,39,42,
40,69,60,34,12,2,4,31,36,81,33,71,32,68,5,30,59,61,10,71,49,63,30,62,
83,35,56,82,2,14,59,68,74,32,31,3,28,38,54,38}

Returns: 4369

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

typedef vector<int> IntVec;

class TravellingSalesmanEasy {
public:
	int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
		int ans = 0;
		IntVec v[100];
		for (int i = 0; i < (int)profit.size(); ++i) {
			v[city[i] - 1].push_back(profit[i]);
		}
		for (int i = 0; i < M; ++i) {
			sort(v[i].begin(), v[i].end());
		}
		for (int i = 0; i < (int)visit.size(); ++i) {
			IntVec &a = v[visit[i] - 1];
			if (a.size() > 0) {
				ans += a.back();
				a.pop_back();
			}
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
			int Arg0 = 2;
			int Arr1[] = {3,10};
			int Arr2[] = {1,1};
			int Arr3[] = {2,1};
			int Arg4 = 10;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arr1[] = {3,5,2,6,4};
			int Arr2[] = {1,1,1,1,1};
			int Arr3[] = {1,1,1};
			int Arg4 = 15;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {77,33,10,68,71,50,89};
			int Arr2[] = {4,1,5,6,2,2,1};
			int Arr3[] = {6,5,5,6,4};
			int Arg4 = 155;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 7;
			int Arr1[] = {22,91,53,7,80,100,36,65,92,93,19,92,95,3,60,50,39,36,2,30,63,84,2};
			int Arr2[] = {5,3,4,3,6,5,6,6,5,2,7,6,3,2,6,1,7,4,6,3,7,2,5};
			int Arr3[] = {5,7,1,3,6,2,5,7,3,6,3,2,7,3,1,3,1,7,2,3,1,1,3,1,6,1};
			int Arg4 = 1003;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 85;
			int Arr1[] = {94,21,99,27,91,1,64,96,32,39,84,71,97,53,73,20,7,13,33,45,5,85,7,87,
94,37,48,30,5,85,47,62,91,18,71,37,7,25,75,17,40,19,89,85,86,87,45,
12,61,71,32,73,63,89,25,51,60,76,32,2,69,78,28,32,74,44,47,11,82,5,
2,28,54,35,67,44,35,6,70,66,77,7,60,67,33,66,21,91,76,75,16,79,20,24,
91,31,2,50,11,19,93,49,4,7,55,9,95,39,54,12,48,38,73,100,57,97,44,2,
2,51,40,4,51,3,95,93,56,88,60,98,67,7,99,46,71,75,24,82,87,29,92,92,
81,87,34,83,58,46,79,53,38,32,97,41,65,10,54,81,42,37,76,28,11,50,
13,29,15,99,73,72,2,81,39,75,1,54};
			int Arr2[] = {72,69,19,25,3,65,10,42,37,76,29,34,41,14,46,46,37,55,30,32,84,57,74,
16,10,48,67,31,44,84,11,59,67,63,5,31,28,71,3,21,42,21,61,50,5,79,79,
27,69,33,47,70,76,70,17,73,28,64,77,84,9,6,63,71,17,71,40,9,8,16,76,
76,6,53,47,10,45,31,78,55,13,35,50,43,32,78,78,44,20,56,24,43,80,62,
72,16,5,72,67,29,11,51,64,27,7,44,59,1,40,71,64,63,67,81,72,22,73,59,
21,44,3,18,9,75,72,43,13,44,79,42,58,49,81,44,42,41,35,81,63,74,42,79,
42,39,45,49,18,73,53,36,80,34,75,57,10,79,79,33,48,18,81,3,69,36,37,
49,54,29,17,81,83,13,8,69,5,84};
			int Arr3[] = {39,29,15,5,3,65,29,64,60,21,13,10,73,75,44,84,15,61,26,49,31,27,83,24,
16,55,60,74,71,53,68,15,75,15,36,4,47,9,77,45,63,32,77,84,8,68,11,5,18,
80,36,52,42,59,79,83,81,29,43,70,29,19,68,5,83,60,71,66,62,81,85,39,42,
40,69,60,34,12,2,4,31,36,81,33,71,32,68,5,30,59,61,10,71,49,63,30,62,
83,35,56,82,2,14,59,68,74,32,31,3,28,38,54,38};
			int Arg4 = 4369;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg4, getMaxProfit(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TravellingSalesmanEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
