// BEGIN CUT HERE
/*
SRM 678 Div2 Medium (500)

PROBLEM STATEMENT
In a galaxy far far away... each week has N days.
Obi-Wan has exactly N shirts.
The shirts are numbered 1 through N.
Each day he wears one of those N shirts.
Each week he wears each shirt exactly once.

In different weeks Obi-Wan may wear his shirts in different orders.
However, not all orders are always possible.
Whenever Obi-Wan wears a shirt for a day, he has to wash it before he can use it again.
Washing and drying a shirt takes N-2 full days.
In other words, if he wears a shirt on day x, the earliest day when he can wear it again is day x+N-1.

The Jedi council recently sent Obi-Wan on a mission that lasted for some unknown number of full N-day weeks.
He remembers the order in which he wore his shirts during the first week of the mission.
He also remembers the order in which he wore his shirts during the last week of the mission.
You are given this information in vector <int>s firstWeek and lastWeek.
Each of these vector <int>s contains N elements: the numbers of shirts he wore during that week, in order.

For example, assume that N = 4, firstWeek = {1,2,3,4}, and lastWeek = {4,3,2,1}.
It is possible that this particular mission took four weeks.
One possible order in which Obi-Wan could have worn his shirts looks as follows:

week 1: {1,2,3,4}
week 2: {2,3,4,1}
week 3: {3,4,2,1}
week 4: {4,3,2,1}

Given firstWeek and lastWeek, compute and return the smallest number of weeks the mission could have taken.


DEFINITION
Class:AttackOfTheClones
Method:count
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int count(vector <int> firstWeek, vector <int> lastWeek)


NOTES
-N can be calculated as the number of elements of firstWeek


CONSTRAINTS
-firstWeek will contain between 2 and 2500 integers inclusive.
-firstWeek and lastWeek will contain the same number of elements.
-firstWeek and lastWeek will represent permutations of the first N positive integers.


EXAMPLES

0)
{1,2,3,4}
{4,3,2,1}

Returns: 4

The example from the problem statement.


1)
{1,2,3,4}
{1,2,3,4}

Returns: 1

Be careful! The first week and the last week can be indeed the same week.


2)
{8,4,5,1,7,6,2,3}
{2,4,6,8,1,3,5,7}

Returns: 7

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class AttackOfTheClones {
public:
	int count(vector <int> firstWeek, vector <int> lastWeek) {
		int a[2560], b[2560], d[2560];
		int N = (int)firstWeek.size();
		for (int i = 0; i != N; ++i) {
			a[firstWeek[i] - 1] = i;
			b[lastWeek[i] - 1] = i;
		}
		for (int i = 0; i != N; ++i) {
			d[i] = b[i] + N - a[i];
		}
		int m = *min_element(d, d + N);
		return N - m + 1;
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
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {4,3,2,1};
			int Arg2 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1,2,3,4};
			int Arr1[] = {1,2,3,4};
			int Arg2 = 1;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {8,4,5,1,7,6,2,3};
			int Arr1[] = {2,4,6,8,1,3,5,7};
			int Arg2 = 7;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, count(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AttackOfTheClones ___test;
	___test.run_test(0);
//	___test.run_test(1);
//	___test.run_test(2);
//	___test.run_test(3);
//	___test.run_test(4);
//	___test.run_test(5);
	___test.run_test(-1);
}
// END CUT HERE
