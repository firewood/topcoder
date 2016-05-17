// BEGIN CUT HERE
/*
SRM 690 Div2 Medium (500)

PROBLEM STATEMENT
Cucumber Boy is trying to be elected to the city council.
In order to achieve that, he needs to show that he has a lot of support in some part of the city.

The city is divided into N districts.
These are numbered from 0 to N-1.
For each i, there are A[i] voters in district i, and out of them B[i] support Cucumber Boy.

Cucumber Boy must choose a part of the city: K or more districts with consecutive numbers.
Cucumber Boy wants to maximize the proportion of votes in his favor.
Formally, Cucumber Boy wants to maximize the value X/Y, where Y is the total number of voters in the chosen districts and X is the number of Cucumber Boy's supporters among them.

You are given the vector <int>s A and B with N elements each.
You are also given the int K.
Compute and return a real number: the largest value X/Y that can be achieved.

DEFINITION
Class:GerrymanderEasy
Method:getmax
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double getmax(vector <int> A, vector <int> B, int K)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-A will contain between 1 and 1,000 elements, inclusive.
-A and B will contain the same number of elements.
-For each i, A[i] will be between 1 and 10,000, inclusive.
-For each i, B[i] will be between 0 and A[i], inclusive.
-K will be between 1 and the number of elements in A, inclusive.


EXAMPLES

0)
{5,1,2,7}
{4,0,2,2}
2

Returns: 0.75

The optimal solution is to choose districts 0, 1, and 2.
The total number of voters will be Y = 5+1+2 = 8.
The total number of Cucumber Boy's supporters will be X = 4+0+2 = 6.
Hence, the proportion of votes in Cucumber Boy's favor is X/Y = 0.75.

Note that the chosen districts must have consecutive numbers.
We are not allowed to choose only districts 0 and 2.


1)
{12,34,56,78,90}
{1,1,1,1,1}
1

Returns: 0.08333333333333333


2)
{10000,10000,10000,10000,10000,10000,10000,10000,10000,10000}
{3,1,4,1,5,9,2,6,5,3}
5

Returns: 5.4E-4


3)
{123,4,46,88,22,34,564,87,56,311,886}
{0,0,0,0,0,0,0,0,0,0,0}
1

Returns: 0.0

Sometimes the answer will be 0.

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class GerrymanderEasy {
public:
	double getmax(vector <int> A, vector <int> B, int K) {
		double ans = 0;
		for (int i = 0; (i + K) <= (int)A.size(); ++i) {
			for (int k = K; (i + k) <= (int)A.size(); ++k) {
				int a = accumulate(A.begin() + i, A.begin() + i + k, 0);
				int b = accumulate(B.begin() + i, B.begin() + i + k, 0);
				ans = max(ans, (double)b / a);
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5,1,2,7};
			int Arr1[] = {4,0,2,2};
			int Arg2 = 2;
			double Arg3 = 0.75;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {12,34,56,78,90};
			int Arr1[] = {1,1,1,1,1};
			int Arg2 = 1;
			double Arg3 = 0.08333333333333333;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
			int Arr1[] = {3,1,4,1,5,9,2,6,5,3};
			int Arg2 = 5;
			double Arg3 = 5.4E-4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {123,4,46,88,22,34,564,87,56,311,886};
			int Arr1[] = {0,0,0,0,0,0,0,0,0,0,0};
			int Arg2 = 1;
			double Arg3 = 0.0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg3, getmax(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GerrymanderEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
