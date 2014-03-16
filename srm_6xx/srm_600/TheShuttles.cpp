// BEGIN CUT HERE
/*
SRM 600 Div2 Easy (250)

PROBLEM STATEMENT
Note that the memory limit for all tasks in this SRM is 256 MB.

The company Manao Inc. cares for its employees and tries to provide them with as much comfort as possible. One of the services Manao Inc. provides is transportation of employees from N distant locations to the office. The locations are numbered from 0 to N-1. You are given a vector <int> cnt containing N elements. The i-th (0-based index) element of cnt is the number of employees who live near location i.

The company wants to purchase several shuttles of the same size. These shuttles will then be used for employee transportation. Each of the shuttles will only serve one particular location. Each location will be assigned the smallest number of shuttles sufficient to transport all of the employees living close to it.

The cost of a shuttle consists of the cost baseCost of its frame and some additional cost seatCost per each seat. That is, a shuttle with X seats will cost baseCost + X * seatCost. For its shuttles, Manao Inc. can choose X to be any positive integer. (But remember that all the shuttles must have the same X.) Compute and return the least amount of money the company needs to spend on the shuttles in order to provide transportation for all employees.

DEFINITION
Class:TheShuttles
Method:getLeastCost
Parameters:vector <int>, int, int
Returns:int
Method signature:int getLeastCost(vector <int> cnt, int baseCost, int seatCost)


CONSTRAINTS
-cnt will contain between 1 and 50 elements, inclusive.
-Each element of cnt will be between 1 and 100, inclusive.
-baseCost will be between 1 and 100, inclusive.
-seatCost will be between 1 and 100, inclusive.


EXAMPLES

0)
{9}
30
5

Returns: 75

Manao Inc. provides transportation for its employees from a single location. There are 9 employees living near it. A shuttle with X seats will cost the company 30 + 5X. It is optimal to buy a single shuttle with 9 seats.


1)
{9, 4}
30
5

Returns: 150

Manao Inc. provides transportation from two locations. There are 9 employees living near location 0 and 4 employees living near location 1. It is optimal to buy two shuttles with 9 seats each and send a single shuttle to each location. (Note that the shuttles we buy must all be of the same size. It is not allowed to buy one shuttle with 9 and another with 4 seats.)


2)
{9, 4}
10
5

Returns: 105

This is the same test as the previous example, but baseCost is lower. It is optimal to buy three shuttles with 5 seats each and send two shuttles to location 0 and one shuttle to location 1.


3)
{51, 1, 77, 14, 17, 10, 80}
32
40

Returns: 12096

*/
// END CUT HERE
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class TheShuttles {
public:
	int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
		int ans = 99999999;
		for (int s = 1; s <= 100; ++s) {
			int t = 0;
			for (int i = 0; i < (int)cnt.size(); ++i) {
				t += ((cnt[i] + s-1)/s) * (baseCost + seatCost * s);
			}
			ans = min(ans, t);
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
			int Arr0[] = {9};
			int Arg1 = 30;
			int Arg2 = 5;
			int Arg3 = 75;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9, 4};
			int Arg1 = 30;
			int Arg2 = 5;
			int Arg3 = 150;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9, 4};
			int Arg1 = 10;
			int Arg2 = 5;
			int Arg3 = 105;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {51, 1, 77, 14, 17, 10, 80};
			int Arg1 = 32;
			int Arg2 = 40;
			int Arg3 = 12096;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg3, getLeastCost(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheShuttles ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
