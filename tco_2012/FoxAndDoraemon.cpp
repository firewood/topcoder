// BEGIN CUT HERE
/*
// TCO12 Round 1B Medium (500)

// PROBLEM STATEMENT
// Fox Ciel has lots of homework to do.
The homework consists of some mutually independent tasks. Different
tasks may take different amounts of time to complete.
You are given a vector <int> workCost. For each i, the i-th task
takes workCost[i] seconds to complete.
She would like to attend a party and meet her friends, thus she wants
to finish all tasks as quickly as possible.

The main problem is that all foxes, including Ciel, really hate doing homework.
Each fox is only willing to do one of the tasks.
Luckily, Doraemon, a robotic cat from the 22nd century, gave Fox Ciel a split hammer:
a magic gadget which can split any fox into two foxes.

You are given an int splitCost.
Using the split hammer on a fox is instantaneous.
Once a hammer is used on a fox, the fox starts to split.
After splitCost seconds she will turn into two foxes -- the original fox and
another completely new fox.
While a fox is splitting, it is not allowed to use the hammer on her again.

The work on a task cannot be interrupted: once a fox starts working on a task,
she must finish it.
It is not allowed for multiple foxes to cooperate on the same task.
A fox cannot work on a task while she is being split using the hammer.
It is possible to split the same fox multiple times.
It is possible to split a fox both before and after she solves one of the tasks.

Compute and return the smallest amount of time in which the foxes can solve all the tasks.


DEFINITION
Class:FoxAndDoraemon
Method:minTime
Parameters:vector <int>, int
Returns:int
Method signature:int minTime(vector <int> workCost, int splitCost)


CONSTRAINTS
-workCost will contain between 1 and 50 elements, inclusive.
-Each element in workCost will be between 1 and 3,600, inclusive.
-splitCost will be between 1 and 3,600, inclusive.


EXAMPLES

0)
{1,2}
1000

Returns: 1002

Fox Ciel is only willing to do one task. She is given two tasks, therefore she must split once. 
The optimal strategy is to use the split hammer immediately.
After 1000 seconds we have two foxes. 
Each of them will do one of the tasks in parallel.


1)
{3,6,9,12}
1000

Returns: 2012


2)
{1000,100,10,1}
1

Returns: 1001

One optimal solution:

We start with a single fox A.
Immediatelly, we use the split hammer.
In 1 second we will have foxes A and B.
Fox A will start working on task 0.
At the same time, fox B will start working on task 1.
Fox B will be done 101 seconds from the start.
As she already solved a task, we need more foxes to do tasks 2 and 3.
Therefore we use the split hammer on B.
At 102 seconds from the start we will get a new fox C and let her solve task 2.
We use the split hammer on B again.
At 103 seconds from the start we will get a new fox D and let her solve task 3.


3)
{1712,1911,1703,1610,1697,1612}
100

Returns: 2012


4)
{3000,3000,3000,3000,3000,3000,3000,3000,3000,3000}
3000

Returns: 15000


5)
{58}
3600

Returns: 58

*/
// END CUT HERE
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

typedef vector<int> IntVec;
typedef pair<int, int> II;
typedef map<II, int> IIMap;

class FoxAndDoraemon {
	IntVec w;
	int c;
	IIMap m;

public:
	int rec(int n, int e) {
		II key(n, e);
		if (m.count(key) > 0) {
			return m[key];
		}
		int &res = m[key];
		if (e <= n) {
			res = w[e-1];
		} else {
			res = 999999999;
			int i;
			for (i = 0; i < n; ++i) {
				res = min(res, max(w[e-1], c + rec((n - i) * 2, e - i)));
			}
		}
		return res;
	}

	int minTime(vector <int> workCost, int splitCost) {
		w = workCost;
		c = splitCost;
		m.clear();
		sort(w.begin(), w.end());
		int res = rec(1, w.size());
		return res;
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
			int Arr0[] = {1,2};
			int Arg1 = 1000;
			int Arg2 = 1002;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3,6,9,12};
			int Arg1 = 1000;
			int Arg2 = 2012;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1000,100,10,1};
			int Arg1 = 1;
			int Arg2 = 1001;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1712,1911,1703,1610,1697,1612};
			int Arg1 = 100;
			int Arg2 = 2012;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_4
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
			int Arg1 = 3000;
			int Arg2 = 15000;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

		// test_case_5
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {58};
			int Arg1 = 3600;
			int Arg2 = 58;

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			verify_case(n, Arg2, minTime(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxAndDoraemon ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
