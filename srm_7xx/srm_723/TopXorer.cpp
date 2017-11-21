// BEGIN CUT HERE
/*
SRM 723 Div1 Easy (250)

PROBLEM STATEMENT
Like Topcoder, TopXorer uses a rating system.
The rating of each person is a non-negative integer.

You are a coach.
You want to select an n-person team.
The team members will be labeled 0 through n-1.
You have a set of constraints decribed by the vector <int> x with n elements.
For each valid i, the rating of team member i must be between 0 and x[i], inclusive.

As the name suggests, the rating of a team in TopXorer is computed as the bitwise xor of the ratings of all team members.

You are given the vector <int>s x.
Please compute and return the maximal team rating your team can have.


DEFINITION
Class:TopXorer
Method:maximalRating
Parameters:vector <int>
Returns:int
Method signature:int maximalRating(vector <int> x)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-Each element in x will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2,2,2}

Returns: 3

One optimal solution is to select people with ratings (2, 0, 1).
The team rating will then be (2 xor 0 xor 1) = 3.


1)
{1,2,4,8,16}

Returns: 31

This time the only optimal solution is to select people with the largest possible ratings.


2)
{1024,1024}

Returns: 2047


3)
{7,4,12,33,6,8,3,1}

Returns: 47


4)
{0}

Returns: 0

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class TopXorer {
public:
	int maximalRating(vector <int> x) {
		int n = (int)x.size();
		sort(x.rbegin(), x.rend());
		vector<int> u(n);
		int ans = 0;
		for (int i = 30; i >= 0; --i) {
			int b = 1 << i;
			for (int j = 0; j < n; ++j) {
				if ((u[j] | b) <= x[j]) {
					u[j] |= b;
					ans |= b;
					break;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
	int maximalRating2(vector <int> x) {
		int n = (int)x.size();
		vector<int> f(n);
		int ans = 0;
		while (true) {
			int i;
			for (i = 0; i < n; ++i) {
				if (++f[i] <= x[i]) {
					break;
				}
				f[i] = 0;
			}
			if (i >= n) {
				break;
			}
			int s = 0;
			for (i = 0; i < n; ++i) {
				s ^= f[i];
			}
			ans = max(ans, s);
		}
		return ans;
	}

private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2,2,2};
			int Arg1 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximalRating(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,4,8,16};
			int Arg1 = 31;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximalRating(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1024,1024};
			int Arg1 = 2047;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximalRating(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {7,4,12,33,6,8,3,1};
			int Arg1 = 47;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximalRating(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0};
			int Arg1 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg1, maximalRating(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TopXorer ___test;
	___test.run_test(-1);

	for (int t = 0; t < 100; ++t) {
		int n = (rand() % 4) + 1;
		vector<int> x(n);
		for (int i = 0; i < n; ++i) {
			x[i] = rand() % 20;
		}
		int p = ___test.maximalRating(x);
		int q = ___test.maximalRating2(x);
		if (p != q) {
			printf("FAILED\n");
			break;
		}
	}
}
// END CUT HERE
