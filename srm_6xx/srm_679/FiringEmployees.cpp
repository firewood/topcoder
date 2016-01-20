// BEGIN CUT HERE
/*
SRM 679 Div1 Easy (250)

PROBLEM STATEMENT
BottomCoder has a CEO and N employees.
The CEO has number 0, the employees are numbered 1 through N.
Each employee can be described by three numbers: their salary, their productivity, and the number of their direct manager.
For each employee E, employee E's manager has a number smaller than E.
Hence, the company has a tree-like hierarchy.

You are given the description of BottomCoder in the vector <int>s manager, salary, and productivity.
For each i between 1 and N, inclusive, employee i is described by the values manager[i-1], salary[i-1], and productivity[i-1].

The profit from an employee can be computed as the employee's productivity minus their salary.
Note that the profit from an employee can be negative.
The total profit of the company is the sum of profits of its employees.

The CEO would like to increase the total profit of the company by firing some of its employees.
However, if he fires an employee E, he must also fire all employees who reported to E.
For example, if he fires your manager, he must fire you as well.
As another example, if he fires the manager of your manager, he must fire your manager and therefore he must also fire you.

Find a valid way of firing some (possibly none, possibly all) employees that maximizes the profit of the resulting company.
Return the total profit after the selected employees are fired.


DEFINITION
Class:FiringEmployees
Method:fire
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int fire(vector <int> manager, vector <int> salary, vector <int> productivity)


NOTES
-The CEO of BottomCoder has both salary and productivity equal to zero. The CEO cannot be fired.


CONSTRAINTS
-manager, salary and productivity will contain N elements each.
-manager will contain between 1 and 2500 elements inclusive.
-Each element of salary will be between 1 and 10,000 inclusive.
-Each element of productivity will be between 1 and 10,000 inclusive.
-The i-th element of manager will be between 0 and i inclusive.


EXAMPLES

0)
{0,0,0}
{1,2,3}
{3,2,1}

Returns: 2

The CEO has three direct employees.
The first one has a salary of 1 and a productivity of 3.
The second one has a salary of 2 and a productivity of 2.
The third one has a salary of 3 and a productivity of 1.
The CEO should fire employee 3.
The CEO can also fire employee 2, but it does not matter: here, firing is equally good as keeping.


1)
{0,1,2,3}
{4,3,2,1}
{2,3,4,5}

Returns: 4

Employee 1 has a negative profit: 2-4 = (-2).
The other three employees have nonnegative profits: 0, 2, and 4.

It would seem that the CEO should fire employee 1.
However, if he does that, he would have to fire all four employees, because 1 is (either directly or indirectly) the manager of each of them.
This would leave the CEO with an empty company that has profit 0.

The optimal strategy is not to fire anyone.
The total profit in this case will be (-2) + 0 + 2 + 4 = 4.


2)
{0,1}
{1,10}
{5,5}

Returns: 4

In this case the best choice is to fire employee number 2 and keep employee number 1.


3)
{0,1,2,1,2,3,4,2,3}
{5,3,6,8,4,2,4,6,7}
{2,5,7,8,5,3,5,7,9}

Returns: 6


4)
{0,0,1,1,2,2}
{1,1,1,2,2,2}
{2,2,2,1,1,1}

Returns: 3

*/
// END CUT HERE
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class FiringEmployees {
public:
	int fire(vector <int> m, vector <int> s, vector <int> p) {
		int N = (int)m.size();
		int a[2560] = {};
		for (int i = N; i > 0; --i) {
			int d = p[i - 1] - s[i - 1];
			int boss = m[i - 1];
			a[i] += d;
			if (a[i] > 0) {
				a[boss] += a[i];
			}
		}
		return a[0];
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
			int Arr0[] = {0,0,0};
			int Arr1[] = {1,2,3};
			int Arr2[] = {3,2,1};
			int Arg3 = 2;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,3};
			int Arr1[] = {4,3,2,1};
			int Arr2[] = {2,3,4,5};
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1};
			int Arr1[] = {1,10};
			int Arr2[] = {5,5};
			int Arg3 = 4;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,1,2,1,2,3,4,2,3};
			int Arr1[] = {5,3,6,8,4,2,4,6,7};
			int Arr2[] = {2,5,7,8,5,3,5,7,9};
			int Arg3 = 6;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {0,0,1,1,2,2};
			int Arr1[] = {1,1,1,2,2,2};
			int Arr2[] = {2,2,2,1,1,1};
			int Arg3 = 3;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
			verify_case(n, Arg3, fire(Arg0, Arg1, Arg2));
		}
		n++;


		if ((Case == -1) || (Case == n)){
			vector <int> Arg[3];
			for (int i = 0; i < 2500; ++i) {
				Arg[0].push_back(i);
				Arg[1].push_back(1);
				Arg[2].push_back(1);
			}
			Arg[2].back() = 100;
			int Arg3 = 99;

			verify_case(n, Arg3, fire(Arg[0], Arg[1], Arg[2]));
		}
		n++;
	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FiringEmployees ___test;
	___test.run_test(-1);
}
// END CUT HERE
