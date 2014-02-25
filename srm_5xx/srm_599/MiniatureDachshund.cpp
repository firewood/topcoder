// BEGIN CUT HERE
/*
SRM 599 Div2 Easy (250)

PROBLEM STATEMENT
Dachshund is a popular dog breed. In this problem, a miniature dachshund is defined as a dachshund whose weight is not more than 5,000 grams.

Lun the miniature dachshund loves mikan (satsuma oranges). She has just bought some mikan. You are given a vector <int> mikan. It gives the weight of all mikan she bought. For each valid i, mikan[i] is the weight of the i-th mikan in grams.
You are also given an int weight. Currently, Lun weighs weight grams. When she eats i-th mikan, her weight increases by mikan[i] grams. If she eats multiple mikan, her weight increases by their total weight. She cannot eat just a part of a mikan. In other words, if she chooses to eat a mikan, she eats it completely.

She wants to remain being a miniature dachshund. That is, she wants her weight not to exceed 5,000 grams. Under this condition, calculate and return the maximum number of mikan Lun can eat.


DEFINITION
Class:MiniatureDachshund
Method:maxMikan
Parameters:vector <int>, int
Returns:int
Method signature:int maxMikan(vector <int> mikan, int weight)


CONSTRAINTS
-mikan will contain between 1 and 50 elements, inclusive.
-Each element of mikan will be between 50 and 200, inclusive.
-weight will be between 3,000 and 5,000, inclusive.


EXAMPLES

0)
{100, 100, 100, 100, 100}
4750

Returns: 2

Here, Lun weighs 4,750 grams and has bought 5 mikan, each of which weighs 100 grams. When she eats 2 of these, her weight will be 4,950 grams. She should not eat more.


1)
{100, 100, 100, 100, 50}
4750

Returns: 3

This time, one of the mikan is smaller. She can eat it with 2 of the 100-gram mikan. Note that her weight is allowed to be exactly 5,000 grams.


2)
{120, 90, 130, 100, 110, 80}
3000

Returns: 6

When she is light enough, she can eat all of the mikan she has bought.


3)
{50}
5000

Returns: 0

When her weight is already 5,000 grams, she should not eat anything.


4)
{200, 50, 200, 50, 200, 50, 200, 50}
4800

Returns: 4

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

class MiniatureDachshund {
public:
	int maxMikan(vector <int> mikan, int weight) {
		sort(mikan.begin(), mikan.end());
		int ans = 0;
		for (int i = 0; i < (int)mikan.size(); ++i) {
			weight += mikan[i];
			if (weight > 5000) {
				break;
			}
			++ans;
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
			int Arr0[] = {100, 100, 100, 100, 100};
			int Arg1 = 4750;
			int Arg2 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {100, 100, 100, 100, 50};
			int Arg1 = 4750;
			int Arg2 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {120, 90, 130, 100, 110, 80};
			int Arg1 = 3000;
			int Arg2 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {50};
			int Arg1 = 5000;
			int Arg2 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {200, 50, 200, 50, 200, 50, 200, 50};
			int Arg1 = 4800;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, maxMikan(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MiniatureDachshund ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
