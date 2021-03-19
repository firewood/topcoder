// BEGIN CUT HERE
/*
SRM 802 Div1 Medium (600)

PROBLEM STATEMENT
Time limit is 3 seconds.

There are N students, where N is even.
The students are numbered starting from 0.

Some pairs of students are friends: for each valid i, students X[i] and Y[i] are friends.

For a group project the students have to be split into two groups with exactly N/2 students in each of them.
The quality of a split can be measured by the number of friendships that are broken by the split. 
More precisely, for each split we can count the pairs of friends who aren't in the same group, and we want to minimize this value.

Return the number of optimal ways to split the students into two groups.
(Two ways of splitting the students are considered the same if each student's groupmates are the same.)


DEFINITION
Class:BestEvenSplit
Method:count
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int count(int N, vector <int> X, vector <int> Y)


CONSTRAINTS
-N will be between 2 and 30, inclusive.
-N will be even.
-X and Y will contain the same number of elements.
-For each i, 0 <= X[i] < Y[i] <= N-1.
-All pairs of friends described by X and Y will be distinct.


EXAMPLES

0)
6
{0, 0, 1, 1, 3}
{2, 4, 3, 5, 5}

Returns: 1

There are five friendships: 0-2, 0-4, 1-3, 1-5, and 3-5. There is an unique optimal split of these students into teams: one team has to be {0,2,4} and the other {1,3,5}. This way everyone's all friends are on their team.


1)
6
{}
{}

Returns: 10

Each of the 10 possible splits of these students into two groups is clearly equally good.


2)
6
{3}
{5}

Returns: 4

In the optimal split students 3 and 5 have to be in the same group. We have four possibilities for their last teammate.


3)
6
{0, 2, 4}
{1, 3, 5}

Returns: 6


4)
8
{0, 1, 2, 3}
{4, 5, 6, 7}

Returns: 3


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

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

class BestEvenSplit {
public:
	int count(int N, vector <int> X, vector <int> Y) {
		int f[30] = {};
		for (int i = 0; i < (int)X.size(); ++i) {
			f[X[i]] |= 1 << Y[i];
			f[Y[i]] |= 1 << X[i];
		}
		int ans = 0, max_count = 0, x, y;
		for (int comb = (1 << N/2) - 1; comb < 1 << N; x = comb & -comb, y = comb + x, comb = ((comb & ~y) / x >> 1) | y) {
			int rcomb = ~comb & ((1 << N) - 1);
			if (rcomb < comb) break;
			int cnt = 0;
			for (int i = 0; i < N; ++i) {
				cnt += popcount(f[i] & ((comb & (1 << i)) ? comb : rcomb));
			}
			ans += cnt == max_count;
			if (cnt > max_count) {
				max_count = cnt;
				ans = 1;
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
			int Arg0 = 6;
			int Arr1[] = {0, 0, 1, 1, 3};
			int Arr2[] = {2, 4, 3, 5, 5};
			int Arg3 = 1;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			// int Arr1[] = {};
			// int Arr2[] = {};
			int Arg3 = 10;

			vector <int> Arg1;
			vector <int> Arg2;
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {3};
			int Arr2[] = {5};
			int Arg3 = 4;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arg0 = 6;
			int Arr1[] = {0, 2, 4};
			int Arr2[] = {1, 3, 5};
			int Arg3 = 6;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arg0 = 8;
			int Arr1[] = {0, 1, 2, 3};
			int Arr2[] = {4, 5, 6, 7};
			int Arg3 = 3;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;

#ifndef _DEBUG
		if ((Case == -1) || (Case == n)) {
			int Arg0 = 30;
			int Arr1[] = { 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14 };
			int Arr2[] = { 15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };
			int Arg3 = 8;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, count(Arg0, Arg1, Arg2));
		}
		n++;
#endif

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BestEvenSplit ___test;
	___test.run_test(-1);
}
// END CUT HERE
