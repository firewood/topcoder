// BEGIN CUT HERE
/*
SRM 827 Div1 Easy (200)

PROBLEM STATEMENT

Ela decided to practice her problem solving skills by solving some number of problems each day.
In order to avoid burnout, she alternately has some heavy days on which she solves many problems and then some light days on which she solves fewer problems.

The number of days of each type are given in the long longs heavyDays and lightDays.
The number of problems solved on each day of a given type are heavyProblems and lightProblems.

You are given a collection of queries in the vector<long long> queries.
For each index i, determine the day (numbered starting from 1) on which Ela will solve her queries[i]-th problem.
Return a vector<long long> with the answers to all queries (in the order in which they were given).


DEFINITION
Class:ContestTraining
Method:practice
Parameters:long long, long long, long long, long long, vector<long long>
Returns:vector<long long>
Method signature:vector<long long> practice(long long heavyDays, long long lightDays, long long heavyProblems, long long lightProblems, vector<long long> queries)


CONSTRAINTS
-heavyDays will be between 1 and 10^18, inclusive.
-lightDays will be between 1 and 10^18, inclusive.
-heavyProblems and lightProblems will satisfy 1 <= lightProblems < heavyProblems <= 10^18.
-queries will have between 1 and 200 elements, inclusive.
-Each element of queries will be between 1 and 10^18, inclusive.


EXAMPLES

0)
5
2
5
1
{5, 21, 25, 26, 27, 28, 32, 43, 50}

Returns: {1, 5, 5, 6, 7, 8, 8, 11, 12 }

Ela has alternately 5 heavy days (Monday to Friday) and 2 light days (Saturday, Sunday). On each heavy day she solves 5 problems, on each light day she solves 1 problem.
The beginning of her schedule looks as follows:

Day 1 (Monday): problems 1-5
Day 2 (Tuesday): problems 6-10
Day 3 (Wednesday): problems 11-15
Day 4 (Thursday): problems 16-20
Day 5 (Friday): problems 21-25
Day 6 (Saturday): problem 26
Day 7 (Sunday): problem 27
Day 8 (Monday): problems 28-32
Day 9 (Tuesday): problems 33-37
Day 10 (Wednesday): problems 38-42
Day 11 (Thursday): problems 43-47
Day 12 (Friday): problems 48-52
Day 13 (Saturday): problem 53
...

Thus: she solves her 5th problem still on day 1, her 21st and 25th problem are both solved on day 5, the 26th problem on day 6, the 27th problem on day 7, problems with numbers 28-32 are solved on day 8 (which is a heavy day again), and so on.


1)
1
1234567890
10
1
{7, 17, 18, 19, 20, 987654321, 987654322, 2345678901, 345678901234}

Returns: {1, 8, 9, 10, 11, 987654312, 987654313, 2345678883, 345678898714 }

On the very first day Ela solves 10 problems. Then she has very many light days and on each of them she only solves a single problem. For all queries except for the last two the corresponding problem is solved before her second heavy day.


2)
1
1234567890
10
1
{19, 345678901234, 987654322, 18, 17, 2345678901, 987654321, 20, 20, 20, 7}

Returns: {10, 345678898714, 987654313, 9, 8, 2345678883, 987654312, 11, 11, 11, 1 }

Queries aren't necessarily given in sorted order. Queries aren't necessarily distinct.

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

#ifdef __GNUC__
#define int128_t __int128
#else
#include <boost/multiprecision/cpp_int.hpp>
typedef boost::multiprecision::int128_t int128_t;
#endif

class ContestTraining {
public:
	vector<long long> practice(long long heavyDays, long long lightDays, long long heavyProblems, long long lightProblems, vector<long long> queries) {
		int128_t a = int128_t(heavyDays) * heavyProblems, b = int128_t(lightDays) * lightProblems, c = a + b;
		vector<long long> ans;
		for (auto q : queries) {
			int128_t d = q - 1, e = d / c, f = d % c, x = e * (heavyDays + lightDays);
			if (f < a) {
				x += f / heavyProblems;
			} else {
				x += heavyDays + (f - a) / lightProblems;
			}
			ans.emplace_back((long long)x + 1);
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5LL;
			long long Arg1 = 2LL;
			long long Arg2 = 5LL;
			long long Arg3 = 1LL;
			long Arr4[] = {5, 21, 25, 26, 27, 28, 32, 43, 50};
			long Arr5[] = {1, 5, 5, 6, 7, 8, 8, 11, 12 };

			vector<long long> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, practice(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1234567890LL;
			long long Arg2 = 10LL;
			long long Arg3 = 1LL;
			long long Arr4[] = {7, 17, 18, 19, 20, 987654321, 987654322, 2345678901LL, 345678901234LL};
			long long Arr5[] = {1, 8, 9, 10, 11, 987654312, 987654313, 2345678883LL, 345678898714LL };

			vector<long long> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, practice(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 1LL;
			long long Arg1 = 1234567890LL;
			long long Arg2 = 10LL;
			long long Arg3 = 1LL;
			long long Arr4[] = {19, 345678901234, 987654322, 18, 17, 2345678901, 987654321, 20, 20, 20, 7};
			long long Arr5[] = {10, 345678898714, 987654313, 9, 8, 2345678883, 987654312, 11, 11, 11, 1 };

			vector<long long> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
			vector<long long> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0])));
			verify_case(n, Arg5, practice(Arg0, Arg1, Arg2, Arg3, Arg4));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ContestTraining ___test;
	___test.run_test(-1);
}
// END CUT HERE
