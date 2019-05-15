// BEGIN CUT HERE
/*
SRM 757 Div1 Easy (250)

PROBLEM STATEMENT

You have C pet centipedes.
You want to take them out for a walk, but it's quite cold.
You want to give them socks to make them feel more comfortable.

Each of your centipedes has F feet.
You have a large bin with centipede socks.
The socks come in different colors, but your centipedes are quite picky and each of them requires to wear F socks of the same color.

You are given the ints C and F.
You are also given the vector <int> sockCounts.
Each element of sockCounts is the number of socks of one particular color you have in the bin.

Find and return the smallest X such that if you take any X socks out of the bin, it is guaranteed that you will be able to use some of them to keep all feet of all your centipedes warm.
If there is no such X, return -1 instead.


DEFINITION
Class:CentipedeSocks
Method:fewestSocks
Parameters:int, int, vector <int>
Returns:int
Method signature:int fewestSocks(int C, int F, vector <int> sockCounts)


CONSTRAINTS
-C will be between 1 and 50, inclusive.
-F will be between 1 and 100, inclusive.
-sockCounts will have between 1 and 100 elements, inclusive.
-Each element of sockCounts will be between 1 and 10^7, inclusive.


EXAMPLES

0)
1
100
{1, 1, 1, 1, 100}

Returns: 104

One centipede with 100 feet. If you are really unlucky, you need to remove all 104 socks from the bin until you get all 100 pink ones.


1)
1
100
{40, 50, 60, 70}

Returns: -1

You do not have 100 socks of any single color, so the poor centipede will be cold.


2)
3
10
{12345}

Returns: 30

There are 12345 red socks in the bin. You just grab the first 30 and put 10 of them onto each of your centipedes.


3)
2
3
{4, 4, 5}

Returns: 10

Two red, two blue, and five pink socks are still not enough to satisfy two three-legged centipedes.

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>
#include <bitset>

using namespace std;

class CentipedeSocks {
public:
	int fewestSocks(int C, int F, vector <int> sockCounts) {
		int ans = -1, n = (int)sockCounts.size(), total = 0;
		vector< bitset<50002> > dp(50);
		dp[0][0] = true;
		for (int i = 0; i < n; ++i) {
			int socks = min(sockCounts[i], C * F);
			int c = socks / F;
			total += c;
			vector< bitset<50002> > next = dp;
			for (int j = 0; j < C; ++j) {
				for (int k = 0; k < c; ++k) {
					if (j + k >= C) break;
					next[j + k] |= dp[j] << ((k + 1) * F - 1);
				}
				if (j + c >= C) break;
				next[j + c] |= dp[j] << socks;
			}
			dp = next;
		}
		ans = -1;
		if (total >= C) {
			for (int j = 0; j <= 50000; ++j) {
				if (dp[C - 1][j]) {
					ans = max(ans, j + 1);
				}
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
			int Arg0 = 1;
			int Arg1 = 100;
			int Arr2[] = {1, 1, 1, 1, 100};
			int Arg3 = 104;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 1;
			int Arg1 = 100;
			int Arr2[] = {40, 50, 60, 70};
			int Arg3 = -1;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 3;
			int Arg1 = 10;
			int Arr2[] = {12345};
			int Arg3 = 30;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 2;
			int Arg1 = 3;
			int Arr2[] = {4, 4, 5};
			int Arg3 = 10;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 100;
			int Arr2[] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,5000 };
			int Arg3 = 99 * 99 + 100 * 50;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 100;
			int Arr2[] = { 99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,50000 };
			int Arg3 = 99 * 99 + 100 * 50;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 100;
			int Arr2[] = { 5000,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99 };
			int Arg3 = 99 * 99 + 100 * 50;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 50;
			int Arg1 = 100;
			int Arr2[] = { 50000,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99 };
			int Arg3 = 99 * 99 + 100 * 50;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

		if ((Case == -1) || (Case == n)) {
			int Arg0 = 23;
			int Arg1 = 9;
			int Arr2[] = { 215, 28, 69, 67, 2, 31, 260, 59, 11, 439, 189, 1, 53, 356, 8, 6, 3, 904, 385, 2, 45, 156, 109, 23, 389, 34, 207, 916 };
			int Arg3 = 397;

			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fewestSocks(Arg0, Arg1, Arg2));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CentipedeSocks ___test;
	___test.run_test(-1);
}
// END CUT HERE
