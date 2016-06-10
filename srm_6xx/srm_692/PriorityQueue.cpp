// BEGIN CUT HERE
/*
SRM 692 Div2 Easy (250)

PROBLEM STATEMENT

It's lunchtime! 
The school canteen is currently empty. 
N children are going to enter the canteen and form a single queue. 
The children are numbered 0 through N-1 in the order in which they enter the canteen. 
Whenever a child enters the canteen, it performs one of two possible actions:

either it stands at the current end of the lunch queue,
or it skips the entire queue and goes to stand at its current beginning.

You are given the description of the children's behaviour: a string S containing N characters. 
For each valid i, S[i] is either 'e' or 'b'. 
Here, 'e' means that child i goes to the end of the queue, and 'b' means it goes to the beginning of the queue.

You are also given a vector <int> a with N elements.
The element a[j] is the annoyance factor of child j (explained below).

At the beginning, the displeasure of each child is zero. 
The displeasure D[i] of child i grows whenever another child cuts in front of them. 
More precisely, whenever child i already stands in the queue and child j goes to the beginning of the queue, the displeasure of child i will grow by a[i].

The total displeasure is the sum of all D[i].
Compute and return the total displeasure after all N children have joined the queue.


DEFINITION
Class:PriorityQueue
Method:findAnnoyance
Parameters:string, vector <int>
Returns:int
Method signature:int findAnnoyance(string S, vector <int> a)


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-The string S will contain N characters.
-a will contain N elements.
-Each element of a will be between 1 and 1,000, inclusive.


EXAMPLES

0)
"bbbbb"
{1,1,1,1,1}

Returns: 10

The queue will look as follows: { child 4, child 3, child 2, child 1, child 0 }.

The individual displeasures at the end are D[0] = 4, D[1] = 3, D[2] = 2, D[3] = 1, and D[4] = 0.
Thus, the total displeasure is 4+3+2+1+0 = 10.


1)
"bee"
{50,40,30}

Returns: 0

When the first child joins the queue, there are no other children in the queue yet, so all displeasures remain at zero. The other two children stand at the end of the queue, so they don't change anyone's displeasure either. The total displeasure at the end is therefore 0.


2)
"ebbe"
{5,2,11,1}

Returns: 12


3)
"bbeebeebeeeebbb"
{58,517,301,524,79,375,641,152,810,778,222,342,911,313,336}

Returns: 20485

*/
// END CUT HERE
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class PriorityQueue {
public:
	int findAnnoyance(string S, vector <int> a) {
		int ans = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			if (S[i] == 'b') {
				ans += accumulate(a.begin(), a.begin() + i, 0);
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
			string Arg0 = "bbbbb";
			int Arr1[] = {1,1,1,1,1};
			int Arg2 = 10;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bee";
			int Arr1[] = {50,40,30};
			int Arg2 = 0;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			string Arg0 = "ebbe";
			int Arr1[] = {5,2,11,1};
			int Arg2 = 12;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			string Arg0 = "bbeebeebeeeebbb";
			int Arr1[] = {58,517,301,524,79,375,641,152,810,778,222,342,911,313,336};
			int Arg2 = 20485;

			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg2, findAnnoyance(Arg0, Arg1));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PriorityQueue ___test;
	___test.run_test(-1);
}
// END CUT HERE
