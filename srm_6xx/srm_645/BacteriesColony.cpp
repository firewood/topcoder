// BEGIN CUT HERE
/*
SRM 645 Div2 Easy (250)

PROBLEM STATEMENT
Grazyna works in a laboratory.
Her team is about to perform an experiment with special bacteria.

There is a row of vessels.
Each vessel contains a colony of bacteria.
The colonies may currently have different sizes.
Namely, for each valid i there are currently colonies[i] bacteria in the i-th vessel (0-based index).

Grazyna has a theory about how the colony sizes change.
According to the theory, the colony sizes only change during nights and it only happens in two specific cases:

If during a day a colony finds itself immediately between two larger colonies, during the next night its size will increase by 1.
If during a day a colony finds itself immediately between two smaller colonies, during the next night its size will decrease by 1.

Note that the colonies in the first and last vessel never change their sizes as they are never between two colonies.
Also note that multiple colonies can change their size each night.

The experiment will go on for as long as some colonies keep changing their sizes.
You are given the vector <int> colonies.
Compute the result of the experiment, assuming that the colony sizes change according to Grazyna's theory.
Return a vector <int> with the same number of elements as colonies.
For each valid i, element i of the return value should be the final size of the colony in the i-th vessel.


DEFINITION
Class:BacteriesColony
Method:performTheExperiment
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> performTheExperiment(vector <int> colonies)


NOTES
-For each valid input the experiment will terminate after finitely many steps.


CONSTRAINTS
-colonies will have between 3 and 50 elements, inclusive.
-Each element of colonies will be between 1 and 100, inclusive.


EXAMPLES

0)
{5, 3, 4, 6, 1 }

Returns: {5, 4, 4, 4, 1 }


The colony sizes during the first day are given as input: {5, 3, 4, 6, 1}.
During the first night colony 1 (0-based index) will grow and colony 3 will shrink.
During the second day the colony sizes will be {5, 4, 4, 5, 1}.
During the second night colony 3 will shrink again.
During the third day the colony sizes will be {5, 4, 4, 4, 1}.
There are no more changes during the third night, so that is the final state and the experiment ends.


1)
{1, 5, 4, 9 }

Returns: {1, 4, 5, 9 }

During the first night colony 1 will shrink from 5 to 4 and at the same time colony 2 will grow from 4 to 5. Afterwards there will be no more changes.


2)
{78, 34, 3, 54, 44, 99 }

Returns: {78, 34, 34, 49, 49, 99 }


3)
{32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 }

Returns: {32, 59, 59, 59, 47, 47, 47, 47, 47, 18, 18, 19, 53, 53, 91 }

*/
// END CUT HERE
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BacteriesColony {
public:
	vector <int> performTheExperiment(vector <int> colonies) {
		int N = (int)colonies.size();
		vector <int> c[2];
		c[0] = colonies;
		int x = 0;
		while (c[0] != c[1]) {
			c[x ^ 1] = c[x];
			for (int i = 1; i < N - 1; ++i) {
				if (c[x][i - 1] < c[x][i] && c[x][i] > c[x][i + 1]) {
					c[x ^ 1][i]--;
				}
				if (c[x][i - 1] > c[x][i] && c[x][i] < c[x][i + 1]) {
					c[x ^ 1][i]++;
				}
			}
			x ^= 1;
		}
		return c[x];
	}

// BEGIN CUT HERE
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }

	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }

public:
	void run_test(int Case) { 
		int n = 0;

		// test_case_0
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {5, 3, 4, 6, 1 };
			int Arr1[] = {5, 4, 4, 4, 1 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

		// test_case_1
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {1, 5, 4, 9 };
			int Arr1[] = {1, 4, 5, 9 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

		// test_case_2
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {78, 34, 3, 54, 44, 99 };
			int Arr1[] = {78, 34, 34, 49, 49, 99 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

		// test_case_3
		if ((Case == -1) || (Case == n)){
			int Arr0[] = {32, 68, 50, 89, 34, 56, 47, 30, 82, 7, 21, 16, 82, 24, 91 };
			int Arr1[] = {32, 59, 59, 59, 47, 47, 47, 47, 47, 18, 18, 19, 53, 53, 91 };

			vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
			vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
			verify_case(n, Arg1, performTheExperiment(Arg0));
		}
		n++;

	}

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BacteriesColony ___test;
	___test.run_test(-1);
}
// END CUT HERE
