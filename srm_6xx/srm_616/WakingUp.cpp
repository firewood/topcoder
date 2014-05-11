// BEGIN CUT HERE
/*
SRM 616 Div1 Easy (250)

PROBLEM STATEMENT
Alex is sleeping soundly. At any minute T, his sleepiness can be characterized by an integer. Initially, at minute 0, Alex's sleepiness is some unknown integer S.

Unfortunately, there are several repeatedly ringing alarms disturbing him.

Starting from minute 1, the following happens each minute. First, Alex's sleepiness increases by D. Then some of the alarms ring, decreasing Alex's sleepiness.

Formally, alarms' characteristics are given in three vector <int>s period, start and volume. The i-th alarm rings at minutes start[i], start[i] + period[i], start[i] + 2 * period[i], etc., and each time it rings, Alex's sleepiness instantly decreases by volume[i]. If several alarms ring at the same minute, their effects are added up, so each of them decreases Alex's sleepiness by its volume.

While Alex's sleepiness is positive, he's still sleeping. Once it becomes less than or equal to zero, Alex immediately wakes up. Note that Alex's initial sleepiness can be non-positive. In that case he just wakes up at minute 0.

You are given the vector <int>s period, start, volume, and the int D. Return the largest possible value of S (Alex's initial sleepiness) such that he will wake up at some moment. If he is guaranteed to wake up for all possible values of S, return -1 instead.


DEFINITION
Class:WakingUp
Method:maxSleepiness
Parameters:vector <int>, vector <int>, vector <int>, int
Returns:int
Method signature:int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D)


NOTES
-It is possible to prove that the answer for any test case fits into a 32-bit signed integer type.


CONSTRAINTS
-period will contain between 1 and 50 elements, inclusive.
-period, start and volume will contain the same number of elements.
-Each element of period will be between 1 and 10, inclusive.
-start[i] will be between 1 and period[i], inclusive.
-Each element of volume will be between 1 and 1000, inclusive.
-D will be between 1 and 100, inclusive.


EXAMPLES

0)
{2, 3}
{1, 2}
{3, 4}
3

Returns: 2

There are two alarms. The first alarm rings every 2 minutes, starting from minute 1, and has volume 3. The second alarm rings every 3 minutes, starting from minute 2, and has volume 4.

Here is what would happen for S = 2:


At minute 0, Alex's sleepiness is 2.
At minute 1, Alex's sleepiness increases to 5. Then the first alarm rings, decreasing his sleepiness to 2.
At minute 2, Alex's sleepiness increases to 5. Then the second alarm rings, decreasing his sleepiness to 1.
At minute 3, Alex's sleepiness increases to 4. Then the first alarm rings, decreasing his sleepiness to 1.
At minute 4, Alex's sleepiness increases to 4. No alarm rings at this minute.
At minute 5, Alex's sleepiness increases to 7. Then both alarms ring, decreasing his sleepiness to 0, so he wakes up.


It can be proven that for any larger S, Alex will never wake up.


1)
{1}
{1}
{17}
17

Returns: 0

For any positive S, Alex will never wake up. It's better not to fall asleep.


2)
{1}
{1}
{23}
17

Returns: -1

Each minute Alex's sleepiness decreases by 6. That means he will wake up at some moment, regardless of the initial sleepiness.


3)
{9, 2, 5, 5, 7}
{6, 1, 4, 1, 6}
{71, 66, 7, 34, 6}
50

Returns: 78


4)
{5, 6, 5, 3, 8, 3, 4}
{1, 1, 3, 2, 6, 3, 3}
{42, 85, 10, 86, 21, 78, 38}
88

Returns: -1

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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

class WakingUp {
public:
	int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
		int m = 1;
		for (int i = 1; i <= 10; ++i) {
			m = lcm(m, i);
		}
		int low = 0;
		int c = 0;
		int t;
		for (t = 1; t <= m; ++t) {
			c += D;
			for (int i = 0; i < (int)period.size(); ++i) {
				if (t >= start[i] && ((t - start[i]) % period[i]) == 0) {
					c -= volume[i];
				}
			}
			low = min(low, c);
		}
		int low2 = 0;
		for (; t <= 2*m; ++t) {
			c += D;
			for (int i = 0; i < (int)period.size(); ++i) {
				if (t >= start[i] && ((t - start[i]) % period[i]) == 0) {
					c -= volume[i];
				}
			}
			low2 = min(low2, c);
		}
		if (low2 < low) {
			return -1;
		}
		return -low;
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
			int Arr0[] = {2, 3};
			int Arr1[] = {1, 2};
			int Arr2[] = {3, 4};
			int Arg3 = 3;
			int Arg4 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arr2[] = {17};
			int Arg3 = 17;
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arr1[] = {1};
			int Arr2[] = {23};
			int Arg3 = 17;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {9, 2, 5, 5, 7};
			int Arr1[] = {6, 1, 4, 1, 6};
			int Arr2[] = {71, 66, 7, 34, 6};
			int Arg3 = 50;
			int Arg4 = 78;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 6, 5, 3, 8, 3, 4};
			int Arr1[] = {1, 1, 3, 2, 6, 3, 3};
			int Arr2[] = {42, 85, 10, 86, 21, 78, 38};
			int Arg3 = 88;
			int Arg4 = -1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			int Arr0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int Arr1[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int Arr2[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			int Arg3 = 100;
			int Arg4 = 0;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg4, maxSleepiness(Arg0, Arg1, Arg2, Arg3));
		}
		n++;


	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WakingUp ___test;
	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
