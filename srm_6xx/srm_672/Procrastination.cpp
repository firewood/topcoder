// BEGIN CUT HERE
/*
SRM 672 Div1 Easy (250)

PROBLEM STATEMENT
You are working in the Huge Software Company.
The company is so huge that it has an infinite number of employees.
Employee number 1 is reserved for the Big Boss and Legendary Founder of the company, Mr. Z.
Ordinary employees are numbered using positive integers, starting from 2.

At the beginning of the day each employee is assigned a task they should accomplish:
for each x from 2 to infinity, employee number x is assigned task number x.
During the day some pairs of employees will swap the tasks they were assigned.
The swapping follows a precise schedule that is described below.

The working day in the Huge Software Company has infinitely many hours.
The hours are numbered using positive integers, starting from 1.
During hour 1 there are no swaps at all.
During each of the following hours there are infinitely many swaps.
These look as follows:

During hour 2 we have the following swaps: workers 4 and 5 swap their tasks, workers 6 and 7 swap their tasks, workers 8 and 9 swap their tasks, and so on.
During hour 3 we have the following swaps: workers 6 and 7 swap their tasks, workers 9 and 10 swap their tasks, workers 12 and 13 swap their tasks, and so on.
...

Formally, for each h greater than or equal to 2, during hour h we look at all workers that have numbers divisible by h and strictly greater than h. Each of these workers will swap the task they currently have with the worker with a number one larger than their own.

It can be shown that for each employee there is a finite number of hours after which the employee will never swap their current task with anyone.
It can also be shown that for each task there is a finite number of hours after which the task will remain with the current employee forever.

You are given a long long n.
Compute and return the number of employee who will have the task number n at the end of the day.


DEFINITION
Class:Procrastination
Method:findFinalAssignee
Parameters:long long
Returns:long long
Method signature:long long findFinalAssignee(long long n)


CONSTRAINTS
-n will be between 2 and 10^10, inclusive.


EXAMPLES

0)
3

Returns: 3

Employee 3 is never involved in any swaps: neither with employee 2, nor with employee 4.


1)
8

Returns: 11

Task 8 starts assigned to employee 8. During hour 2 this employee swaps it for another task with employee 9. During hour 3 employee 9 gives this task to employee 10. Finally, during hour 5 employee 10 gives this task to employee 11 where it will stay forever.


2)
20

Returns: 20

Task 20 goes from employee 20 to employee 21 (during hour 2), then to employee 22 (during hour 3), then back to employee 21 (during hour 7), and finally back to employee 20 (during hour 10). This is where it then remains forever.


3)
196248

Returns: 196259


4)
5587021440

Returns: 5587021440

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

class Procrastination {
public:
	long long findFinalAssignee(long long n) {
		LL ans = n;
		LL x;
		for (x = 2; x * x <= n; ++x) {
			if (ans >= x * 2 && (ans % x) == 0) {
				++ans;
			} else if ((ans - 1) >= x * 2 && ((ans - 1) % x) == 0) {
				--ans;
			}
		}
		for (LL y = x; y >= 2; --y) {
			LL z = ans / y;
			if (z >= x) {
				if (ans >= z * 2 && (ans % z) == 0) {
					++ans;
				} else if ((ans - 1) >= z * 2 && ((ans - 1) % z) == 0) {
					--ans;
				}
			}
		}
		return ans;
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 3LL;
			long long Arg1 = 3LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 8LL;
			long long Arg1 = 11LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 20LL;
			long long Arg1 = 20LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 196248LL;
			long long Arg1 = 196259LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			long long Arg0 = 5587021440LL;
			long long Arg1 = 5587021440LL;

			verify_case(n, Arg1, findFinalAssignee(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Procrastination ___test;
	___test.run_test(-1);
}
// END CUT HERE
