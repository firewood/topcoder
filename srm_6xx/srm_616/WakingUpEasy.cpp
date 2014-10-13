// BEGIN CUT HERE
/*
SRM 616 Div2 Easy (250)

PROBLEM STATEMENT
Alex is sleeping soundly. At any moment, his sleepiness can be characterized by an integer. You are given an int S that represents Alex's initial sleepiness.

Unfortunately, several alarms are going to disturb him. These alarms will be ringing in a cyclic order. Each alarm is characterized by its volume.

You are given a list of alarm volumes in a vector <int> volume in the order in which the alarms are going to ring. Every minute the first alarm on the list rings, and Alex's sleepiness instantly decreases by its volume. The alarm is then moved to the end of the alarm list.

While Alex's sleepiness is positive, he's still sleeping. Once it becomes less than or equal to zero, Alex immediately wakes up.

Return the number of alarms after which Alex will wake up.


DEFINITION
Class:WakingUpEasy
Method:countAlarms
Parameters:vector <int>, int
Returns:int
Method signature:int countAlarms(vector <int> volume, int S)


CONSTRAINTS
-volume will contain between 1 and 50 elements, inclusive.
-Each element of volume will be between 1 and 100, inclusive.
-S will be between 1 and 10000, inclusive.


EXAMPLES

0)
{5, 2, 4}
13

Returns: 4

Initially, Alex's sleepiness is 13, and the list of alarms is {5, 2, 4}.
After the first alarm, Alex's sleepiness is 8. The list of alarms becomes {2, 4, 5}.
After the second alarm, Alex's sleepiness is 6. The list of alarms becomes {4, 5, 2}.
After the third alarm, Alex's sleepiness is 2. The list of alarms becomes {5, 2, 4}.
After the fourth alarm, Alex's sleepiness is -3, so Alex wakes up.


1)
{5, 2, 4}
3

Returns: 1

The first alarm is enough here.


2)
{1}
10000

Returns: 10000

The only alarm has to ring 10000 times before Alex finally wakes up.


3)
{42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
  92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
  95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69}
9999

Returns: 203

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class WakingUpEasy {
public:
	int countAlarms(vector <int> volume, int S) {
		int ans = 0;
		for (int i = 0; S > 0; i = (i + 1) % volume.size()) {
			S -= volume[i];
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
			int Arr0[] = {5, 2, 4};
			int Arg1 = 13;
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countAlarms(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 2, 4};
			int Arg1 = 3;
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countAlarms(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1};
			int Arg1 = 10000;
			int Arg2 = 10000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countAlarms(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37,
  92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36,
  95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69};
			int Arg1 = 9999;
			int Arg2 = 203;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, countAlarms(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WakingUpEasy ___test;
	___test.run_test(-1);
}
// END CUT HERE
