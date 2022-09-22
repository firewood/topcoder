// BEGIN CUT HERE
/*
SRM 838 Div1 Easy (250)

PROBLEM STATEMENT

There are some coins on your table. Some of them are face-up (i.e., you can see their numerical value), the rest is face-down.

The values on the face-up coins are given in the vector <int> faceUp, and the values of the other coins are in faceDown.

You are allowed to flip some of the coins.
You want to reach a state in which the sum of the numbers visible on the coins is exactly equal to goal.
Your goal is to reach that state by performing as few flips as possible.

If the goal cannot be reached, return {-123456789}.
Otherwise, return a vector <int> describing the shortest possible solution.
Each element of the return value should be either +x (representing an action where you flip a face-down coin worth x face-up) or -x (representing the opposite action).

If there are multiple optimal solutions, you may return any one of them.


DEFINITION
Class:FlippingCoinSum
Method:flip
Parameters:vector <int>, vector <int>, int
Returns:vector <int>
Method signature:vector <int> flip(vector <int> faceUp, vector <int> faceDown, int goal)


NOTES
-If the goal cannot be reached, the correct return value is an array with one element: the negative integer -123456789.


CONSTRAINTS
-faceUp will contain between 0 and 50 elements, inclusive.
-faceDown will contain between 0 and 50 elements, inclusive.
-Each element of faceUp will be between 1 and 1000, inclusive.
-Each element of faceDown will be between 1 and 1000, inclusive.
-goal will be between 0 and 100,000, inclusive.


EXAMPLES

0)
{2, 2, 5}
{1, 10}
9

Returns: { }

The sum of visible numbers is already exactly 9, so the only optimal solution is to do nothing.

1)
{2, 2, 5}
{1, 10}
14

Returns: {-5, 10 }

The only optimal solution here is to flip the 5 face-down and the 10 face-up.

2)
{2, 2, 5}
{2, 10}
3

Returns: {-123456789 }

There is no way to produce the sum 3. In particular, note that we cannot flip a coin worth 2 face-down three times in a row, as there are currently only two face-up coins worth 2 each.

3)
{1, 1, 1, 1, 1, 1, 1}
{1, 1, 1, 1, 1, 1, 1}
10

Returns: {1, 1, 1 }

Any three of the seven face-down coins need to be turned face-up.

4)
{1, 1, 2, 2, 2, 3, 3, 3, 3}
{1, 2, 3, 4, 5, 6, 7}
0

Returns: {-1, -1, -2, -2, -2, -3, -3, -3, -3 }

All coins need to end face-down.

5)
{5, 5, 5, 5, 47, 100}
{42, 80, 174}
147

Returns: {-100, 80 }

One valid but not optimal solution is to flip all coins worth 5 face-down. The returned solution (flip the 100 face-down and the 80 face-up) needs fewer flips.

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
#include <cstring>

using namespace std;

typedef long long LL;

class FlippingCoinSum {
public:
	vector<int> build(const vector <int>& c, vector<LL> &f, bool maximize) {
		vector<int> dp(50005, -1);
		dp[0] = 0;
		f[0] = 0;
		for (int ci = 0; ci < c.size(); ++ci) {
			int x = c[ci];
			vector<int> next = dp;
			for (int i = 50000; i >= x; --i) {
				if (dp[i - x] >= 0) {
					int y = dp[i - x] + 1;
					if (next[i] < 0 || maximize == (y >= next[i])) {
						next[i] = y;
						f[i] = f[i - x] | (1LL << ci);
					}
				}
			}
			dp = next;
		}
		return dp;
	}

	vector <int> flip(vector <int> faceUp, vector <int> faceDown, int goal) {
		int mc = 1 << 30;
		vector <int> ans = { -123456789 };
		vector<LL> fa(50005, 0), fb(50005, 0);
		vector<int> ac = build(faceUp, fa, true);
		vector<int> bc = build(faceDown, fb, false);
		for (int a = 0; a <= 50000 && a <= goal; ++a) {
			int b = goal - a;
			if (ac[a] >= 0 && b >= 0 && b <= 50000 && bc[b] >= 0) {
				int c = faceUp.size() - ac[a] + bc[b];
				if (c < mc) {
					mc = c;
					ans.clear();
					for (int i = 0; i < faceUp.size(); ++i) {
						if ((fa[a] & (1LL << i)) == 0) {
							ans.emplace_back(-faceUp[i]);
						}
					}
					for (int i = 0; i < faceDown.size(); ++i) {
						if ((fb[b] & (1LL << i)) != 0) {
							ans.emplace_back(faceDown[i]);
						}
					}
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 5};
			int Arr1[] = {1, 10};
			int Arg2 = 9;
//			int Arr3[] = { };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3;
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 5};
			int Arr1[] = {1, 10};
			int Arg2 = 14;
			int Arr3[] = {-5, 10 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {2, 2, 5};
			int Arr1[] = {2, 10};
			int Arg2 = 3;
			int Arr3[] = {-123456789 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 1, 1, 1, 1, 1};
			int Arr1[] = {1, 1, 1, 1, 1, 1, 1};
			int Arg2 = 10;
			int Arr3[] = {1, 1, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 1, 2, 2, 2, 3, 3, 3, 3};
			int Arr1[] = {1, 2, 3, 4, 5, 6, 7};
			int Arg2 = 0;
			int Arr3[] = {-1, -1, -2, -2, -2, -3, -3, -3, -3 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 5, 5, 5, 47, 100};
			int Arr1[] = {42, 80, 174};
			int Arg2 = 147;
			int Arr3[] = {-100, 80 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 8, 975, 982, 970, 997, 976, 987, 996, 990, 965, 969, 978, 971, 1, 1000, 980, 999, 995, 991, 973, 988, 993, 963, 256, 964, 968, 974, 961, 981, 992, 998, 4, 64, 983, 989, 967, 2, 962, 32, 979, 977, 512, 16, 984, 966, 986, 994, 128, 985, 972 };
			int Arr1[] = { 8, 975, 982, 970, 997, 976, 987, 996, 990, 965, 969, 978, 971, 1, 1000, 980, 999, 995, 991, 973, 988, 993, 963, 256, 964, 968, 974, 961, 981, 992, 998, 4, 64, 983, 989, 967, 2, 962, 32, 979, 977, 512, 16, 984, 966, 986, 994, 128, 985, 972 };
			int Arg2 = 40243;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3;
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)) {
			int Arr0[] = { 8, 975, 982, 970, 997, 976, 987, 996, 990, 965, 969, 978, 971, 1, 1000, 980, 999, 995, 991, 973, 988, 993, 963, 256, 964, 968, 974, 961, 981, 992, 998, 4, 64, 983, 989, 967, 2, 962, 32, 979, 977, 512, 16, 984, 966, 986, 994, 128, 985, 972 };
			int Arr1[] = { 8, 975, 982, 970, 997, 976, 987, 996, 990, 965, 969, 978, 971, 1, 1000, 980, 999, 995, 991, 973, 988, 993, 963, 256, 964, 968, 974, 961, 981, 992, 998, 4, 64, 983, 989, 967, 2, 962, 32, 979, 977, 512, 16, 984, 966, 986, 994, 128, 985, 972 };
			int Arg2 = 12345;
			int Arr3[] = { -976, -969, -971, -980, -991, -973, -988, -993, -963, -964, -968, -974, -961, -981, -992, -998, -983, -989, -967, -962, -979, -977, -512, -984, -966, -986, -994, -985, -972 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
			verify_case(n, Arg3, flip(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FlippingCoinSum ___test;
	___test.run_test(-1);
}
// END CUT HERE
