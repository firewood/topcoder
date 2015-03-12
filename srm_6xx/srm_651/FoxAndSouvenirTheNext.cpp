// BEGIN CUT HERE
/*
SRM 651 Div2 Medium (500)

PROBLEM STATEMENT
Fox Ciel just returned home from her trip to New Fox City.
She has brought a bunch of souvenirs.
You are given their values in a vector <int> value.


Now she wants to give each souvenir either to her mother or to her father.
She would like to divide the souvenirs in a fair way.
More precisely:

The total number of souvenirs given to her mother must be the same as the total number of souvenirs given to her father.
At the same time, the total value of souvenirs given to her mother must be the same as the total value of souvenirs given to her father.

Return "Possible" if she can reach her goal, and "Impossible" otherwise.


DEFINITION
Class:FoxAndSouvenirTheNext
Method:ableToSplit
Parameters:vector <int>
Returns:string
Method signature:string ableToSplit(vector <int> value)


CONSTRAINTS
-value will contain between 1 and 50 elements, inclusive.
-Each element in value will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,2,3,4}

Returns: "Possible"

One valid solution is to give the souvenirs with values 1 and 4 to her mother and the other two to her father. Each parent receives two souvenirs, and as 1+4 = 2+3, the total value is also the same for both parents.


1)
{1,1,1,3}

Returns: "Impossible"

There is no valid solution. Note that {1,1,1} and {3} is not a valid way to split the souvenirs: even though the total value is the same, the number of souvenirs is not.


2)
{1,1,2,3,5,8}

Returns: "Possible"

We have 1+1+8 = 2+3+5.


3)
{2,3,5,7,11,13}

Returns: "Impossible"

The sum of values is an odd number, so it is impossible.


4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48}

Returns: "Possible"


5)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}

Returns: "Impossible"

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
#include <string.h>

using namespace std;

class FoxAndSouvenirTheNext {
	bool possible(vector <int> &value) {
		int N = (int)value.size();
		if (N % 2) {
			return false;
		}
		int sum = accumulate(value.begin(), value.end(), 0);
		if (sum % 2) {
			return false;
		}
		int dp[64][2560] = {};
		dp[0][0] = 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 2500; j >= value[i]; --j) {
				for (int k = i; k >= 0; --k) {
					if (dp[k][j - value[i]] > 0) {
						dp[k + 1][j] = 1;
					}
				}
			}
		}
		return dp[N / 2][sum / 2] > 0;
	}

public:
	string ableToSplit(vector <int> value) {
		return possible(value) ? "Possible" : "Impossible";
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToSplit(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,1,3};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToSplit(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,1,2,3,5,8};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToSplit(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,3,5,7,11,13};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToSplit(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
			string Arg1 = "Possible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToSplit(Arg0));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			string Arg1 = "Impossible";

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, ableToSplit(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndSouvenirTheNext ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
